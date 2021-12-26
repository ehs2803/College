/*
 * myLib.h
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#ifndef MYLIB_H_
#define MYLIB_H_

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

static unsigned char fnd_num[17] = {  //segment값:  0~15표현, 모두 OFF 총 17개
//	0		1		2		3		4		5		6		7
	0x3f,	0x06,	0x5b,	0x4f,	0x66,	0x6d,	0x7d,	0x27,
//	8		9		a		b		c		d		e		f
	0x7f,	0x67,	0x5f,	0x7c,	0x39,	0x5e,	0x79,	0x71,
//	off
	0x00
};

static unsigned char fnd_pos[6] = {  //6개의 자리
//	D1		D2		D3		D4		D5		D6
	0x01,	0x02,	0x04,	0x08,	0x10,	0x20
};

void UART_init(float BRD, int BRDI, int BRDF);
void LED_init();
void PUSH_init();

char UART_getch(void);
char UART_getkey(void);
void UART_putch(uint8_t data);
void UART_putstr(char* pt);
void UART_printf(char *fmt, ...);
int Scale(int i);

void FND_init();
void FND_clear();
void WRITE_FND(int digit, int seg_out);		 //dot 포함하지 않는 숫자 표현
void WRITE_FND_DOT(int digit, int seg_out);  //dot를 포함해서 숫자 표현하는 함수

void BUZZER_init();
void TIMER_init();
void BUZZER_clear();
void Play(int freq);
void DelayForPlay(int DLY);
void WDTinitISR(void);

#endif /* MYLIB_H_ */
