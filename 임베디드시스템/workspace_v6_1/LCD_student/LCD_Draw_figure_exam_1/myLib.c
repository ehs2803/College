/*
 * MyLib.c
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#include "myLib.h"
#include "cortex_m4.h"

#define DMA_EN
#define QSPI_EN
#define QSPI_IMAGE_PAGE  1020
#define QSPI_PAGE_SIZE    256

extern uint32_t g_ui32SysClock;

inline uint16_t ReadData(void) {
	//
	// Split the write into two bytes and pass them to the LCD controller.
	//
	//LCDIDDDataWrite(LCD0_BASE, 0, ui16Data);
	return LCDIDDDataRead(LCD0_BASE, 0);
	//LCDIDDDataWrite(LCD0_BASE, 0, ui16Data & 0xff);
}

inline void WriteData(uint16_t ui16Data) {
	//
	// Split the write into two bytes and pass them to the LCD controller.
	//
	LCDIDDDataWrite(LCD0_BASE, 0, ui16Data);
	//LCDIDDDataWrite(LCD0_BASE, 0, ui16Data & 0xff);
}

inline void WriteCommand(uint16_t ui8Data) {
	//
	// Pass the write on to the controller.
	//
	LCDIDDCommandWrite(LCD0_BASE, 0, ui8Data);
}
void PUSH_init(){

	RCGCGPIO = RCGCGPIO | 0x3210;

	GPIO_PORTP_DIR = GPIO_PORTP_DIR & ~(0x01<<1);
	GPIO_PORTN_DIR = GPIO_PORTN_DIR & ~(0x01<<3);
	GPIO_PORTE_DIR = GPIO_PORTE_DIR & ~(0x01<<5);
	GPIO_PORTK_DIR = GPIO_PORTK_DIR & ~(0x01<<7);


	GPIO_PORTP_AFSEL = GPIO_PORTP_AFSEL & (~ (0x01<<1));
	GPIO_PORTN_AFSEL = GPIO_PORTN_AFSEL & (~ (0x01<<3));
	GPIO_PORTE_AFSEL = GPIO_PORTE_AFSEL & (~ (0x01<<5));
	GPIO_PORTK_AFSEL = GPIO_PORTK_AFSEL & (~ (0x01<<7));

	GPIO_PORTP_DEN = GPIO_PORTP_DEN | (0x01<<1);
	GPIO_PORTN_DEN = GPIO_PORTN_DEN | (0x01<<3);
	GPIO_PORTE_DEN = GPIO_PORTE_DEN | (0x01<<5);
	GPIO_PORTK_DEN = GPIO_PORTK_DEN | (0x01<<7);
}

void LCD_init(unsigned long g_ui32SysClock) {
	static uint8_t pui8DMAControlTable[1024];
	tLCDIDDTiming sTimings;
	unsigned long ulClockMS;

	ulClockMS = g_ui32SysClock / (3 * 1000);

	PinoutSet();
	SysCtlPeripheralEnable(SYSCTL_PERIPH_LCD0);

	#ifdef DMA_EN
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);
	#endif

		SysCtlDelay(50 * ulClockMS);
		LCDModeSet(LCD0_BASE, LCD_MODE_LIDD, g_ui32SysClock, g_ui32SysClock);
		LCDDMAConfigSet(LCD0_BASE, LCD_DMA_BURST_4);
		LCDIDDConfigSet(LCD0_BASE, LIDD_CONFIG_ASYNC_MPU80);
		sTimings.ui8WSSetup = CYCLES_FROM_TIME_NS(g_ui32SysClock, 4);
		sTimings.ui8WSDuration = CYCLES_FROM_TIME_NS(g_ui32SysClock, 10);
		sTimings.ui8WSHold = CYCLES_FROM_TIME_NS(g_ui32SysClock, 1);
		sTimings.ui8RSSetup = CYCLES_FROM_TIME_NS(g_ui32SysClock, 0);
		sTimings.ui8RSDuration = CYCLES_FROM_TIME_NS(g_ui32SysClock, 45);
		sTimings.ui8RSHold = CYCLES_FROM_TIME_NS(g_ui32SysClock, 1);
		sTimings.ui8DelayCycles = CYCLES_FROM_TIME_NS(g_ui32SysClock, 35);
		LCDIDDTimingSet(LCD0_BASE, 0, &sTimings);



		//
		// Enter sleep mode (if we are not already there).
		//
		WriteCommand(0x0001);	// software reset

		SysCtlDelay(ulClockMS);

		WriteCommand(0x00E2);	//PLL multiplier, set PLL clock to 120M
		WriteData(0x0014);	//29
		WriteData(0x0003);
		WriteData(0x0004);

		WriteCommand(0x00E0);  // PLL enable
		WriteData(0x0001);

		SysCtlDelay(ulClockMS / 10);

		WriteCommand(0x00E0);
		WriteData(0x0003);

		SysCtlDelay(ulClockMS / 5);

		WriteCommand(0x00E6);	//PLL setting for PCLK, depends on resolution
		WriteData(0x0003);	//04
		WriteData(0x00A0);	//B9
		WriteData(0x0000);	//38

		WriteCommand(0x00B0);	//LCD SPECIFICATION
		WriteData(0x0020);	// 24-bit
		WriteData(0x0000);	// TFT-mode
		WriteData(0x01); 	//Set HDP
		WriteData(0xDF);
		WriteData(0x01);
		WriteData(0x0F);
		WriteData(0x00);	// RGB

		WriteCommand(0x00B4);	//HSYNC
		WriteData(0x02);
		WriteData(0x0D);
		WriteData(0x00);
		WriteData(0x25);
		WriteData(0x02);
		WriteData(0x00);
		WriteData(0x00);
		WriteData(0x00);

		WriteCommand(0x00B6);	//VSYNC
		WriteData(0x01);
		WriteData(0x1E);
		WriteData(0x00);
		WriteData(0x08);
		WriteData(0x01);
		WriteData(0x00);
		WriteData(0x00);

		WriteCommand(0xB8);
		WriteData(0x0007);	//GPIO3=input, GPIO[2:0]=output
		WriteData(0x0001);	//GPIO0 normal

		WriteCommand(0xBA);
		WriteData(0x000F);	//GPIO[3:0] out 1

		WriteCommand(0x36);	//rotation
		WriteData(0x0001);

		WriteCommand(0x00F0); //pixel data interface
		WriteData(0x0003);

		SysCtlDelay(ulClockMS / 2);

		WriteCommand(0x00BE); //set PWM for B/L
		WriteData(0x0001); //06 frequency
		WriteData(0x00FF); //C0 duty
		WriteData(0x0009); //bit[3]DBC enable,bit[0]PWM enable
		WriteData(0x00FF); //C0 DBC manual brightness
		WriteData(0x0088); //10 DBC minimum brightness
		WriteData(0x0000); //08 Brightness prescaler

		WriteCommand(0x00d4);
		WriteData(0x0000);
		WriteData(0x001C);
		WriteData(0x0020);
		WriteData(0x0000);
		WriteData(0x0046);
		WriteData(0x0050);
		WriteData(0x0000);
		WriteData(0x00A8);
		WriteData(0x00C0);

		WriteCommand(0x00d0);
		WriteData(0x0001); //DBC disable

		//
		// Set the X address of the display cursor.
		//
		WriteCommand(LCD_X_RAM_ADDR_REG);
		WriteData(0);
		WriteData(0);
		WriteData(HDP_S >> 8);
		WriteData(HDP_S & 0xff);
		//
		// Set the Y address of the display cursor.
		//
		WriteCommand(LCD_Y_RAM_ADDR_REG);
		WriteData(0);
		WriteData(0);
		WriteData(VDP_S >> 8);
		WriteData(VDP_S & 0xFF);

		//
		// Write the pixel value.
		//
		WriteCommand(LCD_RAM_DATA_REG);
		for (ulClockMS = 0; ulClockMS < (LCD_HEIGHT * LCD_WIDTH); ++ulClockMS) {
			WriteData(0x07E0);
		}
		WriteCommand(0x0029); //display on


		GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_5);
		GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
		GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_5, GPIO_DIR_MODE_OUT);

	#ifdef DMA_EN
	    uDMAEnable();
	    uDMAControlBaseSet(&pui8DMAControlTable[0]);
	    uDMAChannelAttributeDisable(UDMA_CHANNEL_SW, UDMA_ATTR_ALL);
	#endif

	#ifdef QSPI_EN
		SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
		SysCtlPeripheralReset(SYSCTL_PERIPH_SSI3);
		MX66L51235FInit(g_ui32SysClock);

	#endif
}


void RestoreBackground(unsigned char *buffer, int x1, int y1, int x2, int y2, int image){
	int i;
	unsigned long ulClockMS;

	ulClockMS = g_ui32SysClock / (3 * 1000);

	WriteCommand(LCD_X_RAM_ADDR_REG);		// Set X
	WriteData(x1 >> 8);
	WriteData(x1 & 0xFF);
	WriteData(x2-1 >> 8);
	WriteData(x2-1 & 0xff);

	WriteCommand(LCD_Y_RAM_ADDR_REG);		// Set Y
	WriteData(y1 >> 8);
	WriteData(y1 & 0xFF);
	WriteData(y2-1 >> 8);
	WriteData(y2-1 & 0xff);

	WriteCommand(LCD_RAM_DATA_REG);

	for(i = y1; i <= y2; ++i){
		MX66L51235FRead(image + (i*480*2 + x1*2), buffer, (x2-x1)*2);

		uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
		uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[0], (void *)0x44050018, (x2-x1)/2);
		uDMAChannelEnable(UDMA_CHANNEL_SW);
		uDMAChannelRequest(UDMA_CHANNEL_SW);
		SysCtlDelay(ulClockMS /DIV_MS);

		uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
		uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(x2-x1)], (void *)0x44050018, (x2-x1)/2);
		uDMAChannelEnable(UDMA_CHANNEL_SW);
		uDMAChannelRequest(UDMA_CHANNEL_SW);
		SysCtlDelay(ulClockMS /DIV_MS);
	}

	SetFullFrame();
}

void PutPixel(int x, int y, int color){
	WriteCommand(LCD_X_RAM_ADDR_REG);		// Set X
	WriteData(x >> 8);
	WriteData(x & 0xFF);
	WriteData(x >> 8);
	WriteData(x & 0xff);

	WriteCommand(LCD_Y_RAM_ADDR_REG);		// Set Y
	WriteData(y >> 8);
	WriteData(y & 0xFF);
	WriteData(y >> 8);
	WriteData(y & 0xff);

	WriteCommand(LCD_RAM_DATA_REG);
	WriteData(color);
}

void DrawLine(int x1, int y1, int x2, int y2, int color){
	int dx,dy,e;
	dx=x2-x1;
	dy=y2-y1;

	if(dx>=0)
	{
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 1/8 octant
			{
				e=dy-dx/2;
				while(x1<=x2)
				{
					PutPixel(x1, y1, color);

					if(e>0){y1+=1;e-=dx;}
					x1+=1;
					e+=dy;
				}
			}
			else		// 2/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					PutPixel(x1, y1, color);

					if(e>0){x1+=1;e-=dy;}
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 8/8 octant
			{
				e=dy-dx/2;
				while(x1<=x2)
				{
					PutPixel(x1, y1, color);

					if(e>0){y1-=1;e-=dx;}
					x1+=1;
					e+=dy;
				}
			}
			else		// 7/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					PutPixel(x1, y1, color);

					if(e>0){x1+=1;e-=dy;}
					y1-=1;
					e+=dx;
				}
			}
		}
	}
	else //dx<0
	{
		dx=-dx;		//dx=abs(dx)
		if(dy >= 0) // dy>=0
		{
			if(dx>=dy) // 4/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					PutPixel(x1, y1, color);

					if(e>0){y1+=1;e-=dx;}
					x1-=1;
					e+=dy;
				}
			}
			else		// 3/8 octant
			{
				e=dx-dy/2;
				while(y1<=y2)
				{
					PutPixel(x1, y1, color);

					if(e>0){x1-=1;e-=dy;}
					y1+=1;
					e+=dx;
				}
			}
		}
		else		   // dy<0
		{
			dy=-dy;   // dy=abs(dy)

			if(dx>=dy) // 5/8 octant
			{
				e=dy-dx/2;
				while(x1>=x2)
				{
					PutPixel(x1, y1, color);

					if(e>0){y1-=1;e-=dx;}
					x1-=1;
					e+=dy;
				}
			}
			else		// 6/8 octant
			{
				e=dx-dy/2;
				while(y1>=y2)
				{
					PutPixel(x1, y1, color);

					if(e>0){x1-=1;e-=dy;}
					y1-=1;
					e+=dx;
				}
			}
		}
	}

	SetFullFrame();
}

void DrawRect(int x1, int y1, int x2, int y2, int color){
	int i, j;
	for(j = x1;j < x2;j++){
		for(i = y1;i < y2;i++){
			PutPixel(j, i, color);
		}
	}
}


void Scroll_left(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll){
	int i, j;
	static unsigned char temp_buffer[LCD_HEIGHT * 20];
	unsigned long ulClockMS = g_ui32SysClock / (3 * 1000);

	WriteCommand(LCD_Y_RAM_ADDR_REG);
	WriteData(y1 >> 8);
	WriteData(y1 & 0xFF);
	WriteData(y2-1 >> 8);
	WriteData(y2-1 & 0xff);

	for(j = x1; j <= x2; j+=scroll){
		if(j != x2){
			WriteCommand(LCD_X_RAM_ADDR_REG);
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(0x2E);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[i*(y2-y1)*2], (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		WriteCommand(LCD_X_RAM_ADDR_REG);
		if(j >= x2){
			WriteData((j - scroll)>>8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[i*(y2-y1)*2], (void *)0x44050018, (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		else if(j > x1){
			WriteData((j - scroll)>>8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[i*(y2-y1)*2], (void *)0x44050018, (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}

		}

		else if(j == x1){
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[i*(y2-y1)*2], &temp_buffer[i*(y2-y1)*2], (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
	}

	SetFullFrame();
}

void Scroll_right(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll){
	int i, j;
	static unsigned char temp_buffer[LCD_HEIGHT * 20];
	unsigned long ulClockMS = g_ui32SysClock / (3 * 1000);

	WriteCommand(LCD_Y_RAM_ADDR_REG);
	WriteData(y1 >> 8);
	WriteData(y1 & 0xFF);
	WriteData(y2-1 >> 8);
	WriteData(y2-1 & 0xff);

	for(j = x2; j >= x1; j-=scroll){
		if(j != x1){
			WriteCommand(LCD_X_RAM_ADDR_REG);
			WriteData((j - scroll) >> 8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(0x2E);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[i*(y2-y1)*2], (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		if(j == x2){
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[i*(y2-y1)*2], &temp_buffer[i*(y2-y1)*2], (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
		else if(j == x1){
			WriteCommand(LCD_X_RAM_ADDR_REG);
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[i*(y2-y1)*2], (void *)0x44050018, (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
		else if(j < x2){
			WriteCommand(LCD_X_RAM_ADDR_REG);
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[i*(y2-y1)*2], (void *)0x44050018, (y2-y1));
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
	}

	SetFullFrame();
}
void Scroll_down(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll){
	int i, j;
	static unsigned char temp_buffer[LCD_WIDTH * 20];
	unsigned long ulClockMS = g_ui32SysClock / (3 * 1000);

	WriteCommand(LCD_X_RAM_ADDR_REG);
	WriteData(x1 >> 8);
	WriteData(x1 & 0xFF);
	WriteData(x2-1 >> 8);
	WriteData(x2-1 & 0xff);

	for(j = y1; j <= y2; j+=scroll){
		if(j != y2){
			WriteCommand(LCD_Y_RAM_ADDR_REG);
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(0x2E);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[(i*2)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[(i*2+1)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		WriteCommand(LCD_Y_RAM_ADDR_REG);
		if(j >= y2){
			WriteData((j - scroll) >> 8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[(i*2)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[(i*2+1)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		else if(j>y1){
			WriteData((j - scroll) >> 8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2+1)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}

		}

		else if(j == y1){
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2)*(x2-x1)], &temp_buffer[(i*2)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2+1)*(x2-x1)], &temp_buffer[(i*2+1)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
	}

	SetFullFrame();
}

void Scroll_up(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll){
	int i, j;
	static unsigned char temp_buffer[LCD_WIDTH * 20];
	unsigned long ulClockMS = g_ui32SysClock / (3 * 1000);

	WriteCommand(LCD_X_RAM_ADDR_REG);
	WriteData(x1 >> 8);
	WriteData(x1 & 0xFF);
	WriteData(x2-1 >> 8);
	WriteData(x2-1 & 0xff);

	for(j = y2; j >= y1; j-=scroll){
		if(j != y1){
			WriteCommand(LCD_Y_RAM_ADDR_REG);
			WriteData((j - scroll) >> 8);
			WriteData((j - scroll) & 0xFF);
			WriteData((j - 1) >> 8);
			WriteData((j - 1) & 0xff);

			WriteCommand(0x2E);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[(i*2)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_NONE |  UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, (void *)0x44050018,  &buffer[(i*2+1)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}

		WriteCommand(LCD_Y_RAM_ADDR_REG);
		if(j == y2){
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2)*(x2-x1)], &temp_buffer[(i*2)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_16 | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2+1)*(x2-x1)], &temp_buffer[(i*2+1)*(x2-x1)], (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
		else if(j <= y1){
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[(i*2)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &temp_buffer[(i*2+1)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}
		}
		else if(j){
			WriteData(j >> 8);
			WriteData(j & 0xFF);
			WriteData((j + scroll - 1) >> 8);
			WriteData((j + scroll - 1) & 0xff);

			WriteCommand(LCD_RAM_DATA_REG);
			for(i = 0; i < scroll; i++){
				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);

				uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_16 | UDMA_SRC_INC_16 | UDMA_DST_INC_NONE | UDMA_ARB_8);
				uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, &buffer[(i*2+1)*(x2-x1)], (void *)0x44050018, (x2-x1)/2);
				uDMAChannelEnable(UDMA_CHANNEL_SW);
				uDMAChannelRequest(UDMA_CHANNEL_SW);
				SysCtlDelay(ulClockMS /DIV_MS);
			}

		}
	}

	SetFullFrame();
}


void SetFullFrame(){
	WriteCommand(LCD_X_RAM_ADDR_REG);
	WriteData(0);
	WriteData(0);
	WriteData(479 >> 8);
	WriteData(479 & 0xff);

	WriteCommand(LCD_Y_RAM_ADDR_REG);
	WriteData(0 >> 8);
	WriteData(0 & 0xFF);
	WriteData(271 >> 8);
	WriteData(271 & 0xff);
}
