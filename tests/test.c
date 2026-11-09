#include "pc_eeprom_max_wear_slot_u32.h"
#include <assert.h>
#include <stdint.h>
int main(void){uint32_t a[]={2u,UINT32_MAX,UINT32_C(0x80000000),UINT32_MAX};size_t i=99u;assert(pc_eeprom_max_wear_slot_u32(a,4u,&i)&&i==1u);assert(!pc_eeprom_max_wear_slot_u32(a,0u,&i)&&i==1u);assert(!pc_eeprom_max_wear_slot_u32(NULL,4u,&i)&&i==1u);assert(!pc_eeprom_max_wear_slot_u32(a,4u,NULL));return 0;}
