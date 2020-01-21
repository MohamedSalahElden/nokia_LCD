/*
 * main.c
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */

#include "glcd.h"
#include "GLCD_characters.h"
#include "GLCD_2D.h"

void main(void){
	GLCD_init();
	GLCD_clearImage();
	GLCD_update();
	uint8 i = 0;
	while(1){
		i++;
		GLCD_clearImage();
//		GLCD_drawRectangle(0+i,0+i,10+i,10+i);
//		GLCD_drawRectangle(30-i,30-i,40-i,40-i);
		GLCD_drawimage(CIRCLE_5_5,5,5,20,i);
		i = (i>=48)? 0 : i ;
		GLCD_update();
//		_delay_ms(5);
	}
}
