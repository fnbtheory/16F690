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

#use delay(clock=32000)

void main(void)
{
	setup(); // Initial setup
	run(); // Runs the main function
}

void run ()
{ // Runs indefinitely
    while (true) {
        int input = 0;
        input = read_adc(ADC_START_AND_READ); // Gets the voltage
        display(input);
    }    
}

// Display the voltage
void display (int input)
{
	int temp = 0;
	temp = segment[input/50];
    output_c(temp);
}

// Setup ports and ADC config
void setup()
{
	SET_TRIS_C(0); // Sets PORT C to output only
    setup_adc_ports(sAN2);
    setup_adc(adc_clock_internal);
    set_adc_channel(2);
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
