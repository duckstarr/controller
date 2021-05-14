/**
 * @file test.cpp
 * @brief Unit testing PID class.
 * 
 */

#include <gtest/gtest.h>
#include "pid_controller.h"

using namespace controller;

/**
 * @brief Test PID inheritance.
 */
class PIDController : public PID
{
    public:
        PIDController (const double P, const double I, const double D, const double min, const double max) :
            PID(P, I, D, min, max)
        {
        }

        double PIDOutput()
        {
            return PID::compute(4.0, 0.0, 0.1);
        }
};

class PIDTest : public ::testing::Test
{
    protected:
        PIDTest()
        {
            double P, I, D;
            double min, max;

            P = 1.0;
            I = 0.2;
            D = 0.0;

            min = -5.0;
            max = 5.0;

            PID = new PIDController(P, I, D, min, max);
        }
        ~PIDTest()
        {
            delete PID;
        }

        PIDController * PID;
};

TEST_F(PIDTest, ComputeDesiredState)
{
    EXPECT_EQ(PID->PIDOutput(), 4.08);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}