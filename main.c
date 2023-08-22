/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1937
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "RGB_5050.h"
#include "BMP_180.h"

color_led COLOR_LED[16];
bool status_communication = false;
BMP_180 DATA_BMP_180;
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    __delay_ms(1000);
    LATBbits.LATB4 = 1;
    
//    COLOR_LED[0].RGB.red = 255;
//    COLOR_LED[1].RGB.red = 255;
//    COLOR_LED[2].RGB.red = 255;
    COLOR_LED[3].rgb_color = 0xFFFFFF;
//    COLOR_LED[4].RGB.red = 255;
//    COLOR_LED[5].RGB.green = 255;
//    COLOR_LED[6].RGB.green = 255;
    COLOR_LED[7].rgb_color = 0xFFFFFF;
//    COLOR_LED[8].RGB.green = 255;
//    COLOR_LED[9].RGB.green = 255;
//    COLOR_LED[10].RGB.green = 255;
    COLOR_LED[11].rgb_color = 0xFFFFFF;
//    COLOR_LED[12].RGB.blue = 255;
//    COLOR_LED[13].RGB.blue = 255;
//    COLOR_LED[14].RGB.blue = 255;
    COLOR_LED[15].rgb_color = 0xFFFFFF;
//    
    set_strip_led_color(16, COLOR_LED);
    
//    set_led_color(16, 0, 0, 0);
    
    DATA_BMP_180.CALIBRATION_DATA = get_calibration_data_BMP180();
    
    while (1)
    {
//        status_communication = check_communication_BMP180();
//        if(status_communication){
//            set_led_color(1, 0, 255, 0);
//        }
        
        DATA_BMP_180.temperature = get_temperature_BMP180();
        __delay_ms(5000);
//        LATBbits.LATB5 = 1;
//        LATBbits.LATB5 = 0;
    }
}
/**
 End of File
*/