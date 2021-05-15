/**
 * @file lqr_controller.h
 * @brief Infinite-horizon Linear Quadratic Regulator.
 * 
 */

#ifndef LQR_CONTROLLER_H
#define LQR_CONTROLLER_H

#include <Eigen/Dense>

namespace controller
{

class LQR
{
    public:
        LQR(const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R);
        ~LQR() {};
        
        /**
         * @brief An infinite-horizon LQR controller with penalties on the state feedback and input signal (Q and R, respectively).
         * @brief LQR gain is solved by searching for stable poles of the system through the Hamiltonian matrix.
         * 
         * @param A System dynamics matrix.
         * @param B Input matrix.
         * @param E State error.
         * @return Eigen::MatrixXd LQR gain, K.
         */
        Eigen::MatrixXd computeHamiltonian(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& E);

    private:
        // Declare generic MAT for LQR computations.
        Eigen::MatrixXd K;
        Eigen::MatrixXd Q;
        Eigen::MatrixXd R;
        Eigen::MatrixXd I;
        Eigen::MatrixXd P;

        // Declare Hamilton matrix.
        Eigen::MatrixXd Ham;

        // Output.
        Eigen::MatrixXd cmd_vel;
        Eigen::MatrixXd controlUpdate;
};

} // namespace controller

#endif /* LQR_CONTROLLER_H */