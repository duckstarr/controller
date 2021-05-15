/**
 * @file low_pass_filter.cpp
 * @brief Low-Pass Filter Lib.
 * 
 */
#include "low_pass_filter.h"
#include <math.h>

using namespace filter;

LPF::LPF() : output(0)
{
}

double LPF::computeStep(const double input, const double w0, const double dt)
{
    // Using the Kirchoff's Laws we arrive at the following differential equation.
    if(w0 <= 0 || dt <= 0) return output += input - output;
    else return output += (input - output) * (1 - std::exp(-dt * 2 * M_PI * w0));
}