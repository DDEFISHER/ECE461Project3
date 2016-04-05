/*
 * uart_task.c
 *
 *  Created on: Apr 4, 2016
 *      Author: daniel
 */
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

#include "driverlib.h"

/* Example/Board Header files */
#include "Board.h"

#include <stdint.h>

Void echoFxn(UArg arg0, UArg arg1)
{
    int8_t input_x[] = "      ";
    int8_t input_y[] = "      ";


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

    int8_t prompt = 65;

	Semaphore_pend(start_data_semaphore, BIOS_WAIT_FOREVER);	// wait on button semaphore

    UART_write(uart, &prompt, 1);



    while (1) {

      UART_read(uart, &input_x, 4);
      //UART_read(uart, &input_y, 6);
      //UART_read(uart, &input_z, 6);



    	//output[0] = (int8_t)input[0];
    	//output[1] = (int8_t)input[1];
      write_lcd(input_x, 1);

      MAP_Interrupt_enableInterrupt(INT_ADC14);

    }
}
