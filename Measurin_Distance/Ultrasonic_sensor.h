/*
 * Ultrasonic_sensor.h
 *
 *  Created on: Oct 18, 2023
 *      Author: shady
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Trigger_port PORTB_ID
#define Trigger_pin PIN5_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*initializing the ultra_sonic sensor */
void Ultrasonic_init(void);
 /*sending the trigger signal which is 10 microseconds  to make 8 signals */
void Ultrasonic_Trigger(void);
/*starting the calculations and the sending the read distance*/
uint16 Ultrasonic_readDistance(void);
/*call back function responsible of changing the edge of the Icu */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_SENSOR_H_ */
