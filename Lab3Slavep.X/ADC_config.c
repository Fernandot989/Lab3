#define _XTAL_FREQ 4000000
#include "ADC_config.h"
#include <xc.h>

/**************************************************
 Funcion para configurar ADC
 ***************************************************/
void ADC_config (uint8_t channel){
    PORTA = 0;
    TRISA = 0;
    ANSEL = ANSEL | 0x00;
    ANSEL = ANSEL | 0x01;
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 = 1;
    
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;
    
    ADCON1bits.ADFM = 0;
    
    ADCON0bits.CHS = channel;
    
    ADCON0bits.ADON = 1;
    __delay_us(100);
}