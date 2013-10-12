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
	SET_TRIS_C(0); // Sets PORT C to output only
	SET_TRIS_B(240); // Setuo PORT B to use for inputs
	setup(); // Initial setup
	button(); // Calls the function button()
}

void button()
{
    while(true)
	{
        if(!input(B4)) // Frequency Down
        {
            frequency_down();
        }
        else if(!input(B5)) // Frequency Up
        {
            frequency_up();
        }
        else if(!input(B6)) // Duty Down
        {
            duty_down();
        }
		else if(!input(B7)) // Duty Up
        {
            duty_up();
        }
        display(); // Update display after every change
    }
}

void frequency_down()
{
	// If the period still greater than the duty, subtract
    if (period > duty)
    {
        period--; // Decrease period
    }
}

void frequency_up()
{
	// Do not allow the period to go above 200
    if (period < 200) 
    {
        period++; // Increase period
    }
}

void duty_down()
{
	// Do not allow the duty to go below 1
    if (duty > 1) 
    {
        duty--; // Decrease duty
    }
}

void duty_up()
{
	// If the period still greater than the duty, add
    if (duty < period) 
    {
        duty++; 
    }
}

// Update the output with the new values
void display()
{
    set_pwm1_duty(duty);
	setup_timer_2(t2_div_by_1,period,1);
}

// Initial setup of pic
void setup()
{
	// Switch the ADC off
	setup_adc(adc_off);
	
	// Setup the individual ports for pulse steering
	// h_l means whilst half are high the other half is low
	setup_ccp1(ccp_pwm_h_l | ccp_pulse_steering_a
						   | ccp_pulse_steering_b
						   | ccp_pulse_steering_c
						   | ccp_pulse_steering_d);
	
	// Setup the initial output with the default values
	set_pwm1_duty(duty);
	setup_timer_2(t2_div_by_1,period,1);

}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
