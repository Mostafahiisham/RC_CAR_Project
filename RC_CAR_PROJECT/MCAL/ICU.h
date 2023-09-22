/*
 * ICU.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mostafa Hisham
 *      Layer : ICU - PROTOTYPE
 */

#ifndef ICU_H_
#define ICU_H_

typedef enum{
	ICU_EDGE_FALLING,
	ICU_EDGE_RISING
}ICU_EdgeType;
void ICU_Init();
void ICU_SetEdge(ICU_EdgeType edge);
void ICU_DisableNotification(void);
void ICU_EnableNotification(void);
void ICU_SetCallBack(void (*ICU_PTR)(u16 value));

#endif /* ICU_H_ */
