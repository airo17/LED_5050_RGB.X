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

#ifndef _BH_1750_H    /* Guard against multiple inclusion */
#define _BH_1750_H


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

#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "mcc_generated_files/mcc.h"
    
//#define BH1750_ADDRESS  0x5C // Address if terminal ADDR = ?H? ADDR ? 0.7VCC
#define BH1750_ADDRESS  0x0023 // Address if terminal ADDR = 'L' ADDR ? 0.3VCC
    
#define COMAND_POWER_DOWN 0b00000000
#define COMAND_POWER_ON 0b00000001
#define COMAND_RESET    0b00000111
#define COMAND_C_H_RESOLUTION_MODE 0b00010000  // Continuously H-Resolution Mode Measurement Time is typically 120ms. Resolution 1 lx
#define COMAND_C_H_RESOLUTION_MODE2 0b00010001  // Continuously H-Resolution Mode2 Measurement Time is typically 120ms. Resolution .5 lx
#define COMAND_C_L_RESOLUTION_MODE 0b00010011   // Continuously L-Resolution Mode Measurement Time is typically 16. Resolution 4 lx
#define COMAND_OT_H_RESOLUTION_MODE 0b00100000  // One Time H-Resolution Mode Measurement Time is typically 120ms. Resolution 1 lx  It is automatically set to Power Down mode after measurement.
#define COMAND_OT_H_RESOLUTION_MODE2 0b00100001  // One Time H-Resolution Mode2 Measurement Time is typically 120ms. Resolution .5 lx It is automatically set to Power Down mode after measurement.
#define COMAND_OT_L_RESOLUTION_MODE 0b00100011   // One Time L-Resolution Mode Measurement Time is typically 16. Resolution 4 lx It is automatically set to Power Down mode after measurement.
    
void power_on_BH1750(void);
void power_down_BH1750(void);
void reset_BH1750(void);
void continuously_H_resolution_Mode_BH1750(void);
void continuously_H_resolution_Mode2_BH1750(void);
void continuously_L_resolution_Mode_BH1750(void);
void one_time_H_resolution_Mode_BH1750(bool power_on_first);
void one_time_H_resolution_Mode2_BH1750(bool power_on_first);
void one_time_L_resolution_Mode_BH1750(bool power_on_first);
uint16_t read_result_BH1750(void);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
