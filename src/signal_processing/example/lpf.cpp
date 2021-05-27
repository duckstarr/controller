/**
 * @file lpf.cpp
 * @brief A practicle example that uses low-pass-filter to process an input signal.
 * 
 */

#include <low_pass_filter.hpp>
#include <memory>
#include <iostream>

using namespace filter;

int main()
{
    // Create low-pass-filter.
    auto ptr = std::unique_ptr<LPF>(new LPF);

    double input_signal = 1.0;
    double cutoff_frequency = 1.0;
    double dt = 0.1;
    
    for(unsigned int i = 0; i < 15; i++)
    {
        std::cout << "LPF Output: " << ptr->computeStep(input_signal, cutoff_frequency, dt) << std::endl;
    }

    /**
     * @brief 
     * LPF Output: 0.466512
     * LPF Output: 0.71539
     * LPF Output: 0.848164
     * LPF Output: 0.918997
     * LPF Output: 0.956786
     * LPF Output: 0.976946
     * LPF Output: 0.987701
     * LPF Output: 0.993439
     * LPF Output: 0.9965
     * LPF Output: 0.998133
     * LPF Output: 0.999004
     * LPF Output: 0.999469
     * LPF Output: 0.999716
     * LPF Output: 0.999849
     * LPF Output: 0.999919
     * 
     */

    return EXIT_SUCCESS;
}