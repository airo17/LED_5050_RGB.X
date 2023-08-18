/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "BMP_180.h"

static BMP_180 BMP180;

calibration_data_BMP180 get_calibration_data_BMP180(void){
    uint8_t buffer_I2C[23] = {0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    SERCOM0_I2C_WriteRead(BMP180_ADDRESS, &buffer_I2C[0], 1, &buffer_I2C[1], 22);

    while(SERCOM0_I2C_IsBusy());
    
    BMP180.CALIBRATION_DATA.AC1 = (buffer_I2C[1] << 8) | buffer_I2C[2];
    BMP180.CALIBRATION_DATA.AC2 = (buffer_I2C[3] << 8) | buffer_I2C[4];
    BMP180.CALIBRATION_DATA.AC3 = (buffer_I2C[5] << 8) | buffer_I2C[6];
    BMP180.CALIBRATION_DATA.AC4 = (buffer_I2C[7] << 8) | buffer_I2C[8];
    BMP180.CALIBRATION_DATA.AC5 = (buffer_I2C[9] << 8) | buffer_I2C[10];
    BMP180.CALIBRATION_DATA.AC6 = (buffer_I2C[11] << 8) | buffer_I2C[12];
    BMP180.CALIBRATION_DATA.B1 = (buffer_I2C[13] << 8) | buffer_I2C[14];
    BMP180.CALIBRATION_DATA.B2 = (buffer_I2C[15] << 8) | buffer_I2C[16];
    BMP180.CALIBRATION_DATA.MB = (buffer_I2C[17] << 8) | buffer_I2C[18];
    BMP180.CALIBRATION_DATA.MC = (buffer_I2C[19] << 8) | buffer_I2C[20];
    BMP180.CALIBRATION_DATA.MD = (buffer_I2C[21] << 8) | buffer_I2C[22];
    
    return BMP180.CALIBRATION_DATA;
}

int32_t get_temperature_BMP180(void){
    int32_t x1 = 0;
    int32_t x2 = 0;
    int32_t t = 0;
    int32_t uncompensated_temperature = 0;
    uint8_t buffer_I2C[5] = {REGISTER_MEASUREMENT_CONTROL, COMANDO_START_MEASUREMENT_TEMPERATURE, REGISTER_MSB, 0x00, 0x00};
    
    SERCOM0_I2C_Write(BMP180_ADDRESS, &buffer_I2C[0], 2);
    for(uint32_t i = 0; i < 1000000; i++);
    SERCOM0_I2C_WriteRead(BMP180_ADDRESS, &buffer_I2C[2], 1, &buffer_I2C[3], 2);
    while(SERCOM0_I2C_IsBusy());
    
    uncompensated_temperature = (buffer_I2C[3] << 8) | buffer_I2C[4];
    
    x1 = ((uncompensated_temperature - BMP180.CALIBRATION_DATA.AC6) * BMP180.CALIBRATION_DATA.AC5) >> 15;
    
    if ((x1 == BMP180_CHECK_DIVISOR) && (BMP180.CALIBRATION_DATA.MD == BMP180_CHECK_DIVISOR))
    {
        return BMP180_INVALID_DATA;
    }
    
    x2 = (BMP180.CALIBRATION_DATA.MC << 11) / (x1 + BMP180.CALIBRATION_DATA.MD);
    BMP180.CALIBRATION_DATA.B5 = x1 + x2;
    t = (BMP180.CALIBRATION_DATA.B5 + 8) >> 4;
    
    return t;
}

int32_t get_pressure_BMP180(uint8_t mode_oversampling_setting){
    int32_t b6 = 0;
    int32_t x1 = 0;
    int32_t x2 = 0;
    int32_t x3 = 0;
    int32_t b3 = 0;
    uint32_t b4 = 0;
    uint32_t b7 = 0;
    int32_t uncompensated_pressure = 0;
    int32_t p = 0;
    uint8_t buffer_I2C[6] = {REGISTER_MEASUREMENT_CONTROL, (COMANDO_START_MEASUREMENT_PRESSURE + (mode_oversampling_setting << 6)),
                             REGISTER_MSB, 0x00, 0x00};
    
    SERCOM0_I2C_Write(BMP180_ADDRESS, &buffer_I2C[0], 2);
    for(uint32_t i = 0; i < 1000000; i++);
    SERCOM0_I2C_WriteRead(BMP180_ADDRESS, &buffer_I2C[2], 1, &buffer_I2C[3], 3);
    while(SERCOM0_I2C_IsBusy());
    
    uncompensated_pressure = ((buffer_I2C[3] << 16) | (buffer_I2C[4] << 8) | buffer_I2C[5]) >> (8 - mode_oversampling_setting);
    
    b6 = BMP180.CALIBRATION_DATA.B5 - 4000;
    x1 = (BMP180.CALIBRATION_DATA.B2 * ((b6 * b6) >> 12)) >> 11;
    x2 = (BMP180.CALIBRATION_DATA.AC2 * b6) >> 11;
    x3 = x1 + x2;
    b3 = (((BMP180.CALIBRATION_DATA.AC1 * 4 + x3) << mode_oversampling_setting) + 2) >> 2;
    x1 = (BMP180.CALIBRATION_DATA.AC3 * b6) >> 13;
    x2 = (BMP180.CALIBRATION_DATA.B1 * ((b6 * b6) >> 12)) >> 16;
    x3 = ((x1 + x2) + 2) >> 2;
    b4 = BMP180.CALIBRATION_DATA.AC4 * ((uint32_t)(x3 + 32768)) >> 15;
//    b7 = ((uint32_t)(uncompensated_pressure - b3)) * (50000 >> mode_oversampling_setting);
    
    if((b3 > uncompensated_pressure) && (b3 > 0)){
        b7 = (b3 - uncompensated_pressure) * (50000 >> mode_oversampling_setting);
    }
    else{
        b7 = (uncompensated_pressure - b3) * (50000 >> mode_oversampling_setting);
    }
    
    if(b7 < 0x80000000){
        p = (b7 << 1) / b4;
    }
    else{
        p = (b7 / b4) << 1;
    }
    
    x1 = (p >> 8) * (p >> 8);
    x1 = (x1 * 3038) >> 16;
    x2 = (-7357 * p) >> 16;
    p = p + ((x1 + x2 + 3791) >> 4);
    
    return p;
}

bool check_communication_BMP180(void){
    uint8_t buffer_I2C[2] = {REGISTER_ID, 0x00};
    
    SERCOM0_I2C_WriteRead(BMP180_ADDRESS, &buffer_I2C[0], 1, &buffer_I2C[1], 1);
    while(SERCOM0_I2C_IsBusy());
    
    if(buffer_I2C[1] == 0x55){
        return true;
    }
    else{
        return false;
    }
}

///* This section lists the other files that are included in this file.
// */
//
///* TODO:  Include other files here if needed. */
//
//
///* ************************************************************************** */
///* ************************************************************************** */
///* Section: File Scope or Global Data                                         */
///* ************************************************************************** */
///* ************************************************************************** */
//
///*  A brief description of a section can be given directly below the section
//    banner.
// */
//
///* ************************************************************************** */
///** Descriptive Data Item Name
//
//  @Summary
//    Brief one-line summary of the data item.
//    
//  @Description
//    Full description, explaining the purpose and usage of data item.
//    <p>
//    Additional description in consecutive paragraphs separated by HTML 
//    paragraph breaks, as necessary.
//    <p>
//    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
//    
//  @Remarks
//    Any additional remarks
// */
//int global_data;
//
//
///* ************************************************************************** */
///* ************************************************************************** */
//// Section: Local Functions                                                   */
///* ************************************************************************** */
///* ************************************************************************** */
//
///*  A brief description of a section can be given directly below the section
//    banner.
// */
//
///* ************************************************************************** */
//
///** 
//  @Function
//    int ExampleLocalFunctionName ( int param1, int param2 ) 
//
//  @Summary
//    Brief one-line description of the function.
//
//  @Description
//    Full description, explaining the purpose and usage of the function.
//    <p>
//    Additional description in consecutive paragraphs separated by HTML 
//    paragraph breaks, as necessary.
//    <p>
//    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
//
//  @Precondition
//    List and describe any required preconditions. If there are no preconditions,
//    enter "None."
//
//  @Parameters
//    @param param1 Describe the first parameter to the function.
//    
//    @param param2 Describe the second parameter to the function.
//
//  @Returns
//    List (if feasible) and describe the return values of the function.
//    <ul>
//      <li>1   Indicates an error occurred
//      <li>0   Indicates an error did not occur
//    </ul>
//
//  @Remarks
//    Describe any special behavior not described above.
//    <p>
//    Any additional remarks.
//
//  @Example
//    @code
//    if(ExampleFunctionName(1, 2) == 0)
//    {
//        return 3;
//    }
// */
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}
//
//
///* ************************************************************************** */
///* ************************************************************************** */
//// Section: Interface Functions                                               */
///* ************************************************************************** */
///* ************************************************************************** */
//
///*  A brief description of a section can be given directly below the section
//    banner.
// */
//
//// *****************************************************************************
//
///** 
//  @Function
//    int ExampleInterfaceFunctionName ( int param1, int param2 ) 
//
//  @Summary
//    Brief one-line description of the function.
//
//  @Remarks
//    Refer to the example_file.h interface header for function usage details.
// */
//int ExampleInterfaceFunction(int param1, int param2) {
//    return 0;
//}


/* *****************************************************************************
 End of File
 */
