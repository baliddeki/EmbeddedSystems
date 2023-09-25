/*
 * key_pad.c
 *
 * Created: 9/17/2023 1:08:29 PM
 * Author : ari
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRJ = 0b00010111;
	DDRH = 0xff;
    while (1) 
    {
		PORTJ = 0b11111011;
		
		if ((PINJ & 0b00001000) == 0x0)
		{
			PORTH |= (1 << PH1);
		}else
		{
			PORTH &= ~(1 << PH1);
		}
		}
}

