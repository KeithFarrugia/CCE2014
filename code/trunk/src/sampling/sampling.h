/*!
 * \file sampling.h
 *
 * \brief  This file deals with the sampling part of the project, it should
 * create a timer and take samples at set intervals
 *
 * \author Keith Farrugia & Jonas Rousseau-Morvan
 * \date 20/03/2024
 * \version 0.0
 */
#ifndef SAMPLING_H
#define SAMPLING_H

/* External includes */
#include <adc.h>
#include <timer.h>
#include <platform.h>

/* local includes */
#include <stdio.h>
#include "buffer.h"
#include "../io/lcd.h"
#include "../io/leds.h"
#include "../libraries/stdfunc.h"
#include "../libraries/references.h"


extern volatile buffer_t* buffer_to_fill;
extern volatile int buffer_index;


/*============================================================================*
 *               ENTER THE REALM OF FUNCTION DECLARATIONS                     *
 *============================================================================*/

/*!
 * \fn void sampler_init(void)
 * \brief This function sets back the global buffer_index variable to zero.
 * \author Keith Farrugia.
 */
void sampler_init(void);

/*!
 * \fn void sampling_callback(void)
 * \brief This function increments the index, reads a value and pushes it into
 * the buffer.
 * \author Keith Farrugia.
 */
void sampling_callback(void);

/*!
 * \fn void start_sampler(buffer_t* buffer)
 * \brief This function launches the sampling routine. It should only be called
 * once until the sampling routine is stopped. 
 * \param buffer The first buffer to fill with samples.
 * \author Keith Farrugia.
 */
void start_sampler(buffer_t* buffer);

/*!
 * \fn void sampler_swap_buffers(buffer_t* buffer_new)
 * \brief This function swaps the current bufer with given buffer.
 * \param buffer_new The new buffer to be filled.
 * \author keith Farrugia.
 */
void sampler_swap_buffers(buffer_t* buffer_new);

/*!
 * \fn void stop_sampler(void)
 * \brief This function stops the sampling routine.
 * \author Keith Farrugia.
 */
void stop_sampler(void);

#endif /* SAMPLING_H */

