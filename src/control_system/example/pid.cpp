/**
 * @file pid.cpp
 * @brief A practical example on PID controllers.
 * 
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