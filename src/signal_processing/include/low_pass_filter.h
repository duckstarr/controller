/**
 * @file low_pass_filter.h
 * @brief Low-Pass Filter Lib.
 * 
 */
#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

namespace filter
{

class LPF
{
    public:
        // Create LPF.
        LPF();
        ~LPF() {};

        /**
         * @brief A setp input response.
         * 
         * @param input input signal.
         * @param w0 cutoff frequency.
         * @param dt timestamp.
         * @return double 
         */
        double computeStep(const double input, const double w0, const double dt);

    private:
        double output;

};

} // namespace filter

#endif /* LOW_PASS_FILTER_H */