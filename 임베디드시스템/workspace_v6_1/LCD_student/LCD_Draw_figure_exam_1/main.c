#include "cortex_m4.h"
#include "myLib.h"
#include "math.h"
#include "time.h"

#define COLOR_BLUE		0x001f
#define COLOR_GREEN		0x07E0
#define COLOR_RED		0xF800
#define COLOR_WHITE		0xFFFF
#define COLOR_BLACK		0x0000
#define COLOR_YELLOW	0xffA0

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

uint32_t g_ui32SysClock;

int main(void) {
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

	PUSH_init();
	LCD_init(g_ui32SysClock);

	int width = 480;
	int height = 272;
	int push_data;
	int mode = 0;

	DrawRect(		 0, 		 0, width / 2, height / 2, COLOR_BLUE);
	DrawRect(		 0, height / 2, width / 2, 	   height, COLOR_RED);
	DrawRect(width / 2, height / 2,   	width, 	   height, COLOR_GREEN);
	DrawRect(width / 2, 		 0, 	width, height / 2, COLOR_YELLOW);

	while(1){
		push_data = (~GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) & (~GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					(~GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) & (~GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(push_data & 0x01) mode = 1;
		if(push_data & 0x02) mode = 2;
		if(push_data & 0x04) mode = 3;
		if(push_data & 0x08) mode = 4;

		if(mode == 1) Scroll_left(buffer, 0, 0, width, height, 1);
		if(mode == 2) Scroll_right(buffer, 0, 0, width, height, 1);
		if(mode == 3) Scroll_up(buffer, 0, 0, width, height, 1);
		if(mode == 4) Scroll_down(buffer, 0, 0, width, height, 1);

	}
}

