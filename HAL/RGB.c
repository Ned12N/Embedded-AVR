#include "RGB.h"
#include "StdTypes.h"
#include "MemMap.h"



void set_color( const char * string)
{
	for (int i = 0; i < NUM_COLORS; i++)
	{
		/*
	you don't have to compare the string character-by-character
	The comparison of two pointers works by comparing the strings pointed to by the two pointers.
 */
		if (color_names[i]==string)
		{
			RED_PIN = colors[i][0];
			GREEN_PIN = colors[i][1];
			BLUE_PIN = colors[i][2];
			return;
		}
	}
}

 

void RGB_ToggleColors(void)
{
	for (int i = 0; i < NUM_COLORS; i++)
	{
			RED_PIN = colors[i][0];
			GREEN_PIN = colors[i][1];
			BLUE_PIN = colors[i][2];
			_delay_ms(DELAY_TIME);
	}
}