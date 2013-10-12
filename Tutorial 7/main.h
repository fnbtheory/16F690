#define A0 PIN_A0

#define DB0 PIN_C0
#define DB1 PIN_C1
#define DB2 PIN_C2
#define DB3 PIN_C3
#define DB4 PIN_C4
#define DB5 PIN_C5
#define DB6 PIN_C6
#define DB7 PIN_C7

#define VC PIN_B4
#define RS PIN_B5
#define RW PIN_B6
#define E PIN_B7

void setup();
void setup_lcd();
void run();
void display(char input);
void clear();