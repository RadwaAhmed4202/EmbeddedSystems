/*
 * SPI_Register.h
 *
 *  Created on: Nov 11, 2023
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR            *((volatile u8*)0x2d)
#define SPCR_SPE        6
#define SPCR_MSTR       4
#define SPCR_SPR1       1
#define SPCR_SPR0       0

#define SPSR            *((volatile u8*)0x2e)
#define SPSR_SPIF       7

#define SPDR            *((volatile u8*)0x2f)

#endif /* SPI_REGISTER_H_ */
