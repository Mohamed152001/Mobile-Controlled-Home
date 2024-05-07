/*
 * CLCD_interface.h
 *
 *  Created on: 29 Nov 2023
 *      Author: Mohamed Harby
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

///////////////////////////////////////////////////////
/* LCD ROWS x COLUMNS  16x2 */
#define CLCD_ROW_1       0
#define CLCD_ROW_2       1

#define CLCD_Col_1       1
#define CLCD_Col_2       2
#define CLCD_Col_3       3
#define CLCD_Col_4       4
#define CLCD_Col_5       5
#define CLCD_Col_6       6
#define CLCD_Col_7       7
#define CLCD_Col_8       8
#define CLCD_Col_9       9
#define CLCD_Col_10      10
#define CLCD_Col_11      11
#define CLCD_Col_12      12
#define CLCD_Col_13      13
#define CLCD_Col_14      14
#define CLCD_Col_15      15
#define CLCD_Col_16      16

#define Clear_display   0x01

//////////////////////////////////////////////////////
void CLCD_voidInit        (                void           );

void CLCD_voidClear       (               void            );

void CLCD_voidSendData    (         u8 Copy_u8Data        );

void CLCD_voidSendCommand (u8 Copy_u8Command              );

void CLCD_voidSetPosition (u8 Copy_u8Row, u8 Copy_u8Column);

void CLCD_voidSendString  ( u8 *Copy_Pu8String            );

void CLCD_voidSendNumber(u64 Copy_u64Number);
#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
