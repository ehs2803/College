/*
 * MyLib.c
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */
#include "MyLib.h"
#include "cortex_m4.h"

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

	GPIO_PORTH_PC = GPIO_PORTH_PC | 0x00FF;
	GPIO_PORTN_PC = GPIO_PORTN_PC | 0x0F00;
	GPIO_PORTC_PC = GPIO_PORTC_PC | 0xFF00;
	GPIO_PORTG_PC = GPIO_PORTG_PC | 0x00FF;

	GPIO_PORTH_DR2R = GPIO_PORTH_DR2R & (~(0x0F));
	GPIO_PORTN_DR2R = GPIO_PORTN_DR2R & (~(0x30));
	GPIO_PORTC_DR2R = GPIO_PORTC_DR2R & (~(0xF0));
	GPIO_PORTG_DR2R = GPIO_PORTG_DR2R & (~(0x0F));

	GPIO_PORTH_DR4R = GPIO_PORTH_DR4R | 0x0F;
	GPIO_PORTN_DR4R = GPIO_PORTN_DR4R | 0x30;
	GPIO_PORTC_DR4R = GPIO_PORTC_DR4R | 0xF0;
	GPIO_PORTG_DR4R = GPIO_PORTG_DR4R | 0x0F;

	GPIO_PORTH_DR8R = GPIO_PORTH_DR8R | 0x0F;
	GPIO_PORTN_DR8R = GPIO_PORTN_DR8R | 0x30;
	GPIO_PORTC_DR8R = GPIO_PORTC_DR8R | 0xF0;
	GPIO_PORTG_DR8R = GPIO_PORTG_DR8R | 0x0F;

	GPIO_PORTH_SLR = GPIO_PORTH_SLR & (~(0x0F));
	GPIO_PORTN_SLR = GPIO_PORTN_SLR & (~(0x30));
	GPIO_PORTC_SLR = GPIO_PORTC_SLR & (~(0xF0));
	GPIO_PORTG_SLR = GPIO_PORTG_SLR & (~(0x0F));

	GPIO_PORTH_DR12R = GPIO_PORTH_DR12R & (~(0x0F));
	GPIO_PORTN_DR12R = GPIO_PORTN_DR12R & (~(0x30));
	GPIO_PORTC_DR12R = GPIO_PORTC_DR12R & (~(0xF0));
	GPIO_PORTG_DR12R = GPIO_PORTG_DR12R & (~(0x0F));
}

void LED_init(){
   //GPIO Run Mode Clock Gating control(p. 400)
   RCGCGPIO = RCGCGPIO | (0x3 << 10);

   //direction (p.795)
   GPIO_PORTL_DIR = GPIO_PORTL_DIR | 0xf;
   GPIO_PORTM_DIR = GPIO_PORTM_DIR | 0xf;

   //Digital enable (p.817)
   GPIO_PORTL_DEN = GPIO_PORTL_DEN | 0xf;
   GPIO_PORTM_DEN = GPIO_PORTM_DEN | 0xf;

   //Alternate Function Select(p.806)
   GPIO_PORTL_AFSEL = GPIO_PORTL_AFSEL & (~0xf);
   GPIO_PORTM_AFSEL = GPIO_PORTM_AFSEL & (~0xf);

   //port control register (p.823)
   GPIO_PORTL_PCTL = 0x00005555;
   GPIO_PORTM_PCTL = 0x00005555;

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
void DIP_init(){
	RCGCGPIO = RCGCGPIO | 0x4043;

	GPIO_PORTA_DIR = GPIO_PORTA_DIR & ~((0x01<<3) | (0x01<<6) | (0x01<<7));
	GPIO_PORTB_DIR = GPIO_PORTB_DIR & ~(0x01<<3);
	GPIO_PORTQ_DIR = GPIO_PORTQ_DIR & ~((0x01<<6) | (0x01<<5) | (0x01<<4));
	GPIO_PORTG_DIR = GPIO_PORTG_DIR & ~(0x01<<6);

	GPIO_PORTA_AFSEL = GPIO_PORTA_AFSEL & (~ ((0x01<<3) | (0x01<<6) | (0x01<<7)));
	GPIO_PORTB_AFSEL = GPIO_PORTB_AFSEL & (~ (0x01<<3));
	GPIO_PORTQ_AFSEL = GPIO_PORTQ_AFSEL & (~ ((0x01<<6) | (0x01<<5) | (0x01<<4)));
	GPIO_PORTG_AFSEL = GPIO_PORTG_AFSEL & (~ (0x01<<6));

	GPIO_PORTA_DEN = GPIO_PORTA_DEN | (0x01<<3) | (0x01<<6) | (0x01<<7);
	GPIO_PORTB_DEN = GPIO_PORTB_DEN | (0x01<<3);
	GPIO_PORTQ_DEN = GPIO_PORTQ_DEN | (0x01<<6) | (0x01<<5) | (0x01<<4);
	GPIO_PORTG_DEN = GPIO_PORTG_DEN | 0x01<<6;
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
void FND_clear(){
	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80, 0);
	GPIO_WRITE(GPIO_PORTG, 0x01 | 0x02 | 0x04 | 0x08, 0);

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, 0);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, 0);
}
