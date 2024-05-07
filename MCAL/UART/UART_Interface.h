
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

extern void UART_voidInit (void);

extern void UART_TransmitData (u8 UART_DataToBeSent);

extern u8 UART_RecieveData(void);

extern void UART_voidPrintf(u8 Copy_u8PrintedData[]);

void UART_RECEIVE_String(u8 *array, u8 maxLength);


#endif
