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
 *  ======== main.c ========
 */
#include "driverlib.h"
#include "msp.h"

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

typedef struct LcdObj {
	int8_t buffer[15];
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
	 for(index = 0; index < 15; index++) {
	    	lcd_message.buffer[index] = ' ';
	 }
	 lcd_message.position = 1;

	while(1) {

		Mailbox_pend(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);// wait/block until post of msg, get msg.val

		int8_t buff[15] = "            ";

		int loop_index = 0;

		for(loop_index = 0; loop_index < 15; loop_index++) {

			buff[loop_index] = lcd_message.buffer[loop_index];
		}
		int position = lcd_message.position;
    write_lcd(buff,position);

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
    for(index = 0; index < 15; index++) {
        lcd_message.buffer[index] = ' ';
    }
    lcd_message.position = 3;


    int old_diffs_x[50];
    int old_diffs_y[50];
    int old_diffs_z[50];

    for(index = 0; index < 50; index++) {

        old_diffs_x[index] = 1000;
        old_diffs_y[index] = 1000;
        old_diffs_z[index] = 1000;
    }
    int old_x = 0;
    int old_y = 0;
    int old_z = 0;

    int new_x = 0;
    int new_y = 0;
    int new_z = 0;

    int average_x = 0;
    int average_y = 0;
    int average_z = 0;
    int counter = 0;
    int loop_index = 0;

    while(1) {

      Mailbox_pend(ADC_Mbx, &adc_message, BIOS_WAIT_FOREVER);


      new_x = adc_message.x;
      new_y = adc_message.y;
      new_z = adc_message.z;

      if((old_x - new_x) > 0 ) {

        old_diffs_x[counter] = old_x - new_x;
      } else {
        old_diffs_x[counter] = new_x - old_x;
      }
      if((old_y - new_y) > 0 ) {

        old_diffs_y[counter] = old_y - new_y;
      } else {
        old_diffs_x[counter] = new_y - old_y;
      }
      if((old_z - new_z) > 0 ) {

        old_diffs_z[counter] = old_z - new_z;
      } else {
        old_diffs_z[counter] = new_z - old_z;
      }

      old_x = new_x;
      old_y = new_y;
      old_z = new_z;


      counter++;

      if(counter > 49) {

          int sum_x = 0;
          int sum_y = 0;
          int sum_z = 0;

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_x = sum_x + old_diffs_x[loop_index];

          }
          average_x = sum_x/(counter+1);

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_y = sum_y + old_diffs_y[loop_index];

          }

          average_y = sum_y/(counter+1);

          for(loop_index = 0; loop_index < counter; loop_index++) {

            sum_z = sum_z + old_diffs_z[loop_index];

          }

          average_z = sum_z/(counter+1);

          int index = 0;
          for(index = 0; index < 15; index++) {
              lcd_message.buffer[index] = ' ';
            }

          combine_ints_to_string(average_x, average_y, average_z, 12,lcd_message.buffer);
          counter = 0;
          lcd_message.position = 3;
          Mailbox_post(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);
      }


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
        adc_message.z = ADC14_getResult(ADC_MEM2);

        Mailbox_post(ADC_Mbx, &adc_message, BIOS_WAIT_FOREVER);
    }

}
// Idle function that starts uart capture and adc capture
void start_button()
{
	if ((P1IN & BIT4) == 0) {
    P1OUT &= ~BIT0;
		P2OUT |= BIT1;
		Semaphore_post(start_data_semaphore);// unbock uart
	}

}

Void uartFxn(UArg arg0, UArg arg1)
{
    int8_t input[] = "               ";

    LcdObj lcd_message;
    int index = 0;
    for(index = 0; index < 15; index++) {
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

    int total_x = 0;
    int total_y = 0;
    int total_z = 0;

    int average_x = 0;
    int average_y = 0;
    int average_z = 0;

    int counter = 0;

    int rx = 0;

    while (1) {

      UART_read(uart, &input, 2);

      if(input[0] == '$' && input[1] == '$') {
        P2OUT &= ~BIT1;
        P1OUT |= BIT0;
        BIOS_exit(1);
      }
      rx = (int)input[1];

      if(input[0] == '-') {
        rx = 0 - rx; 
      }

      total_x = total_x + rx;

      UART_read(uart, &input, 2);

      if(input[0] == '$' && input[1] == '$') {
        P2OUT &= ~BIT1;
        P1OUT |= BIT0;
        BIOS_exit(1);
      }
      rx = (int)input[1];

      if(input[0] == '-') {
        rx = 0 - rx; 
      }

      total_y = total_y + rx;

      UART_read(uart, &input, 2);

      if(input[0] == '$' && input[1] == '$') {
        P2OUT &= ~BIT1;
        P1OUT |= BIT0;
        BIOS_exit(1);
      }
      rx = (int)input[1];

      if(input[0] == '-') {
        rx = 0 - rx; 
      }

      total_z = total_z + rx;
      /*
      if((counter % 3) == 0) {
      total_x = total_x + rx;
      } else if ((counter % 3) == 1) {
      total_y = total_y + rx;
      } else {
      total_z = total_z + rx;
      }*/

      counter++;

      if(counter > 50) {


          average_x = total_x/counter;
          average_y = total_y/counter;
          average_z = total_z/counter;
          combine_ints_to_string(average_x, average_y, average_z, 15,lcd_message.buffer);
          counter = 0;
          total_x = 0;
          total_y = 0;
          total_z = 0;

          lcd_message.position = 1;
          Mailbox_post(LCD_Mbx, &lcd_message, BIOS_WAIT_FOREVER);
      }
        MAP_Interrupt_enableInterrupt(INT_ADC14);
  }
}
