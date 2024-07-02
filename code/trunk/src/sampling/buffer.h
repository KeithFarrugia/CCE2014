/*!
 *	\file buffer.h
 *
 *	\brief This file contains the buffer_queue type and the buffering functions
 *	prototypes.
 *
 *	\author Jonas ROUSSEAU-MORVAN
 *	\date 13/03/2024
 *	\version 0.0
 */

#ifndef _BUFFER_H_
#define _BUFFER_H_

/* External includes */
#include <adc.h>
/* local includes */
#include "../libraries/stdfunc.h"
#include "../libraries/references.h"

/*============================================================================*
 *               ENTER THE REALM OF FUNCTION DECLARATIONS                     *
 *============================================================================*/

/*!
 * \struct buffer_s
 *
 * \brief This struct represents a buffer it is comprised of several fields:
 *		- buf is an array of bytes (char) which size is given by the BUFFER_SIZE
 *		  macro ;
 *		- filled is a first-order logic value set to FALSE if the buffer needs
 *		  to filled again.
 *
 */
typedef struct buffer_s
{
	volatile float buf[BUFFER_SIZE];
	volatile bool_t filled;
} buffer_t;


#endif /* _BUFFER_H_ */
