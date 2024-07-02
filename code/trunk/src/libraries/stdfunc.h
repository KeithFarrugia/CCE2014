/*!
 *	\file stdfunc.h
 *
 *	\brief This file contains the functions prototypes of the stdfunc.c file.
 *
 *	\author Keith Farrugia & Jonas ROUSSEAU-MORVAN
 *	\date 13/03/2024
 *	\version 0.0
 */
#ifndef _STDFUNC_H_
#define _STDFUNC_H_

/* External includes */
#include <stdlib.h>
#include <math.h>
/* local includes */
#include "references.h"

/* implementing booleans */
typedef int bool_t;
#define TRUE 1
#define FALSE 0

/* Use char as bytes */
typedef char byte_t;

/* Struct to represent complex numbers. */
typedef struct
{
    float real;
    float imag;
} complex_t;

/*============================================================================*
 *               ENTER THE REALM OF FUNCTION DECLARATIONS                     *
 *============================================================================*/

/*!
 * \fn void int_to_char(int input, char arr[])
 * \brief Converts an int to a string.
 * \param input the int one wants to convert ;
 * \param arr the character array in which the result is stored.
 * \pre the size of argument arr must be greater than the number of digit in
 * input by at least 1.
 * \author Jonas Rousseau-Morvan.
 */
void int_to_char(int input, char arr[]);

/**
 * \fn void *safe_malloc(size_t size)
 * \brief Wraps malloc to make a call to exit(EXIT_FAILURE) if malloc fails.
 * \param size the size of the memory space to allocate.
 * \author Jonas Rousseau-Morvan.
 */
void *safe_malloc(size_t size);

/*!
 * \fn int toSeconds(int seconds)
 * \brief Converts Seconds to Clock Cycles.
 * \param seconds The seconds one wants to change to clock cycles;
 * \return Returns the Clock cycles required to wait the time in seconds.
 * \author Keith Farrugia.
 */
int toSeconds(int seconds);

/*!
 * \fn toMilliSeconds(int milliseconds)
 * \brief Converts Milli Seconds to Clock Cycles.
 * \param milliseconds The milliseconds one wants to change to clock cycles;
 * \return Returns the Clock cycles required to wait the time in milliseconds.
 * \author Keith Farrugia.
 */
int toMilliSeconds(int milliseconds);

/*!
 * \fn toHertz(int hertz)
 * \brief Converts devides the clock cycles to get the wait time for the
 * amount of hertz.
 * \param hertz The hertz one wants to change to clock cycles;
 * \return Returns the Clock cycles required to wait the time in Hertz.
 * \author Keith Farrugia.
 */
int toHertz(int hertz);

#endif
