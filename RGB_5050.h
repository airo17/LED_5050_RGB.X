/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _RGB_5050_H    /* Guard against multiple inclusion */
#define _RGB_5050_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */

#include "mcc_generated_files/mcc.h"
#include <stdint.h>

#define PIN_HIGH    LATBbits.LATB5 = 1
#define PIN_LOW     LATBbits.LATB5 = 0
    
#define T0      PIN_HIGH;PIN_LOW;PIN_LOW;PIN_LOW
#define T1      PIN_HIGH;PIN_HIGH;PIN_HIGH;PIN_LOW
#define T_RST   PIN_HIGH;PIN_LOW;__delay_ms(200)

#define GREEN   0x00FF00
#define RED     0xFF0000
#define BLUE    0x0000FF
#define LED_OFF 0x000000    
    
typedef union {
    struct rgb {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    }RGB;
    uint32_t RGB_COLOR;
}color_led;
    
void set_led_color(uint8_t number_led, uint8_t green, uint8_t red, uint8_t blue);
void set_strip_led_color(uint8_t number_led, color_led *COLOR_LED);
//    /* ************************************************************************** */
//    /** Descriptive Constant Name
//
//      @Summary
//        Brief one-line summary of the constant.
//    
//      @Description
//        Full description, explaining the purpose and usage of the constant.
//        <p>
//        Additional description in consecutive paragraphs separated by HTML 
//        paragraph breaks, as necessary.
//        <p>
//        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
//    
//      @Remarks
//        Any additional remarks
//     */
//#define EXAMPLE_CONSTANT 0
//
//
//    // *****************************************************************************
//    // *****************************************************************************
//    // Section: Data Types
//    // *****************************************************************************
//    // *****************************************************************************
//
//    /*  A brief description of a section can be given directly below the section
//        banner.
//     */
//
//
//    // *****************************************************************************
//
//    /** Descriptive Data Type Name
//
//      @Summary
//        Brief one-line summary of the data type.
//    
//      @Description
//        Full description, explaining the purpose and usage of the data type.
//        <p>
//        Additional description in consecutive paragraphs separated by HTML 
//        paragraph breaks, as necessary.
//        <p>
//        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
//
//      @Remarks
//        Any additional remarks
//        <p>
//        Describe enumeration elements and structure and union members above each 
//        element or member.
//     */
//    typedef struct _example_struct_t {
//        /* Describe structure member. */
//        int some_number;
//
//        /* Describe structure member. */
//        bool some_flag;
//
//    } example_struct_t;
//
//
//    // *****************************************************************************
//    // *****************************************************************************
//    // Section: Interface Functions
//    // *****************************************************************************
//    // *****************************************************************************
//
//    /*  A brief description of a section can be given directly below the section
//        banner.
//     */
//
//    // *****************************************************************************
//    /**
//      @Function
//        int ExampleFunctionName ( int param1, int param2 ) 
//
//      @Summary
//        Brief one-line description of the function.
//
//      @Description
//        Full description, explaining the purpose and usage of the function.
//        <p>
//        Additional description in consecutive paragraphs separated by HTML 
//        paragraph breaks, as necessary.
//        <p>
//        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
//
//      @Precondition
//        List and describe any required preconditions. If there are no preconditions,
//        enter "None."
//
//      @Parameters
//        @param param1 Describe the first parameter to the function.
//    
//        @param param2 Describe the second parameter to the function.
//
//      @Returns
//        List (if feasible) and describe the return values of the function.
//        <ul>
//          <li>1   Indicates an error occurred
//          <li>0   Indicates an error did not occur
//        </ul>
//
//      @Remarks
//        Describe any special behavior not described above.
//        <p>
//        Any additional remarks.
//
//      @Example
//        @code
//        if(ExampleFunctionName(1, 2) == 0)
//        {
//            return 3;
//        }
//     */
//    int ExampleFunction(int param1, int param2);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
