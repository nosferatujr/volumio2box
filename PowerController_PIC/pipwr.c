/* 
 * File:   pipwr.c
 * Author: josep
 *
 * Created on 10 de febrero de 2016, 8:00
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config IOSCFS = 8MHZ    // Internal Oscillator Frequency Select (8 MHz)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)

#define TIMEOFF 15
#define PIPWR RA0
#define LCDPWR RA1
#define RPIHALT RA2
#define BTN RA3
#define LED RA5
#define OFF 0
#define ON 1
#define LON 0
#define LOFF 1

#define _XTAL_FREQ 8000000 // USADO PARA EL CALCULO DEL DELAY

    void parada();
    void marcha();
    void parant();

void main() {
    ANSEL=0;
    TRISA0=0; // SALIDA  PIPWR
    TRISA1=0; // SALIDA  LCDPWR
    TRISA2=0; // SALIDA  RPIHALT
    TRISA3=1; // ENTRADA  RESET
    TRISA4=1; // ENTRADA  BTN
    TRISA5=0; // SALIDA  LED
    
    while (1){
        parada();
        marcha();
        parant();

    }
}
void parada()
{
while (BTN==1){
    PIPWR=OFF;
    LCDPWR=OFF;
    RPIHALT=OFF;
    LED=LOFF;
    }
    return;
}
void marcha()
{
PIPWR=ON;
LCDPWR=ON;
RPIHALT=ON;
LED=LON;
__delay_ms(1000);
 while (BTN==1){

 }

    return;
}
void parant()
{int i;
    LCDPWR=OFF;
    RPIHALT=OFF;
    LED=LOFF;
    for (i=0;i<TIMEOFF;i++){
    __delay_ms(500);
    LED=LON;
    __delay_ms(500);
    LED=LOFF;
    }
    return;
}