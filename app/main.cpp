#include <iostream>
#include "pid.hpp"

int main(){

   PID pid(0.1, 100.0, -100.0, 0.1, 0.01, 0.5);

    double setpoint = 10.0;  // Desired value
    double pv = 5.0;         // Process value

    double result = pid.calculate(setpoint,pv);

    std::cout << "output:"<< result << std::endl;
  
}