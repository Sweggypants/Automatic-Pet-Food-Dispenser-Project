// LCDKeypad.c
// Program to test LCD and keypad.
// For project using USB interface with Bootloader

#include <xc.h>
#include "lcd.h"
#include "delays.h"
#include "keypad.h"

unsigned char key, outchar;
unsigned char p1, p2, p3, p4;
char Message1 [ ] = "Enter Time :  "; // Defining a 20 char string

void main(void) {
    int i;
    lcd_init(); // Initialise LCD module

    while (1) {

        lcd_write_cmd(0x80); // Move cursor to line 1 position 1
        for (i = 0; i < 20; i++) //for 20 char LCD module
        {
            outchar = Message1[i];
            lcd_write_data(outchar); // write character data to LCD
        }

        lcd_write_cmd(0xC0); // Move cursor to line 2 position 1

        key = getkey(); // waits and get an ascii key number when pressed
        p1 = key;
        lcd_write_data(key); //display on LCD

        switch (p1) {
            case 1: delay_ms(1000)
                    ; break;
            case 2: delay_ms(2000); break;
            case 3: delay_ms(3000); break;
            case 4: delay_ms(4000); break;
        } 

    }
}




