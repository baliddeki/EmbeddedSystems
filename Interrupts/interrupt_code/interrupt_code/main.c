/*
 * interrupts.c
 *
 * Created: 10/2/2023 10:10:51 AM
 * Author : ari
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRH = 0xff;
	DDRD = 0x00;
	EIMSK |= (1 << INT3);
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

//interrupt service routine
ISR(INT3_vect ){
	PORTH ^= (1 << 0);
}

