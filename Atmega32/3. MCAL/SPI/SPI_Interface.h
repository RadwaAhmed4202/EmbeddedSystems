/*
 * SPI_Interface.h
 *
 *  Created on: Nov 11, 2023
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit();

void SPI_voidSlaveInit();

u8 SPI_u8Transceive(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
