#ifndef SEGMENT_H_
#define SEGMENT_H_


#define SEGMENT_PORT PORTC
#define BUTTON_DDPORT DDRD

#define BUTTON1_PU (!(READ_BIT(PIND,3)))
#define BUTTON2_PD ((READ_BIT(PIND,4)))
#define BUTTON3_PU (!(READ_BIT(PIND,5)))

static u8 flag1=0;
static u8 flag2=0;
static u8 flag3=0;

// Task 1  ------------------------
#define RED_LED 0
#define BLUE_LED 1
#define GREEN_LED 2
#define TRAFFIC_PORT PORTD
// --------------------------------
// Task 2
#define COUNTER_TIME 20
u8 Counter=0;
// --------------------------------
//Task 4 ------------------------
#define STOPWATCH_TIME 5
u8 i;
u8 Watch_Timer=STOPWATCH_TIME;
u8 Timer_IsPaused=0;
u8 Is_Increment=0;
u8 Is_Decrement=0 ;
u8 IS_Toggle=0;
// --------------------------------

void segment_dis_Switch(u8 n);
void segment_dis_LookUpTable(u8 n);
void segment_BinaryTodecimal(u8 n);
void Traffic_lights(void);
void Segment_2Buttons_Click(void);
void Segment_2Buttons_Hold(void);
void STOPWatch(void);




#endif /* SEGMENT_H_ */