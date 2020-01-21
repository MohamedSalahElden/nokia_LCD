/*
 * GLCD_2D.c
 *
 *  Created on: Jan 20, 2020
 *      Author: SALAH
 */

#include "glcd.h"
#include "GLCD_2D.h"

static uint8 image[504] = {0xFF , 0};
const uint8 CIRCLE_8_8[] = {
		0,0,0,1,1,0,0,0,
		0,0,1,1,1,1,0,0,
		0,1,1,1,1,1,1,0,
		1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,0,
		0,0,1,1,1,1,0,0,
		0,0,0,1,1,0,0,0
};
const uint8 CIRCLE_5_5[] = {
		0,1,1,1,0,
		1,1,1,1,1,
		1,1,1,1,1,
		1,1,1,1,1,
		0,1,1,1,0
};
void GLCD_clearImage(void){
	uint16 i = 0;
	for(i=0 ; i<504 ; i++){
		image[i] = 0x00;
	}
}

void GLCD_update(void){
	GLCD_goto(0 , 0);
	GLCD_sendData(image , 504);
}

void GLCD_writePixel(uint16 x , uint16 y , uint8 value){
	if((x<0) || (x>83)){return;}
	if((y<0) || (y>47)){return;}
	uint8 bank = y / 8;
	uint8 bit  = y % 8;
	uint8 byte = x ;
	uint16 index = ((bank * 84) + byte);
	WRITE_BIT(image[index] , bit , value);
}

void GLCD_drawRectangle(const uint16 x1 , const uint16 y1 , const uint16 x2 , const uint16 y2){
	int i , j;
	for(i=x1 ; i<x2 ; i++){
		for(j=y1 ; j<y2 ; j++){
			GLCD_writePixel(i,j,1);
		}
	}
}


void GLCD_drawimage(const uint8* data , const uint8 x_size , const uint8 y_size ,  const uint8 x , const uint16 y){
	uint8 i,j,d = 0;
	for(i=x ; i<(x + x_size) ; i++){
		for(j=y ; j<(y + y_size) ; j++){
			if(data[d] == 0){
				GLCD_writePixel(i,j,0);
			}
			else{
				GLCD_writePixel(i,j,1);
			}
			d++;
		}
	}
}




