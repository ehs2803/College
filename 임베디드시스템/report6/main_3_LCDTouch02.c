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
#define Image02			0x80000
#define Image03			0xc0000
#define Image04			0x100000
#define Image05			0x140000
#define Image06			0x180000
#define Image07			0x1c0000

//volatile unsigned int variable0 = 0;

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y);
extern int32_t user_X, user_Y;
uint32_t g_ui32SysClock;

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

int step1=1, step2=1, step3=1, step4=1;

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
		if(step1==1){
			DrawImage(buffer, 0,136, 240, 272, Image00);
		}
		else{
			DrawImage(buffer, 0,136, 240, 272, Image01);
		}

		if(step2==1){
			DrawImage(buffer, 240,136, 480, 272, Image02);
		}
		else{
			DrawImage(buffer, 240,136, 480, 272, Image03);
		}

		if(step3==1){
			DrawImage(buffer, 0,0, 240, 136, Image04);
		}
		else{
			DrawImage(buffer, 0,0, 240, 136, Image05);
		}

		if(step4==1){
			DrawImage(buffer, 240,0, 480, 136, Image06);
		}
		else{
			DrawImage(buffer, 240,0, 480, 136, Image07);
		}
	}

	return 0;
}

int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y){
    if(user_X >= 0 && user_X < 480 && user_Y >= 0 && user_Y < 272){
    	int x = user_X, y = user_Y;
    	if(x<240 && x>0 && y<272 & y>136){
    		step1++;
    		if(step1==3) step1=1;
    	}
    	if(x<480 && x>240 && y<272 & y>136){
    		step2++;
    		if(step2==3) step2=1;
    	}
    	if(x<240 && x>0 && y<136 & y>0){
    		step3++;
    		if(step3==3) step3=1;
    	}
    	if(x<480 && x>240 && y<136 & y>0){
    		step4++;
    		if(step4==3) step4=1;
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
