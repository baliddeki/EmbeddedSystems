/*
 * adam.c
 *
 * Created: 10/1/2023 12:49:55 PM
 * Author : ari
 */ 

#include <avr/io.h>
#include <util/delay.h>
void latch(){
	PORTE &=~(1<<PE0);
	_delay_ms(50);
	PORTE |=(1<<PE0);
	_delay_ms(50);
}
int main(void)
{
	
	
    /* Replace with your application code */
    while (1) 
    {
		PORTE &=~(1<<PE1);
		PORTE &=~(1<<PE2);
		
		PORTD = 0B00001111;
		latch();
		
    }
}

