#include "quaternions.h"
#include <stdio.h>
#include <math.h>
quaternion quat_add(quaternion *q1, quaternion *q2){
    quaternion q_result;
    q_result.w = q1->w + q2->w;
    q_result.x = q1->x + q2->x;
    q_result.y = q1->y + q2->y;
    q_result.z = q1->z + q2->z;
    return q_result;
}

quaternion quat_multiply(quaternion* q1, quaternion* q2){
    quaternion q_result;
    q_result.w = (q1->w)*(q2->w) - (q1->x)*(q2->x) - (q1->y)*(q2->y) - (q1->z)*(q2->z);
    q_result.x = (q1->w)*(q2->x) + (q1->x)*(q2->w) + (q1->y)*(q2->z) - (q1->z)*(q2->y);
    q_result.y = (q1->w)*(q2->y) - (q1->x)*(q2->z) + (q1->y)*(q2->w) + (q1->z)*(q2->x);
    q_result.z = (q1->w)*(q2->z) + (q1->x)*(q2->y) - (q1->y)*(q2->x) + (q1->z)*(q2->w);
    return q_result;
}


quaternion quat_conjugate(quaternion *q){
    quaternion q_result;
    q_result.w = q->w;
    q_result.x = -q->x;
    q_result.y = -q->y;
    q_result.z = -q->z;
    return q_result;
}

void quat_str(quaternion *q, char* r_str){
    #if QUAT_TARGET == WINDOWS
        sprintf(r_str, "%.3fw %.3fx %.3fy %.3fz \n", q->w, q->x, q->y, q->z);
    #elif QUAT_TARGET == STM32

    #else
        #error UNKNOWN TARGET  
    #endif
}


void quat_print(quaternion *q, char* r_str){
    #if QUAT_TARGET == WINDOWS
        sprintf(r_str, "%.3fw %.3fx %.3fy %.3fz \n", q->w, q->x, q->y, q->z);
        printf(r_str);
    #elif QUAT_TARGET == STM32

    #else
        #error UNKNOWN TARGET  
    #endif
}


quaternion quat_multiply_const(quaternion *q, QUAT_DATA_TYPE val){
    quaternion q_result;
    q_result.w = q->w * val;
    q_result.x = -q->x * val;
    q_result.y = -q->y * val;
    q_result.z = -q->z * val;
    return q_result;
}

float quat_norm(quaternion* q){
    return sqrt(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
}