/*
 * MyLib.h
 *
 *  Created on: 2015. 4. 6.
 *      Author: ESL-LKH
 */

#ifndef MYLIB_H_
#define MYLIB_H_

/*  C1 : 도 , D1 : 레 , E1 : 미 ...
    DLY_4 : 4분음표 , DLY_8 : 8분음표 , DLY_16 : 16분음표     */
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
void Melody_Controll(void);
void PUSH_init();
void LED_init();
void LED_clear();

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


#endif /* MYLIB_H_ */
