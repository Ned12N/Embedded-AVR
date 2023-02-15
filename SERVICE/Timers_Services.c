#include "Timers_Services.h"



static volatile u16 t1,t2,t3,flag=0;

void PWM_Measure(u32* Pfreq,u8* Pduty)
{
	u16 Ton,Toff;
	TCNT1=0; // set timer to zero to make sure we don't get an overflow
	Timer1_ICU_SetCallBack(Func_ICU);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3); // stuck here until you take (t1,t2,t3) from interrupt
	Ton=t2-t1;
	Toff=t3-t2;
	
	*Pduty=((u32)Ton*100)/((u32)Ton+Toff);// * 100 to make sure result is not zero because it would be small
	*Pfreq= ((u32)1000000)/((u32)Toff+Ton); // *1m to get by HZ
}

static void Func_ICU(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=3;
	}
}
