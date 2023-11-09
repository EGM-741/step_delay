#define motor1_1 7
#define motor1_2 8
#define motor2_1 12
#define motor2_2 13
#define speedpin1 9
#define speedpin2 10
#define encod1_1 2
#define encod1_2 4
#define encod2_1 3
#define encod2_2 5
byte speed = 60;
byte acc = 1;
bool start = 1;
volatile long interruptCounter1 = 0;
volatile long interruptCounter2 = 0;