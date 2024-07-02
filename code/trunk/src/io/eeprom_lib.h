#ifndef EEPROM_LIB_H
#define EEPROM_LIB_H

#include "eeprom.h"
#include "switches.h"

/**
 * @brief Toggles the scrolling state when a button is pressed and saves the state to EEPROM.
 * @param SCROLLING The current scrolling state, which will be toggled if the button is pressed.
 * \author Gabriel Vella & Alessandro Parrella
 */
void EEPROM_toggle_scroll(int SCROLLING);

#endif
