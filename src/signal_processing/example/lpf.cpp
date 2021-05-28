/**
 * @file lpf.cpp
 * @brief !Valgrind output
 *  Memcheck, a memory error detector
 *  Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
 *  Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
 *  Command: ./src/signal_processing/signal_processing_lpf_example
 *  
 *  HEAP SUMMARY:
 *      in use at exit: 0 bytes in 0 blocks
 *    total heap usage: 3 allocs, 3 frees, 73,736 bytes allocated
 *  
 *  All heap blocks were freed -- no leaks are possible
 *  
 *  For lists of detected and suppressed errors, rerun with: -s
 *  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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