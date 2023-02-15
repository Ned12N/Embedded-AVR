#include "ULTRASONIC.h"

static volatile u16 t1,t2;
static volatile u8 flag=0;

static void f_icu(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		DIO_WritePin(PINC0,HIGH);
		flag=1;
	}
	else if(flag==1)
	{
		DIO_WritePin(PINC0,LOW);
		t2=ICR1;
		flag=2;
	}
}

void ULTRASONIC_Init(void)
{
	Timer1_ICU_SetCallBack(f_icu);
	Timer1_ICU_InterruptEnable();
}

u16 ULTRASONIC_GetDistance(void)
{
	u16 t,d;
	
	TCNT1=0;
	flag=0;
	Timer1_InputCaptureEdge(RISING);
	
	DIO_WritePin(PIND7,HIGH);
	_delay_us(10);
	DIO_WritePin(PIND7,LOW);
	
	while(flag<2);
	
	t=t2-t1;
	d=t/58;
	return d;
}

