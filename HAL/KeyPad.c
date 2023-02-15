#include "KeyPad.h"

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	// put (1) on each row
	DIO_WritePin(FIRST_OUTPUT+0,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for (c=0;c<COLMS;c++)
		{
			if(DIO_ReadPin(FIRST_INPUT+c)==LOW) // check if i pressed here --> Read the first button 
			{
				key=KeysArray[r][c];
				// wait until i release my finger from the Buttons
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
	return key;
}

