/*
 * CourseWork.c
 *
 * Created: 10/28/2023 8:41:17 AM
 * Author : ari
 */ 

#include <avr/io.h>

/*
Method for buzzer to sound when tourist arrives
*/

void buzz(){
	#define TAS PK1  // TAS - tourist arrival switch
	#define TAB PJ3  // TAB - tourist arrival buzz
	
	 DDRK &= ~(1 << TAS);
	 
	 DDRJ |= (1 << TAB);
	 
	 if ((PINK & (1 << TAS)) == 0) {
		 // Toggle the state of the buzzer pin
		 PORTJ ^= (1 << TAB);
	 }
	
	
}


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		buzz();
    }
}

