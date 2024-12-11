/*
 * USART_Interface.h
 *
 *  Created on: 8 May 2024
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*
 * Function Name: USART_void_Init
 * Purpose      : Initialize USART
 * Parameters   : void
 * Return value : void
*/
void USART_void_Init();

/*
 * Function Name: USART_void_Send_Data
 * Purpose      : Send u8 of data
 * Parameters   : Copy_u8_Data
 * Return value : void
*/
void USART_void_Send_Data(u8 Copy_u8_Data);

/*
 * Function Name: USART_u8_Receive_Data
 * Purpose      : Receive u8 of data
 * Parameters   : void
 * Return value : u8
*/
u8 USART_u8_Receive_Data();

/*
 * Function Name: USART_void_Send_Number
 * Purpose      : Send a number
 * Parameters   : Copy_u32_Number
 * Return value : void
*/
void USART_void_Send_Number(u32 Copy_u32_Number);

/*
 * Function Name: USART_32_Receive_Number
 * Purpose      : Receive a number
 * Parameters   : void
 * Return value : u32
*/
u32 USART_32_Receive_Number();

/*
 * Function Name: USART_void_Send_String
 * Purpose      : send a string
 * Parameters   : Copy_pU8_String
 * Return value : void
*/
void USART_void_Send_String(u8* Copy_pU8_String);

/*
 * Function Name: USART_void_Receive_String
 * Purpose      : receive a string
 * Parameters   : Return_pu8_String
 * Return value : void
*/
void USART_void_Receive_String(u8* Return_pu8_String);

/*
 * Function Name: USART_void_Enable_Int_Rx
 * Purpose      : enable INT USART, Rx Complete
 * Parameters   : void
 * Return value : void
*/
void USART_void_Enable_Int_Rx();

/*
 * Function Name: USART_void_Disable_Int_Rx
 * Purpose      : disable INT USART, Rx Complete
 * Parameters   : void
 * Return value : void
*/
void USART_void_Disable_Int_Rx();

#endif /* USART_INTERFACE_H_ */
