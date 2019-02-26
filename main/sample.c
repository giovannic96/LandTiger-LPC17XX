#include <stdio.h>
#include "LPC17xx.H"                    
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "adc/adc.h"

int main (void) {
  	
	SystemInit();  												
  LED_init();                           
  BUTTON_init();												
	joystick_init();											
	init_RIT(0x004C4B40); // 50ms						
	ADC_init();
	init_timer(2, 0x09BF3188);	/* 25Mhz * 6.541s = 163525000 -> 0x09BF3188 */
	
	LPC_SC->PCON |= 0x1; // power-down mode
	LPC_SC->PCON &= ~(0x2);						
	LPC_SC->PCONP |= (1<<22); // Enable power for TIMER 2
	LPC_SC->PCONP |= (1<<23); // Enable power for TIMER 3

	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
  while (1) {            
		__ASM("wfi");
  }

}
