#ifndef MADGWICK_H
#define MADGWICK_H
#include "quaternions.h"
extern volatile quaternion q_w_curr;
void madgwick_update(quaternion *q_w_meass);
#endif