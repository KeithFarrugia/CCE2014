/*!
 * \file lcd_roll.c
 *
 * \brief This file contains the functions to handle auto-scrolling of the LCD
 * when printing on it.
 *
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */
#include "lcd_roll.h"

/* The line width of the LCD. */
#define LINE_WIDTH 16

int SCROLLING = 0;

/* Buffers containing the strings on each lines. */
char top_line[LINE_WIDTH + 1] = {' '};
int line_index;

/*!
 * \fn void toggle_scroll(void)
 * \brief This function activates or de-activate scrolling.
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */
void toggle_scroll(void) {
    SCROLLING = !SCROLLING;
    line_index = 0;
    lcd_set_cursor(0, 0);
}

/*!
 * \fn static void lcd_roll_newline()
 * \brief If on line 0, goes to the next line, if on line 1, prints the content
 * on line 1 to line 0 then goes at start of cleared line 1;
 * \author Keith Farrugia & Jonas Rousseau-Morvan.
 */
static void lcd_roll_newline() {
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_print(top_line);
    line_index = 0;

    lcd_set_cursor(0, 1);
}

void lcd_roll_print(char* str) {
    int i = 0;
    if (SCROLLING) {
        while (str[i] != '\0') {
            for (; line_index < LINE_WIDTH && str[i] != '\0'; line_index += 1) {
                top_line[line_index] = str[i];
                lcd_put_char(str[i]);
                i += 1;
            }
            if (str[i] != '\0')
                lcd_roll_newline();
        }
    } else {
        lcd_clear();
        lcd_set_cursor(0, 0);
        lcd_print(str);
    }
}
