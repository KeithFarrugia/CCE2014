/*!
 *	\file main.c
 *
 *	\brief This file contains the main function (program entry point).
 *
 *	\author Everyone
 *	\date 13/03/2024
 *	\version 0.0
 */

/* External includes */
#include <platform.h>
#include <adc.h>
#include <stdio.h>
#include <timer.h>
#include <time.h>
/* Local includes */
#include "libraries/references.h"
#include "io/lcd_roll.h"
#include "io/leds.h"
#include "io/eeprom.h"
#include "io/eeprom_lib.h"
#include "libraries/delay.h"
#include "dtmf/dtmf.h"

/*============================================================================*
 *                    THIS IS THE PROGRAM'S ENTRY POINT                       *
 *============================================================================*/

/*!
 * \fn int main(void)
 * \brief This function is the entry point of the program. It launches different
 * initializations and launches the main DTMF-recognition routine.
 */
int main(void) {
	leds_init();
	EEPROM_Init();
	lcd_init();
	adc_init();
	
	// Read last saved scroll setting from EEPROM
	EEPROM_Read(EEPROM_PAGE_OFFSET(0),
				EEPROM_PAGE_ADRESS(0),
    			&SCROLLING,
	    		MODE_8_BIT,					
	    		sizeof(SCROLLING));
	
	lcd_clear();	
	dtmf_main();
}

