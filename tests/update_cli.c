#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "pc_cluster_update_center_i32.h"
int main(void){int32_t sample,center;int64_t sum;uint32_t count;
 while(scanf("%" SCNd32 " %" SCNd64 " %" SCNu32,&sample,&sum,&count)==3){
  if(!pc_cluster_update_center_i32(sample,&sum,&count,&center))return 2;
  printf("%" PRId64 " %" PRIu32 " %" PRId32 "\n",sum,count,center);}
 return 0;}