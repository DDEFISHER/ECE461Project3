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
	int8_t *buffer;
} LcdObj, *LcdMsg;

Void LcDTask(UArg arg0, UArg arg1)
{

	LcdObj lcd_message;

	lcd_message.buffer = "012345678901";

	while(1) {

		//Semaphore_pend(lcd_draw_semaphore, BIOS_WAIT_FOREVER);// wait on semaphore from Timer ISR
		Mailbox_pend(ADC_Mbx, &lcd_message, BIOS_WAIT_FOREVER);// wait/block until post of msg, get msg.val


		write_lcd(lcd_message.buffer, 1);
	}


}
Void adcCalc(UArg arg0, UArg arg1)
{
    int8_t adc14_x[5] = "hello";

    LcdObj lcd_message;

    lcd_message.buffer = "012345678901";

	write_lcd(adc14_x, 3);
	while(1) {

		Semaphore_pend(adc_calc_semaphore, BIOS_WAIT_FOREVER);

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
    uint16_t x;
    uint16_t y;
    uint16_t z;

    MAP_Interrupt_disableInterrupt(INT_ADC14);
    status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);

    /* ADC_MEM2 conversion completed */
    if(status & ((uint32_t)0x00000004))
    {
        /* Store ADC14 conversion results */
        x = ADC14_getResult(ADC_MEM0);
        y = ADC14_getResult(ADC_MEM1);
        z = ADC14_getResult(ADC_MEM2);
        //P1OUT ^= BIT0;
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
    lcd_message.buffer = "012345678901";


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

    //send this char for handshaking with PC
    int8_t prompt = 65;

	Semaphore_pend(start_data_semaphore, BIOS_WAIT_FOREVER);	// wait on button semaphore

    UART_write(uart, &prompt, 1);



    while (1) {

      UART_read(uart, &input_x, 4);




    	//output[0] = (int8_t)input[0];
    	//output[1] = (int8_t)input[1];
      //write_lcd(input_x, 1);

      lcd_message.buffer = input_x;
      Mailbox_post(ADC_Mbx, &lcd_message, BIOS_WAIT_FOREVER);
      //Semaphore_post(lcd_draw_semaphore);
      MAP_Interrupt_enableInterrupt(INT_ADC14);

    }
}
