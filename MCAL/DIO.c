#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_InitPin(DIO_Pin_type pin  , DIO_PinStatus_type status)
{
		DIO_Pin_type port = pin / 8; // get the port number
		u8 pin_num = pin %8 ;        // get the pin number
		
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(DDRB,pin_num);
			break;
			
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

void DIO_WritePin(DIO_Pin_type pin , DIO_PinVoltage_type volt)
{
	if(volt==HIGH)
	{
		switch(pin)
		{ 
			case PINA0:
			SET_BIT(PORTA,PINA0);
			break;
			
			case PINA1:
			SET_BIT(PORTA,PINA1);
			break;
			
			case PINA2:
			SET_BIT(PORTA,PINA2);
			break;
			
			case PINA3:
			SET_BIT(PORTA,PINA3);
			break;
			
			case PINA4:
			SET_BIT(PORTA,PINA4);
			break;
			
			case PINA5:
			SET_BIT(PORTA,PINA5);
			break;
			
			case PINA6:
			SET_BIT(PORTA,PINA6);
			break;
			
			case PINA7:
			SET_BIT(PORTA,PINA7);
			break;
			
			case PINB0:
			SET_BIT(PORTB,(PINB0-8));
			break;
			
			case PINB1:
			SET_BIT(PORTB,(PINB1-8));
			break;
			
			case PINB2:
			SET_BIT(PORTB,(PINB2-8));
			break;
			
			case PINB3:
			SET_BIT(PORTB,(PINB3-8));
			break;
			
			case PINB4:
			SET_BIT(PORTB,(PINB4-8));
			break;
			
			case PINB5:
			SET_BIT(PORTB,(PINB5-8));
			break;
			
			case PINB6:
			SET_BIT(PORTB,(PINB6-8));
			break;
			
			case PINB7:
			SET_BIT(PORTB,(PINB7-8));
			break;
			
			case PINC0:
			SET_BIT(PORTC,(PINC0-16));
			break;
			
			case PINC1:
			SET_BIT(PORTC,(PINC1-16));
			break;
			
			case PINC2:
			SET_BIT(PORTC,(PINC2-16));
			break;
			
			case PINC3:
			SET_BIT(PORTC,(PINC3-16));
			break;
			
			case PINC4:
			SET_BIT(PORTC,(PINC4-16));
			break;
			
			case PINC5:
			SET_BIT(PORTC,(PINC5-16));
			break;
			
			case PINC6:
			SET_BIT(PORTC,(PINC6-16));
			break;
			
			case PINC7:
			SET_BIT(PORTC,(PINC7-16));
			break;
			
			case PIND0:
			SET_BIT(PORTD,(PIND0-24));
			break;
			
			case PIND1:
			SET_BIT(PORTD,(PIND1-24));
			break;
			
			case PIND2:
			SET_BIT(PORTD,(PIND2-24));
			break;
			
			case PIND3:
			SET_BIT(PORTD,(PIND3-24));
			break;
			
			case PIND4:
			SET_BIT(PORTD,(PIND4-24));
			break;
			
			case PIND5:
			SET_BIT(PORTD,(PIND5-24));
			break;
			
			case PIND6:
			SET_BIT(PORTD,(PIND6-24));
			break;
			
			case PIND7:
			SET_BIT(PORTD,(PIND7-24));
			break;
		}
	}
	else if(volt==LOW)
	{
		switch(pin)
		{
			case PINA0:
			CLR_BIT(PORTA,PINA0);
			break;
			
			case PINA1:
			CLR_BIT(PORTA,PINA1);
			break;
			
			case PINA2:
			CLR_BIT(PORTA,PINA2);
			break;
			
			case PINA3:
			CLR_BIT(PORTA,PINA3);
			break;
			
			case PINA4:
			CLR_BIT(PORTA,PINA4);
			break;
			
			case PINA5:
			CLR_BIT(PORTA,PINA5);
			break;
			
			case PINA6:
			CLR_BIT(PORTA,PINA6);
			break;
			
			case PINA7:
			CLR_BIT(PORTA,PINA7);
			break;
			
			case PINB0:
			CLR_BIT(PORTB,(PINB0-8));
			break;
			
			case PINB1:
			CLR_BIT(PORTB,(PINB1-8));
			break;
			
			case PINB2:
			CLR_BIT(PORTB,(PINB2-8));
			break;
			
			case PINB3:
			CLR_BIT(PORTB,(PINB3-8));
			break;
			
			case PINB4:
			CLR_BIT(PORTB,(PINB4-8));
			break;
			
			case PINB5:
			CLR_BIT(PORTB,(PINB5-8));
			break;
			
			case PINB6:
			CLR_BIT(PORTB,(PINB6-8));
			break;
			
			case PINB7:
			CLR_BIT(PORTB,(PINB7-8));
			break;
			
			case PINC0:
			CLR_BIT(PORTC,(PINC0-16));
			break;
			
			case PINC1:
			CLR_BIT(PORTC,(PINC1-16));
			break;
			
			case PINC2:
			CLR_BIT(PORTC,(PINC2-16));
			break;
			
			case PINC3:
			CLR_BIT(PORTC,(PINC3-16));
			break;
			
			case PINC4:
			CLR_BIT(PORTC,(PINC4-16));
			break;
			
			case PINC5:
			CLR_BIT(PORTC,(PINC5-16));
			break;
			
			case PINC6:
			CLR_BIT(PORTC,(PINC6-16));
			break;
			
			case PINC7:
			CLR_BIT(PORTC,(PINC7-16));
			break;
			
			case PIND0:
			CLR_BIT(PORTD,(PIND0-24));
			break;
			
			case PIND1:
			CLR_BIT(PORTD,(PIND1-24));
			break;
			
			case PIND2:
			CLR_BIT(PORTD,(PIND2-24));
			break;
			
			case PIND3:
			CLR_BIT(PORTD,(PIND3-24));
			break;
			
			case PIND4:
			CLR_BIT(PORTD,(PIND4-24));
			break;
			
			case PIND5:
			CLR_BIT(PORTD,(PIND5-24));
			break;
			
			case PIND6:
			CLR_BIT(PORTD,(PIND6-24));
			break;
			
			case PIND7:
			CLR_BIT(PORTD,(PIND7-24));
			break;
		}
	}
}



DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Pin_type port = pin / 8; // get the port number
	u8 pin_num = pin %8 ;        // get the pin number
	DIO_PinVoltage_type volt=LOW ; 
	
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num) ;
		break ; 
 
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break ; 
 		
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break ; 
		
		case PD:
		volt=READ_BIT(PIND,pin_num) ;
		break ;
	}
	return volt;
}

 
void DIO_Init(void)
{	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]); // loop to initialize every pin and take the status from the global array in config file
	}
}

void DIO_WritePort(DIO_Port_type port, u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
}


extern void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Pin_type port = pin / 8; // get the port number
	u8 pin_num = pin %8 ;        // get the pin number
	
	switch(port)
	{
		case PA:
		TOG_BIT(PORTA,pin_num);
		break;
		
		case PB:
		TOG_BIT(PORTB,pin_num);
		break;
		
		case PC:
		TOG_BIT(PORTC,pin_num);
		break;
		
		case PD:
		TOG_BIT(PORTD,pin_num);
		break;
	}
}