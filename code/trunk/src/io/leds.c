#include <platform.h>
#include <gpio.h>
#include "leds.h"
#include "switches.h"

void leds_init(void) {
	// Set 3 led pins to outputs.
	gpio_set_mode(P_LED_R, Output);
	gpio_set_mode(P_LED_G, Output);
	gpio_set_mode(P_LED_B, Output);
	
	leds_set(0, 0, 0);
}

void leds_set(int red_on, int green_on, int blue_on) {
	// Boolean operation to decide on state for both active
	// high and low LEDs.
	gpio_set(P_LED_R, !red_on != LED_ON);
	gpio_set(P_LED_G, !green_on != LED_ON);
	gpio_set(P_LED_B, !blue_on != LED_ON);
}

// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************   

void light_leds() {
   int red = switch_get(P_SW_UP);
   int green = switch_get(P_SW_CR);
   int blue = switch_get(P_SW_DN);

   leds_set(red, green, blue);
}
