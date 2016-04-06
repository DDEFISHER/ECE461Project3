/*
 * lcd_display.h
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

void init_lcd();
void write_lcd(int8_t input_x[],int position);
void reverse(char s[], int length);
void itoa(int n, char s[]);
void combine_ints_to_string(int x, int y, int z, int n, char s[]);

#endif /* LCD_DISPLAY_H_ */
