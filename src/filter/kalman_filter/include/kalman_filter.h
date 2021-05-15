/**
 * @file kalman_filter.h
 * @brief Kalman Filter.
 * 
 */

#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include <Eigen/Dense>

namespace controller
{

class KalmanFilter
{
    public:
        /**
         * @brief Create a Kalman filter.
         * 
         * @param C Output matrix
         * @param Q Process noise covariance
         * @param R Measurement noise covariance
         * @param P Estimate error covariance
         */
        KalmanFilter(
            const Eigen::MatrixXd& A,
            const Eigen::MatrixXd& C,
            const Eigen::MatrixXd& Q,
            const Eigen::MatrixXd& R,
            const Eigen::MatrixXd& P
        );
        ~KalmanFilter() {};

        /**
         * @brief Initialize the filter with initial states as zero.
         * 
         */
        void init();

        /**
         * @brief Initialize the filter with an estimation on the initial states.
         * @param t0 initial timestamp.
         * @param x0 estimated state of the system.
         * 
         */
        void init(double t0, const Eigen::VectorXd& x0);

        /**
         * @brief An adaptive Kalman filter.
         * @brief Update the estimated state based on measured values, using the given time step and dynamics matrix.
         * @param y measurements.
         * @param dt timestamp.
         * 
         */
        Eigen::VectorXd compute(const Eigen::VectorXd& y, double dt);

    private:
        // Matrices for computation.
        Eigen::MatrixXd A, C, Q, R, P, K, P0;

        // Systems dimension.
        int m; // Number of measurements.
        int n; // Number of states.

        Eigen::MatrixXd I; // Identity matrix.
        Eigen::VectorXd x_hat, x_hat_new; // Estimated states.

        // Initial timer.
        double t0;

        // Flag.
        bool initialized;
};

} // namespace controller

#endif /* KALMAN_FILTER_H */
