#include "main.h"

// ��ȡ��ǰCPU��������ֱ�Ӷ�ȡ�Ĵ�����
#define DWT_GetCycles()    DWT->CYCCNT

uint8_t delay_ms(uint16_t time, uint32_t* get_tick);

void DWT_Init(void) ;

void Delay_us(uint32_t us);

uint8_t Timer_Check_us(uint32_t *last_cycles, uint32_t interval_us);


