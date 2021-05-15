/**
 * @file mpc.h
 * @brief Finite-horizon Model Predictive Controller.
 * 
 */

#ifndef MPC_H
#define MPC_H

#include <Eigen/Dense>

namespace controller
{

class MPC
{
    public:
        MPC(const Eigen::MatrixXd& Q, const Eigen::MatrixXd& R, const double S);
        ~MPC() {};

        /**
         * @brief An MPC based on the following problem statement:
         * 
         *        min(U) with penalties on the current state, final state, and input signal (Q, P, and R, respectively).
         * 
         *        s.t. x0 = x(t)
         *             x(k + 1) = Ax(k) + Bu(k), k = 0, ... , N-1
         *             u_min <= u <= u_max
         *             y˙ cos θ − x˙ sin θ = 0 non-holonomic constraint
         *             u(k) ∈ U if sensor is in range.
         *             x(k) ∈ X if sensor is in range.
         * 
         * @param A System dynamics matrix.
         * @param B Input matrix.
         * @param E State error.
         * @param numIteration The length of online receding time window to search for a stable solution.
         * @param tolarance The tolarance of the Riccati convergence.
         * @param dt Timestamp.
         * @return Eigen::MatrixXd cmd_vel
         */
        Eigen::MatrixXd computeDiscrete(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& E, const unsigned int numIteration, const double tolarance, const double dt);

    private:
        // Declare generic MAT for MPC computations.
        Eigen::MatrixXd K;
        Eigen::MatrixXd Q;
        Eigen::MatrixXd R;
        Eigen::MatrixXd I;
        Eigen::MatrixXd P;
        Eigen::MatrixXd P_new;

        // Discrete MAT.
        Eigen::MatrixXd Ad;
        Eigen::MatrixXd Bd;

        // Output.
        Eigen::MatrixXd cmd_vel;
        Eigen::MatrixXd controlUpdate;

        // Flags.
        double difference;
        double saturation;
        bool converged;
};

} // namespace control_toolbox

#endif /* MPC_H */