#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    Kp = Kp;
    Ki = Ki;
    Kd = Kd;
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
    double result = -1 * Kp * p_error - Ki * i_error - Kd * d_error;
    return result;
}
