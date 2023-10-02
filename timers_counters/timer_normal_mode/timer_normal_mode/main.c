/*
 * timer_normal_mode.c
 *
 * Created: 10/2/2023 2:28:22 PM
 * Author : ari
 */ 

#define F_CPU 1000000ul //frequency = 1 MHz
#include <avr/io.h>




int main(void)
{
	
	DDRD = 0xff;
	TCCR0 = 0x00;
	TCCR0 |= (1 << CS00); //define clock source without pre-scaling
	TCNT0 = 0x00; //start counter from zero
	int count = 0;
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		//creating rounds to generate a second
		while ((TIFR & 0b00000001) > 0)
		{
			count++;
			
			if (count == 3922){
				PORTD ^= (1 << 0);
				count = 0;
			}
			TIFR &= !(1 < TOV0);
		}
    }
}

