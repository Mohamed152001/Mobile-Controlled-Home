/*
 * DIO_program.c
 *
 *
 * Created on: Nov 11, 2023
 * Author : Mohamed Harby
 *
 *
 */

/*	Includes from Service Layer */
#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"


/* DIO header files */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	case DIO_OUTPUT:
		switch(Copy_u8Port)
		{
		case DIO_PORTA :
			SET_BIT(DDRA_REG , Copy_u8Pin );
			break;
		case DIO_PORTB :
			SET_BIT(DDRB_REG , Copy_u8Pin );
			break;
		case DIO_PORTC :
			SET_BIT(DDRC_REG , Copy_u8Pin );
			break;
		case DIO_PORTD :
			SET_BIT(DDRD_REG , Copy_u8Pin );
			break;
		default:
			break;
		}
		break;

		case DIO_INPUT :
			switch(Copy_u8Port)
			{
			case DIO_PORTA :
				CLR_BIT(DDRA_REG , Copy_u8Pin );
				break;
			case DIO_PORTB :
				CLR_BIT(DDRB_REG , Copy_u8Pin );
				break;
			case DIO_PORTC :
				CLR_BIT(DDRC_REG , Copy_u8Pin );
				break;
			case DIO_PORTD :
				CLR_BIT(DDRD_REG , Copy_u8Pin );
				break;
			default:
				break;
			}
			break;

			default:
				break ;
	}
}

void DIO_voidSetPinValue	(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Value)
	{
	case DIO_HIGH :
		switch(Copy_u8Port)
		{
		case DIO_PORTA :
			SET_BIT(PORTA_REG , Copy_u8Pin );
			break ;
		case DIO_PORTB :
			SET_BIT(PORTB_REG , Copy_u8Pin );
			break ;
		case DIO_PORTC :
			SET_BIT(PORTC_REG , Copy_u8Pin );
			break ;
		case DIO_PORTD :
			SET_BIT(PORTD_REG , Copy_u8Pin );
			break ;

		default :
			break;
		}
		break;

		case DIO_LOW :
			switch(Copy_u8Port)
			{
			case DIO_PORTA :
				CLR_BIT(PORTA_REG , Copy_u8Pin );
				break ;
			case DIO_PORTB :
				CLR_BIT(PORTB_REG , Copy_u8Pin );
				break ;
			case DIO_PORTC :
				CLR_BIT(PORTC_REG , Copy_u8Pin );
				break ;
			case DIO_PORTD :
				CLR_BIT(PORTD_REG , Copy_u8Pin );
				break ;

			default :
				break;
			}
			break;

			default :
				break ;
	}
}

u8  DIO_u8GetPinValue		(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ReturnedValue ;
	switch(Copy_u8Port )
	{
	case DIO_PORTA :
		Local_u8ReturnedValue =	GET_BIT(PINA_REG ,Copy_u8Pin) ;
		break;
	case DIO_PORTB:
		Local_u8ReturnedValue =	GET_BIT(PINB_REG ,Copy_u8Pin) ;
		break ;
	case DIO_PORTC :
		Local_u8ReturnedValue =	GET_BIT(PINC_REG ,Copy_u8Pin) ;
		break;
	case DIO_PORTD :
		Local_u8ReturnedValue =	GET_BIT(PIND_REG ,Copy_u8Pin) ;
		break;

	default :
		break;
	}

	return Local_u8ReturnedValue ;
}

void DIO_voidSetPortDirection	(u8 Copy_u8Port ,u8 Copy_u8Direction  )
{
	switch(Copy_u8Direction)
	{
	case DIO_OUTPUT :
		switch(Copy_u8Port)
		{
		case DIO_PORTA :
			DDRA_REG = 0xff ;
			break;

		case DIO_PORTB :
			DDRB_REG = 0xff ;
			break;

		case DIO_PORTC :
			DDRC_REG = 0xff ;
			break;

		case DIO_PORTD :
			DDRD_REG = 0xff ;
			break;

		default:
			break;

		}
		break;

		case DIO_INPUT:
			switch(Copy_u8Port)
			{
			case DIO_PORTA :
				DDRA_REG = 0x00 ;
				break;

			case DIO_PORTB :
				DDRB_REG = 0x00 ;
				break;

			case DIO_PORTC :
				DDRC_REG = 0x00 ;
				break;

			case DIO_PORTD :
				DDRD_REG = 0x00 ;
				break;

			default:
				break;

			}
			break;

			default:
				break;

	}

}

void DIO_voidSetPortValue		(u8 Copy_u8Port ,u8 Copy_u8Value  )
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA :
		PORTA_REG = Copy_u8Value ;
		break;
	case DIO_PORTB :
		PORTB_REG = Copy_u8Value ;
		break;
	case DIO_PORTC :
		PORTC_REG = Copy_u8Value ;
		break;
	case DIO_PORTD :
		PORTD_REG = Copy_u8Value ;
		break;
	default:
		break;
	}
}

u8 DIO_u8GetPortValue			(u8 Copy_u8Port)
{
	u8 Local_u8ReturnedValue ;

	switch(Copy_u8Port)
	{
	case DIO_PORTA :
			Local_u8ReturnedValue = PINA_REG ;
			break;
		case DIO_PORTB :
			Local_u8ReturnedValue = PINB_REG ;
			break;
		case DIO_PORTC :
			Local_u8ReturnedValue = PINC_REG ;
			break;
		case DIO_PORTD :
			Local_u8ReturnedValue = PIND_REG ;
			break;
		default:
			break;
	}

	return Local_u8ReturnedValue ;
}
