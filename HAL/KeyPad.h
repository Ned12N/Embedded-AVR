
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_interface.h"
#include "StdTypes.h"

/***************************Config*******************************/
// ROWS
#define FIRST_OUTPUT PINB4
// Columns 
#define FIRST_INPUT PIND2	

#define ROWS 4 
#define COLMS  4
#define NO_KEY 'T'

static u8 KeysArray[ROWS][COLMS]={
	{'7','8','9','A'},
    {'4','5','6','B'},
	{'1','2','3','E'},
	{'C','0','=','F'},	
};
/****************************************************************/

/*
This function retrieves a key pressed on a 4x4 keypad and returns the corresponding key value.

	1- First, the function sets all rows to high.
	2- It then iterates through the rows and sets each one to low, one at a time.
	3- For each row, it checks the state of each column to determine if a button has been pressed.
	4- If a button is pressed, the corresponding key value is retrieved from the "KeysArray" 2D array
	   and stored in the "key" variable.
	5- The function then waits until the button is released.
	6- This process is repeated for each row and column.
	7- Finally, the "key" value is returned.*/

u8 KEYPAD_GetKey(void);



#endif /* KEYPAD_H_ */