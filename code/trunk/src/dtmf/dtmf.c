/*!
 * \file dtmf.c
 *
 * \brief This file contains the functions related to recognizing the DTMF
 * frequencies, it also contains the main loop of the program.
 *
 * \author Keith Farrugia & Jonas Rousseau-Morvan 
 */

#include "dtmf.h"

/* ===========================================================================*
 *				              CALCULATE DTMF                                  *
 * ===========================================================================*/

 DTMF_value calc_dtmf(buffer_t* buf) {
    int i, valid_index = 0;
    frequency_magnitude_t raw_set[8];
    frequency_magnitude_t valid_set[2];

    /* -----------------------------------------------------
     * Parse Goertzal
     */
    parse_goertzel(buf->buf, BUFFER_SIZE, raw_set);

    /* -----------------------------------------------------
     * Filter using the treshold
     * Only allow for at most 2 valid inputs
     */
    for (i = 0; i < DTMF_SIZE; i++) {
        if (raw_set[i].magnitude >= DTMF_THRESHOLD && valid_index < 2) {
            valid_set[valid_index++] = raw_set[i];
        }else if (raw_set[i].magnitude >= DTMF_THRESHOLD){
						valid_index++;
				}
    }

     /* -----------------------------------------------------
     * Seperate between quiet regions and invalid 
     * valued. Quiet regions are when non of the values
     * are above the treshold
     */
    if (valid_index == 2) {
        return dtmf_recognition(valid_set[0].frequency, valid_set[1].frequency);

    }else if (valid_index == 0){
        return QUIET;

    } else {
        return NOT_DTMF;
    }
}

/* ============================================================================
 *				DTMF Recognition
 * ============================================================================
 */
DTMF_value dtmf_recognition(float frequence1, float frequence2) {
    /* -----------------------------------------------------
     * Ensuring that frequence1 is always smaller or
     * equal to frequence2. 
     */
    if (frequence1 > frequence2) {
        float tmp = frequence1;
        frequence1 = frequence2;
        frequence2 = tmp;
    }

    /* -----------------------------------------------------
     * Comparing the values of the frequencies to 
     * standard DTMF frequencies to check if the 
     * current sample is a legal DTMF signal.
     */
    switch ((int) frequence1) {
        case 697:
            switch ((int) frequence2) {
                case 1209:      return  DTMF_1;
                case 1336:      return  DTMF_2;
                case 1477:      return  DTMF_3;
                case 1633:      return  DTMF_A;
            }
            break;
        case 770:
            switch ((int) frequence2) {
                case 1209:      return  DTMF_4;
                case 1336:      return  DTMF_5;
                case 1477:      return  DTMF_6;
                case 1633:      return  DTMF_B;
            }
            break;
        case 852:
            switch ((int) frequence2) {
                case 1209:      return  DTMF_7;
                case 1336:      return  DTMF_8;
                case 1477:      return  DTMF_9;
                case 1633:      return  DTMF_C;
            }
            break;
        case 941:
            switch ((int) frequence2) {
                case 1209:      return  DTMF_STAR;
                case 1336:      return  DTMF_0;
                case 1477:      return  DTMF_SHARP;
                case 1633:      return  DTMF_D;
            }
            break;
    }

    /* return the recognized DTMF value. */
    return NOT_DTMF;
}

/* ============================================================================
 *				Print DTMF
 * ============================================================================
 */
void dtmf_print(DTMF_value signal) {
    /* ----------------------------------------------------- *
     *    Print a sinle DTMF value                           *
     * ----------------------------------------------------- */
    switch (signal) {
        case DTMF_0         :lcd_roll_print("0 ");  break;
        case DTMF_1         :lcd_roll_print("1 ");  break;
        case DTMF_2         :lcd_roll_print("2 ");  break;
        case DTMF_3         :lcd_roll_print("3 ");  break;
        case DTMF_4         :lcd_roll_print("4 ");  break;
        case DTMF_5         :lcd_roll_print("5 ");  break;
        case DTMF_6         :lcd_roll_print("6 ");  break;
        case DTMF_7         :lcd_roll_print("7 ");  break;
        case DTMF_8         :lcd_roll_print("8 ");  break;
        case DTMF_9         :lcd_roll_print("9 ");  break;
        case DTMF_A         :lcd_roll_print("A ");  break;
        case DTMF_B         :lcd_roll_print("B ");  break;
        case DTMF_C         :lcd_roll_print("C ");  break;
        case DTMF_D         :lcd_roll_print("D ");  break;
        case DTMF_STAR      :lcd_roll_print("* ");  break;
        case DTMF_SHARP     :lcd_roll_print("# ");  break;
        default:break;
    }
}

/* ============================================================================
 *				Main DTMF Loop
 * ============================================================================
 */
void dtmf_main(void){
    /* -----------------------------------------------------
     * Variable Initialization
     */
    int buf_index_current, buf_index_next, count_invalid;
    buffer_t buf_array[2];
    DTMF_value dtmf = NOT_DTMF, last_dtmf = NOT_DTMF;

    buf_index_current = 0;
    count_invalid = MAX_QUIET;
    buf_index_next = (int) ((buf_index_current + 1) % 2);
	
    /* -----------------------------------------------------
     * Start Sampler
     */
    start_sampler(&buf_array[buf_index_current]);

    /* -----------------------------------------------------
     * Infinite while loop
     */
    while (TRUE) {
        EEPROM_toggle_scroll(SCROLLING);
        light_leds();

        /* -----------------------------------------------------
         * Wait for sampling to finish
         */
        while (buf_array[buf_index_current].filled == FALSE) {};

        /* -----------------------------------------------------
         * Swap Buffers
         */
        buf_index_next = (buf_index_current + 1) % 2;
        sampler_swap_buffers(&buf_array[buf_index_next]);

        dtmf = calc_dtmf(&buf_array[buf_index_current]);

        if (dtmf == QUIET){
            count_invalid++;
        }else if(dtmf == NOT_DTMF){
            count_invalid = 0;
        }else if (dtmf != last_dtmf){
            dtmf_print(dtmf);
            count_invalid = 0;
            last_dtmf = dtmf;
        }else if(dtmf == last_dtmf && count_invalid >= MAX_QUIET){
            dtmf_print(dtmf);
            count_invalid = 0;
            last_dtmf = dtmf;
        }else{
            count_invalid = 0;
        }
				
        /* -----------------------------------------------------
         * Update Index
         */
        buf_index_current = buf_index_next;
        buf_index_next = (int) ((buf_index_current + 1) % 2);
    }
}
