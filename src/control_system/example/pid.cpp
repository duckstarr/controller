/**
 * @file pid.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/control_system/control_system_pid_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 3 allocs, 3 frees, 73,832 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

#include <pid_controller.hpp>
#include <memory>
#include <iostream>

using namespace controller;

int main()
{
    double P, I, D;
    double min, max;

    P = 1.0;
    I = 0.2;
    D = 0.0;

    min = -5.0;
    max = 5.0;

    auto ptr = std::unique_ptr<PID>(new PID(P, I, D, min, max));

    auto velocity = ptr->compute(4.0, 0.0, 0.1);

    /**
     * @brief velocity: 4.08
     */
    std::cout << "velocity: " << velocity << std::endl;

    return EXIT_SUCCESS;
}