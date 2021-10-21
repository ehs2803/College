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

	int j=0;
	while(1){
		int i=0;

		for(i=0;i<16;i++){

			GPIO_WRITE(GPIO_PORTL, i, 0xf);
			delay(2000000);
			GPIO_WRITE(GPIO_PORTL, i, 0x0);
		}
		i=15;

		for(i=15;i>=0;i--){

			GPIO_WRITE(GPIO_PORTL, i, 0xf);
			delay(2000000);
			GPIO_WRITE(GPIO_PORTL, 0x0f, 0x0);
		}
		if(j==15) j=0;
		else j++;

		GPIO_WRITE(GPIO_PORTM, 0xf, j);
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


