/**
 * @file lqr.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/control_system/control_system_lqr_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 73 allocs, 73 frees, 80,424 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

#include <lqr_controller.hpp>
#include <memory>
#include <Eigen/Dense>
#include <iostream>

using namespace controller;

int main()
{
    unsigned int x = 3; // Number of states [position x, position y, theta].
    unsigned int u = 2; // Input dimension [translation rate, rotation rate].
    double dt = 0.025; // Timestamp.

    // Declare MAT for LQR computation.
    Eigen::MatrixXd A(x, x); // System dynamics matrix.
    Eigen::MatrixXd B(x, u); // Input matrix.
    Eigen::MatrixXd Q(x, x); // Weight on the systems state.
    Eigen::MatrixXd R(u, u); // Weight on control input.

    A <<
        cos(M_PI_4), -sin(M_PI_4), 0.0,
        sin(M_PI_4), cos(M_PI_4), 0.0,
        0.0, 0.0, 1.0;

    B <<
        cos(M_PI_4) * dt, 0.0,
        sin(M_PI_4) * dt, 0.0,
        0.0, dt;

    R <<
        100.0, 0.0,
        0.0, 100.0;

    Q <<
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0;

    // Initialize LQR controller and assign the MAT.
    auto ptr = std::unique_ptr<LQR>(new LQR(Q, R));

    // Get state error.
    Eigen::MatrixXd stateError(x, x);
    stateError <<
        0.0023, 0.0, 0.0,
        0.0, 0.001, 0.0,
        0.0, 0.0, 0.001;

    // Get velocity controller.
    Eigen::MatrixXd cmd_vel = ptr->computeHamiltonian(A, B, stateError);
    std::cout << "\ncmd_vel.x\tcmd_vel.orientation.z\n" << cmd_vel(0,0) << "\t\t" << cmd_vel(0,1) << std::endl;

    /** !Output.
     * @brief cmd_vel.x	    cmd_vel.orientation.z
     *        0.16		    0.0800001
     */

    return EXIT_SUCCESS;
}