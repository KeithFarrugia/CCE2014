#include "eeprom_lib.h"
#include "lcd_roll.h"

void EEPROM_toggle_scroll(int SCROLLING) {
	static int previousState = 0; 
  	int currentState = switch_get(P_SW_DN);

	// Check if button has transitioned from not pressed to pressed
	if (currentState == 1 && previousState == 0) {
      	SCROLLING = !SCROLLING;  // Toggle the value of SCROLLING
		toggle_scroll();

    	// Save the new state of SCROLLING to EEPROM
    	EEPROM_Write(EEPROM_PAGE_OFFSET(0),
        	         EEPROM_PAGE_ADRESS(0),
            	     &SCROLLING,
                	 MODE_8_BIT,
                 	sizeof(SCROLLING));
   	}

	previousState = currentState;
}
