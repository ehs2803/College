#include "myLib.h"
#include "cortex_m4.h"
#include "math.h"
#include <stdio.h>

#define DMA_EN
#define QSPI_EN
#define QSPI_IMAGE_PAGE  1020
#define QSPI_PAGE_SIZE    256

extern uint32_t g_ui32SysClock;

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

//////////////////////////// BUZZER ///////////////////////////////////////

void BUZZER_clear(){
	GPTMTAILR = 0;
	GPTMTMATCHR = 0;
}
void Play(int freq){
	GPTMTAILR = freq;
	GPTMTMATCHR = freq/2;
}
void DelayForPlay(int DLY){
	//Watchdog Load(p.1185)
	WDT1LOAD = DLY * 1000000;
	while(!(WDT1CTL & 0x80000000));
	//Watchdog Control(p.1187)
	WDT1CTL = 0x1;

	while(WDT1VALUE > 20);
	WDT1CTL = 0x0;
	WDT1ICR = 0x1;
}

void BUZZER_init(){
	RCGCGPIO = RCGCGPIO | 0xA;

	GPIO_PORTB_DIR = GPIO_PORTB_DIR | 0x04;
	GPIO_PORTD_DIR = GPIO_PORTD_DIR | 0x10;

	GPIO_PORTB_AFSEL = GPIO_PORTB_AFSEL | 0x4;			// Timer
	GPIO_PORTD_AFSEL = GPIO_PORTD_AFSEL & (~ (0x10));

	GPIO_PORTB_PC = GPIO_PORTB_PC | 0x30;
	GPIO_PORTD_PC = GPIO_PORTD_PC | 0x300;

	GPIO_PORTB_DR2R = GPIO_PORTB_DR2R & (~(0x4));
	GPIO_PORTD_DR2R = GPIO_PORTD_DR2R & (~(0x10));

	GPIO_PORTB_DR4R = GPIO_PORTB_DR4R | 0x4;
	GPIO_PORTD_DR4R = GPIO_PORTD_DR4R | 0x10;

	GPIO_PORTB_DR8R = GPIO_PORTB_DR8R | 0x4;
	GPIO_PORTD_DR8R = GPIO_PORTD_DR8R & (~(0x10));

	GPIO_PORTB_SLR = GPIO_PORTB_SLR & (~(0x4));
	GPIO_PORTD_SLR = GPIO_PORTD_SLR & (~(0x10));;

	GPIO_PORTB_DR12R = GPIO_PORTB_DR12R & (~(0x4));
	GPIO_PORTD_DR12R = GPIO_PORTD_DR12R & (~(0x10));

	GPIO_PORTB_PCTL = GPIO_PORTB_PCTL | 0x300;
	GPIO_PORTD_PCTL = GPIO_PORTD_PCTL & (~(0xF0000));

	GPIO_PORTB_DEN = GPIO_PORTB_DEN | 0x4;
	GPIO_PORTD_DEN = GPIO_PORTD_DEN | 0x10;
}

void TIMER_init(){
//-------------------- PWM --------------------
	RCGCTIMER = RCGCTIMER | 0x20;

	GPTMCC = 0x1;

	GPTMCFG = 0x4;

	GPTMTAMR = GPTMTAMR | 0xA;

	GPTMCTL = GPTMCTL | 0x40; // 0x41 . timer enable

	GPTMTAPR = 0x0;

//-------------------- WDT --------------------
	RCGCWD = RCGCWD | 0x2;

	INTEN0 = 0x1<<18;

	ALTCLKCFG = 0x0;

	RCGCGPIO = RCGCGPIO | 0x2020;

	GPIO_PORTF_AFSEL = GPIO_PORTF_AFSEL & (~ 0x2);
	GPIO_PORTP_AFSEL = GPIO_PORTP_AFSEL & (~ 0x2);

	GPIO_PORTF_DIR = GPIO_PORTF_DIR | 0x2;
	GPIO_PORTP_DIR = GPIO_PORTP_DIR & ~(0x2);

	GPIO_PORTF_PC = GPIO_PORTF_PC | 0xC;
	GPIO_PORTF_DR2R = GPIO_PORTF_DR2R & (~PIN1);
	GPIO_PORTF_DR4R = GPIO_PORTF_DR4R | 0x2;

	GPIO_PORTF_DR8R = GPIO_PORTF_DR8R | 0x2;
	GPIO_PORTF_SLR = GPIO_PORTF_SLR & (~0x2);
	GPIO_PORTF_DR12R = GPIO_PORTF_DR12R & (~0x2);

	GPIO_PORTF_DEN = GPIO_PORTF_DEN | 0x2;
	GPIO_PORTP_DEN = GPIO_PORTP_DEN | 0x2;
}

void WDTinitISR(void){
	// WDT
	WDT1ICR = 0x1;
}

/////////////////////////// UART /////////////////////////////////////////




void UART_init(float BRD, int BRDI, int BRDF) {
	//UART Run Mode Clock Gating control(p.406)
	RCGCUART = RCGCUART | (0x01 << 0) | (0x01 << 3)/*(Bluetooth)*/;
	//GPIO Run Mode Clock Gating control(p.400)
	RCGCGPIO = RCGCGPIO | (0x01 << 0) | (0x01 << 8);

	//(p.806)
	GPIO_PORTA_AFSEL = GPIO_PORTA_AFSEL | (0x01 << 0) | (0x01 << 1);

	//peripheral configuration (p.836)
	GPIO_PORTA_PC = GPIO_PORTA_PC | 0xF;

	//drive control register setting(slew rate control) (p.808~810, p.816, p.828)
	GPIO_PORTA_DR2R = GPIO_PORTA_DR2R & (~((0x01 << 0) | (0x01 << 1)));

	GPIO_PORTA_DR4R = GPIO_PORTA_DR4R | (0x01 << 0) | (0x01 << 1);

	GPIO_PORTA_DR8R = GPIO_PORTA_DR8R & (~((0x01 << 0) | (0x01 << 1)));

	GPIO_PORTA_SLR = GPIO_PORTA_SLR & (~((0x01 << 0) | (0x01 << 1)));

	GPIO_PORTA_DR12R = GPIO_PORTA_DR12R & (~((0x01 << 0) | (0x01 << 1)));

	//port control register (p.823)
	GPIO_PORTA_PCTL = 0x11;

	GPIO_PORTA_DEN = (0x01 << 0) | (0x01 << 1);

	//UART Control(p.1343)
	UARTCTL_UART0 = 0x300; // [9:8] RX,TX Enable [0] UART Disable
	UARTIBRD_UART0 = BRDI; // Baud Rate Setting
	UARTFBRD_UART0 = BRDF; // Baud Rate Setting

	//Uart Line Control(p.1341)
	UARTLCRH_UART0 = 0x60; // [6:5] 8bit Data

	//UART clock source(p.1368)
	UARTCC_UART0 = 0;

	//UART Control
	UARTCTL_UART0 = 0x301; // UART Enable

}

char UART_getch(void) {   //char단위 수신
	while (!(UART0FR & 0x40));   //full flag 확인하다 return
	return UART0_DATA;           //while문이어서 계속 대기
}

char UART_getkey(void) {
	if (!(UART0FR & 0x40)) {
		return 0;
	} else
		return UART0_DATA;
}

void UART_putch(uint8_t data) {   //char단위 송신
	UART0_DATA = data;
	while (!(UART0FR & 0x80));
}


void UART_putstr(char* pt) {
	while (*pt)
		UART_putch(*pt++);
}

void UART_printf(char *fmt, ...) {
	va_list ap;
	char ch_buffer[256];

	va_start(ap, fmt);
	vsprintf(ch_buffer, (const char*) fmt, ap);

	UART_putstr(ch_buffer);
	va_end(ap);
}

///////////////////////////////////////////////////////////////////////////////////////

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



void LCD_Init(unsigned long g_ui32SysClock) {
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

void DrawCircle(int x, int y, int r, int color){
	int i, j;


	for(i =x-r;i<x+r;i++ ){
		for(j = y-r;j<y+r;j++){
			if((j-y)*(j-y) <= ((r*r)-((i-x)*(i-x)))){
				PutPixel(i, j, color);
			}
		}
	}
}



void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color){
	int i, j;
	DrawLine(x1, y1, x2, y2, color);
	DrawLine(x1, y1, x3, y3, color);
	DrawLine(x2, y2, x3, y3, color);


	for(i =min(x1,x2,x3);i<max(x1,x2,x3);i++ ){
		for(j = min(y1,y2,y3);j<max(y1,y2,y3);j++){

			if(j<=LineFunc(x1,y1,x2,y2,i)&&j>=LineFunc(x1,y1,x3,y3,i)&&j<=LineFunc(x2,y2,x3,y3,i)){
				PutPixel(i, j, color);
			}
		}
	}
}

int LineFunc(float x1,float y1,float x2,float y2,float xin){
	int yout = ((y2-y1)/(x2-x1))*(xin-x1)+y1;
	return yout;
}

int max(int a,int b,int c){
	if(a>b&&a>c) return a;
	else if(b>a && b>c) return b;
	else return c;
}

int min(int a,int b,int c){
	if(a<b&&a<c) return a;
	else if(b<a && b<c) return b;
	else return c;
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


void delay(int count){
	while(count != 0){
		count--;
	}
}
