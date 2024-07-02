/*!
 * \file goertzel.c
 *
 * \brief This file contains functions implementing the Goertzel algorithm.
 *
 * \author Keith Farrugia
 */

#include "goertzel.h"

float goertzel(volatile float* x, int N, int index) {
    int i;
    float coeff, omega, s_prev = 0, s_prev2 = 0, s;
    omega = (2.0f * PI * (DTMF[index] / SAMPLE_RATE));
    coeff = 2.0f * cosf(omega);

    for (i = 0; i < N; i++) {
        s = x[i] + coeff * s_prev - s_prev2;
        s_prev2 = s_prev;
        s_prev = s;
    }
    return (s_prev * s_prev) + (s_prev2 * s_prev2) - (coeff * s_prev * s_prev2);
}

void parse_goertzel(volatile float* sample,
                    int num_sample,
                    frequency_magnitude_t freq_mag_sets[DTMF_SIZE]) {
    int i;

    /* Get magnitude for each DTMF Frequency */
    for (i = 0; i < DTMF_SIZE; i++) {
        freq_mag_sets[i].frequency = DTMF[i];
        freq_mag_sets[i].magnitude = goertzel(sample, num_sample, i);
    }
}
