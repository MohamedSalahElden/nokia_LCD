/*
 * GLCD_characters.c
 *
 *  Created on: Jan 20, 2020
 *      Author: SALAH
 */

#include "glcd.h"
#include "font.h"
#include "GLCD_characters.h"

void GLCD_writeCharacter(const uint8 character){
	if((character >= 0 ) && (character <91)){
		GLCD_sendData(ASCII[character - 32] , 6);
	}
}
void GLCD_writeString(const uint8* character){
	uint8 i = 0;
	while(*(character + i) != '\0'){
		GLCD_sendData(ASCII[character[i] - 32] , 6);
		i++;
	}
}
