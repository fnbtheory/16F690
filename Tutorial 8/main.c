// Author: Kyluke McDougall

#include <16F690.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS
#FUSES INTRC_IO                 //Low power osc < 200 khz  LP
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOMCLR                   //Master Clear pin used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES NOFCMEN                  //Fail-safe clock monitor disabled

#include "main.h"

#use delay(clock=8000000)
#use rs232(baud=9600, xmit=PIN_B7, rcv=PIN_B5)

void main(void)
{
	setup(); // Initial setup
	run(); // Runs the main function
}

void run ()
{ // Runs indefinitely
    
    char test;
	
	// Prints initial output
    printf("Tutorial 8 -> Kyluke McDougall - 211213020\n");
    
	// Runs indefinitely to capture output
    while(true)
    {
       test = getc(); // Capture keyboard input
       putc(test);
		
		// Check if a line is not filled
	   if (new_line != 8) {
	   		display(test); // Display character pressed
			new_line++;
		}
		// If a line is filled, move to the next one
	   else {
			// If the last line is not being used yet
			if (clear_line != 1){
				clear_line = 1;
				new_line = 0;
				next_line();
			}
			// If the last line is full, clear the LCD
			else {
				clear_line = 0;
				new_line = 0;
				clear();
			}
		}
    }
}     

// Display the character onto the LCD
void display (char input)
{
	output_c(input);
	output_high(RS);
	output_low(RW);
	output_high(E);
	output_low(E);
	delay_us(40);
}

// Setup ports and ADC config
void setup()
{
	SET_TRIS_C(0); // Sets PORT C to output only

	setup_lcd();
}

// Setup LCD for usage
void setup_lcd()
{
	delay_ms(40);
	output_low(RS);
	output_low(RW);
	output_high(E);
	output_c(56);
	output_low(E);
	delay_us(40);

	delay_ms(40);
	output_low(RS);
	output_low(RW);
	output_high(E);
	output_c(56);
	output_low(E);
	delay_us(40);

	output_low(E);
	output_low(RS);
	output_low(RW);
	output_high(E);
	output_c(15);
	output_low(E);
	delay_us(40);

	output_low(RS);
	output_low(RW);
	output_high(E);
	output_c(1);
	output_low(E);
	delay_ms(2);

	output_low(RS);
	output_low(RW);
	output_high(E);
	output_c(6);
	output_low(E);
	delay_ms(200);
}

// Clear the display for the LCD
void clear()
{
	output_c(1);
	output_low(RS);
	output_low(RW);
	output_high(E);
	output_low(E);
	delay_ms(2);
}

// Jump to the next line on the LCD
void next_line()
{
	output_c(192);
	output_low(RS);
	output_low(RW);
	output_high(E);
	output_low(E);
	delay_ms(2);
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
