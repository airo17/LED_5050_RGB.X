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

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


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

#include "mcc_generated_files/examples/i2c_master_example.h"
#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include <math.h>

#define BMP180_ADDRESS  0x77
#define REGISTER_MEASUREMENT_CONTROL    0xF4
#define COMANDO_START_MEASUREMENT_TEMPERATURE   0x2E
#define COMANDO_START_MEASUREMENT_PRESSURE      0x34
#define REGISTER_MSB    0xF6
#define REGISTER_LSB    0xF7
#define REGISTER_ID     0xD0

    
#define MODE_PRESSURE_ULTRA_LOW_POWER       0
#define MODE_PRESSURE_STANDARD              1
#define MODE_PRESSURE_HIGH_RESOLUTION       2
#define MODE_PRESSURE_ULTRA_HIGH_RESOLUTION 3 
    
#define BMP180_CHECK_DIVISOR    0
#define BMP180_INVALID_DATA     0
    
typedef struct{
    int16_t AC1;
    int16_t AC2;
    int16_t AC3;
    uint16_t AC4;
    uint16_t AC5;
    uint16_t AC6;
    int16_t B1;
    int16_t B2;
    int32_t B5;     // This value is calculate in the temperature function
    int16_t MB;
    int16_t MC;
    int16_t MD;
}calibration_data_BMP180;

typedef struct{
    int32_t temperature;
    int32_t pressure;
    calibration_data_BMP180 CALIBRATION_DATA;
}BMP_180;
    
calibration_data_BMP180 get_calibration_data_BMP180(void);
int32_t get_temperature_BMP180(void);
int32_t get_pressure_BMP180(uint8_t mode_oversampling_setting);
bool check_communication_BMP180(void);

//    /* ************************************************************************** */
//    /* ************************************************************************** */
//    /* Section: Constants                                                         */
//    /* ************************************************************************** */
//    /* ************************************************************************** */
//
//    /*  A brief description of a section can be given directly below the section
//        banner.
//     */
//
//
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
