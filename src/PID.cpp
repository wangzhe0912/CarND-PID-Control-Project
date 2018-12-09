#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	cout << "init: " << Kp << " " << Ki << " " << Kd << endl;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    iteration = 0;
    total_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

    total_error += cte*cte;
}

double PID::TotalError() {
    if (iteration == 0) {
        return 0;
    }
    return total_error / iteration;
}

double PID::GetSteerValue() {

	cout << Kp << " " << p_error << " " << Ki << " " << i_error << " " << Kd << " " << d_error << endl;
    double result = -1 * Kp * p_error - Ki * i_error - Kd * d_error;
    cout << "result: " << result << endl;
    return result;
}
