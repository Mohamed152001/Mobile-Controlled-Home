/*
 * CLCD_config.h
 *
 *  Created on: 29 Nov 2023
 *      Author: Mohamed Harby
 */

#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_

//////////////////////////////////////////////

#define CLCD_DATA_PORT      DIO_PORTC    // to explain which port is used for the LCD

#define CLCD_CTRL_PORT      DIO_PORTD

#define CLCD_RS             DIO_PIN7

#define CLCD_RW             DIO_PIN6

#define CLCD_EN             DIO_PIN5

#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
