#include "main.h"

#define DWT_GetCycles()    DWT->CYCCNT

uint8_t Delay_ms_uwTick(uint16_t time, uint32_t* get_tick);

void Delay_ms_uwTick_cycle(uint16_t time, uint32_t* get_tick);

void DWT_Init(void) ;

void Delay_us_cpu(uint32_t us);

void Delay_ms_cpu(uint32_t ms);

uint8_t Timer_Check_us(uint32_t *last_cycles, uint32_t interval_us);


