/**
 * @file lpf.cpp
 * @brief A practicle example that uses low-pass-filter to process an input signal.
 * 
 */

#include "low_pass_filter.h"
#include <iostream>

using namespace filter;

int main()
{
    // Create low-pass-filter.
    LPF LPF;

    double input_signal = 5.0;
    double cutoff_frequency = 2.0;
    double dt = 0.1;
    
    for(unsigned int i = 0; i < 15; i++)
    {
        std::cout << "LPF Output: " << LPF.computeStep(input_signal, cutoff_frequency, dt) << std::endl;
    }

    /**
     * @brief 
     * LPF Output: 3.57695
     * LPF Output: 4.59499
     * LPF Output: 4.88473
     * LPF Output: 4.96719
     * LPF Output: 4.99066
     * LPF Output: 4.99734
     * LPF Output: 4.99924
     * LPF Output: 4.99978
     * LPF Output: 4.99994
     * LPF Output: 4.99998
     * LPF Output: 5
     * LPF Output: 5
     * LPF Output: 5
     * LPF Output: 5
     * LPF Output: 5
     * 
     */

    return EXIT_SUCCESS;
}