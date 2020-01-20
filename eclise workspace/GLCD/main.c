/*
 * main.c
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */

#include "glcd.h"
#include "GLCD_characters.h"
void main(void){
	GLCD_init();
	GLCD_writeString("a7la mesa  ");
	while(1);
}
