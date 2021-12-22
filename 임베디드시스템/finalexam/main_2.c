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



	
	// 2번
	while(1){
		WRITE_FND(6,cnt_touch);
		if(checksroll==1){
			Scroll_left(buffer, 0, 0, width, height, 1);
		}
	}


}



// 2번
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y){
    if(user_X >= 0 && user_X < 480 && user_Y >= 0 && user_Y < 272){
    	//Uart_Printf("TEST 0 x : %d, y : %d \n\r", user_X, user_Y);
    	cnt_touch++;
    	if(checkmade==1){
    		if(user_X>=rx1 && user_X<=rx2 && user_Y>=ry1 && user_Y<=ry2){// 내부
    			DrawRect_fill(buffer, 0,0,480,272,COLOR_GREEN);
    			DrawRect_fill(buffer, 240-50,136-50, 240+50, 136+50 ,COLOR_BLUE);
    			checkmade=2;
    		}

    	}
    	else if(checkmade==2){
    		if(user_X>=190 && user_X<=290 && user_Y>=136-50 && user_Y<=186){
        		if(checkimage==0){
        			DrawImage(buffer, 240-50,136-50, 240+50, 136+50, Image01);
        			checkimage=1;
        		}
        		else{
        			checksroll=1;
        		}
    		}

    	}
    	else{
    		if(checktouchcnt==0){
    			checktouchcnt=1;
    			rx1=user_X;
    			ry1=user_Y;
    		}
    		else if(checktouchcnt==1){
    			checktouchcnt=2;
    			rx2=user_X;
    			ry2=user_Y;
    			DrawRect_fill(buffer, rx1, ry1, rx2, ry2, COLOR_BLUE);
    			checkmade=1;
    		}
    	}

}
}


