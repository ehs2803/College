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

unsigned char buffer[LCD_WIDTH * LCD_HEIGHT];
int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y);
extern int32_t user_X, user_Y;
uint32_t g_ui32SysClock;

void PutPixel2(int x, int y, int color);
void DrawRect1(int x1, int y1, int x2, int y2, int color);
int main(void) {
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

	LCD_Init(g_ui32SysClock);
	//Touch
//TouchScreenInit(g_ui32SysClock);
	//TouchScreenCallbackSet(PointerMessage);
	//LCD_Init(g_ui32SysClock);
	//DrawRect1(100, 100,200,200 , COLOR_RED);
	while(1){
		DrawRect1(100, 100,200,200 , COLOR_BLUE);
	}
}

int32_t PointerMessage(uint32_t ui32Message, int32_t i32X, int32_t i32Y){
    if(user_X >= 0 && user_X < 480 && user_Y >= 0 && user_Y < 272){
    	//Uart_Printf("TEST 0 x : %d, y : %d \n\r", user_X, user_Y);

    }
	return 0;
}

void PutPixel2(int x, int y, int color){
   WriteCommand(LCD_X_RAM_ADDR_REG);      // Set X
   WriteData(x >> 8);
   WriteData(x & 0xFF);
   WriteData(x >> 8);
   WriteData(x & 0xff);

   WriteCommand(LCD_Y_RAM_ADDR_REG);      // Set Y
   WriteData(y >> 8);
   WriteData(y & 0xFF);
   WriteData(y >> 8);
   WriteData(y & 0xff);

   WriteCommand(LCD_RAM_DATA_REG);
   WriteData(color);
}
void DrawRect1(int x1, int y1, int x2, int y2, int color){
   int i, j;
   for(j = x1;j < x2;j++){
      for(i = y1;i < y2;i++){
         PutPixel2(j, i, color);
      }
   }
}
