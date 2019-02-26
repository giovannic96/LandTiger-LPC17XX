#include "button.h"
#include "lpc17xx.h"

void BUTTON_init(void) {

  LPC_PINCON->PINSEL4    |= (1 << 20);  // INT0 /* External interrupt 0 pin selection */
  LPC_GPIO2->FIODIR      &= ~(1 << 10);            /* PORT2.10 defined as input          */

  LPC_PINCON->PINSEL4    |= (1 << 22);  // KEY1
  LPC_GPIO2->FIODIR      &= ~(1 << 11);    
  
  LPC_PINCON->PINSEL4    |= (1 << 24);  // KEY2    
  LPC_GPIO2->FIODIR      &= ~(1 << 12);    

	LPC_PINCON->PINSEL4    |= (1 << 26);  // TP_INT
  LPC_GPIO2->FIODIR      &= ~(1 << 13);    
	
  LPC_SC->EXTMODE = 0x7;

	NVIC_EnableIRQ(EINT3_IRQn);              /* enable irq in nvic                 */
	NVIC_SetPriority(EINT3_IRQn, 3);				 /* priority, the lower the better     */
  NVIC_EnableIRQ(EINT2_IRQn);              
	NVIC_SetPriority(EINT2_IRQn, 1);				 
  NVIC_EnableIRQ(EINT1_IRQn);              
	NVIC_SetPriority(EINT1_IRQn, 2);				 
  NVIC_EnableIRQ(EINT0_IRQn);              
	NVIC_SetPriority(EINT0_IRQn, 3);				 
}
