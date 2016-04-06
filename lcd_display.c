/*
 * lcd_display.c
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */
/* GrLib Includes */
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"

/* Graphic library context */
Graphics_Context g_sContext;

void init_lcd()
{
	P2OUT &= ~BIT1;
	P2DIR |= BIT1; //for green led
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);

    Graphics_drawStringCentered(&g_sContext,
                                    "Project3",
                                     AUTO_STRING_LENGTH,
                                     64,
                                     64,
                                     OPAQUE_TEXT);
}
void write_lcd(int8_t input_x[], int position)
{
	if(position == 1) {
	Graphics_drawStringCentered(&g_sContext,
	                            input_x,
	                            AUTO_STRING_LENGTH,
	                            64,
	                            40,
	                            OPAQUE_TEXT);
	} else if(position == 3) {
	Graphics_drawStringCentered(&g_sContext,
			                    input_x,
			                    AUTO_STRING_LENGTH,
			                    64,
			                    80,
			                    OPAQUE_TEXT);
	}

}
/* reverse:  reverse string s in place */
void reverse(char s[], int length) {
    int i, j;
    char c;

    for (i = 0, j = length-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}
void combine_ints_to_string(int x, int y, int z, int n, char s[]) {

 char x_buff[4] = "    ";
 itoa(x,x_buff);
 char y_buff[4] = "    ";
 itoa(y,y_buff);
 char z_buff[4] = "    ";
 itoa(z,z_buff);


 int index = 0;

 for(index = 0; index < 4; index++) {

   if(x_buff[index] != '\0') {
     s[index] = x_buff[index];
   } else {
     s[index] = ' ';
   }
 }
 for(index = 0; index < 4; index++) {

   if(y_buff[index] != '\0') {
     s[index+4] = y_buff[index];
   } else {
     s[index+4] = ' ';
   }
 }
 for(index = 0; index < 4; index++) {

   s[index+8] = z_buff[index];
 }
}

