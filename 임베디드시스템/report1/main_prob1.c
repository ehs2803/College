#include "cortex_m4.h"
#include "MyLib.h"
#include "prob1.h"
void LED_clear();
void delay(int);

int main(void){

	uint32_t g_ui32SysClock;

	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
									   	 SYSCTL_OSC_MAIN   |
									     SYSCTL_USE_PLL    |
									     SYSCTL_CFG_VCO_480),
									     120000000);

	LED_init();
	LED_clear();


	while(1){
		int i=1, j=8, k;
		for(k=0;k<4;k++){
			GPIO_WRITE(GPIO_PORTL, 0xf, i);
			GPIO_WRITE(GPIO_PORTM, 0xf, j);
			delay(2500000);
			i=i<<1;
			j=j>>1;
		}
	}


	return 0;
}

void LED_clear(){
	GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
	GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
	delay(2500000);
}

void delay(int count){
	while(count != 0){
		count--;
	}
}


