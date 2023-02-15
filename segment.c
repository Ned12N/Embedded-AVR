#include "Utils.h"
#include "MemMap.h"
#include "StdTypes.h"
#include "segment.h"

void segment_dis_Switch(u8 n)
{
	switch(n)
	{
		case 0:
		SEGMENT_PORT=0x3f;
		break;
	}
}

void segment_dis_LookUpTable(u8 n)
{
	u8 arr[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};
	u8 reminder = n%10;
	n=n/10;
	PORTD=arr[n];
	PORTB=arr[reminder];
}
void segment_dis_Hexa(u8 n)
{
	SEGMENT_PORT= n;
}

// Task 0 -_- Convert binary number to work on 7 Segment -- 7SEG-BCD --
void segment_BinaryTodecimal(u8 n)
{               // let n = 34
	u8 n1=n%10; // here we get number 4
	u8 n2=n/10; // here we get number 3
	n1=n1|(n2<<4); // use OR and Shifting to get the new Number
	SEGMENT_PORT= n1;// here the decoder take the first 4 bit to 7-SEG and the other 4bit to another 7-SEG
}

// Task 1
void Traffic_lights(void)
{	
	u8 Traffic_Counter=30;
	
	SET_BIT(TRAFFIC_PORT,RED_LED);
	 while(Traffic_Counter!=0)
		   {  
			segment_BinaryTodecimal(Traffic_Counter);
			Traffic_Counter--;	
			_delay_ms(200);	
			}
	
	CLR_BIT(TRAFFIC_PORT,RED_LED);
	SET_BIT(TRAFFIC_PORT,BLUE_LED);
	Traffic_Counter=5;
	
	while(Traffic_Counter!=0)
			{
				segment_BinaryTodecimal(Traffic_Counter);
				Traffic_Counter--;	
				_delay_ms(200);	
			}
	
	CLR_BIT(TRAFFIC_PORT,BLUE_LED);
	SET_BIT(TRAFFIC_PORT,GREEN_LED);
	Traffic_Counter=30;
	
	 while(Traffic_Counter!=0)
			 {
				 segment_BinaryTodecimal(Traffic_Counter);
				 Traffic_Counter--;
				 _delay_ms(200);
			 }
	 CLR_BIT(TRAFFIC_PORT,GREEN_LED);
}

// Task 2 ---- if you Click the Button1 the numbers will  increment by (1)  or Button2 to decrement by (1) 
void Segment_2Buttons_Click(void)
{
	BUTTON_DDPORT=0;

	if(BUTTON1_PU) // if you press the button enter here
	{
		if(flag1==0)
		{
			segment_BinaryTodecimal(Counter);
			Counter++;
			flag1=1;
		}
		if(Counter>=COUNTER_TIME)
		{
			Counter=0;
		}
	}
	else
	{
		flag1=0;
	}

	if(BUTTON2_PD) // if you press the button enter here
	{
		if(flag2==0)
		{
			if(Counter<=0)
			{
				Counter=COUNTER_TIME;
			}
			Counter--;
			segment_BinaryTodecimal(Counter);
			flag2=1;
		}
	}
	else
	{
		flag2=0;
	}
	
}

// Task 3 ---- if you Hold any Button of (Button1,Button2)  it will keep (incrementing,decrementing) 
void Segment_2Buttons_Hold(void)
{
	BUTTON_DDPORT=0; // Set Port Direction to input 
// adding flags to  the first lines allow holding the button and incrementing in the same time 
flag1=0; 
flag2=0;
	if(BUTTON1_PU) // if you press the button enter here and Increment the number
	{
		if(flag1==0)
		{
			segment_BinaryTodecimal(Counter);
			Counter++;
			flag1=1;
		}
		if(Counter>=COUNTER_TIME)
		{
			Counter=0;
		}
	}
	else
	{
		flag1=0;
	}
    _delay_ms(200); // ---------- DELAY to show the numbers slowly -------------
	
	if(BUTTON2_PD) // if you press the button enter here and decrement the number
	{
		if(flag2==0)
		{
			if(Counter<=0)
			{
				Counter=COUNTER_TIME;
			}
			Counter--;
			segment_BinaryTodecimal(Counter);
			flag2=1;
		}
	}
	else
	{
		flag2=0;
	}
	
}


// Task 4 ----- Function to Make StopWatch and assign 2 Buttons to (Reset) and (Pause)
//              and assign the third button to Toggle  another MODE ---> to (increment by 1) and ( increment by 10 ) 
void STOPWatch(void)
{   
	while( IS_Toggle!=1) //---------------------- First MODE --------------------------------
	{
		if(BUTTON3_PU) // if Toggle Button then leave this (While LOOP)
		{
			IS_Toggle=1;       // To leave while loop and enter the next loop which contains MODE 2
			Timer_IsPaused=1; // discard if Condition 
			flag1=0;         // reset the flag
		}
		if(BUTTON1_PU)  // Button 1 for Pause
		{
			if(flag1==0) // Flag method ---->> if you hold the button the CPU will not get stuck and wont enter (else) until release the button 
			{
			Timer_IsPaused=!(Timer_IsPaused); // ----- Toggle Pause/Play -----
			flag1=1;	
			}
		}
		else
		{
			flag1=0;
		}
		if(BUTTON2_PD)
		{
		Watch_Timer=STOPWATCH_TIME;    // ----- Reset Timer ----- 
		}

		if(Watch_Timer>0) // keep decrementing if timer is bigger than 0 ... if timer=0 then just display 0 in (else)
		{
			if(!Timer_IsPaused)
			{
				segment_BinaryTodecimal(Watch_Timer);
				Watch_Timer--;
				_delay_ms(200);
			}
		}
		else
		{
		segment_BinaryTodecimal(Watch_Timer);	
		}
	}	

	while(IS_Toggle!=0) //---------------------- SECOND MODE --------------------------------
	{		
		if(BUTTON1_PU) // if you press this button ---> increment by (1)
			{
				if(flag1==0)
				{
					Is_Increment=!(Is_Increment);
					flag1=1;
				}
			}
		else
			{
				flag1=0;
			}
		if(BUTTON2_PD) // if you press this button ---> increment by (10)
			{
				if(flag2==0)
				{
					Is_Increment=2;
					flag2=1;
				}
			}
		 else
			{
				flag2=0;
			}
			
		if(Is_Increment==1) // incrementing by (1)
			{
				Watch_Timer++;
				segment_BinaryTodecimal(Watch_Timer);
				Is_Increment=0;	
			}
		else if(Is_Increment==2)  // incrementing by (10)
			{
				Watch_Timer=Watch_Timer+10;
				segment_BinaryTodecimal(Watch_Timer);
				Is_Increment=0;
			}
			 
			if(BUTTON3_PU) // if Toggle Button then leave this (While LOOP)
			{
				if(flag3==0)
				{
				Timer_IsPaused=0;
				IS_Toggle=0;       // To leave while loop and enter the next loop which contains MODE 2
				flag3=0;
				}
			}
			else
			{
				flag3=0;
			}
	}
	
	
	
	
			
}