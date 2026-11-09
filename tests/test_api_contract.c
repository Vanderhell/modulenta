#include <stdint.h>
#include <limits.h>
#include "pc_cluster_update_center_i32.h"
int main(void){int64_t sum=0;uint32_t count=0;int32_t center=77;union{int64_t sum;uint32_t count;}alias;
 if(!pc_cluster_update_center_i32(1,&sum,&count,&center)||sum!=1||count!=1u||center!=1)return 1;
 sum=1;count=1u;if(!pc_cluster_update_center_i32(2,&sum,&count,&center)||center!=2)return 2;
 sum=-1;count=1u;if(!pc_cluster_update_center_i32(-2,&sum,&count,&center)||center!=-2)return 3;
 sum=0;count=1u;if(!pc_cluster_update_center_i32(1,&sum,&count,&center)||center!=0)return 4;
 sum=0;count=0u;center=77;if(pc_cluster_update_center_i32(1,&sum,&count,NULL)||sum!=0||count!=0u||center!=77)return 5;
 if(pc_cluster_update_center_i32(1,NULL,&count,&center)||pc_cluster_update_center_i32(1,&sum,NULL,&center))return 6;
 sum=7;count=0u;center=77;if(pc_cluster_update_center_i32(1,&sum,&count,&center)||sum!=7||count!=0u||center!=77)return 7;
 sum=0;count=UINT32_MAX;center=77;if(pc_cluster_update_center_i32(1,&sum,&count,&center)||sum!=0||count!=UINT32_MAX||center!=77)return 8;
 sum=INT64_MAX;count=1u;center=77;if(pc_cluster_update_center_i32(1,&sum,&count,&center)||sum!=INT64_MAX||count!=1u||center!=77)return 9;
 sum=INT64_MAX;count=1u;center=77;if(pc_cluster_update_center_i32(0,&sum,&count,&center)||sum!=INT64_MAX||count!=1u||center!=77)return 10;
 alias.sum=0;if(pc_cluster_update_center_i32(1,&alias.sum,&alias.count,&center))return 11;
 return 0;}
