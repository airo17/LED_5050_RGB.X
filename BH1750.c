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

/* This section lists the other files that are included in this file.
 */
#include "BH1750.h"

bool power_on_BH1750(void){
    uint8_t comand = COMAND_POWER_ON;
    bool flag_conect = false;
    
    flag_conect = SERCOM0_I2C_Write(BH1750_ADDRESS, &comand, 1);

    while(SERCOM0_I2C_IsBusy());
    
    return flag_conect;
}

bool continuously_H_resolution_Mode2_BH1750(void){
    uint8_t comand = COMAND_C_H_RESOLUTION_MODE2;
    bool flag_conect = false;
    
    flag_conect = SERCOM0_I2C_Write(BH1750_ADDRESS, &comand, 1);

    while(SERCOM0_I2C_IsBusy());
    
    return flag_conect;
}

uint16_t read_result_BH1750(void){
    uint8_t result[2] = {0};
    
    SERCOM0_I2C_Read(BH1750_ADDRESS, &result[0], 2);

    while(SERCOM0_I2C_IsBusy());
    
    return ((result[0] << 8) | result[1]) / 1.2;
}

/* *****************************************************************************
 End of File
 */
