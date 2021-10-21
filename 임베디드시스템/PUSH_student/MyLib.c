/*
 * MyLib.c
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#include "cortex_m4.h"
#include "myLib.h"
void LED_init(){
	//GPIO Run Mode Clock Gating control(p. 400)
	RCGCGPIO = RCGCGPIO | 0x0C00;

	//direction (p.795)
	GPIO_PORTL_DIR = 0xF;
	GPIO_PORTM_DIR = 0xF;

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

	//Digital enable (p.817)
	GPIO_PORTL_DEN = 0xf;
	GPIO_PORTM_DEN = 0xf;
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
void DIP_init(){
	RCGCGPIO = RCGCGPIO | 0x4043;

	GPIO_PORTA_DIR = GPIO_PORTA_DIR & ~((0x01<<3)|(0x01<<6)|(0x01<<7)) ;
	GPIO_PORTB_DIR = GPIO_PORTB_DIR & ~(0x01<<3);
	GPIO_PORTQ_DIR = GPIO_PORTQ_DIR & ~((0x01<<6)|(0x01<<5)|(0x01<<4));
	GPIO_PORTG_DIR = GPIO_PORTG_DIR & ~(0x01<<6);

	GPIO_PORTA_AFSEL = GPIO_PORTA_AFSEL & ~((0x01<<3)|(0x01<<6)|(0x01<<7)) ;
    GPIO_PORTB_AFSEL = GPIO_PORTB_AFSEL & ~(0x01<<3);
	GPIO_PORTQ_AFSEL = GPIO_PORTQ_AFSEL & ~((0x01<<6)|(0x01<<5)|(0x01<<4)) ;
	GPIO_PORTG_AFSEL = GPIO_PORTG_AFSEL & ~(0x01<<6);

	GPIO_PORTA_DEN = GPIO_PORTA_DEN | (0x01<<3)|(0x01<<6)|(0x01<<7) ;
	GPIO_PORTB_DEN = GPIO_PORTB_DEN | (0x01<<3);
	GPIO_PORTQ_DEN = GPIO_PORTQ_DEN | (0x01<<6)|(0x01<<5)|(0x01<<4);
	GPIO_PORTG_DEN = GPIO_PORTG_DEN | (0x01<<6);
}
