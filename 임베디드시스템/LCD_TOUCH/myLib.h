/*
 * myLib.h
 *
 *  Created on: 2015. 2. 25.
 *      Author: ESL-LKH
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#pragma once
#include "cortex_m4.h"

#define 	HDP_S 	479
#define		VDP_S	271
#define LCD_HEIGHT	272
#define LCD_WIDTH	480
#define SCROLL	10
#define DIV_MS	17


#define LCD_ENTRY_MODE_REG        0x36
#define LCD_RAM_DATA_REG          0x2C
#define LCD_X_RAM_ADDR_REG        0x2A
#define LCD_Y_RAM_ADDR_REG        0x2B

/////////////////////////////////////////////////////////////////
/*  C1 : �� , D1 : �� , E1 : �� ...
    DLY_4 : 4����ǥ , DLY_8 : 8����ǥ , DLY_16 : 16����ǥ     */
#define DLY_2 	32
#define DLY_4 	16
#define DLY_8	8
#define DLY_16	4
#define B0      64800
#define C1 		61068
#define D1 		54421
#define E1 		48484
#define F1 		45844
#define G1 		40815
#define A1 		36363
#define B1 		32388
#define C2 		30592

void BUZZER_init();
void TIMER_init();

void delay(int count);
void BUZZER_clear();
void Play(int freq);
void DelayForPlay(int DLY);
void WDTinitISR(void);

void LED_init();
void DIP_init();
void PUSH_init();

static unsigned char fnd_num[17] = {
//	0		1		2		3		4		5		6		7
	0x3f,	0x06,	0x5b,	0x4f,	0x66,	0x6d,	0x7d,	0x27,
//	8		9		a		b		c		d		e		f
	0x7f,	0x67,	0x5f,	0x7c,	0x39,	0x5e,	0x79,	0x71,
//	off
	0x00
};

static unsigned char fnd_pos[6] = {
//	D1		D2		D3		D4		D5		D6
	0x01,	0x02,	0x04,	0x08,	0x10,	0x20
};

void FND_write(int digit, int seg_out);
void FND_write_dot(int digit, int seg_out);
void FND_clear();
void FND_init();

////////////////////////////////////////////////////////////
void LCD_Init(unsigned long ulClockMS);
inline uint16_t ReadData(void);
inline void WriteData(uint16_t ui16Data);
inline void WriteCommand(uint16_t ui8Data);

void Port_Init(void);
void Uart_Init(float BRD, int BRDI, int BRDF);
char Uart_GetCh(void);
char Uart_GetKey(void);
void Uart_PutCh(uint8_t data);
void Uart_PutStr(char* pt);
void Uart_Printf(char *fmt,...);

void SetFullFrame();
void Scroll_up(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_down(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_right(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_left(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void DrawLine(unsigned char *buffer, int x1, int y1, int x2, int y2, int color);
void PutPixel(unsigned char *buffer, int x, int y, int color);

void RestoreBackground(unsigned char *buffer, int x1, int y1, int x2, int y2, int image);
void DrawImage(unsigned char *buffer, int x1, int y1, int x2, int y2, int image);
void DrawRect_fill(unsigned char *buffer, int x1, int y1, int x2, int y2, int color);
void DrawCircle(unsigned char *buffer, int nCenterX,int nCenterY,int nRadius,int color);
void DrawCircle_fill(unsigned char *buffer, int nCenterX,int nCenterY,int nRadius,int color);

void uPutPixel(int x, int y, int color);
void uDrawLine(int x1, int y1, int x2, int y2, int color);
void uDrawRect(int x1, int y1, int x2, int y2, int color);
void uDrawTriangle(int x1, int y1, int x2, int y2,int x3, int y3, int color);
void uDrawCircle(int x, int y, int r, int color);
int LineFunc(float x1,float y1,float x2,float y2,float xin);
int max(int a,int b,int c);
int min(int a,int b,int c);

#endif /* MYLIB_H_ */
