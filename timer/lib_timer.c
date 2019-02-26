#include "lpc17xx.h"
#include "timer.h"

void enable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 )
  {
	LPC_TIM0->TCR = 1;
  }
  else if (timer_num == 1)
  {
	LPC_TIM1->TCR = 1;
  }
	else if (timer_num == 2)
  {
	LPC_TIM2->TCR = 1;
  }
	else if (timer_num == 3)
  {
	LPC_TIM3->TCR = 1;
  }
  return;
}

void disable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 )
  {
	LPC_TIM0->TCR = 0;
  }
  else if (timer_num == 1)
  {
	LPC_TIM1->TCR = 0;
  }
	else if (timer_num == 2)
  {
	LPC_TIM2->TCR = 0;
  }
	else if (timer_num == 3)
  {
	LPC_TIM3->TCR = 0;
  }
  return;
}

void reset_timer( uint8_t timer_num )
{
  uint32_t regVal;

  if ( timer_num == 0 )
  {
	regVal = LPC_TIM0->TCR;
	regVal |= 0x02;
	LPC_TIM0->TCR = regVal;
  }
  else if (timer_num == 1)
  {
	regVal = LPC_TIM1->TCR;
	regVal |= 0x02;
	LPC_TIM1->TCR = regVal;
  }
	else if (timer_num == 2)
  {
	regVal = LPC_TIM2->TCR;
	regVal |= 0x02;
	LPC_TIM2->TCR = regVal;
  }
	else if (timer_num == 3)
  {
	regVal = LPC_TIM3->TCR;
	regVal |= 0x02;
	LPC_TIM3->TCR = regVal;
  }
  return;
}

uint32_t init_timer ( uint8_t timer_num, uint32_t TimerInterval )
{
  if ( timer_num == 0 )
  {
	LPC_TIM0->MR0 = TimerInterval;
	LPC_TIM0->MCR = 3;

	NVIC_EnableIRQ(TIMER0_IRQn);
	return (1);
  }
  else if ( timer_num == 1 )
  {
	LPC_TIM1->MR0 = TimerInterval;
	LPC_TIM1->MCR = 3;				

	NVIC_EnableIRQ(TIMER1_IRQn);
	return (1);
  }
	else if ( timer_num == 2 )
  {
	LPC_TIM2->MR0 = TimerInterval;
	LPC_TIM2->MCR = 3;				

	NVIC_EnableIRQ(TIMER2_IRQn);
	return (1);
  }
	else if ( timer_num == 3 )
  {
	LPC_TIM3->MR0 = TimerInterval;
	LPC_TIM3->MCR = 3;				

	NVIC_EnableIRQ(TIMER3_IRQn);
	return (1);
  }
  return (0);
}
