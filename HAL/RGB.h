#ifndef RGB_H_
#define RGB_H_

#include "StdTypes.h"
#include "MemMap.h"
#define F_CPU 8000000
#include <util/delay.h>
 /******************************************************************************************/
#define NUM_COLORS 15
#define DELAY_TIME 200
/************************************PIN mapping of the RGB LED*************************/
#define RED_PIN		OCR0
#define BLUE_PIN	OCR1B
#define GREEN_PIN	OCR1A

#define  LED_TYPE COMMON_CATHODE  
 /*********************************Timer information**************************************/
#define TIMER_TYPE			 FASTPWM
#define TIMER_PRESCALER		   8
#define TIMER_COMPARE_VALUE   255
#define OC_MODE            NON_INVERTING 
 /******************************************************************************************/
extern u16 colors[][3];
extern const u8 *color_names[];
/******************************************************************************************/

/* Function that take the name of the color as string and compare it with array of the colors names
   then assign the Color Values to Timer register */
void set_color(const char * color);

/*Function iterate through all the colors in the array*/
void RGB_ToggleColors(void); 









#endif /* RGB_H_ */