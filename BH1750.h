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
#include "peripheral/sercom/i2c_master/plib_sercom0_i2c_master.h"
    
//#define BH1750_ADDRESS  0x5C // Address if terminal ADDR = ?H? ADDR ? 0.7VCC
#define BH1750_ADDRESS  0x0023 // Address if terminal ADDR = 'L' ADDR ? 0.3VCC
    
#define COMAND_POWER_ON 0b00000001    
#define COMAND_C_H_RESOLUTION_MODE 0b00010000  // Continuously H-Resolution Mode Measurement Time is typically 120ms.
#define COMAND_C_H_RESOLUTION_MODE2 0b00010001  // Continuously H-Resolution Mode2 Measurement Time is typically 120ms.
    
bool power_on_BH1750(void);
bool continuously_H_resolution_Mode2_BH1750(void);
uint16_t read_result_BH1750(void);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
