#include "PID.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

}

void PID::UpdateError(double cte) {
  i_error += cte;
  	
  d_error = cte - p_error;
  p_error = cte;

}

double PID::TotalError() {
  if (abs(i_error)>30)
  {
  i_error = 0;
  }

  return i_error;
}

