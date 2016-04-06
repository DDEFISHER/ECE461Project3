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
#include "msp.h"
/* GrLib Includes */
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"


/* XDC module Headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/cfg/global.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

/* Example/Board Header files */
#include "Board.h"

#include <stdint.h>

#include "lcd_display.h"
#include "ped_adc.h"
#include "uart_task.h"

typedef struct LcdObj {
	int8_t buffer[12];
	int position;
} LcdObj;

typedef struct AdcObj {
    int x;
	int y;
	int z;
} AdcObj;

Void LcDTask(UArg arg0, UArg arg1)
{

	LcdObj lcd_message;

	int index = 0;
	for(index = 0; index < 12; index++) {
		lcd_message.buffer[index] = ' ';
	}

	lcd_message.position = 1;

	while(1) {

		Mailbox_pend(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);// wait/block until post of msg, get msg.val


		write_lcd(lcd_message.buffer, lcd_message.position);
	}
}

Void adcCalc(UArg arg0, UArg arg1)
{
	AdcObj adc_message;
	adc_message.x = 0;
	adc_message.y = 0;
	adc_message.z = 0;

	LcdObj lcd_message;
	int index = 0;
    for(index = 0; index < 12; index++) {
    		lcd_message.buffer[index] = ' ';
    }
    lcd_message.position = 3;



    int old_x = 1000;
    int old_y = 1000;
    int old_z = 1000;

    int new_x = 0;
    int new_y = 0;
    int new_z = 0;

	while(1) {

		Mailbox_pend(ADC_Mbx, &adc_message, BIOS_WAIT_FOREVER);

		new_x = adc_message.x;
		new_y = adc_message.y;
		new_z = adc_message.z;

		combine_ints_to_string(new_x - old_x, new_y - old_y, new_z-old_z, 12,lcd_message.buffer);
		lcd_message.position = 3;

		old_x = adc_message.x;
		old_y = adc_message.y;
		old_z = adc_message.z;
		Mailbox_post(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);
	}
}

int main(void)
{
    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Board_initUART();
    init_clocks();
    init_lcd();
    init_adc();

    /* Turn on user LED */
    //GPIO_write(Board_LED0, Board_LED_ON);
    //GPIO_write(Board_LED1, Board_LED_ON);

    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
//Hwi to handle adc14 interript
void ADC14_IRQHandler(void)
{
    uint64_t status;

    AdcObj adc_message;
    adc_message.x = 0;
    adc_message.y = 0;
    adc_message.z = 0;

    MAP_Interrupt_disableInterrupt(INT_ADC14);
    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ((uint32_t)0x00000004))
    {
        /* Store ADC14 conversion results */
        adc_message.x = ADC14_getResult(ADC_MEM0);
        adc_message.y = ADC14_getResult(ADC_MEM1);
        adc_message.z = ADC14_getResult(ADC_MEM2);

        Mailbox_post(ADC_Mbx, &adc_message, BIOS_WAIT_FOREVER);
    }

}
// Idle function that starts uart capture and adc capture
void start_button()
{
	if ((P1IN & BIT4) == 0) {
		P2OUT |= BIT1;
		Semaphore_post(start_data_semaphore);// unbock uart
	}

}

Void echoFxn(UArg arg0, UArg arg1)
{
    int8_t input_x[] = "      ";
    int8_t input_y[] = "      ";

    LcdObj lcd_message;
    int index = 0;
    for(index = 0; index < 12; index++) {
    	lcd_message.buffer[index] = ' ';
    }

    lcd_message.position = 1;


    UART_Handle uart;
    UART_Params uartParams;

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;
    uart = UART_open(Board_UART0, &uartParams);

    if (uart == NULL) {
        System_abort("Error opening the UART");
    }

    Semaphore_pend(start_data_semaphore, BIOS_WAIT_FOREVER);	// wait on button semaphore

    //send this char for handshaking with PC
    int8_t prompt = 65;

    UART_write(uart, &prompt, 1);



    while (1) {

      UART_read(uart, &input_x, 4);

      //give lcd mail box buffer the input
      lcd_message.buffer[0] = input_x[0];
      lcd_message.buffer[1] = input_x[1];
      lcd_message.buffer[2] = input_x[2];
      lcd_message.buffer[3] = input_x[3];
      lcd_message.position = 1;

      Mailbox_post(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);
      MAP_Interrupt_enableInterrupt(INT_ADC14);
    }
}
