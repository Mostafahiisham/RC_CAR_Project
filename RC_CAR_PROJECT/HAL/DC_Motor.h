/*
 * DC_Motor.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Mostafa Hisham
 *      Layer : HAL
 *      SWC   : DC-MOTOR - PROTOTYPE
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

typedef enum{
	MOTOR1,
	MOTOR2,
	MOTOR3,
	MOTOR4
}Motor_Number;

void DCMOTOR_RotateCounterClockWise(Motor_Number motor);
void DCMOTOR_RotateClockwise(Motor_Number motor);
void DCMOTOR_Stop(Motor_Number motor);


#endif /* DC_MOTOR_H_ */
