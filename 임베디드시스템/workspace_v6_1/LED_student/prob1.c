/*
 * prob1.c
 *
 *  Created on: 2021. 10. 9.
 *      Author: nec
 */

#include "prob1.h"
#include "cortex_m4.h"

void prob1_run(){
	uint32_t g_ui32SysClock;

	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
										   	 SYSCTL_OSC_MAIN   |
										     SYSCTL_USE_PLL    |
										     SYSCTL_CFG_VCO_480),
										     120000000);

	LED_init();
	LED_clear();

	while(1){
		GPIO_WRITE(GPIO_PORTL, 0x3, 0x2);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, 0xf, 0xf);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
		delay(2500000);
	}
}
