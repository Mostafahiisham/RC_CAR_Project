/*
 * main.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mostafa Hisham
 *      Layer : APP
 *      SWC   : APP - PROTOTYPE
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

void CAR_CONTROL(u8 data);
void MOVE_Forward(void);
void MOVE_Backward(void);
void MOVE_Right(void);
void MOVE_Left(void);
void CAR_Brake(void);
void WAIT_Lights(void);
void WAIT_LightsTurnOff(void);
void RIGHT_Sign(void);
void LEFT_Sign(void);
/*CAR SPEED FUNCTIONS*/
void SPEED_Increase(void);
void SPEED_Decrease(void);
/* OBSTACLE DETECTION */
void OBSTACLE_DETECT(void);
/*CAR LIGHTS FUNCTION */
void CAR_LIGHT(void);

#endif /* APP_MAIN_H_ */
