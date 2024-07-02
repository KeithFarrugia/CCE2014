/*!
 * \file references.h
 *
 * \brief This file is meant contain all global variables that must be available
 * for multiple files.
 * 
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 * \date 19/04/2024
 * \version 0.0
 */
#ifndef _REFERENCES_H_
#define _REFERENCES_H_

/*============================================================================*
 *                       PREPROCESSOR-DEFINED CONSTANTS                       *
 *============================================================================*/

/* The buffer size. */
#define BUFFER_SIZE 256
/* The reference voltage. */
#define VREF 3.3f
/* The sample rate of the ADC. */
#define SAMPLE_RATE 8000
/* The size of the FFT. */
#define FFT_SIZE 32
/* Clock speed in Hz (120kHz !) */
#define CLOCK_SPEED 120000000
/* π and 2π  (as FLOATS and not DOUBLES — otherwise compiling errors)*/
#define PI 3.14159265358979323846f
#define TWO_PI (2.f * PI)
/* The maximum number of QUIET DTMF value accepted. */
#define MAX_QUIET 3
/* The number of DTMF frequencies. */
#define DTMF_SIZE 8
/* Magnitude threashold to select received frequencies. */
#define DTMF_THRESHOLD 140.f

/* An array of each DTMF reference frequencies. */
static float DTMF[] =
    {697.0f, 770.0f, 852.0f, 941.0f, 1209.0f, 1336.0f, 1477.0f, 1633.0f};

/* This is used to activate/deactivate LCD scrolling */
extern int SCROLLING;

/*!
 * \enum DTMF_value
 * \brief This enum encapsulates the different DTMF reference values
 * (0, 1, 2, …, 9, A, B, C, D, *, #) and adds a value for non-DTMF signal
 * NOT_DTMF.
 */
typedef enum {
    DTMF_0, DTMF_1, DTMF_2,
    DTMF_3, DTMF_4, DTMF_5,
    DTMF_6, DTMF_7, DTMF_8,
    DTMF_9, DTMF_A, DTMF_B,
    DTMF_C, DTMF_D, DTMF_STAR,
    DTMF_SHARP, 
    NOT_DTMF, QUIET
} DTMF_value;

#endif /* _REFERENCE_H_*/
