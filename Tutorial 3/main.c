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
	SET_TRIS_C(192); // Sets the last 2 pins of port C to inputs 1100 000
	button(); // Calls the function button()
}

void button()
{
    while(true) // Loop forever
	{
    	output_c(0); // Switch off the LEDs for blinking effect
    	
        if(input(C7) && input(C6)) // If both buttons are pressed
        {
            reset(); // Reset the count
        }
        else if(input(C6)) // If port C6 is activated
        {
            down_count(); // Count down once and display
        }
        else if(input(C7)) // If port C7 is activated
        {
            up_count(); // Count up once and display
        }
        display(); // Display everytime and when nothing is pressed.
    }   
}

void reset()
{
    count = 0; // Sets the global variable to 0, which means count == 0
}

void up_count()
{
    if (count < 15) // Prevent count from going higher than 15
    {
        count++; // Increment the global variable
        delay_ms(100); // Delay for 100ms + 100ms in display() to create a 200ms delay
        display(); // Display the new value
    }
}       

void down_count()
{
    if (count > 0) // Prevent the count every going below 0
    {
        count--; // Decrement the global variable
        delay_ms(100); // Delay for 100ms + 100ms in display() to create a 200ms delay
        display(); // Display the new value
    }
}

void display()
{
    delay_ms(100); // Wait 100ms before displaying anything
    output_c(count); // Display the value of count on the LEDs
}    

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
