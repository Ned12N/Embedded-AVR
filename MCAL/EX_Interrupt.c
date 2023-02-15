#include "EX_Interrupt.h"

/********************************Pointer to Functions to be assigned to ISR *******************************/
static void (*Fptr_INT0)(void)=NULL_PTR;
static void (*Fptr_INT1)(void)=NULL_PTR;
static void (*Fptr_INT2)(void)=NULL_PTR;


void EXI_Enable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXI_Disable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		CLR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLR_BIT(GICR,INT1);
		break;
		case EX_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
}

void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt){
		case EX_INT0:
		switch(Edge){
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
		}
		break;
		case EX_INT1:
		switch(Edge){
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
		}
		break;
		case EX_INT2:
		switch(Edge){
			case FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			CLR_BIT(MCUCSR,ISC2);
		}
		break;
	}
}



/***********************Call Back Functions******************************/
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt)
	{
		case EX_INT0:
		Fptr_INT0=LocalPtr;
		break;
		
		case EX_INT1:
		Fptr_INT1=LocalPtr;
		break;
		
		case EX_INT2:
		Fptr_INT2=LocalPtr;
		break;
	}
}

/**************************************** ISR ***********************************/
ISR(INT0_vect)
{
	if(Fptr_INT0!=NULL_PTR)
	{
		Fptr_INT0();	
	}
	
}


ISR(INT1_vect)
{
	 if(Fptr_INT1!=NULL_PTR)
	 {
		 Fptr_INT1();
	 }
 }

ISR(BAD_vect,ISR_NAKED)
{
	if(Fptr_INT1!=NULL_PTR)
	{
		Fptr_INT1();
	}
}




