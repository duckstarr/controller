/**
 * @file pid_controller.cpp
 * @brief PID Controller Lib.
 * 
 */

#include "pid_controller.h"

using namespace controller;

PID::PID(const double P, const double I, const double D, const double min, const double max) : 
    P(P), I(I), D(D), min(min), max(max)
{
    stateError = {};
    statePID = {};
}

double PID::compute(const double setpoint, const double current_state, const double dt)
{
    // Compute state error.
    stateError.proportional = setpoint - current_state;
    stateError.integral += stateError.proportional * dt;
    stateError.derivative = (stateError.proportional - stateError.pre_error) / dt;

    // Compute PID term.
    statePID.proportional = P * stateError.proportional;
    statePID.integral = I * stateError.integral;
    statePID.derivative = D * stateError.derivative;

    // Compute desired state.
    statePID.output = statePID.proportional + statePID.integral + statePID.derivative;

    // Hard constraints on desired state.
    if(statePID.output > max) statePID.output = max;
    else if (statePID.output < min) statePID.output = min;

    // Update previous error.
    stateError.pre_error = stateError.proportional;

    return statePID.output;
}