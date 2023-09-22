/*
 * Macros.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Mostafa Hisham
 *      Layer : LIB
 */

#ifndef INCLUDE_MACROS_H_
#define INCLUDE_MACROS_H_

#define SET_BIT(NUMBER,BIT)    NUMBER |=(1<<BIT)
#define CLR_BIT(NUMBER,BIT)    NUMBER &= ~(1<<BIT)
#define GET_BIT(NUMBER,BIT)    ((NUMBER>>BIT) & 1)
#define TOGGLE_BIT(NUMBER,BIT) NUMBER ^=(1<<BIT)
#define SET_BYTE(NUMBER,VALUE)    (NUMBER = VALUE)
#endif /* INCLUDE_MACROS_H_ */
