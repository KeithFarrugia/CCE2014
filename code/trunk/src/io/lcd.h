/*!
 * \file      lcd.h
 * \brief     Driver for Hitachi HD44780 LCD controller in 4-bit mode.
 * \copyright ARM University Program &copy; ARM Ltd 2014.
 *
 * Modified for use with LPC4088 experiment bundle;
 * Copyright 2016-2017 Johann A. Briffa
 */
#ifndef LCD_H
#define LCD_H

/*! \brief Initialises the LCD module.
 */
void lcd_init(void);

/*! \brief Moves the cursor position to the specified location.
 *  \param column  Destination column for the cursor.
 *  \param row     Destination row for the cursor.
 */
void lcd_set_cursor(int column, int row);

/*! \brief Clears the LCD and relocates the cursor to {0,0}.
 */
void lcd_clear(void);

/*! \brief Prints the null terminated string to the LCD and
 *         increments the cursor.
 *  \param string  Null terminated string to be printed.
 */
void lcd_print(char *string);

/*! \brief Prints the specified character to the LCD and
 *         increments the cursor.
 *  \param c  Character to be printed.
 */
void lcd_put_char(char c);

/*! \brief Enables or disables visibility of the cursor.
 *  \param visible New visibility of the cursor.
 */
void lcd_set_cursor_visibile(int visible);

/*! \fn void lcd_print_substring(char *string, int idx_1, int idx_2)
 *	\brief Prints a subtring from an input string and start and end indexes.
 *	\param string The input string.
 *	\param idx_1 The index of the first character of the substring.
 *	\param idx_2 The index of the last character of the substring.
 *	\pre The value of both indexes must be less than the string length and
 *	there must be idx_1 strictly less.
 */
void lcd_print_substring(char *string, int idx_1, int idx_2);


#endif // LDC_H
