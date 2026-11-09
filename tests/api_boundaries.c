#include "pc_imu_axis_sign_flip_i32.h"
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
int main(void){const int32_t in[3]={1,INT32_MIN,3};int32_t out[3]={7,8,9};if(pc_imu_axis_sign_flip_i32(NULL,0,out)||out[0]!=7||out[1]!=8||out[2]!=9)return 1;if(pc_imu_axis_sign_flip_i32(in,0,NULL))return 2;if(pc_imu_axis_sign_flip_i32(in,1,out)||out[0]!=7||out[1]!=8||out[2]!=9)return 3;if(pc_imu_axis_sign_flip_i32(in,3,out)||out[0]!=7||out[1]!=8||out[2]!=9)return 4;return 0;}