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
	//TouchScreenInit(g_ui32SysClock);
    //TouchScreenCallbackSet(PointerMessage);
    PUSH_init();
    int flag=0;
    int push_data;
    DrawRect_fill(buffer,0, 0, 480, 272, COLOR_WHITE);
    while(1){
    		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
    									~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
    									~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
    									~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );


    		if(!flag){
    			if(push_data & 0x01){
    				flag=1;
    				DrawImage(buffer, 190,86, 290, 186, Image00);

    			}
    			if(push_data & 0x02){
    				flag=1;
    				DrawImage(buffer, 190,86, 290, 186, Image01);
    			}
    			if(push_data & 0x04){
    				DrawImage(buffer, 190,86, 290, 186, Image02);

    			}
    			if(push_data & 0x08){
    				DrawImage(buffer, 190,86, 290, 186, Image03);

    			}
    		}
    		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
    				!(push_data & 0x4) &&!(push_data & 0x8)){
    			flag=0;
    		}
    		delay(900000);
    	}
	return 0;
}




void delay(int count){
	while(count != 0){
		count--;
	}
}
