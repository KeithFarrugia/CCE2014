/*!
 * \file dtmf.h
 *
 * \brief This file contains the function prototypes for the dtmf.c file, that
 * is, the functions used to recognize the dtmf frequencies.
 *
 * \author Keith farrugia & Jonas Rousseau-Morvan
 */

#ifndef DTMF_H
#define DTMF_H

#include "../io/lcd.h"
#include "../libraries/delay.h"
#include "../fourier/goertzel.h"
#include "../sampling/buffer.h"
#include "../sampling/sampling.h"
#include "../libraries/references.h"
#include "../libraries/stdfunc.h"
#include "../io/lcd_roll.h"
#include "../io/leds.h"
#include "../io/eeprom.h"
#include "../io/eeprom_lib.h"

/*!
 * \fn DTMF_value calc_dtmf(buffer_t* buf)
 * \brief This function calculates the DTMF value from the input buffer by
 * performing Goertzel analysis on the buffer data and filtering the results
 * based on a threshold.
 * 
 * \param buf Pointer to the buffer containing the input samples.
 * \return The calculated DTMF value or NOT_DTMF if no valid DTMF signals are
 * detected.
 * \author Keith Farrugia
 */
DTMF_value calc_dtmf(buffer_t* buf);

/*!
 * \fn DTMF_value dtmf_recognition(frequency_magnitude_t **input)
 * \brief This function receives an array of (frequency, magnitude) couples that
 * must have already been sorted by the threshold algorithm and determine if it
 * corresponds to a reference DTMF value.
 * \param input The list of (frequency, magnitude) couples.
 * \return A DTMF_value element, if there is an error OR no value is recognized,
 * it will be NOT_DTMF.
 * \author Jonas Rousseau-Morvan
 */
DTMF_value dtmf_recognition(float frequence1, float frequence2);

/*!
 * \fn void dtmf_print(DTMF_value signal)
 * \brief This function receives a <code>DTMF_value<code/> value and prints the
 * corresponding DTMF on the LCD screen if this is a legal value.
 * \param signal The DTFM scanned by the program.
 * \author Jonas Rousseau-Morvan
 */
void dtmf_print(DTMF_value signal);

/*! 
 * \fn void dtmf_main(void)
 * \brief This function initializes variables and starts the sampler.
 * It then enters an infinite loop where it waits for sampling to finish,
 * calculates the DTMF value from the buffer, and processes the DTMF value.
 * 
 * \author Keith Farrugia & Jonas Rousseau-Morvan
 */
void dtmf_main(void);


#endif /* DTMF_H */
