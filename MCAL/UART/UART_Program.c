/*
 * UART_Program.c
 *
 *  Created on: May 5, 2024
 *      Author: Mohamed Harby
 *
 */

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"



#define F_CPU   8000000UL

#include <util/delay.h>

extern void UART_voidInit (void)
{

	/*  Store the low byte of the UBBR*/
	UBRRL =  (u8) MyUBRR;

	/*  Store the High byte of the UBBR*/
	UBRRH = (u8)((MyUBRR)>>8);

	/* Configuration of UCSRnA Register  */
	UCSRnA= ( (U2X<<1) | (MPCM<<0) );

	/* Enable Transmit bit(3) and Receive bit(4) in UCSRnC Register */
	UCSRnB = ( (RXEN<<4) | (TXEN<<3) | (UCSZ2<<2) );

	/* Configure UCRnC Register to make 8-bit data & 1 stop bit & no parity  Asynchronous Mode*/
	UCSRnC = ((URSEL << 7) | (UMSEL << 6) | (UPM1 << 5) | (UPM0 << 4)
			| (USBS << 3) | (UCSZ1 << 2) | (UCSZ0 << 1));

	//set_bit(SREG,7);
}

extern void UART_TransmitData (u8 UART_DataToBeSent)
{


	 /* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
	while(GET_BIT(UCSRnA,5)==0);
	//while( ! (UCSRnA & (1<<6)) );

	/* So put data in the UDR Register */
	UDR=UART_DataToBeSent;
	//clear the transmit interrupt flag
	SET_BIT(UCSRnA,6);
}

extern u8 UART_RecieveData(void)
{
	//while ( ! (UCSRnA & (1<<7)) );
	while(GET_BIT(UCSRnA,7)==0);
	return UDR;

}

//====================================================================================================
extern void UART_voidPrintf(u8 Copy_u8PrintedData[])
{

	u8 iterator=0;

	for (iterator=0;Copy_u8PrintedData[iterator]!='\0';iterator++)
	{
		UART_TransmitData(Copy_u8PrintedData[ iterator]);

	}

	UART_TransmitData('\0');

}

void UART_RECEIVE_String(u8 *array, u8 maxLength)
	{
	    u8 i = 0;
	    while (i < maxLength )
	    {
	        array[i] = UART_RecieveData();
	        i++;
	    }
	    array[i] = '\0'; // null-terminate the string
	}


