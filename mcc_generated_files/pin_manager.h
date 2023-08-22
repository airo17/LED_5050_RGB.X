/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1937
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set LED_STATUS aliases
#define LED_STATUS_TRIS                 TRISBbits.TRISB4
#define LED_STATUS_LAT                  LATBbits.LATB4
#define LED_STATUS_PORT                 PORTBbits.RB4
#define LED_STATUS_WPU                  WPUBbits.WPUB4
#define LED_STATUS_ANS                  ANSELBbits.ANSB4
#define LED_STATUS_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_STATUS_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_STATUS_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED_STATUS_GetValue()           PORTBbits.RB4
#define LED_STATUS_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_STATUS_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_STATUS_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_STATUS_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_STATUS_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED_STATUS_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set PIN_LEDS aliases
#define PIN_LEDS_TRIS                 TRISBbits.TRISB5
#define PIN_LEDS_LAT                  LATBbits.LATB5
#define PIN_LEDS_PORT                 PORTBbits.RB5
#define PIN_LEDS_WPU                  WPUBbits.WPUB5
#define PIN_LEDS_ANS                  ANSELBbits.ANSB5
#define PIN_LEDS_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define PIN_LEDS_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define PIN_LEDS_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define PIN_LEDS_GetValue()           PORTBbits.RB5
#define PIN_LEDS_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define PIN_LEDS_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define PIN_LEDS_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define PIN_LEDS_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define PIN_LEDS_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define PIN_LEDS_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/