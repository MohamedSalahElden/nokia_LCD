/*
 * glcd.h
 *
 *  Created on: Jan 19, 2020
 *      Author: SALAH
 */

#ifndef GLCD_H_
#define GLCD_H_

#include "common_macros.h"
#include "common_macros2.h"
#include "micro_config.h"
#include "std_types.h"

#define GLCD_DATA PORTB
#define GLCD_DIR DDRB
#define	DC 1
#define RST 0

void GLCD_init(void);
void GLCD_sendCommand(uint8 command);
void GLCD_sendData(uint8* data , uint16 size);
void GLCD_reset(void);
void GLCD_goto(uint8 bank , uint8 byte);
void GLCD_clear(void);
#endif /* GLCD_H_ */
