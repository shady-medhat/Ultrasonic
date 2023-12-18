/*
 * Ultrasonic_sensor.c
 *
 *  Created on: Oct 18, 2023
 *      Author: shady
 */
#include "icu.h"
#include "gpio.h"
#include "Ultrasonic_sensor.h"
#include <util/delay.h> /* For the delay functions */


uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
 void Ultrasonic_init(void){

	 /* Create configuration structure for ICU driver */
		ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	 /* Initialize ICU driver */
		ICU_init(&ICU_Configurations);
	 /* Set the Call back function pointer in the ICU driver */
		ICU_setCallBack(Ultrasonic_edgeProcessing);
		/*set the direction of the trigger pin as output*/
		GPIO_setupPinDirection(Trigger_port,Trigger_pin,PIN_OUTPUT);
 }
void Ultrasonic_Trigger(void){
	GPIO_writePin(Trigger_port,Trigger_pin,LOGIC_HIGH); /*write one on trigger pin*/
	_delay_us(10);/*then wait 10 microseconds to generate 8 signals successfully*/
	GPIO_writePin(Trigger_port,Trigger_pin,LOGIC_LOW);/*clear trigger pin*/


}

uint16 Ultrasonic_readDistance(void){

Ultrasonic_Trigger();/*call trigger function*/
while( g_edgeCount = 0) {};
return  (uint16)(( float64) g_timeHigh / 58)+1;  /*make calculations using time calculated by Icu to get distance*/
}

void Ultrasonic_edgeProcessing(void){

		g_edgeCount++;
		if(g_edgeCount == 1)
		{
			/*
			 * Clear the timer counter register to start measurements from the
			 * first detected rising edge
			 */
			ICU_clearTimerValue();
			/* Detect falling edge */
			ICU_setEdgeDetectionType(FALLING);
		}
		else if(g_edgeCount == 2)
		{
			/* Store the High time value */
			g_timeHigh = ICU_getInputCaptureValue();
			/* Clear the timer counter register to start measurements again */

			ICU_clearTimerValue();
			/* Detect rising edge */
			ICU_setEdgeDetectionType(RAISING);
			g_edgeCount = 0;
		}

}
