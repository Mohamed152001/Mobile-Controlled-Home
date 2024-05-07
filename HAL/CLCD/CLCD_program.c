/*
 * CLCD_program.c
 *
 *  Created on: 29 Nov 2023
 *      Author: Mohamed Harby
 */
#include <util/delay.h>

/* includes from service */
#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"

///////////////////////////////////////////

/* includes from MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"

//////////////////////////////////////////////
/* 16x2 Character LCD*/
#include "../CLCD/CLCD_config.h"
#include "../CLCD/CLCD_interface.h"
#include "../CLCD/CLCD_private.h"

/////////////////////////////////////////////
void CLCD_voidInit (void)
 {
		/* Data Port -->Output*/
		DIO_voidSetPortDirection(CLCD_DATA_PORT , DIO_OUTPUT);

		// RS, RW, EN-->OUTPUT
		DIO_voidSetPinDirection(CLCD_CTRL_PORT, CLCD_RS, DIO_OUTPUT);
		DIO_voidSetPinDirection(CLCD_CTRL_PORT, CLCD_RW, DIO_OUTPUT);
		DIO_voidSetPinDirection(CLCD_CTRL_PORT, CLCD_EN, DIO_OUTPUT);

		/* Initialisation sequence*/
		_delay_ms(50);
		/*Function Set*/
		CLCD_voidSendCommand (0b00111100);  // data length 8 bit--> 1 , display lines --> 1, Font 5x11 dots -->1
		_delay_ms(1);
		/* Display ON/OFF control*/
		CLCD_voidSendCommand (0b00001100);  //  ON display --> 1 , Cursor OFF--> 0, Cursor blinking OFF -->0
		_delay_ms(1);
		/* Display Clear*/
		CLCD_voidSendCommand (0b00000001);
		_delay_ms(2);
		/*Entry Mode Set */
		CLCD_voidSendCommand (0b00000110);
 }


///////////////////////////////////////////////
void CLCD_voidClear       (               void            )
{

	CLCD_voidSendCommand(0x01);

}
///////////////////////////////////////////////

void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	 /*RS--> LOW TO SEND COMMAND */
	 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RS, DIO_LOW);

	 /*RW--> LOW TO WRITE */
	 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RW, DIO_LOW);

	 /* TO SEND COMMAND TO DATA PORT */
	 DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8Command);

	 /* ENABLE SEQUENCE */
	 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN, DIO_HIGH);
	 _delay_ms(1);
	 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN, DIO_LOW);
	 _delay_ms(1);

}
//////////////////////////////////////////////
 void CLCD_voidSendData (u8 Copy_u8Data)
{
	 /*RS--> HIGH TO SEND DATA */
		 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RS, DIO_HIGH);

		 /*RW--> LOW TO WRITE */
		 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_RW, DIO_LOW);

		 /* TO SEND DATA TO DATA PORT */
		 DIO_voidSetPortValue(CLCD_DATA_PORT , Copy_u8Data);

		 /* ENABLE SEQUENCE */
		 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN, DIO_HIGH);
		 _delay_ms(1);
		 DIO_voidSetPinValue(CLCD_CTRL_PORT, CLCD_EN, DIO_LOW);
		 _delay_ms(1);

}
//////////////////////////////////////////////
 void CLCD_voidSetPosition (u8 Copy_u8Row, u8 Copy_u8Column)
 {
	 switch (Copy_u8Row)
	 {
	 case CLCD_ROW_1:
		 CLCD_voidSendCommand (0x80 + Copy_u8Column -1 ); // to move between columns

		 break;
	 case CLCD_ROW_2:
		 CLCD_voidSendCommand (0x80 + 64 + Copy_u8Column -1 );
		 break;

	 default:
		 break;
	 }
 }
/////////////////////////////////////////////////////////////////////
 void CLCD_voidSendString  ( u8 * Copy_Pu8String  )
 {
	 u8 Local_u8Iterator =0 ;

	 while(Copy_Pu8String[Local_u8Iterator] != '\0'   )
	 {
		 CLCD_voidSendData(Copy_Pu8String [Local_u8Iterator]);
		 Local_u8Iterator ++ ;
	 }
 }

//////////////////////////////////////////////////////////////////////
 void CLCD_voidSendNumber(u64 Copy_u64Number)
 {

	 if (Copy_u64Number ==0)
	 {
		 CLCD_voidSendData ('0');
	 }
	 else
	 {
		 u64 Local_u64Reversed =1;

		 while (Copy_u64Number !=0)
		 {
		     Local_u64Reversed = (Local_u64Reversed *10) + (Copy_u64Number % 10);
		     Copy_u64Number = Copy_u64Number/10;
		 }

		 while(Local_u64Reversed !=1)
		 {
		 	 CLCD_voidSendData ((Local_u64Reversed % 10) +'0');
		 	 Local_u64Reversed /=10;
		 }
	 }

 }
