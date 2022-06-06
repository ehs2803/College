#include "cortex_m4.h"
#include "myLib.h"
#include "math.h"
#include "time.h"

#define COLOR_BLUE		0x001f
#define COLOR_GREEN		0x07E0
#define COLOR_RED		0xF000
#define COLOR_WHITE		0xFFFF
#define COLOR_BLACK		0x0000
#define COLOR_YELLOW	0xffA0
#define COLOR_ORANGE    0xfac0
#define COLOR_CYAN     0x0fff
#define COLOR_PUPLE     0xd00f

#define Image00			0x00000
#define Image01			0x40000
#define Image02			0x80000
#define Image03			0xc0000
#define Image04			0x100000
#define Image05			0x140000
#define Image06			0x180000
#define Image07			0x1c0000

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y);
extern int32_t user_X, user_Y;
uint32_t g_ui32SysClock;

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];


//int Melody_Name[] = {E1,D1,C1,D1,E1,E1,E1,D1,D1,D1,E1,E1,E1,E1,D1,C1,D1,E1,E1,E1,D1,D1,E1,D1,C1};
//int PlayList[] = { C1, D1, E1, F1, G1, A1, B1 };
//int colorlist[] = {COLOR_RED, COLOR_ORANGE ,COLOR_YELLOW};
int count=0;
//int nlist[] = {1,2,3,4,5,6,7,8};
int mode=0;
int cnt_touch=0;
int rx1, rx2, ry1, ry2;
int checkmade=0;
int checktouchcnt=0;
int checkimage=0;
int checksroll=0;
int cx, cy;
int nx,ny;

int main(void) {
	int width = 480;
	int height = 272;
	float BRD;
	int   BRDI;
	int   BRDF;

	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
										SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
										SYSCTL_CFG_VCO_480), 120000000);

	BRD = (float)g_ui32SysClock / (16 * 115200);
	BRDI = (int)BRD;
	BRDF = (int)(((BRD - (int)BRD)*64) + 0.5);
	//Uart
	Uart_Init(BRD, BRDI, BRDF);

    LED_init();
    DIP_init();
    PUSH_init();

    FND_init();


	//LCD
	LCD_Init(g_ui32SysClock);
	//Touch
	TouchScreenInit(g_ui32SysClock);
    TouchScreenCallbackSet(PointerMessage);

	//Buzzer
	TIMER_init();
	BUZZER_init();
	GPTMCTL = GPTMCTL | 0x41;
	BUZZER_clear();
	WDTinitISR();


	//3¹ø
	while(1){

	}



}

// 3¹ø
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y){
    if(user_X >= 0 && user_X < 480 && user_Y >= 0 && user_Y < 272){
    	Uart_Printf("TEST 0 x : %d, y : %d \n\r", user_X, user_Y);
    	if(checkmade==0){
        	DrawRect_fill(buffer, user_X-25, user_Y-25, user_X+25, user_Y+25, COLOR_RED);
        	checkmade=1;
        	cx=user_X;
        	nx=user_X;
        	cy=user_Y;
        	ny=user_Y;
        	delay(1000000);
    	}
    	if(checkmade==1){
    		if(user_X>=cx-25 && user_X<=cx+25 && user_Y>=cy-25 && user_Y<=cy+25){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(4);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			WDT1LOAD = 0xffffffff;


			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(4);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			WDT1LOAD = 0xffffffff;

			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(4);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			WDT1LOAD = 0xffffffff;

			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(4);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			WDT1LOAD = 0xffffffff;

    		}
    		else{
    			int i;
    			nx=user_X;
    			ny=user_Y;
    			int cntx=(nx-cx)/5;
    			int cnty=(ny-cy)/5;
    			for(i=0;i<cntx;i++){
        			DrawRect_fill(buffer, 0, 0, 480, 272, COLOR_GREEN);
        			DrawRect_fill(buffer, cx-25+5, cy-25, cx+25+5, cy+25, COLOR_RED);
        			delay(1000000);
        			cx=cx+5;

    			}
    			for(i=0;i<cnty;i++){
        			DrawRect_fill(buffer, 0, 0, 480, 272, COLOR_GREEN);
        			DrawRect_fill(buffer, cx-25, cy-25+5, cx+25, cy+25+5, COLOR_RED);
        			delay(1000000);
        			cy=cy+5;

    			}
    		
    			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
    			Play(E1);
    			DelayForPlay(4);
    			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
    			WDT1LOAD = 0xffffffff;


    			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
    			Play(E1);
    			DelayForPlay(4);
    			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
    			WDT1LOAD = 0xffffffff;

    			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
    			Play(E1);
    			DelayForPlay(4);
    			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
    			WDT1LOAD = 0xffffffff;

    			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
    			Play(E1);
    			DelayForPlay(4);
    			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
    			WDT1LOAD = 0xffffffff;


    			}


    		}

    	}
     delay(1000000);
}
