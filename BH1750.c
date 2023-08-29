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

void power_on_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_POWER_ON, 1);
}

void power_down_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_POWER_DOWN, 1);
}

void reset_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_POWER_RESET, 1);
}

void continuously_H_resolution_Mode_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_C_H_RESOLUTION_MODE, 1);
}

void continuously_H_resolution_Mode2_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_C_H_RESOLUTION_MODE2, 1);
}

void continuously_L_resolution_Mode_BH1750(void){
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_C_L_RESOLUTION_MODE, 1);
}

void one_time_H_resolution_Mode_BH1750(bool power_on_first){
    if(power_on_first){
        power_on_BH1750();
    }
    
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_OT_H_RESOLUTION_MODE, 1);
}

void one_time_H_resolution_Mode2_BH1750(bool power_on_first){
    if(power_on_first){
        power_on_BH1750();
    }
    
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_OT_H_RESOLUTION_MODE2, 1);
}

void one_time_L_resolution_Mode_BH1750(bool power_on_first){
    if(power_on_first){
        power_on_BH1750();
    }
    
    I2C_WriteNBytes(BH1750_ADDRESS, COMAND_OT_L_RESOLUTION_MODE, 1);
}

uint16_t read_result_BH1750(void){
    uint8_t result[2] = {0};
    
    I2C_ReadNBytes(BH1750_ADDRESS, &result[0], 2);
    
    return ((result[0] << 8) | result[1]) / 1.2;
}

/* *****************************************************************************
 End of File
 */
