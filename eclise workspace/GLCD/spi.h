/*
 * spi.h
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */

#ifndef SPI_H_
#define SPI_H_

#include "common_macros.h"
#include "common_macros2.h"
#include "micro_config.h"
#include "std_types.h"

#define NULL (void *)(0)
#define SPI_PORT PORTB
#define SPI_DIR	DDRB

#define SS 	 PB4  	/*inverted (to be selected as a slave set to LOW)*/
#define MOSI PB5	/*master out slave in */
#define MISO PB6	/*master in slave out*/
#define SCK  PB7	/*clock */



typedef enum {polling , interrupt}Mode_t;
typedef enum {MSBfirst , LSBfirst}dataOredr_t;
typedef enum {slave , master}dev_t;
typedef enum {rising , falling}clkPolariry_t;
typedef enum {sample , setup}clkPhase_t;
typedef enum {Fcpu_4 , Fcpu_16 ,Fcpu_64 ,Fcpu_128 ,Fcpu_2 ,Fcpu_8 ,Fcpu_32}clkSel_t;
typedef struct{
	Mode_t spiMode;
	dataOredr_t spiDataOrder;
	dev_t spiDevice;
	clkPolariry_t spiClkPolarity;
	clkPhase_t spiClkPhase;
	clkSel_t spiClkSel;
	void (* callback_ptr)(void);
}spiConfig_t;

void SPI_init(spiConfig_t * spiConfig);
void SPI_sendByte(uint8 data);
uint8 SPI_recieveByte(void);
void SPI_activateSlave(void);
void SPI_deActivateSlave(void);

#endif /* SPI_H_ */
