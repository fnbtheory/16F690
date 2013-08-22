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
	#asm
		bsf status, rp0
		clrf portc
		bcf status, rp0
	#endasm
	while(true)
	{
		count = 255; // Sets the count to 255
		#asm
			        
		    clrf portc ; Clears the port after every successful loop
            
            loop1:  DECFSZ count,f ; Decrements count and stores the value in f
			        goto loop1 ; If the value is not 0 it will continue the loop
			        NOP
			loop2:  DECFSZ count,f
			        goto loop2
			        NOP
			loop3:  DECFSZ count,f
			        goto loop3
			        NOP
			loop4:  DECFSZ count,f
			        goto loop4
			        NOP
			loop5:  DECFSZ count,f
			        goto loop5
			        NOP
			loop6:  DECFSZ count,f
			        goto loop6
			        NOP
			loop7:  DECFSZ count,f
			        goto loop7
			        NOP
			loop8:  DECFSZ count,f
			        goto loop8
			        NOP
            
			movlw 0b00000001 ; Sets the port output 1 to high
			movwf portc ; Sends the value to the output
			
			; This loop keeps the led on for a bit longer
		    loop0:  DECFSZ count,f
			        goto loop0
			        NOP

		#endasm
	}
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
