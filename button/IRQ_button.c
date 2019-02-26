#include "button.h"
#include "lpc17xx.h"

extern int down;

void EINT0_IRQHandler (void)	  	/* INT0 */
{		
	NVIC_DisableIRQ(EINT0_IRQn);		
	LPC_PINCON->PINSEL4    &= ~(1 << 20);     
	
	LPC_SC->EXTINT &= (1 << 0);     
}

void EINT1_IRQHandler (void)	  	/* KEY1 */
{
	NVIC_DisableIRQ(EINT1_IRQn);		
	LPC_PINCON->PINSEL4    &= ~(1 << 22);    

	LPC_SC->EXTINT &= (1 << 1);     
}

void EINT2_IRQHandler (void)	  	/* KEY2	*/
{
	NVIC_DisableIRQ(EINT2_IRQn);		
	LPC_PINCON->PINSEL4    &= ~(1 << 24); 
	
  LPC_SC->EXTINT &= (1 << 2);  
}

void EINT3_IRQHandler (void)	  	/* TP_INT	*/
{
	NVIC_DisableIRQ(EINT3_IRQn);		
	LPC_PINCON->PINSEL4    &= ~(1 << 26); 
	
  LPC_SC->EXTINT &= (1 << 3);  
}


