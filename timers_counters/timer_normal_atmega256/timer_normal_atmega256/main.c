/*
 * timer_normal_atmega256.c
 *
 * Created: 10/2/2023 3:45:29 PM
 * Author : ari
 */ 

#define F_CPU 1000000ul //setting frequency to 1mHz
#include <avr/io.h>


int main(void)
{
	int count = 0;
	DDRH =0xff;
	TCCR0A &= ~(1 << WGM01);
	TCCR0B |= (1 << CS00);
	TCNT0 = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		while ((TIFR0 & 0b00000001) > 0){
			count++;
			
			if (count == 3922){
				PORTH ^= (1 << 0);
				count = 0;
			}
		
			TIFR0 &= !(1 < TOV0);
		}
			
			
    }
}

