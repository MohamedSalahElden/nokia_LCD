/*
 * GLCD_2D.c
 *
 *  Created on: Jan 20, 2020
 *      Author: SALAH
 */
#ifndef GLCD_2D_H_
#define GLCD_2D_H_
#include "glcd.h"
#include "common_macros.h"
#include "common_macros2.h"
#include "micro_config.h"
#include "std_types.h"
#include "math.h"

extern const uint8 CIRCLE_8_8[] ;
extern const uint8 CIRCLE_5_5[] ;
void GLCD_clearImage(void);
void GLCD_update(void);
void GLCD_writePixel(uint16 x , uint16 y , uint8 value);
void GLCD_drawRectangle(const uint16 x1 , const uint16 y1 , const uint16 x2 , const uint16 y2);
void GLCD_drawimage(const uint8* data , const uint8 x_size , const uint8 y_size ,  const uint8 x , const uint16 y);

#endif
