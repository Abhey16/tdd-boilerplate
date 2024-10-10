#include <gtest/gtest.h>

#include "pid.hpp"

// test1: Ensure the output is clamped within
// the max and min bounds.
TEST(PIDControllerTest, TestClamping) {
  // Initialize the PID controller with large gains to test clamping
  double dt = 1.0;
  double max = 50.0;   // Maximum output limit
  double min = -50.0;  // Minimum output limit
  double Kp = 10.0;
  double Kd = 5.0;
  double Ki = 1.0;

  PID pid(dt, max, min, Kp, Kd, Ki);

  // Setpoint and process variable
  double setpoint = 100.0;
  double pv = 0.0;

  // Call the calculate function
  double output = pid.calculate(setpoint, pv);

  // Since the error is large and the gains are high, the expected unclamped
  // output will be much greater than max. We expect the output to be clamped to
  // the maximum value of 50.0.

  ASSERT_EQ(output, max);

  // Test clamping for minimum as well
  setpoint = -100.0;  // Large negative error
  output = pid.calculate(setpoint, pv);

  // We expect the output to be clamped to the minimum value of -50.0.
  ASSERT_EQ(output, min);
}

// test2 : Check if the calculate method computes
// the correct output based on known PID gains and inputs.

TEST(PIDControllerTest, TestCalculateOutput) {
  // Initialize the PID controller
  double dt = 1.0;  // Time interval
  double max = 100.0;
  double min = -100.0;
  double Kp = 1.0;  // Proportional gain
  double Kd = 0.1;  // Derivative gain
  double Ki = 0.5;  // Integral gain

  PID pid(dt, max, min, Kp, Kd, Ki);

  // Setpoint and process variable
  double setpoint = 10.0;
  double pv = 0.0;

  // Call the calculate function
  double output = pid.calculate(setpoint, pv);

  double expected_output = 16.0;

  // Check if output matches expected value
  ASSERT_NEAR(output, expected_output,
              0.01);  // Allowing for small floating-point errors
}
