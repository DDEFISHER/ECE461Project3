/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== uartecho.c ========
 */
#include "driverlib.h"
/* GrLib Includes */
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

/* Example/Board Header files */
#include "Board.h"

#include <stdint.h>

#include "msp.h"

#define TASKSTACKSIZE     768

Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];
/* Graphic library context */
Graphics_Context g_sContext;

/* ADC results buffer */
static uint16_t resultsBuffer[3];

/*
 *  ======== echoFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 */
Void echoFxn(UArg arg0, UArg arg1)
{


    int8_t input_x[] = "      ";
    int8_t input_y[] = "      ";
    int8_t input_z[] = "      ";

    UART_Handle uart;
    UART_Params uartParams;
    //const char echoPrompt[] = "\fEchoing characters:\r\n";

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 115200;
    uart = UART_open(Board_UART0, &uartParams);

    if (uart == NULL) {
        System_abort("Error opening the UART");
    }

    //UART_write(uart, echoPrompt, sizeof(echoPrompt));



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

    while (1) {

      UART_read(uart, &input_x, 4);
      //UART_read(uart, &input_y, 6);
      //UART_read(uart, &input_z, 6);

      

    	//output[0] = (int8_t)input[0];
    	//output[1] = (int8_t)input[1];

      Graphics_drawStringCentered(&g_sContext,
                                  &input_x,
                                  AUTO_STRING_LENGTH,
                                  64,
                                  40,
                                  OPAQUE_TEXT);
     /* Graphics_drawStringCentered(&g_sContext,
                                  &input_y,
                                  AUTO_STRING_LENGTH,
                                  64,
                                  50,
                                  OPAQUE_TEXT);
      Graphics_drawStringCentered(&g_sContext,
                                  &input_z,
                                  AUTO_STRING_LENGTH,
                                  64,
                                  60,
                                  OPAQUE_TEXT);*/

    }
}
void init_adc()
{
    /* Configures Pin 4.0, 4.2, and 6.1 as ADC input */
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN0 | GPIO_PIN2, GPIO_TERTIARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN1, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Initializing ADC (ADCOSC/64/8) */
    MAP_ADC14_enableModule();
    MAP_ADC14_initModule(((uint32_t)0x00000000), ((uint32_t)0xC0000000) , ((uint32_t)0x01C00000),
            0);

    /* Configuring ADC Memory (ADC_MEM0 - ADC_MEM2 (A11, A13, A14)  with no repeat)
         * with internal 2.5v reference */
    MAP_ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM2, true);
    MAP_ADC14_configureConversionMemory(ADC_MEM0,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000E), ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM1,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000D), ADC_NONDIFFERENTIAL_INPUTS);

    MAP_ADC14_configureConversionMemory(ADC_MEM2,
    		((uint32_t)0x00000000),
			((uint32_t)0x0000000B), ADC_NONDIFFERENTIAL_INPUTS);

    /* Enabling the interrupt when a conversion on channel 2 (end of sequence)
     *  is complete and enabling conversions */
    MAP_ADC14_enableInterrupt(((uint32_t)0x00000004) );

    /* Enabling Interrupts */
    MAP_Interrupt_enableInterrupt(INT_ADC14);
    MAP_Interrupt_enableMaster();

    /* Setting up the sample timer to automatically step through the sequence
     * convert.
     */
    MAP_ADC14_enableSampleTimer(((uint32_t)0x00000080));

    /* Triggering the start of the sample */
    MAP_ADC14_enableConversion();
    MAP_ADC14_toggleConversionTrigger();
}
void init_clocks()
{
	/* Initializes Clock System */
	MAP_CS_setDCOCenteredFrequency((0x00030000));
	MAP_CS_initClockSignal((0x00000002), (0x00000003), (0x00000000));
	MAP_CS_initClockSignal((0x00000004), (0x00000003), (0x00000000));
	MAP_CS_initClockSignal((0x00000008), (0x00000003), (0x00000000));
	MAP_CS_initClockSignal((0x00000001), (0x00000002), (0x00000000));
}
/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Board_initUART();
    init_clocks();
    init_adc();

    /* Construct BIOS objects */
    Task_Params taskParams;

    Task_Params_init(&taskParams);
    taskParams.stackSize = TASKSTACKSIZE;
    taskParams.stack = &task0Stack;
    taskParams.instance->name = "echo";
    Task_construct(&task0Struct, (Task_FuncPtr)echoFxn, &taskParams, NULL);


    /* Turn on user LED */
    GPIO_write(Board_LED0, Board_LED_ON);
    GPIO_write(Board_LED1, Board_LED_ON);

    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
/* This interrupt is fired whenever a conversion is completed and placed in
 * ADC_MEM2. This signals the end of conversion and the results array is
 * grabbed and placed in resultsBuffer */
void show_adc14_info() {


}
void ADC14_IRQHandler(void)
{
    uint64_t status;

    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ((uint32_t)0x00000004))
    {
        /* Store ADC14 conversion results */
        resultsBuffer[0] = ADC14_getResult(ADC_MEM0);
        resultsBuffer[1] = ADC14_getResult(ADC_MEM1);
        resultsBuffer[2] = ADC14_getResult(ADC_MEM2);

        int8_t adc14_x[] = "  ";
/*
        if(resultsBuffer[0] > 12000) {
        	adc14_x[1] = '1';
        } else if(resultsBuffer[0] < 10000) {
        	adc14_x[1] = '0';
        } else {
        	adc14_x[1] = '5';
        	adc14_x[0] = '.';
        }

        Graphics_drawStringCentered(&g_sContext,
                                          &adc14_x,
                                          AUTO_STRING_LENGTH,
                                          64,
                                          40,
                                          OPAQUE_TEXT);
*/

    }

}
