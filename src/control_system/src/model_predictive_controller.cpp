/**
 * @file model_predictive_controller.cpp
 * @brief Finite-horizon Model Predictive Controller.
 * 
 */

#include <mpc.hpp>
#include <Eigen/Dense>
#include <iostream>

using namespace controller;

MPC::MPC(const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R, const double S) :
    Q(Q), R(R), saturation(S), converged(false)
{
    P_new.setZero();
    Ad.setZero(Q.rows(), Q.cols());
    I.setIdentity(Q.rows(), Q.cols());
    cmd_vel.setZero(1, R.rows()); // [translation rate, rotation rate].
}

Eigen::MatrixXd MPC::computeDiscrete(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& E, unsigned int numIteration, double tolarance, double dt)
{
    // A Cost-to-go matrix P evolving backwards in time from Q is defined as,
    P = Q;

    // Discretization.
    Ad = (I + A * dt * 0.5) * (I - A * dt * 0.5).inverse();
    Bd = B * dt;

    // Iterating over a finite-horizon Algebraic Riccati Equation to a steady-state solution; that is, P_new - P ~= 0 + tolarance.
    for(unsigned int i = 0; i < numIteration; i++)
    {
        P_new = Ad.transpose() * P * Ad - (Ad.transpose() * P * Bd) * (R + Bd.transpose() * P * Bd).inverse() * (Bd.transpose() * P * Ad) + Q;

        // Check system convergence.
        difference = fabs((P_new - P).maxCoeff());
        if(difference < tolarance)
        {
            // std::cout << "Solution found at i = " << i << std::endl;

            converged = true;
            break;
        }

        // Update Riccati solution.
        P = P_new;
    }

    // Get cmd_vel.
    if(converged)
    {
        K = (R + Bd.transpose() * P * Bd).inverse() * Bd.transpose() * P * Ad;
        controlUpdate = K * E;

        // Compute magnitude of velocity vector.
        cmd_vel << 
            sqrt(pow(controlUpdate(0, 0), 2.0) + pow(controlUpdate(0, 1), 2.0) + pow(controlUpdate(0, 2), 2.0)),
            sqrt(pow(controlUpdate(1, 0), 2.0) + pow(controlUpdate(1, 1), 2.0) + pow(controlUpdate(1, 2), 2.0));
        
        // Saturate output signal.
        if(cmd_vel(0, 0) > saturation) cmd_vel(0, 0) = saturation;
        if(cmd_vel(0, 0) < -saturation) cmd_vel(0, 0) = -saturation;
        if(cmd_vel(0, 1) > saturation) cmd_vel(0, 1) = saturation;
        if(cmd_vel(0, 1) < -saturation) cmd_vel(0, 1) = -saturation;

        return cmd_vel;
    }
    else
    {
        std::cout << "MPC controller did not converge. Resetting cmd_vel... 沒有解決方案" << std::endl;
        cmd_vel.setZero();

        return cmd_vel;
    }

    converged = false;
}