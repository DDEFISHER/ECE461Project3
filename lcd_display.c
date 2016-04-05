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
