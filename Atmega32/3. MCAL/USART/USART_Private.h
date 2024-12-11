/*
 * USART_Private.h
 *
 *  Created on: 8 May 2024
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*
 *BaudRate = (Fosc)/16(UBBRL-1)
 *BaudRate = 9600, Fosc = 8000000
*/
#define UBRRL_BAUD_RATE_VAL			51

/*
 * 0b10000110
 * 1  -> URSEL:selecting UCSRC not UBRRH
 * 0  -> select Asynchronous Operation
 * 00 -> Parity Mode:Disabled
 * 0  -> Stop Bit, Select:1-bit
 * 11 -> Character Size(data bits):8-bit
 * 0  -> XXX For synchronous mode
 * */

#define	FRAME_FORMAT			0b10000110

#endif /* USART_PRIVATE_H_ */
