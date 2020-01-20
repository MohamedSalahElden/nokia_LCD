/*
 * spi.c
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */


#include "spi.h"

void SPI_init(spiConfig_t * spiConfig){
	WRITE_BIT(SPCR , SPE  , 0); /*disable SPI module*/
	if(spiConfig->spiDevice == master){
		MAKE_OUTPUT(SPI_DIR , MOSI);
		MAKE_OUTPUT(SPI_DIR , SCK);
		MAKE_OUTPUT(SPI_DIR , SS);
		MAKE_INPUT(SPI_DIR , MISO);
		WRITE_BIT(SPI_PORT , SS , 1); /*deactivate the Slave select pin */
	}
	else if(spiConfig->spiDevice == slave){
		MAKE_INPUT(SPI_DIR , MOSI);
		MAKE_INPUT(SPI_DIR , SCK);
		MAKE_INPUT(SPI_DIR , SS);
		MAKE_OUTPUT(SPI_DIR , MISO);
	}

	WRITE_BIT(SPCR , SPIE , spiConfig->spiMode); /*set mode to interrupt o polling*/
	WRITE_BIT(SPCR , DORD , spiConfig->spiDataOrder); /*configure the data order*/
	WRITE_BIT(SPCR , MSTR , spiConfig->spiDevice); /*configure the device to master or slave*/
	WRITE_BIT(SPCR , CPOL , spiConfig->spiClkPolarity); /*configure polarity to rising , falling*/
	WRITE_BIT(SPCR , CPHA , spiConfig->spiClkPhase); /*configure phase to sample or setup*/
	SPCR = (SPCR & 0xFC) | (spiConfig->spiClkSel & 0x03);	/*configure SPR1 , SPR0 for clock select*/
	SPSR = (SPSR & 0xFE) | (spiConfig->spiClkSel & 0x04)>>2; /* configure SPI2X for clock select*/
	WRITE_BIT(SPCR , SPE  , 1); /*enable SPI module*/
}

void SPI_activateSlave(void){
	WRITE_BIT(SPI_PORT , SS , 0); /*activate the Slave select pin */
}

void SPI_deActivateSlave(void){
	WRITE_BIT(SPI_PORT , SS , 1); /*deactivate the Slave select pin */
}
void SPI_sendByte(uint8 data){
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR , SPIF));
}

uint8 SPI_recieveByte(void){
	while(BIT_IS_CLEAR(SPSR , SPIF));
	return SPDR;
}

