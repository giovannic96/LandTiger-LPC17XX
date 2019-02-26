#include "lpc17xx.h"
#include "timer.h"

int e1, e2;
extern int divisible(int, int);

void TIMER0_IRQHandler (void)
{
	e2 = divisible(e1, e2); // call ASM_funct

  LPC_TIM0->IR = 1;			
  return;
}

void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			
  return;
}

void TIMER2_IRQHandler (void)
{
  LPC_TIM2->IR = 1;			
  return;
}

void TIMER3_IRQHandler (void)
{
  LPC_TIM3->IR = 1;			
  return;
}
