/*!
 * \file lcd_roll.h
 *
 * \brief This file contains the prototypes for the lcd_roll.c file.
 *
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */

#ifndef _LCD_ROLL_H_
#define _LCD_ROLL_H_

#include "lcd.h"
#include "../libraries/references.h"


/*!
 * \fn void toggle_scroll(void)
 * \brief toggles the SCROLLING variable and resets the index.
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */
void toggle_scroll(void);

/*!
 * \fn void lcd_roll_print(char *str)
 * \brief If global variable SCROLLING is on, prints a given string and
 * auto-scrolls when reaching end of line. Else clears screen and prints the
 * given string.
 * \param str The string to print.
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */
void lcd_roll_print(char *str);

#endif /* _LCD_ROLL_H_ */
