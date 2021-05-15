/**
 * @file pid_controller.h
 * @brief PID Controller.
 */

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <vector>

namespace controller
{

class PID
{
    public:
        /**
         * @brief A PID controller that continuously calculates an error value and adjust them accordingly.
         * 
         * @param P proportional gain.
         * @param I integral gain.
         * @param D derivative gain.
         * @param min minimum value of manipulated variable.
         * @param max maximum value of manipulated variable.
         */
        PID(const double P, const double I, const double D, const double min, const double max);
        ~PID() {};

        /**
         * @brief Compute the desired state of a system.
         * 
         * @param setpoint the goal of the system. Example: to go from point A to B, the setpoint is B.
         * @param current_state the current state of a system. Example: to go from A to B, the current_state is A.
         * @param dt the time difference between two data sets. Example: the time it takes to go from A to A + 1 is dt.
         * @return double 
         */
        double compute(const double setpoint, const double current_state, const double dt);

    private:
        double min, max;
        double P, I, D;
        
        struct stateError
        {
            double pre_error;
            double proportional;
            double integral;
            double derivative;
            stateError(): pre_error(0), proportional(0), integral(0), derivative(0){}
        } stateError;

        struct statePID
        {
            double output;
            double proportional;
            double integral;
            double derivative;
            statePID(): output(0), proportional(0), integral(0), derivative(0){}
        } statePID;
};

} // namespace controller

#endif /* PID_CONTROLLER_H */