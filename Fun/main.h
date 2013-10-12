#define A0 PIN_A0

#define C0 PIN_C0
#define C1 PIN_C1
#define C2 PIN_C2
#define C3 PIN_C3

int round_robin[7] = {126,125,123,119,111,95,63};
int segment_numbers[10] = {64,121,36,48,25,18,2,120,0,16};

int h = 6;
int i = 9;

void setup();
void run();
void display(int input);