/**
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC16F18855
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
 * Author: Radek Zaworski
 * 
 * Kod wymaga poprawek w zakresie dobierania zegara dla PWM i rejestru PR6,
 * sygna? PWM nie ma wype?nienia 50% dla wszystkich d?wi?ków, ale gra? gra.
*/

#include "mcc_generated_files/mcc.h"

// sounds
#define C4 119 
#define D4 105
#define E4 94
#define F4 88
#define G4 79
#define A4 70
#define H4 62
#define C5 59
#define D5 52
#define E5 46
#define F5 44
#define G5 39
#define A5 35
#define H5 31

void play(uint8_t sound)
{
    PWM6_LoadDutyValue(125);
    T6PR = sound;
    __delay_ms(400);
    PWM6_LoadDutyValue(0);
    __delay_ms(10);
}

void play_half(uint8_t sound)
{
    PWM6_LoadDutyValue(125);
    T6PR = sound;
    __delay_ms(200);
    PWM6_LoadDutyValue(0);
    __delay_ms(10);
}

void play_quater(uint8_t sound)
{
    PWM6_LoadDutyValue(125);
    T6PR = sound;
    __delay_ms(100);
    PWM6_LoadDutyValue(0);
    __delay_ms(10);
}

void pause_quater(void)
{
    PWM6_LoadDutyValue(0);
    __delay_ms(100);
    PWM6_LoadDutyValue(125);
}

void play2octave(void)
{
    T6PR = C4;
    __delay_ms(500);
        
    T6PR = D4;
    __delay_ms(500);
        
        T6PR = E4;
    __delay_ms(500);
        
    T6PR = F4;
    __delay_ms(500);
        
    T6PR = G4;
    __delay_ms(500);
        
    T6PR = A4;
    __delay_ms(500);
        
    T6PR = H4;
    __delay_ms(500);
        
    T6PR = C5;
    __delay_ms(500);
        
    T6PR = D5;
    __delay_ms(500);
        
    T6PR = E5;
    __delay_ms(500);
        
    T6PR = F5;
    __delay_ms(500);
        
    T6PR = G5;
    __delay_ms(500);
        
    T6PR = A5;
    __delay_ms(500);
    
    //T6PR = H5;
    //__delay_ms(500);
}

void playSWcantina(void) //chujowo co?, próbowa?em ze s?uchu potem z nut xD
{
    play_half(A4);
    play_half(D5);
    play_half(A4);
    play_half(D5);
    play_quater(A4);
    play_half(D5);
    play_quater(A4);
    pause_quater();
    play_quater(G4);
    play_half(A4);
    play_quater(A4);
    play_quater(G4);
    play_quater(A4);
    play_quater(G4);
    play_quater(F4);
    play_quater(G4);
    play_quater(G4);
    play_quater(F4);    
}

void playMario(void)
{
    play(D5);
    play_quater(D5);
    play_quater(C5);
    play_quater(F5);
    play_quater(D5);
    play(F4);
    play_quater(F4);
    play_quater(D4);
    play_quater(E4);
    play_quater(F4);
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //PWM6_LoadDutyValue(127);
    
    extern bool flag; // flag for interrupt every 10ms

    while (1)
    {       
        //play2octave();
        
        playMario();
                
        __delay_ms(1000);
    }
}