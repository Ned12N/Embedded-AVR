#include "StdTypes.h"
#include "DIO_interface.h"

const DIO_Pin_type PinsStatusArray[TOTAL_PINS] = {
	INFREE, // Port A Pin 0  ADC0
	OUTPUT, // Port A Pin 1  ADC1
	OUTPUT, // Port A Pin 2
	OUTPUT, // Port A Pin 3
	OUTPUT, // Port A Pin 4
	OUTPUT, // Port A Pin 5
	OUTPUT, // Port A Pin 6
	INFREE, // Port A Pin 7
	OUTPUT, // Port B Pin 0
	OUTPUT, // Port B Pin 1
	OUTPUT, // Port B Pin 2  INT2
	OUTPUT, // Port B Pin 3
	OUTPUT, // Port B Pin 4
	OUTPUT, // Port B Pin 5
	OUTPUT, // Port B Pin 6
	OUTPUT, // Port B Pin 7
	OUTPUT, // Port C Pin 0
	OUTPUT, // Port C Pin 1
	OUTPUT, // Port C Pin 2
	OUTPUT, // Port C Pin 3
	OUTPUT, // Port C Pin 4
	OUTPUT, // Port C Pin 5
	OUTPUT, // Port C Pin 6
	INFREE, // Port C Pin 7
	INFREE, // Port D Pin 0
	OUTPUT, // Port D Pin 1
	INFREE, // Port D Pin 2  INT0
	INFREE, // Port D Pin 3  INT1
	INFREE, // Port D Pin 4
	INFREE, // Port D Pin 5
	INFREE, // Port D Pin 6
	OUTPUT, // Port D Pin 7
};