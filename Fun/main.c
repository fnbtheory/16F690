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

void main(void)
{
	run(); // Runs the main function
}

void run ()
{ // Runs indefinitely
    while (true) {
        int incr = 0;
        for (incr = 0; incr <= i; incr++) {
            display(incr);
            delay_ms(1000);
        }
    }
}

// Display the voltage
void display (int input)
{
	output_c(segment_numbers[input]);
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
