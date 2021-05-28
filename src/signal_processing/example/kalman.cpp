/**
 * @file kf_node.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/signal_processing/signal_processing_kf_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 2,127 allocs, 2,127 frees, 128,736 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

#include <kalman_filter.hpp>
#include <Eigen/Dense>
#include <memory>
#include <iostream>
#include <vector>
#include <ctime>

using namespace filter;

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
    auto KF = std::unique_ptr<KalmanFilter>(new KalmanFilter(A, C, Q, R, P));

    // Start the Kalman filter with zero initial parameters.
    KF->init();

    // Feed the measurements to the filter and get estimated states of a system.
    Eigen::VectorXd y(m);
    for(unsigned int i = 0; i < measurements.size(); i++)
    {
        y << measurements[i];
        std::cout << "KF Result 結果: " << KF->compute(y, dt).transpose() << std::endl;
        
        /** !Output.
         * @brief KF Result 結果:  0.513434 -0.150251 -0.213232
         * 
         * @brief [position, velocity, acceleration]
         */
    }

    return EXIT_SUCCESS;
}