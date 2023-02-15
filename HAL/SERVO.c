#include "SERVO.h"

void servo(u8 angle)
{
	if(angle>180)
	{
		angle=180;
	}
	#if Timer_MODE==FASTPWM_MODE
	   OCR1B=((angle*(u32)1000)/180) + 999 ;
	#else
	OCR1A=((angle*(u32)1000)/180) + 999 ;
	#endif
}