 #include "StdTypes.h"
 #include "MOTOR_interface.h"
 #include "DIO_interface.h"
 #include "MOTOR_cfg.h"
Erorr_type MOTOR_Stop(MOTOR_type motor)
{
	if(motor>NUMBER_MOTORS)
	{
		return OUT_OF_RANGE;
	}
	switch(motor)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		break;
		
		case M2:
		DIO_WritePin(M2_IN2,LOW);
		break;		
	}
	
	DIO_WritePin(M1_IN2,LOW);
}

void MOTOR_CW(MOTOR_type motor)
{
	switch(motor)
	{
		case M1:
		DIO_WritePin(M1_IN1,HIGH);
		DIO_WritePin(M1_IN2,LOW);
		break;
		
		case M2:
		DIO_WritePin(M2_IN1,HIGH);
		DIO_WritePin(M2_IN2,LOW);
		break;
	}
	
}
void MOTOR_CCW(MOTOR_type motor)
{
	switch(motor)
	{
		case M1:
	DIO_WritePin(M1_IN1,LOW);
	DIO_WritePin(M1_IN2,HIGH);
	break;
		
		case M2:
	DIO_WritePin(M2_IN1,LOW);
	DIO_WritePin(M2_IN2,HIGH);
	break;
	}

}


