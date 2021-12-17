#include "cortex_m4.h"
#include "myLib.h"
#include "math.h"
#include "time.h"

#define COLOR_BLUE		0x001f
#define COLOR_GREEN		0x07E0
#define COLOR_RED		0xF800
#define COLOR_WHITE		0xFFFF
#define COLOR_BLACK		0x0000

#define Image00			0x00000
#define Image01			0x40000

//volatile unsigned int variable0 = 0;

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y);
extern int32_t user_X, user_Y;
uint32_t g_ui32SysClock;

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

int step=1;

int main(void) {

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
	//LCD
	LCD_Init(g_ui32SysClock);
	//Touch
	TouchScreenInit(g_ui32SysClock);
    TouchScreenCallbackSet(PointerMessage);

	while (1){
		if(step==1){
			DrawRect_fill(buffer, 100, 100, 200, 200, COLOR_RED);
		}
		else if(step==2){
			DrawRect_fill(buffer, 100, 100, 200, 200, COLOR_BLUE);
		}
		else{
			DrawRect_fill(buffer, 100, 100, 200, 200, COLOR_BLACK);
		}
	}

	return 0;
}

int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y){
    if(user_X >= 0 && user_X < 480 && user_Y >= 0 && user_Y < 272){
    	int x = user_X, y = user_Y;
    	if(x<200 && x>100 && y<200 & y>100){
    		step++;
    		if(step==4) step=1;
    	}
    	delay(1000000);

    }
	return 0;
}


void delay(int count){
	while(count != 0){
		count--;
	}
}
