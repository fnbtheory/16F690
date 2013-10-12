// Author: Kyluke McDougall

#include <16F690.h>
#device adc=10

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

void main(void)
{
	setup(); // Initial setup
	run(); // Runs the main function
}

void run ()
{ // Runs indefinitely
    while (true) {
        float input = 0; // For temp storage
		int i = 0; // For increment
		char final [8] = "0.00"; // for output
        input = read_adc(ADC_START_AND_READ)/218.0684; // Gets the voltage
        
		// Convert from float to char
		sprintf(final, "%0.2f", input);
		clear();
		
		// Display each character
		for (i = 0; i <=3; i++) {
			display(final[i]);
		}
		display("V");
    }
	
}

// Display the voltage
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
    setup_adc_ports(sAN2);
    setup_adc(adc_clock_internal);
    set_adc_channel(2);

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

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
