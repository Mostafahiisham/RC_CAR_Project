/*
 * UltraSonic.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 *      SWC   : ULTRASONIC SENSOR - PROTOTYPE
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void ULTRASONIC_Init(void);
u8 ULTRASONIC_ReadDistance(void);

#endif /* ULTRASONIC_H_ */
