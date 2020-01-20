 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef COMMON_MACROS_2
#define COMMON_MACROS_2
#include "math.h"
/* SET a certain bit in GPIO register makes it OUTPUT */
#define MAKE_OUTPUT(REG,BIT) (REG |= (1<<BIT))

/* Clear a certain bit in GPIO register makes it INPUT */
#define MAKE_INPUT(REG,BIT) (REG &= (~(1<<BIT)))

/* write a specific bit in register to 0 or 1 regardless it's current value*/
#define WRITE_BIT(REG , BIT , VAL) (REG = ((REG & ~(1<<(BIT))) | ((VAL) << (BIT))))

/*
 * insert macro uses math.h
 * usage :
 * 			enter the destination register with the region of interest from the LSB number to the MSB number
 * 			enter the source value with the region of interest from LSB number to MSB number
 * */
#define INSERT(REG , CS , CE , VAL , MS , ME) (	\
	((REG) & ~(((char)(pow(2 , ((CE - CS)+1)) - 1)) << CS)) |	\
	((((VAL) & ((char)(pow(2 , ((ME - MS)+1)) - 1)))>>MS) << CS)	\
)
#endif
