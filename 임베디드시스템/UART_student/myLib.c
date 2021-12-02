/*
 * myLib.c
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#include "cortex_m4.h"
#include "myLib.h"

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

void LED_init(){
	//GPIO Run Mode Clock Gating control(p. 400)
	RCGCGPIO = RCGCGPIO | 0xC00;

	//direction (p.795)
	GPIO_PORTL_DIR = GPIO_PORTL_DIR | 0xF;
	GPIO_PORTM_DIR = GPIO_PORTM_DIR |0xF;

	//Digital enable (p.817)
	GPIO_PORTL_DEN = GPIO_PORTL_DEN | 0xF;
	GPIO_PORTM_DEN = GPIO_PORTM_DEN | 0xF;

	//Alternate Function Select(p.806)
	GPIO_PORTL_AFSEL = GPIO_PORTL_AFSEL & (~0xf);
	GPIO_PORTM_AFSEL = GPIO_PORTM_AFSEL & (~0xf);

	//port control register (p.823)
	GPIO_PORTL_PCTL = GPIO_PORTL_PCTL | 0x00005555;
	GPIO_PORTM_PCTL = GPIO_PORTM_PCTL | 0x00005555;

	//peripheral configuration (p.836)
	GPIO_PORTL_PC = GPIO_PORTL_PC | 0x00FF;
	GPIO_PORTM_PC = GPIO_PORTM_PC | 0x00FF;

	//drive control register setting(slew rate control) (p.808~810, p.816, p.828)
	GPIO_PORTL_DR2R = GPIO_PORTL_DR2R & (~0xf);
	GPIO_PORTM_DR2R = GPIO_PORTM_DR2R & (~0xf);

	GPIO_PORTL_DR4R = GPIO_PORTL_DR4R | 0xf;
	GPIO_PORTM_DR4R = GPIO_PORTM_DR4R | 0xf;

	GPIO_PORTL_DR8R = GPIO_PORTL_DR8R | 0xf;
	GPIO_PORTM_DR8R = GPIO_PORTM_DR8R | 0xf;

	GPIO_PORTL_SLR = GPIO_PORTL_SLR & (~0xf);
	GPIO_PORTM_SLR = GPIO_PORTM_SLR & (~0xf);

	GPIO_PORTL_DR12R = GPIO_PORTL_DR12R & (~0xf);
	GPIO_PORTM_DR12R = GPIO_PORTM_DR12R & (~0xf);
}

char UART_getch(void) {
	while (!(UART0FR & 0x40));
	return UART0_DATA;
}

char UART_getkey(void) {
	if (!(UART0FR & 0x40)) {
		return 0;
	} else
		return UART0_DATA;
}

void UART_putch(uint8_t data) {
	while (!(UART0FR & 0x80));
	UART0_DATA = data;
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

void delay(int count){
	while(count != 0){
		count--;
	}
}

//////////////////////////// PUSH ///////////////////////////////////////

void PUSH_init(){
	RCGCGPIO = RCGCGPIO | 0x3E10;

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

/////////////////////////////////// FND //////////////////////////////
void FND_init(){

	RCGCGPIO = RCGCGPIO | 0x10c4;

	GPIO_PORTH_DIR = GPIO_PORTH_DIR | 0x0f;
	GPIO_PORTN_DIR = GPIO_PORTN_DIR | 0x30;
	GPIO_PORTC_DIR = GPIO_PORTC_DIR | 0xf0;
	GPIO_PORTG_DIR = GPIO_PORTG_DIR | 0x0f;

	GPIO_PORTH_DEN = GPIO_PORTH_DEN | 0x0f;
	GPIO_PORTN_DEN = GPIO_PORTN_DEN | 0x30;
	GPIO_PORTC_DEN = GPIO_PORTC_DEN | 0xf0;
	GPIO_PORTG_DEN = GPIO_PORTG_DEN | 0x0f;

	GPIO_PORTH_AFSEL = GPIO_PORTH_AFSEL & (~ (0x0F));
	GPIO_PORTN_AFSEL = GPIO_PORTN_AFSEL & (~ (0x30));
	GPIO_PORTC_AFSEL = GPIO_PORTC_AFSEL & (~ (0xF0));
	GPIO_PORTG_AFSEL = GPIO_PORTG_AFSEL & (~ (0x0F));

	//GPIO_PORTH_PC = GPIO_PORTH_PC | 0x00FF;
	GPIO_PORTN_PC = GPIO_PORTN_PC | 0x0F00;
	//GPIO_PORTC_PC = GPIO_PORTC_PC | 0xFF00;
	//GPIO_PORTG_PC = GPIO_PORTG_PC | 0x00FF;

	//GPIO_PORTH_DR2R = GPIO_PORTH_DR2R & (~(0x0F));
	GPIO_PORTN_DR2R = GPIO_PORTN_DR2R & (~(0x30));
	//GPIO_PORTC_DR2R = GPIO_PORTC_DR2R & (~(0xF0));
	//GPIO_PORTG_DR2R = GPIO_PORTG_DR2R & (~(0x0F));

	//GPIO_PORTH_DR4R = GPIO_PORTH_DR4R | 0x0F;
	GPIO_PORTN_DR4R = GPIO_PORTN_DR4R | 0x30;
	//GPIO_PORTC_DR4R = GPIO_PORTC_DR4R | 0xF0;
	//GPIO_PORTG_DR4R = GPIO_PORTG_DR4R | 0x0F;

	//GPIO_PORTH_DR8R = GPIO_PORTH_DR8R | 0x0F;
	GPIO_PORTN_DR8R = GPIO_PORTN_DR8R | 0x30;
	//GPIO_PORTC_DR8R = GPIO_PORTC_DR8R | 0xF0;
	//GPIO_PORTG_DR8R = GPIO_PORTG_DR8R | 0x0F;

	//GPIO_PORTH_SLR = GPIO_PORTH_SLR & (~(0x0F));
	GPIO_PORTN_SLR = GPIO_PORTN_SLR & (~(0x30));
	//GPIO_PORTC_SLR = GPIO_PORTC_SLR & (~(0xF0));
	//GPIO_PORTG_SLR = GPIO_PORTG_SLR & (~(0x0F));

	//GPIO_PORTH_DR12R = GPIO_PORTH_DR12R & (~(0x0F));
	GPIO_PORTN_DR12R = GPIO_PORTN_DR12R & (~(0x30));
	//GPIO_PORTC_DR12R = GPIO_PORTC_DR12R & (~(0xF0));
	//GPIO_PORTG_DR12R = GPIO_PORTG_DR12R & (~(0x0F));
}

void FND_clear(){
	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80, 0);
	GPIO_WRITE(GPIO_PORTG, 0x01 | 0x02 | 0x04 | 0x08, 0);

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, 0);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, 0);
}

void WRITE_FND(int digit, int seg_out){
	int i;

	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80, (fnd_num[seg_out] << 4) & 0xf0);
	GPIO_WRITE(GPIO_PORTG, 0x01 | 0x02 | 0x04 | 0x08, (fnd_num[seg_out] >> 4) & 0x0f);

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, fnd_pos[digit-1] & 0x0f);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, fnd_pos[digit-1] & 0xf0);

	for(i=0; i<9999;i++);
}

void WRITE_FND_DOT(int digit, int seg_out){
	int i;

	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80,  (fnd_num[seg_out] << 4) & 0xf0);
	GPIO_WRITE(GPIO_PORTG, 0x01 | 0x02 | 0x04 | 0x08, ((fnd_num[seg_out] >> 4) & 0x0f) | 0x08);

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, fnd_pos[digit-1] & 0x0f);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, fnd_pos[digit-1] & 0xf0);

	for(i=0; i<9999;i++);
}
