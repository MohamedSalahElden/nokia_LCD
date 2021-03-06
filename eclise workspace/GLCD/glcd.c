/*
 * glcd.c
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */

#include "glcd.h"
#include "spi.h"

spiConfig_t spiLCDconfig = {polling , MSBfirst , master ,rising , sample , Fcpu_4 , NULL };

void GLCD_init(void){
	SPI_init(&spiLCDconfig);
	MAKE_OUTPUT(GLCD_DIR , DC);		/*initialize the LCD DC to output pin*/
	MAKE_OUTPUT(GLCD_DIR , RST);	/*initialize the LCD RST to output pin*/
	WRITE_BIT(GLCD_DATA , DC , 1);	/*LCD is not selected*/
	WRITE_BIT(GLCD_DATA , RST , 1);	/*disable resetting (reset & CS pins are active low)*/
	GLCD_reset();
	GLCD_sendCommand(0x21);
	GLCD_sendCommand(0xC0);
	GLCD_sendCommand(0x07);
	GLCD_sendCommand(0x13);
	GLCD_sendCommand(0x20);
	GLCD_sendCommand(0x0C);
}
void GLCD_sendCommand(uint8 command){

	WRITE_BIT(GLCD_DATA , DC , 0);	/* make DC pin to logic zero for command operation */
	SPI_activateSlave();			/* enable SS pin to slave selection */
	SPI_sendByte(command);			/* send data on data register */
	WRITE_BIT(GLCD_DATA , DC , 1);	/* make DC pin to logic high for data operation */
	SPI_deActivateSlave();			/*disable the slave */
}
void GLCD_sendData(uint8 * data , uint16 size){
	WRITE_BIT(GLCD_DATA , DC , 1);
	SPI_activateSlave();
	uint16 i = 0;
	for(; i<size ; i++){
		SPI_sendByte(data[i]);
	}
	SPI_deActivateSlave();
}
void GLCD_reset(void){
	WRITE_BIT(GLCD_DATA , RST , 0);
	_delay_ms(100);
	WRITE_BIT(GLCD_DATA , RST , 1);
}
void GLCD_goto(uint8 bank , uint8 byte){
	if((bank < 0) || (bank > 5)){return ;}
	if((byte < 0) || (byte >= 84)){return ;}
	uint8 y_address = 0b01000000 + bank ;
	uint8 x_address = 0b10000000 + byte ;
	GLCD_sendCommand(y_address);
	GLCD_sendCommand(x_address);
}

void GLCD_clear(void){
	GLCD_goto(0 , 0);
	int i = 0;
	WRITE_BIT(GLCD_DATA , DC , 1);
	SPI_activateSlave();
	for(i=0 ; i<504 ; i++){
		SPI_sendByte(0X00);
	}
	SPI_deActivateSlave();
}
