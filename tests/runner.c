#include <stdint.h>
#include <stdio.h>
#include "pc_metric_prefix_scale_i32.h"
int main(void){long long v;int e;while(scanf("%lld %d",&v,&e)==2){int32_t o=123456;int ok=pc_metric_prefix_scale_i32((int32_t)v,(int8_t)e,&o);printf("%d %ld\n",ok,(long)o);}return 0;}
