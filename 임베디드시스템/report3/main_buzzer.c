#include "cortex_m4.h"
#include "MyLib.h"

void delay(int count);

int main(void){
	int i;

	uint32_t ui32SysClock;

	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
									   SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
									   SYSCTL_CFG_VCO_480), 120000000);
	BUZZER_init();

	int de=5000;
	GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);  // buzzer ON 4¹ø ÇÉ¿¡ enable
	while(1){

		for(i=0; i<1500; i++)
		{
			de += 10;
			GPIO_WRITE(GPIO_PORTB, 0x04, 0x04);
			delay(de);

			GPIO_WRITE(GPIO_PORTB, 0x04, ~0x04);
			delay(de);

		}
		for(i=0; i<1500; i++)
		{
			de -= 10;
			GPIO_WRITE(GPIO_PORTB, 0x04, 0x04);
			delay(de);

			GPIO_WRITE(GPIO_PORTB, 0x04, ~0x04);
			delay(de);

		}

	}

	GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);  // buzzer OFF

    return 0;
}
void delay(int count){
	while(count != 0){
		count--;
	}
}
