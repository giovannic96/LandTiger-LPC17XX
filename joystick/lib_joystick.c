/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Atomic joystick init functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "joystick.h"

/*----------------------------------------------------------------------------
  Function that initializes joysticks and switch them off
 *----------------------------------------------------------------------------*/

void joystick_init(void) {

  LPC_PINCON->PINSEL3 &= ~(3<<18);	// SELECT PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR   &= ~(1<<25);	//P1.25 Input (joysticks on PORT1 defined as Input)
  LPC_PINCON->PINSEL3 &= ~(3<<20);	// DOWN
	LPC_GPIO1->FIODIR   &= ~(1<<26);	
	LPC_PINCON->PINSEL3 &= ~(3<<22);	// LEFT 
	LPC_GPIO1->FIODIR   &= ~(1<<27);	
	LPC_PINCON->PINSEL3 &= ~(3<<24);	// RIGHT 
	LPC_GPIO1->FIODIR   &= ~(1<<28);	
	LPC_PINCON->PINSEL3 &= ~(3<<26);	// UP
	LPC_GPIO1->FIODIR   &= ~(1<<29);	
}
