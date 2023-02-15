
#ifndef STEPPER_H_
#define STEPPER_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#define F_CPU 8000000
#include <util/delay.h>
/**************************************************/
#define COIL1A PINB6
#define COIL1B PINB4
#define COIL2A PINB7
#define COIL2B PINB5

#define Orange PINB0
#define Yellow PINB1
#define Pink PINB2
#define Blue PINB3


#define DELAY 200 
/**************************************************/

void stepper_BiPolar_CW(void);
void stepper_BiPolar_CCW(void);

void stepper_UniPolar_CW(void);
void stepper_UniPolar_CCW(void);
/*************Half Step****************/
void stepper_UniPolar_HS_CW(void);
void stepper_UniPolar_HS_CCW(void);

void stepper_BiPolar_HS_CW(void);
void stepper_BiPolar_HS_CCW(void);

#endif /* STEPPER_H_ */