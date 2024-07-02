/*!
 *	\file stdfunc.h
 *
 *	\brief This file contains basic C functions that are not directly related
 *	to the project but find themselves useful anyway.
 *
 *	\author Keith Farrugia & Jonas ROUSSEAU-MORVAN
 *	\date 13/03/2024
 *	\version 0.0
 */

/* Local includes */
#include "stdfunc.h"
 
void int_to_char(int input, char arr[]){
	int i, l, tmp;
    l = 0;
    for(tmp = input; tmp; tmp /= 10) l +=1;
    arr[l] = '\0';
    for(i = l; i; i -= 1){
        arr[i-1] = '0' + input % 10;
        input /= 10;
    }
}

void *safe_malloc(size_t size)
{
    void *allocated_return = (void *) malloc(size);
    if(NULL == allocated_return) exit(EXIT_FAILURE);
    return allocated_return;
}

// Function to convert seconds to clock cycles
int toSeconds(int seconds) {
	return seconds * CLOCK_SPEED;
}

// Function to convert milliseconds to clock cycles
int toMilliSeconds(int milliseconds) {
	return (milliseconds * CLOCK_SPEED) / 1000;
}

/**
 * Since the Clock Cycles are at 120,000,000 instructions per second
 * and we want to convert our hertz to the instruction cycles
 * 
 * so if we want to do 2 Hz meaning 2 pulses per second
 * For the controller 1 second is 120,000,000 instruction cycles
 * so 2 pulses per second are 120,000,000 / 2 = 60,000,000
 */
int toHertz(int hertz) {
	return CLOCK_SPEED / hertz;
}

