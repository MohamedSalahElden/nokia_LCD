
#ifndef GLCD_CHARACTER_H_
#define GLCD_CHARACTER_H_


#include "common_macros.h"
#include "common_macros2.h"
#include "micro_config.h"
#include "std_types.h"

/*-----------------function prototype ----------------*/
void GLCD_writeCharacter(const uint8 character);
void GLCD_writeString(const uint8* character);

#endif
