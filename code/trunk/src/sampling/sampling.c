/*!
 * \file sampling.c
 *
 * \brief  This file implements the functions from the sampling.h file.
 *
 * \author Keith Farrugia & Jonas Rousseau-Morvan
 * \date 20/03/2024
 * \version 0.0
 */
#include "sampling.h"
volatile buffer_t* buffer_to_fill;
volatile int buffer_index;

void init_sampler(void) {
    buffer_index = 0;
}

void sampling_callback() {
    if (buffer_to_fill->filled == FALSE) {
        volatile float vadc;
        volatile int res = adc_read();
        vadc = res * (float) VREF / ADC_MASK;
        buffer_to_fill->buf[buffer_index++] = vadc;
    } else {
        // Turn the LED on red
        leds_set(1, 0, 0);
    }

    if (buffer_index >= BUFFER_SIZE) {
        buffer_to_fill->filled = TRUE;
        buffer_index = 0;
    }
}

void start_sampler(buffer_t* buffer) {
    buffer_index = 0;
    buffer_to_fill = buffer;
    buffer_to_fill->filled = FALSE;
    timer_set_callback(sampling_callback);
    timer_init(toHertz(SAMPLE_RATE));
    timer_enable();
}

void sampler_swap_buffers(buffer_t* buffer_new) {
    // Turn off the LED
    leds_set(0, 0, 0);

    buffer_index = 0;
    buffer_to_fill = buffer_new;
    buffer_to_fill->filled = FALSE;
}

void stop_sampler(void) {
    timer_disable();
}
