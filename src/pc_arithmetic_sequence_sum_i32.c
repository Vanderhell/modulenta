#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include "pc_arithmetic_sequence_sum_i32.h"
bool pc_arithmetic_sequence_sum_i32(int32_t start,int32_t step,uint32_t count,int64_t*out){int64_t last,pair,factor,result;if(!out)return false;if(count==0){*out=0;return true;}last=(int64_t)start+(int64_t)step*(int64_t)(count-1u);if(last<INT32_MIN||last>INT32_MAX)return false;pair=(int64_t)start+last;factor=(int64_t)count;if((count&1u)==0u)factor/=2;else pair/=2;result=pair*factor;*out=result;return true;}