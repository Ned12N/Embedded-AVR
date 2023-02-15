#include "Utils.h"
#include "MemMap.h"
#include "StdTypes.h"
#include "DIO_interface.h"  
#include "MOTOR_interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Stepper.h"
#include "ADC.h"
#include "Sensors.h"
#include "EX_Interrupt.h"
#include "Timers.h"
#include "SERVO.h"
#include "RGB.h"
#include "Converter.h"
#include "ULTRASONIC.h"
#include "UART.h"
#include "UART_Services.h"

#define Buzzer_ON DIO_WritePin(PINC5,HIGH)
#define Buzzer_OFF DIO_WritePin(PINC5,LOW)

 

int main(void)
{
    sei(); // enable global interrupt
/*******************************Initilization *******************************/
	DIO_Init();
	LCD_Init();

	ADC_Init(VREF_VCC,ADC_SCALER_64);
UART_Init();

Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
ULTRASONIC_Init();
/*
 LCD_GoTo_WriteString(0,0,"One-Byte Converter");
 LCD_GoTo_WriteString(1,0,"DEC   HEX   BIN");
 _delay_ms(3000);
 LCD_Clear();*/

u8 d0=0 ;
u8 d1=0 ;
u32 t=0;
LCD_GoTo_WriteString(0,0,"UART");
u8 led1[]={"led on"};
u8 led0[]={"led off"};

u8 buzz1[]={"buzz on"};
u8 buzz0[]={"buzz off"};	
	
u8 buffer_string[100] ;

    while(1)
    {
 		UART_ReceiveString(buffer_string);
 		 u8 ledon=string_compare_sheet(buffer_string,led1);
		 u8 ledoff=string_compare_sheet(buffer_string,led0);
		u8 buzzon=string_compare_sheet(buffer_string,buzz1);
		u8 buzzpff=string_compare_sheet(buffer_string,buzz0);

		 if (ledon)
		 {
			DIO_WritePin(PINC1,HIGH);
			LCD_GoTo_WriteString(0,0,buffer_string);
		 }
		 if (buzzon)
		 {
 			 Buzzer_ON;
			  LCD_GoTo_WriteString(1,8,"Buzz on");
		 }
		 if (buzzpff)
		 {
			 Buzzer_OFF;
			 LCD_GoTo_WriteString(0,8,"Buzz off");
		 }
		 
 		  if (ledoff)
 		  {
			DIO_WritePin(PINC1,LOW);
			LCD_GoTo_WriteString(1,0,buffer_string);
 		  }
    }
}
 
 

 