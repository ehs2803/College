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

#endif /* MYLIB_H_ */
