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


unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

uint32_t g_ui32SysClock;

int Melody_Name[] = {E1,D1,C1,D1,E1,E1,E1,D1,D1,D1,E1,E1,E1,E1,D1,C1,D1,E1,E1,E1,D1,D1,E1,D1,C1};
void mDelayForPlay(int DLY);
int width = 480;
int height = 272;
int main(void) {
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);
	LCD_Init(g_ui32SysClock);
	PUSH_init();
	TIMER_init();
	BUZZER_init();
	WDTinitISR();
	GPTMCTL = GPTMCTL | 0x41;
	BUZZER_clear();
	GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);

	int push_data;
	int mode = 0;


	DrawRect(0, 0, width/7, height, COLOR_RED);
	DrawRect(width/7, 0, width/7*2, height , COLOR_ORANGE);
	DrawRect(width/7*2, 0, width/7*3, height , COLOR_YELLOW);
	DrawRect(width/7*3, 0, width/7*4, height , COLOR_GREEN);
	DrawRect(width/7*4, 0, width/7*5, height , COLOR_CYAN);
	DrawRect(width/7*5, 0, width/7*6, height , COLOR_BLUE);
	DrawRect(width/7*6, 0, width, height , COLOR_PUPLE);


	int i=0;
	while(1){
		push_data = (~GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) & (~GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					(~GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) & (~GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(push_data & 0x01) mode = 1;
		if(push_data & 0x02) mode = 2;
		if(push_data & 0x04) mode = 3;
		if(push_data & 0x08) mode = 4;


		if(mode==1){
			Scroll_left(buffer, 0, 0, width, height, 3);

			Play(Melody_Name[i]);
			i++;
			if(i==25) i=0;
			DelayForPlay(4);

			Scroll_left(buffer, 0, 0, width, height, 3);
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

void mDelayForPlay(int DLY){
	//Watchdog Load(p.1185)
	WDT1LOAD = DLY * 1000000;
	while(!(WDT1CTL & 0x80000000));
	//Watchdog Control(p.1187)
	WDT1CTL = 0x1;

	while(WDT1VALUE > 20){
		Scroll_left(buffer, 0, 0, width, height, 1);
	}
	Scroll_left(buffer, 0, 0, width, height, 1);
	WDT1CTL = 0x0;
	WDT1ICR = 0x1;
}
