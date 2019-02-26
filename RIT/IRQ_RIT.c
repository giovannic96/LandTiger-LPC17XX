/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"

int down=0;

void RIT_IRQHandler (void)
{					
	// NB: a static variable inside a function keeps its value between invocations.
	static int select=0; 
	static int ticks=0;
	
	/* BUTTON MANAGEMENT */
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){	// INT0 
			down++;				
			switch(down){
				case 2:
					// your action here
					break;
				default:
					break;
			}
		}
		else {	// button released 
			down=0;			
			NVIC_EnableIRQ(EINT0_IRQn);							 
			LPC_PINCON->PINSEL4 |= (1 << 20);  
		}
	}
	
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){	// KEY1 
			down++;				
			switch(down){
				case 2:
					// your action here
					break;
				default:
					break;
			}
		}
		else {	// button released 
			down=0;			
			NVIC_EnableIRQ(EINT1_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 22);  
		}
	}
	
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<12)) == 0){	// KEY2
			down++;				
			switch(down){
				case 2:
					// your action here
					break;
				default:
					break;
			}
		}
		else {	// button released 
			down=0;			
			NVIC_EnableIRQ(EINT2_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 24);  
		}
	}
	
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<13)) == 0){	// TP_INT
			down++;				
			switch(down){
				case 2:
					// your action here
					break;
				default:
					break;
			}
		}
		else {	// button released 
			down=0;			
			NVIC_EnableIRQ(EINT3_IRQn);							 
			LPC_PINCON->PINSEL4    |= (1 << 26);  
		}
	}
	
	/* JOYSTICK MANAGEMENT */
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	// JOY_SEL pressed 
		select++;
		switch(select){
			case 1:
				// your action here
				break;
			default:
				break;
		}
	}
	else{
		select=0;
	}
		
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	// JOY_DOWN pressed 
		select++;
		switch(select){
			case 1:
				// your action here
				break;
			default:
				break;
		}
	}
	else{
		select=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	// JOY_LEFT pressed 
		select++;
		switch(select){
			case 1:
				// your action here
				break;
			default:
				break;
		}
	}
	else{
		select=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	// JOY_RIGHT pressed 
		select++;
		switch(select){
			case 1:
				// your action here
				break;
			default:
				break;
		}
	}
	else{
		select=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	// JOY_UP pressed 
		select++;
		switch(select){
			case 1:
				// your action here
				break;
			default:
				break;
		}
	}
	else{
		select=0;
	}
	
	/* ADC MANAGEMENT */
	ADC_start_conversion();		
			
  LPC_RIT->RICTRL |= 0x1;	
}
