#include "PID.h"

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
  
  this->p_error = 0.0; // cte
  this->i_error = 0.0; // int_cte += cte
  this->d_error = 0.0; // diff_cte = cte - prev_cte, prev_cte = cte
  
  this->prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  this->p_error = cte;
  this->i_error += cte;
  this->d_error = cte - prev_cte;
}

double PID::TotalError() {
  return -this->Kp*this->p_error - this->Kd*this->d_error - this->Ki*this->i_error;
}

