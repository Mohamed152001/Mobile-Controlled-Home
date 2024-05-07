/*
 * main.c
 *
 *  Created on: May 5, 2024
 *      Author: Mohamed Harby
 *      App   : Mobile Controlled Home
 */

#include <util/delay.h>
#include <string.h>
#include "SERVICE/BIT_MATH.h"
#include "SERVICE/STD_TYPES.h"
#define F_CPU 8000000UL
#include "MCAL/UART/UART_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "MCAL/DIO/DIO_interface.h"

void Enterd_voidusername(u8 *arry );
void Enterd_voiduserpass(u8 *arry );

void Check_voiduser(u8 Var );

void choise_voidEnterd(void);


u8 userName_Enter[7];
u8 userPass_Enter[5];


/*                        Database                 */
 //Users Name Stored
u8 Stored_Users[10][7] = {"user01", "user02", "user03", "user04","user05", "user06", "user07", "user08","user09", "user10"};
//Users Password Stored
u8 Stored_Pass[10][5] = {"1111", "2222", "3333", "4444","5555", "6666", "7777", "8888","9999", "1010"};


u8 user_num  , user_pass , checked_num , choise , try_num = 0 , exit_num = 0;

int main()
{

	/*
	 * LED           PORTA , PIN0
	 * MOTOR         PORTA , PIN7
	 * BUZZER        PORTA , PIN6
	 *
	 */
    // Initialize ports as output
    DIO_voidSetPortDirection(DIO_PORTA, DIO_OUTPUT);
    DIO_voidSetPortDirection(DIO_PORTB, DIO_OUTPUT);



    // Initialize UART and CLCD
    UART_voidInit();
    CLCD_voidInit();






    while (1)
    {


    	if (try_num != 3)
    	{
        	UART_voidPrintf((u8* )"Welcome ");
        	UART_TransmitData('\r');
        	Enterd_voidusername(userName_Enter);
        	Enterd_voiduserpass(userPass_Enter);

        	Check_voiduser(user_num );


    	}
    	else
    	{
    		UART_voidPrintf((u8*) "You Are A Theif !!");
    		UART_TransmitData('\r');
    		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN6 , DIO_HIGH);
    		_delay_ms(5000);
    		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN6 , DIO_LOW);
    		try_num = 0;

    	}

    }

    return 0; // Add return statement
}


void Enterd_voidusername(u8 *arry )
{
    // For Enter User Name
	UART_voidPrintf((u8 *)"Enter User Name : ");
	UART_TransmitData('\r');

	UART_RECEIVE_String(arry, 6);
	UART_TransmitData('\r');


			//  CLCD_voidSendString(userName_Enter);

		for (u8 i = 0; i < 10; i++)
			{
				if (strcmp((char*)arry, (char*)Stored_Users[i]) == 0)
					{
						user_num = i;
							break;
					}
				user_num = 11;

			}
}


void Enterd_voiduserpass(u8 *arry)
{

              // For Enter User Password
        UART_voidPrintf((u8 *)"Enter User Password : ");
        UART_TransmitData('\r');

        UART_RECEIVE_String(arry, 4);
        UART_TransmitData('\r');

        for (u8 i = 0; i < 10; i++)
        {
            if (strcmp((char*)arry, (char*)Stored_Pass[i]) == 0) // Cast to char* for strcmp
            {
                user_pass = i;
                break;
            }
            user_pass = 11;
        }



}

void Check_voiduser(u8 Var )
{
	switch (Var)
	{
	case 0 :
		if (user_pass == 0)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 1:
		if (user_pass == 1)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 2:
		if (user_pass == 2)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 3:
		if (user_pass == 3)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 4:
		if (user_pass == 4)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 5:
		if (user_pass == 5)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 6:
		if (user_pass == 6)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 7:
		if (user_pass == 7)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	case 8:
		if (user_pass == 8)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			try_num++;
		}
		break;
	case 9:
		if (user_pass == 9)
		{
			choise_voidEnterd();
			try_num = 0;
		}
		else
		{
			UART_voidPrintf((u8 *)"Wrong Password !! ");
			UART_TransmitData('\r');
			try_num++;
		}
		break;
	default:
		UART_voidPrintf((u8 *)"Wrong Username !! ");
		UART_TransmitData('\r');
		try_num++;
		break;

   }
}


void choise_voidEnterd(void)
{

	while (exit_num != 1)
	{
		UART_voidPrintf((u8*)"Your Choise is : ");
		UART_TransmitData('\r');
		UART_voidPrintf((u8*)"L -> To Turn on Lamp  ");
		UART_TransmitData('\r');
		UART_voidPrintf((u8*)"F -> To Turn OFF Lamp  ");
		UART_TransmitData('\r');
		UART_voidPrintf((u8*)"D -> To Open Door  ");
		UART_TransmitData('\r');
		UART_voidPrintf((u8*)"E -> To Exit  ");
		UART_TransmitData('\r');

		choise = UART_RecieveData();
		UART_TransmitData('\r');

		if (choise == 'L')
		{
			DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
		}
		else if (choise == 'F')
		{
			DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW);		}
		else if (choise == 'D')
		{
			DIO_voidSetPinValue(DIO_PORTA , DIO_PIN7 , DIO_HIGH);
			_delay_ms(6000);
			DIO_voidSetPinValue(DIO_PORTA , DIO_PIN7 , DIO_LOW);
		}
		else if (choise == 'E')
		{

			try_num = 0;
			exit_num = 1 ;
		}
		else
		{
			UART_voidPrintf((u8*)"Wrong Choise !! ");
			UART_TransmitData('\r');
		}

	}
	exit_num = 0 ;

}

