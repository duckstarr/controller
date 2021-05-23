/**
 * @file lqr_controller.cpp
 * @brief Infinite-horizon Linear Quadratic Regulator.
 * 
 */

#include "lqr_controller.h"
#include <Eigen/Dense>

using namespace controller;

LQR::LQR(
    const Eigen::MatrixXd& Q, 
    const Eigen::MatrixXd& R
    ):
    Q(Q),
    R(R)
{
    P.setZero(Q.rows(), Q.cols());
    cmd_vel.setZero(1, R.rows()); // [translation rate, rotation rate].
}

Eigen::MatrixXd LQR::computeHamiltonian(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::MatrixXd& E)
{
    // Set Hamilton matrix.
    Ham = Eigen::MatrixXd::Zero(2 * A.rows(), 2 * A.rows());
    Ham << A, -B * R.inverse() * B.transpose(), -Q, -A.transpose();

    // Get eigenvalues and eigenvectors from Hamilton matrix.
    Eigen::EigenSolver<Eigen::MatrixXd> eigen(Ham);

    // Form a 2nxn matrix whos columns from a basis of the corresponding subspace.
    Eigen::MatrixXcd eigenVec = Eigen::MatrixXcd::Zero(2 * A.rows(), A.rows());

    // Iterate over the Hamilton matrix and extract a stable Eigenvector.
    int j = 0;
    for(unsigned int i = 0; i < 2 * A.rows(); ++i)
    {
        // Get the negative real part: a stable value in the Laplace domain.
        if(eigen.eigenvalues()[i].real() < 0)
        {
            eigenVec.col(j) = eigen.eigenvectors().block(0, i, 2 * A.rows(), 1);
            ++j;
        }
    }

    // Compute the solution to the Riccati equation.
    Eigen::MatrixXcd U11, U21;

    U11 = eigenVec.block(0, 0, A.rows(), A.rows());
    U21 = eigenVec.block(A.rows(), 0, A.rows(), A.rows());
    P = (U21 * U11.inverse()).real();

    // Update LQR gain.
    K = R.inverse() * B.transpose() * P;
    controlUpdate = K * E;

    // Compute magnitude of velocity vector.
    cmd_vel << 
        sqrt(pow(controlUpdate(0, 0), 2.0) + pow(controlUpdate(0, 1), 2.0) + pow(controlUpdate(0, 2), 2.0)),
        sqrt(pow(controlUpdate(1, 0), 2.0) + pow(controlUpdate(1, 1), 2.0) + pow(controlUpdate(1, 2), 2.0));

    return cmd_vel;
}