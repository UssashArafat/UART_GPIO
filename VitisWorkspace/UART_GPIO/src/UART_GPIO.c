/*******************************************************************************************
* Author:	Ussash Arafat
* Project:	UART_GPIO_Zedboard
* File:		UART_GPIO.c
* Tools:  	Vivado 2020.2
*           Xilinx Vitis 2020.2
* Device: 	Zedboard
********************************************************************************************/
#include "xparameters.h"
#include "xgpio.h"
XGpio dipSwitch, pushButton, led;
int main (void)
{
	//declare variables here
	volatile int DELAY;
    int status0, status1, status2;
    int switchValue;
    int buttonValue;
    //Initialization using function XGpio_Initialize for dip switches
    status0 = XGpio_Initialize(&dipSwitch, XPAR_AXI_GPIO_0_DEVICE_ID);
    //Setting data direction using function XGpio_SetDataDirection for dip switches
    XGpio_SetDataDirection(&dipSwitch, 1, 0xFF);
    //Initialization using function XGpio_Initialize for push buttons
    status1 = XGpio_Initialize(&pushButton, XPAR_AXI_GPIO_1_DEVICE_ID);
    //Setting data direction using function XGpio_SetDataDirection for push buttons
    XGpio_SetDataDirection(&pushButton, 1, 0x1F);
    //Initialization using function XGpio_Initialize for leds
    status2 = XGpio_Initialize(&led, XPAR_AXI_GPIO_0_DEVICE_ID);
    //Setting data direction using function XGpio_SetDataDirection for leds
    XGpio_SetDataDirection(&led, 2, 0x00);
    //Constantly read the push button and dip switches values
    while(1){
        switchValue = XGpio_DiscreteRead(&dipSwitch, 1);
        buttonValue = XGpio_DiscreteRead(&pushButton, 1);
        XGpio_DiscreteWrite(&led, 2, switchValue);
    //write the output to the terminal
        xil_printf ("SWITCH --> %d\r\n", switchValue);
        xil_printf("BUTTON --> %d\r\n", buttonValue);
        xil_printf("\r\n");
    //Delay between each pair of the write function
        for(DELAY=0; DELAY<40000000; DELAY++);
    }
}
