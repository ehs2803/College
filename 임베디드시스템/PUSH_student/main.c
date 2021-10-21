
#include "cortex_m4.h"
#include "MyLib.h"

void LED_clear();
void delay(int count);

int main(void) {
	int push_data;

	uint32_t g_ui32SysClock;

	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
									   	 SYSCTL_OSC_MAIN   |
									     SYSCTL_USE_PLL    |
									     SYSCTL_CFG_VCO_480),
									     120000000);
	PUSH_init();
	LED_init();
	LED_clear();

	while(1){

		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(push_data & 0x01 ){
			//Push1 on
			int i=0;

			for(i=0;i<16;i++){

				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(5000000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
			}
		}


		if(push_data & 0x02){
			//Push2 on
			int i=15;

			for(i=15;i>=0;i--){

				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(5000000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
			}
		}


		if(push_data & 0x04){

			GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);

		}


		if(push_data & 0x08){

			GPIO_WRITE(GPIO_PORTL, 0xf, 0xf);

		}
		delay(500000);
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
