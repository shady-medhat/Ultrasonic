/*
 * App.c
 *
 *  Created on: Oct 18, 2023
 *      Author: shady
 */


#include "lcd.h"/*use Lcd driver to display on it*/
#include <avr/io.h>/*enable I bit  register */
#include "Ultrasonic_sensor.h"/*use driver to calculate distance*/
#include "common_macros.h"/*use set bit function*/
uint16 Distance=0;/*global variable to hold the distance value*/
int main (void){
	LCD_init();/*initialize LCD*/
	Ultrasonic_init();/*initialize ultrasonic sensor driver*/
	SET_BIT(SREG,7);	/* Enable global interrupt */
	LCD_displayStringRowColumn(0, 1, "Distance=    cm"); /*display distance word*/
	while(1){
	Distance=	Ultrasonic_readDistance( ); /*put the recieved value from read distance function in distance variable*/
	LCD_moveCursor(0,11);
	if(Distance >= 100)
		{
		 LCD_intgerToString(Distance);/*display distance on LCD*/
		}
		else
		{
		 LCD_intgerToString(Distance);
		/* In case the digital value is two or one digits print space in the next digit place */
		 LCD_displayCharacter(' ');
		}
	}

}
