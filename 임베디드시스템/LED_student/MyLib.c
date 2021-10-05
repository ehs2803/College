/*
 * MyLib.c
 *
 *  Created on: 2018. 3. 08.
 *      Author: ESL-KMC
 */

#include "MyLib.h"
#include "cortex_m4.h"

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
/*
void LED_init(){
	//GPIO Run Mode Clock Gating control(p. 400)
//	RCGCGPIO = RCGCGPIO |;

	//direction (p.795)
//	GPIO_PORTL_DIR = GPIO_PORTL_DIR | ;
//	GPIO_PORTM_DIR = GPIO_PORTM_DIR | ;

	//Digital enable (p.817)
//	GPIO_PORTL_DEN = ;
//	GPIO_PORTM_DEN = ;

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
*/
