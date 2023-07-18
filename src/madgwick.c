#include "quaternions.h"
#define DELTA_T 0.001f
volatile quaternion q_w_curr = {0.f, 0.f, 0.f, 0.f};

void madgwick_update(quaternion *q_w_meass){
    static quaternion q_w_est_last = {0.f, 1.f, 0.f, 0.f};
    static quaternion qw_dt;
    quaternion q_w_dt_half = quat_multiply_const(&q_w_est_last, 0.5f);
    qw_dt = quat_multiply(&q_w_dt_half, q_w_meass);
    quaternion qw_dt_DT = quat_multiply_const(&qw_dt, DELTA_T);
    q_w_curr = quat_add(&q_w_est_last, &qw_dt_DT);
    q_w_est_last = q_w_curr;
}