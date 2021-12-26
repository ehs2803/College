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


	uint8_t code;

	float BRD;
	int   BRDI;
	int   BRDF;
	uint32_t ui32SysClock;

	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
		                               SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
		                               SYSCTL_CFG_VCO_480), 120000000);
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
										SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
										SYSCTL_CFG_VCO_480), 120000000);
	//uart baud rate(p.1339)
	BRD = (float)ui32SysClock / (16 * 115200);
	BRDI = (int)BRD;
	BRDF = (int)(((BRD - (int)BRD)*64) + 0.5);


	UART_init(BRD, BRDI, BRDF);

	TIMER_init();
	BUZZER_init();
	GPTMCTL = GPTMCTL | 0x41;
	BUZZER_clear();
	WDTinitISR();

	LCD_Init(g_ui32SysClock);


	int x1=190, x2=290, y1=86, y2=186;
	int tempx1=190, tempx2=290, tempy1=86, tempy2=186;
	DrawRect(x1,y1,x2,y2,COLOR_RED);

	while(1){

		code = UART_getch();
		UART_putch(code);

		if(code == 'w'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			y1 += 1;
			y2 += 1;
		}
		if(code == 'a'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(D1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			x1 -= 1;
			x2 -= 1;
		}

		if(code == 's'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(E1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			y1 -= 1;
			y2 -= 1;
		}
		if(code == 'd'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(F1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			x1 += 1;
			x2 += 1;
		}

		if(code == 'W'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			y1 += 5;
			y2 += 5;
		}
		if(code == 'A'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(D1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			x1 -= 5;
			x2 -= 5;
		}
		if(code == 'S'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(E1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			y1 -= 5;
			y2 -= 5;
		}
		if(code == 'D'){
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(F1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			x1 += 5;
			x2 += 5;
		}
		WDT1LOAD = 0xffffffff;

		if(x2 > 480 || x1 < 0 || y1 < 0 || y2 > 272){
			x1 = tempx1;
			x2 = tempx2;
			y1 = tempy1;
			y2 = tempy2;
		}
		else{
			DrawRect(tempx1,tempy1,tempx2,tempy2,COLOR_GREEN);
			DrawRect(x1,y1,x2,y2,COLOR_RED);

			tempx1 = x1;
			tempx2 = x2;
			tempy1 = y1;
			tempy2 = y2;
		}


	}
}

