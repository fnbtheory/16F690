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
#include "math.h"

#use delay(clock=8000000)

void main(void)
{
	setup(); // Initial setup
	run(); // Runs the main function
}

void run ()
{ // Runs indefinitely
	int incr = 0;
	while(true)
	{
		int output = 0;
		
		output = pow(2,incr);
		display(output);
		incr++;
		delay_ms(50);

		if(incr >= 4) {
			incr = 0;
		}
	}
}

// Display the voltage
void display (int out)
{
	output_c(out);
}

// Setup ports
void setup()
{
	SET_TRIS_C(0); // Sets PORT C to output only
	enable_interrupts(int_ext);
	enable_interrupts(global);
	ext_int_edge(H_to_L);
}

#int_ext
void isrext()
{
	delay_ms(500);
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
