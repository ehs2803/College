
/*
 * MyLib.c
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#ifndef _MYLIB_H_
#define _MYLIB_H_

#pragma once
#include "cortex_m4.h"

#define HDP_S 	479
#define	VDP_S	271
#define LCD_HEIGHT	272
#define LCD_WIDTH	480
#define SCROLL	10
#define DIV_MS	17

#define LCD_ENTRY_MODE_REG        0x36
#define LCD_RAM_DATA_REG          0x2C
#define LCD_X_RAM_ADDR_REG        0x2A
#define LCD_Y_RAM_ADDR_REG        0x2B

inline uint16_t ReadData(void);
inline void WriteData(uint16_t ui16Data);
inline void WriteCommand(uint16_t ui8Data);

void PUSH_init();
void LCD_Init(unsigned long g_ui32SysClock);

void RestoreBackground(unsigned char *buffer, int x1, int y1, int x2, int y2, int image);
void PutPixel(int x, int y, int color);
void DrawLine(int x1, int y1, int x2, int y2, int color);
void DrawRect(int x1, int y1, int x2, int y2, int color);
void Scroll_left(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_right(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_down(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void Scroll_up(unsigned char *buffer, int x1, int y1, int x2, int y2, int scroll);
void SetFullFrame();


#endif /* _MYLIB_H_ */
