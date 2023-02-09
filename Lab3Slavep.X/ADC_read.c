#define _XTAL_FREQ 4000000
#include "ADC_read.h"
#include <xc.h>

void ADC_config (uint8_t channel);
/**************************************************
 Funcion para configurar ADC
 ***************************************************/
uint16_t ADC_read (uint8_t channel) {   
    uint16_t ADC;
    ADC_config (channel);
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO == 1){;}
    ADIF = 0;
    ADC = ADRESH;
    return ADC;
}