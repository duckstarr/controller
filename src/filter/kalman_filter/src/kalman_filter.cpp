/**
 * @file kalman_filter.cpp
 * @brief Kalman Filter.
 * 
 */

#include "kalman_filter.h"
#include <Eigen/Dense>
#include <iostream>

using namespace controller;

KalmanFilter::KalmanFilter(
    const Eigen::MatrixXd& A,
    const Eigen::MatrixXd& C,
    const Eigen::MatrixXd& Q,
    const Eigen::MatrixXd& R,
    const Eigen::MatrixXd& P
    ):
    A(A), C(C), Q(Q), R(R), P0(P),
    m(C.rows()), n(A.rows()),
    I(n, n), x_hat(n), x_hat_new(n),
    initialized(false)
{
    // Initialize the identity transformation.
    I.setIdentity();
}

void KalmanFilter::init(double t0, const Eigen::VectorXd& x0)
{
    // Set parameters based on initial guess.
    x_hat = x0;
    P = P0;
    this->t0 = t0;
    initialized = true;
}

void KalmanFilter::init()
{
    // Set parameters to zero.
    x_hat.setZero();
    P = P0;
    t0 = 0;
    initialized = true;
}

Eigen::VectorXd KalmanFilter::compute(const Eigen::VectorXd& y, double dt)
{
    // Error handling.
    if(!this->initialized) throw std::runtime_error("Filter is not initialized!");

    // Set the new state.
    x_hat_new = A * x_hat;

    // Predict error covariance.
    P = A * P * A.transpose() + Q;

    // Update Kalman gain.
    K = P * C.transpose() * (C * P * C.transpose() + R).inverse();

    // Update estimate covariance.
    P = (I - K * C) * P;

    // Update state.
    x_hat_new += K * (y - C * x_hat_new);
    x_hat = x_hat_new;

    return x_hat;
}