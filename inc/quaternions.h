#ifndef QUATERNIONS_H
#define QUATERNIONS_H
#define QUAT_TARGET WINDOWS // uncomment one of it, just for quat_str implementaion.
//#define QUAT_TARGET STM32
#define QUAT_DATA_TYPE float // Most of MCUs has just single precision FPUs otherwise you can define it as double
struct quaternion
{
    QUAT_DATA_TYPE w;
    QUAT_DATA_TYPE x;
    QUAT_DATA_TYPE y;
    QUAT_DATA_TYPE z;
};
typedef struct quaternion quaternion;

quaternion quat_add(quaternion *q1, quaternion *q2);
quaternion quat_multiply(quaternion *q1, quaternion *q2);
quaternion quat_multiply_const(quaternion *q, float val);
quaternion quat_conjugate(quaternion *q);
void quat_print(quaternion *q, char* r_str);
void quat_str(quaternion *q, char* r_str);
float quat_norm(quaternion* q);
#endif      //QUATERNIONS_H