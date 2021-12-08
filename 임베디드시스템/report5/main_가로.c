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


	DrawRect(0, height/7*6, width, height, COLOR_RED);
	DrawRect(0, height/7*5, width, height/7*6 , COLOR_ORANGE);
	DrawRect(0, height/7*4, width, height/7*5 , COLOR_YELLOW);
	DrawRect(0, height/7*3, width, height/7*4 , COLOR_GREEN);
	DrawRect(0, height/7*2, width, height/7*3 , COLOR_BBLUE);
	DrawRect(0, height/7*1, width, height/7*2 , COLOR_BLUE);
	DrawRect(0, 0, width, height/7 , COLOR_PUPLE);


	GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
	int i=0;
	while(1){
		push_data = (~GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) & (~GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					(~GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) & (~GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		//if(push_data & 0x01) mode = 1;
		//if(push_data & 0x02) mode = 2;
		if(push_data & 0x04) mode = 3;
		if(push_data & 0x08) mode = 4;

		if(mode==3){
			Scroll_up(buffer, 0, 0, width, height, 1);

			Play(Melody_Name[i]);
			i++;
			if(i==25) i=0;
			DelayForPlay(4);

			Scroll_up(buffer, 0, 0, width, height, 1);
		}
		if(mode==4){
			Scroll_down(buffer, 0, 0, width, height, 1);

			Play(Melody_Name[i]);
			i++;
			if(i==25) i=0;
			DelayForPlay(4);

			Scroll_down(buffer, 0, 0, width, height, 1);
		}
	}
}

