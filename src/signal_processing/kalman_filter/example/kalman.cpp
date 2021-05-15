/**
 * @file kf_node.cpp
 * @brief A practical example on Kalman Filter.
 * 
 */

#include "kalman_filter.h"
#include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <ctime>

using namespace controller;

int main(int argc, char* argv[])
{
    int n = 3; // Number of states [position, velocity, acceleration].
    int m = 1; // Number of measurements.
    double dt = 1.0/30; // Timestamp.

    // Declare MAT for Kalman filter computation.
    Eigen::MatrixXd A(n, n); // System dynamics matrix
    Eigen::MatrixXd C(m, n); // Output matrix
    Eigen::MatrixXd Q(n, n); // Process noise covariance
    Eigen::MatrixXd R(m, m); // Measurement noise covariance
    Eigen::MatrixXd P(n, n); // Estimate error covariance

    // Measure the position only.
    A << 
        1, dt, 0, 
        0, 1, dt, 
        0, 0, 1;

    C << 1, 0, 0;

    // Reasonable covariance matrices
    Q << 
        .05, .05, .0, 
        .05, .05, .0, 
        .0, .0, .0;

    R << 1;

    P << 
        .1, .1, .1, 
        .1, 10000, 10, 
        .1, 10, 100;

    // Generate random values from 0 - 1.
    std::srand(std::time(0));
    std::vector<double> measurements;

    for(unsigned int i = 0; i < 100 ; i++)
    {
        double noise = ((double)std::rand() / (double)RAND_MAX);
        measurements.push_back(noise);
    }

    // Initialize Kalman filter.
    KalmanFilter KF(A, C, Q, R, P);

    // Start the Kalman filter with zero initial parameters.
    KF.init();

    // Feed the measurements to the filter and get estimated states of a system.
    Eigen::VectorXd y(m);
    for(unsigned int i = 0; i < measurements.size(); i++)
    {
        y << measurements[i];
        std::cout << "KF Result 結果: " << KF.compute(y, dt).transpose() << std::endl;
        
        /** !Output.
         * @brief KF Result 結果:  0.513434 -0.150251 -0.213232
         * 
         * @brief [position, velocity, acceleration]
         */
    }

    return EXIT_SUCCESS;
}