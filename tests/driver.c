#include "pc_imu_axis_sign_flip_i32.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
int main(void){int32_t in[3],out[3];unsigned a,alias;while(scanf("%" SCNd32 " %" SCNd32 " %" SCNd32 " %u %u",&in[0],&in[1],&in[2],&a,&alias)==5){out[0]=71;out[1]=72;out[2]=73;if(alias){if(a<=2u){int32_t x[3]={in[0],in[1],in[2]};int ok=pc_imu_axis_sign_flip_i32(x,(uint8_t)a,x);printf("%d %" PRId32 " %" PRId32 " %" PRId32 "\n",ok,x[0],x[1],x[2]);}else puts("0 71 72 73");}else{int ok=pc_imu_axis_sign_flip_i32(in,(uint8_t)a,out);printf("%d %" PRId32 " %" PRId32 " %" PRId32 "\n",ok,out[0],out[1],out[2]);}}return 0;}
