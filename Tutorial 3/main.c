<<<<<<< HEAD
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
	SET_TRIS_C(192);
	button();
}

void button()
{
    while(true)
	{
    	output_c(0);
    	
        if(input(C7) && input(C6))
        {
            reset();
        }
        else if(input(C6))
        {
            down_count();
        }
        else if(input(C7))
        {
            up_count();
        }
        display();
    }   
}

void reset()
{
    count = 0;
}

void up_count()
{
    if (count < 15)
    {
        count++;
        delay_ms(100);
        display(); 
    }
}       

void down_count()
{
    if (count > 0)
    {
        count--;
        delay_ms(100);
        display();   
    }
}

void display()
{
    delay_ms(100);
    output_c(count);
}    

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
=======
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
	SET_TRIS_C(192);
	while(true)
	{
    	switch(button())
    	{
        	case 1: reset(); break;
        	case 2: down_count(); break;
        	case 3: up_count(); break;
        	default:
        	    delay_ms(100);
                output_c(count);
                break;
        }           
	}
}

int button()
{
    if(!input(C7) && !input(C6))
    {
        return 1;
    }
    else if(!input(C6))
    {
        return 2;
    }
    else if(!input(C7))
    {
        return 3;
    }
    else
        return 0;
}

void reset()
{
    output_c(16);
}

void up_count()
{
    count++;
    if (count <= 15)
    {
        delay_ms(200);
        display();
    }
}       

void down_count()
{
    count--;
    if (count <= 15)
    {
        delay_ms(200);
        display();
    }
}

void display()
{
    output_c(count);
}    

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
>>>>>>> 6fd66c6cc267f8b1d861c4e19ebd960bad0c6b64
