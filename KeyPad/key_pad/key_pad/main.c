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
	
	DDRJ = 11111000;
	DDRH = 0xff;
    while (1) 
    {
		PINJ &= ~(1 << 2);
		
		if (PORTJ & 0b00000100)
		{
			PORTH &= ~(1 << PH0);
		}
    }
}

