#ifndef _PID_SOURCE_
#define _PID_SOURCE_

#include <iostream>
#include <cmath>
#include "pid.hpp"

using namespace std;

/**
 * @brief The PIDImpl class handles the actual PID (Proportional-Integral-Derivative) control logic.
 * 
 * This class performs the calculations for the PID controller. It maintains the internal state,
 * such as the integral of the error and the previous error value, and applies the PID formula
 * to compute the controller's output.
 * 
 * The interface is provided by the PID class, and this class should only be accessed through 
 * the PID class, ensuring a clear separation of interface and implementation.
 */

class PIDImpl
{
    public:
        /**
         * @brief Constructor for PIDImpl.
         * 
         * @param dt  Time interval between control loop updates.
         * @param max Maximum value of the manipulated variable (controller output).
         * @param min Minimum value of the manipulated variable (controller output).
         * @param Kp  Proportional gain.
         * @param Kd  Derivative gain.
         * @param Ki  Integral gain.
         * 
         * @details
         * Initializes the PID controller with the provided gain values (Kp, Ki, Kd), and the 
         * output limits (max, min). The time interval `dt` is used for the integration and
         * differentiation in the PID formula.
         */
        PIDImpl(double dt, double max, double min, double Kp, double Kd, double Ki);

        /**
         * @brief Destructor for PIDImpl.
         * 
         * Cleans up any resources used by the PIDImpl class. As of now, no dynamic memory is allocated,
         * but this ensures that future changes will not lead to memory leaks.
         */
        ~PIDImpl();
        /**
         * @brief Calculates the PID output.
         * 
         * @param setpoint The desired value (target) for the process.
         * @param pv       The current process value (feedback) from the system.
         * @return The manipulated variable (output) that will drive the system towards the setpoint.
         * 
         * @details
         * The method computes the control variable based on the error between the setpoint and the
         * process value. It applies the Proportional, Integral, and Derivative terms to calculate
         * the control action, and ensures the output is within the specified range (`max` and `min`).
         */
        double calculate(double setpoint, double pv);

    private:
        double _dt;        /**< Time interval between updates */
        double _max;       /**< Maximum output value */
        double _min;       /**< Minimum output value */
        double _Kp;        /**< Proportional gain */
        double _Kd;        /**< Derivative gain */
        double _Ki;        /**< Integral gain */
        double _pre_error; /**< Previous error value, used in derivative calculation */
        double _integral;  /**< Accumulated integral of the error */
};

/**
 * @brief PID constructor.
 * 
 * Initializes the PID controller by creating a PIDImpl object. The parameters `dt`, `max`, `min`, `Kp`, `Kd`, and `Ki` 
 * are passed to the PIDImpl constructor, which handles the actual implementation.
 * 
 * @param dt  Time interval between control loop updates.
 * @param max Maximum value of the manipulated variable.
 * @param min Minimum value of the manipulated variable.
 * @param Kp  Proportional gain.
 * @param Kd  Derivative gain.
 * @param Ki  Integral gain.
 */
PID::PID(double dt, double max, double min, double Kp, double Kd, double Ki)
{
    // Replace this line by setting the pimpl pointer to a new object of the 
    // PIDImpl class and send the dt, max, min, kp, kd and ki as inputs to it.
}

/**
 * @brief Calculates the PID controller's output.
 * 
 * @param setpoint The desired value for the process.
 * @param pv       The current process value.
 * @return The manipulated variable (output) that will drive the system towards the setpoint.
 * 
 * @details
 * This function is a wrapper that calls the actual implementation in the PIDImpl class.
 */

double PID::calculate(double setpoint, double pv)
{
    // Call the calculate function of the PIDImpl class through the object
    // of that class. Pass the setpoint and pv as inputs to the function call.
    // Replace these comments with the necessary code.
    return 0.0;
}

/**
 * @brief Destructor for the PID class.
 * 
 * Cleans up the PIDImpl object by deleting it, ensuring proper resource management.
 */
PID::~PID()
{
    // Delete the pimpl variable. Write the necessary code by replacing this line.
}

/**
 * @brief PIDImpl constructor implementation.
 * 
 * @param dt  Time interval between control loop updates.
 * @param max Maximum value of the manipulated variable.
 * @param min Minimum value of the manipulated variable.
 * @param Kp  Proportional gain.
 * @param Kd  Derivative gain.
 * @param Ki  Integral gain.
 * 
 * @details
 * Initializes the internal variables for the PID controller. It sets the initial values of `_pre_error` and `_integral`
 * to zero, as the system has not yet encountered any error.
 */
PIDImpl::PIDImpl(double dt, double max, double min, double Kp, double Kd, double Ki)
    : _dt(dt), _max(max), _min(min), _Kp(Kp), _Kd(Kd), _Ki(Ki), _pre_error(0), _integral(0)
    // Replace these comment lines with the necessary code to 
    // pass the dt, max, min, kp, kd and ki to the attributes of the 
    // PIDImpl class. Initialize the _pre_error and _integral with zero.
{
}

/**
 * @brief Calculates the PID output.
 * 
 * @param setpoint The desired target value for the process.
 * @param pv       The current process value.
 * @return The manipulated variable (output) to drive the system towards the setpoint.
 * 
 * @details
 * This method implements the full PID control logic:
 * - **Proportional Term**: Reacts to the current error between the setpoint and the process value.
 * - **Integral Term**: Accumulates the past errors over time, helping to eliminate steady-state error.
 * - **Derivative Term**: Reacts to the rate of change of the error, helping to dampen the response.
 * 
 * The final output is clamped within the maximum and minimum bounds, ensuring that the controller 
 * output stays within feasible limits for the system being controlled.
 */


 double PIDImpl::calculate(double setpoint, double pv)
{

    // Write a line of code to calculate the error by finding the
    // difference between setpoint and pv. Use double datatype for assignment
   

    // Write code for calculating the ouput for the propotional term
    // by multiplying _kp with the error. Use double for the asignment.


    // Write code for calculaing the Integral term by multiplying error
    // with dt to account for the addition of past error and add it to the 
    // _integral term. Then assign the output to variable Iout of datatype double 
    // after multiplying _ki with the derivative term.

    // Calculate the derivative term by substracting the _pre_error term from
    // the error term and dividing the difference by _dt. Keep the derivative term
    // with datatype double. Then calculate the Dout term by multiplying the 
    // _kd with the derivative term. Again use double as the datatype.
    
    // Use a variable named output of type double and add the Pout, 
    // to Iout and Dout.
    

    // Write some code to clip the output to the _max and _min

    // Save _pre_error to the present error for future calculations.
    
    // Return the output
    // return 0.0;
}

#endif


