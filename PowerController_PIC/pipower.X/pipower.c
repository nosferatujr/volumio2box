/*
 * File:   pipwr.c
 * Author: josep
 *
 * Created on 10 de febrero de 2016, 8:00
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF
        // Code Protection bit (Program memory code protection is disabled)
//#pragma config IOSCFS = 8MHZ    // Internal Oscillator Frequency Select (8 MHz)


#define TIMEOFF 15
#define PIPWR GP0
#define LCDPWR GP1
#define RPIHALT GP2
#define BTN GP3
#define LED GP5
#define OFF 0
#define ON 1
#define LON 0
#define LOFF 1

#define _XTAL_FREQ 8000000 // USADO PARA EL CALCULO DEL DELAY

    void parada();
    void marcha();
    void parant();

void main() {
   // ANSEL=0;
    CMCON=0x07;
    TRISIO0=0; // SALIDA  PIPWR
    TRISIO1=0; // SALIDA  LCDPWR
    TRISIO2=0; // SALIDA  RPIHALT
    TRISIO3=1; // ENTRADA  RESET
    TRISIO4=0; // ENTRADA  BTN
    TRISIO5=0; // SALIDA  LED

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
    RPIHALT=LON;
    LED=LOFF;
    }
    return;
}
void marcha()
{
PIPWR=ON;
LCDPWR=ON;
RPIHALT=LON;
LED=LON;
__delay_ms(1000);
 while (BTN==1){

 }

    return;
}
void parant()
{int i;
    LCDPWR=OFF;
    RPIHALT=LOFF;
    LED=LOFF;
    for (i=0;i<TIMEOFF;i++){
    __delay_ms(500);
    LED=LON;
    __delay_ms(500);
    LED=LOFF;
    }
    return;
}