/*
 * evening.c
 *
 * Created: 9/18/2023 7:37:00 PM
 * Author : ari
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define rs PG0
#define rw PG1
#define enable PG2
#define dataline PORTH


void latch(){
	
	PORTG &= ~(1 << enable);
	_delay_ms(1);
	PORTG |= (1 << enable);
	_delay_ms(1);
}
int main(void)
{
    /* Replace with your application code */	
	
	
	DDRK = 0b11110011;
	DDRG = 0xff;
	DDRH = 0xff;
	PORTK = 0b11111110;
    while (1) 
    {
		PORTG &= ~(1 << rs); //command mode set rs to 0
		PORTG &= ~(1 << rw); //write mode set rw to 0
		
		
		//turn display on, cursor show, blink
		//function set - 00111111
		PORTH = 0b00001111;
		latch();
		
		//shift - 00011100 - 1c
		//PORTH = 0x3f;
		//latch();
		
		PORTH = 0x1c;
		latch();
		
		PORTH = 0x01;
		latch();
		
		PORTG |= (1 << rs); //data mode
		PORTG &= ~(1 << rw);
		latch();
				
		if ((PINK & 0b00000100) == 0x0){			
			PORTH = '2';
			latch();
			
		}		
			
		}
		
    }


