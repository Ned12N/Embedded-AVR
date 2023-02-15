
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "Timers.h"
#define F_CPU 8000000
#include <util/delay.h>



void ULTRASONIC_Init(void);

u16 ULTRASONIC_GetDistance(void);



#endif /* ULTRASONIC_H_ */