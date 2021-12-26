#include "cortex_m4.h"
#include "myLib.h"
#include "math.h"
#include "time.h"

#define COLOR_BLUE		0x001f
#define COLOR_GREEN		0x07E0
#define COLOR_RED		0xF800
#define COLOR_WHITE		0xFFFF
#define COLOR_BLACK		0x0000

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];

uint32_t g_ui32SysClock;

int main(void) {
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

	LCD_Init(g_ui32SysClock);

	DrawLine(190, 86, 290, 86, COLOR_RED);

	DrawLine(190, 186, 290, 186, COLOR_RED);

	DrawLine(190, 86, 190, 186, COLOR_RED);

	DrawLine(290, 86, 290, 186, COLOR_RED);

	DrawLine(0, 0, 480, 272, COLOR_BLUE);

	DrawLine(480, 0, 0, 272, COLOR_BLUE);

	while(1){

	}
}

