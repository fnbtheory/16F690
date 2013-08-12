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
		count = 64000;
		count1 = 64000;
		count2 = 64000;
		count3 = 64000;
		count4 = 64000;
		count5 = 64000;
		count6 = 64000;
		#asm
		    clrf portc
			
			loop:	DECFSZ count,f
					goto loop
					NOP
			loop1:  DECFSZ count1,f
			        goto loop1
			        NOP
			loop2:  DECFSZ count2,f
			        goto loop2
			        NOP
			loop3:  DECFSZ count3,f
			        goto loop3
			        NOP
			loop4:  DECFSZ count4,f
			        goto loop4
			        NOP
			loop5:  DECFSZ count5,f
			        goto loop5
			        NOP
			loop6:  DECFSZ count6,f
			        goto loop6
			        NOP
			        
            
			movlw 0b00000001
			movwf portc

		#endasm
	}
}

//              /)/)
//             ( 0 0)
//             /'-._)
//            /#/
//           /#/	Tighty Whities (Pty) Ltd.
//          /#/		(c) 2013. For Ze Party.
