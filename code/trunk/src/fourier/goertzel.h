/*!
 *	\file goertzel.h
 *
 *	\brief This file contains the prototypes for the Goertzel Algorithm
 * implementation functions.
 *
 *	\author Keith Farrugia
 *	\date 19/04/2024
 *	\version 0.0
 */

#ifndef GOERTZEL_H
#define GOERTZEL_H

/* External includes */
#include <math.h>
/* Local includes */
#include "../libraries/references.h"
#include "../libraries/stdfunc.h"
#include "../sampling/buffer.h"

/*!
 * \struct frequency_magnitude_t
 * \brief This struct acts as a wrapper for (frequency, magnitude) couples.
 */
typedef struct {
    float frequency; /*!< The frequency of the wave. */
    float magnitude; /*!< The magnitude of the wave. */
} frequency_magnitude_t;

/*============================================================================*
 *               ENTER THE REALM OF FUNCTION DECLARATIONS                     *
 *============================================================================*/

/*!
 * \fn float goertzel(volatile float* x, int N, float freq, float sample_rate)
 * \brief Implements the Goertzel algorithm to detect specific frequencies.
 * \param x An audio samples buffer.
 * \param N The size of the samples (in bits).
 * \param index The index relating to the frequency/coefficient
 * \return The magnitude of the given freq in the audio buffer by goertzel.
 * \author Keith Farrugia
 */
float goertzel(volatile float* x, int N, int index);

/*!
 * \fn frequency_magnitude_t** parse_Goertzel(volatile float *sample, int
 * num_sample, float sample_rate)
 * \brief Traverses the set of DTMF of frequencies making use of the goertzel()
 * function to get the magnitudes for each. 
 * \param sample the sampled audio buffer 
 * \param num_sample the size of the sample buffer. 
 * \param freq_mag_sets set of Freq & Magnitudes. 
 * \return void 
 * \author Keith Farrugia
 */
void parse_goertzel(volatile float* sample,
                    int num_sample,
                    frequency_magnitude_t freq_mag_sets[DTMF_SIZE]);

#endif  /* GOERTZEL_H */

