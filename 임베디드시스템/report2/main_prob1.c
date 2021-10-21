
#include "cortex_m4.h"
#include "MyLib.h"

void LED_clear();
void delay(int count);

int main(void) {
	int push_data;
	//int dip_data;
	unsigned char dip_data;
	char count = 0;
	int flag = 0;

	uint32_t ui32SysClock;
	// Run from the PLL at 120 MHz.
	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
											   SYSCTL_CFG_VCO_480), 120000000);

	PUSH_init();
	LED_init();
	DIP_init();
	LED_clear();

	//prob1
	int cnt=0;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
							~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
							~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
							~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(!flag){
			if(push_data & 0x04){
				flag=1;
				cnt++;
			}
			if(push_data & 0x08){
				flag=1;
				GPIO_WRITE(GPIO_PORTL, 0xf, cnt);
			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		delay(900000);

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
