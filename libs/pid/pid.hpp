#ifndef _PID_H_
#define _PID_H_

/**
 * @brief Forward declaration of the PIDImpl class.
 * 
 * The actual implementation details of the PID controller will be handled by 
 * the PIDImpl class. This separation allows the user of the PID class to focus
 * on the interface, while the implementational details are handled by the class
 * PIDImpl.
 */

class PIDImpl;
/**
 * @brief The PID class provides an interface to a PID (Proportional-Integral-Derivative) controller.
 * 
 * The PID class manages the creation, use, and destruction of a PID controller.
 * It is designed as a wrapper around the actual PID implementation (PIDImpl) to 
 * decouple the interface from the implementation. The implementation of the
 * PID controller logic will be handled by the class PIDImpl.
 */

class PID
{
    public:
        /**
         * @brief The constructor to initialize the PID controller. It will take 
         * tthe following described variables for calculation.
         * 
         * @param dt  Time interval between control loop updates.
         * @param max Maximum value of the manipulated variable.
         * @param min Minimum value of the manipulated variable.
         * @param Kp  Proportional gain, which controls the reaction to the current error.
         * @param Kd  Derivative gain, which controls the reaction based on the rate of error change.
         * @param Ki  Integral gain, which controls the reaction based on the accumulation of past errors.
         *
         * @details
         * The constructor initializes the PID controller with the provided gains (Kp, Ki, Kd), 
         * and output limits (max, min). It is expected that the implementation of the internal
         * PID algorithm will be handled in the PIDImpl class.
         */
         
         PID( double dt, double max, double min, double Kp, double Kd, double Ki );

         /**
         * @brief The function named 'calculate' is responsible for calculating the output of the PID controller.
         * The following variables that will taken as inputs by the calculate function.
         * 
         * @param setpoint The desired target value for the system.
         * @param pv       The current process value (feedback) from the system.
         * @return The manipulated variable (output) which will drive the system towards the setpoint.
         * 
         * @details
         * This function will be responsible for calling the calculate function within the
         * PIDImpl class to compute the control variable based on the difference between the
         * setpoint and the current process value (pv).
         */

         double calculate( double setpoint, double pv );

         /**
         * @brief Declaration for the destructor for the PID class.
         * 
         * Cleans up any resources used by the PID controller. The PIDImpl class is responsible
         * for managing any dynamically allocated memory, so the destructor will ensure 
         * proper deallocation.
         */

         ~PID();
         
    private :
        /**
         * @brief Declaration of a pointer to the PIDImpl object that handles the actual PID logic.
         * 
         * The PIDImpl class will contain the implementation of the PID algorithm, while
         * the PID class serves as an interface. By using a pointer to the implementation,
         * we allow for flexible, modular design where the implementation can be changed 
         * without modifying the interface.
         */
        
         PIDImpl *pimpl;

};

#endif