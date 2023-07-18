#include <stdio.h>
#include "madgwick.h"
#include "quaternions.h"

extern volatile quaternion q_w_curr;
int main(void){ 
    quaternion q1 = {0.f, 0.f, 0.0f, 0.4f};
    char print_buff[100];

    for(int i =0;i<10000; i++){
        madgwick_update(&q1);
        quat_str(&q_w_curr,print_buff);
        printf(print_buff);
        printf("%f \n", quat_norm(&q_w_curr));
    }
    
    
    return 0;   
}