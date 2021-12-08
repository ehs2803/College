#include "cortex_m4.h"
#include "myLib.h"
#include "math.h"
#include "time.h"

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

uint32_t g_ui32SysClock;

int Melody_Name[] = {E1,D1,C1,D1,E1,E1,E1,D1,D1,D1,E1,E1,E1,E1,D1,C1,D1,E1,E1,E1,D1,D1,E1,D1,C1};

int main(void) {
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

	PUSH_init();
	LCD_Init(g_ui32SysClock);
	TIMER_init();
	BUZZER_init();
	WDTinitISR();

	GPTMCTL = GPTMCTL | 0x41;

	BUZZER_clear();

	int width = 480;
	int height = 272;
	int push_data;
	int mode = 0;


	DrawRect(0, 0, width/7, height, COLOR_RED);
	DrawRect(width/7, 0, width/7*2, height , COLOR_ORANGE);
	DrawRect(width/7*2, 0, width/7*3, height , COLOR_YELLOW);
	DrawRect(width/7*3, 0, width/7*4, height , COLOR_GREEN);
	DrawRect(width/7*4, 0, width/7*5, height , COLOR_BBLUE);
	DrawRect(width/7*5, 0, width/7*6, height , COLOR_BLUE);
	DrawRect(width/7*6, 0, width, height , COLOR_PUPLE);


	GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
	int i=0;
	while(1){
		push_data = (~GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) & (~GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					(~GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) & (~GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(push_data & 0x01) mode = 1;
		if(push_data & 0x02) mode = 2;
		//if(push_data & 0x04) mode = 3;
		//if(push_data & 0x08) mode = 4;


		if(mode==1){
			Scroll_left(buffer, 0, 0, width, height, 1);

			Play(Melody_Name[i]);
			i++;
			if(i==25) i=0;
			DelayForPlay(4);

			Scroll_left(buffer, 0, 0, width, height, 1);
		}
		if(mode==2){
			Scroll_right(buffer, 0, 0, width, height, 1);

			Play(Melody_Name[i]);
			i++;
			if(i==25) i=0;
			DelayForPlay(4);

			Scroll_right(buffer, 0, 0, width, height, 1);
		}

	}
}

