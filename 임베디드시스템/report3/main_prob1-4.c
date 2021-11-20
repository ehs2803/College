/*
 * main.c
*/

#include "cortex_m4.h"
#include "MyLib.h"


int main(void) {

	uint32_t ui32SysClock;

	// Run from the PLL at 120 MHz.
	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
										SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
										SYSCTL_CFG_VCO_480), 120000000);

	FND_init();
	FND_clear();
	DIP_init();
	PUSH_init();

	int dip_data, push_data, flag=0;
	int num5=0, num6=0;
	int result=0;
	int isMinus=0, isResult=0;
	while(1){
		dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
					( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
					( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
					( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
					( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
					( GPIO_READ(GPIO_PORTG, 0x40) << 1 );

		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(isResult==1){
			FND_clear();
			if(result<10){
				if(isMinus==1){
					WRITE_FND_MINUS(5);
				}
				WRITE_FND(6,result);
			}
			else{
				if(isMinus==1){
					WRITE_FND_MINUS(4);
				}
				WRITE_FND(5,(result/10)%10);
				WRITE_FND(6,result%10);
			}
		}
		else{
			if(num5==0 && num6==0){
				FND_clear();
			}
			else if(num5==0){
				FND_clear();
				WRITE_FND(6,num6);
			}
			else{
				FND_clear();
				WRITE_FND(5,num5);
				WRITE_FND(6,num6);
			}
		}

		if(!flag){
			if(push_data & 0x01){
				flag=1;
				isResult=0;
				FND_clear();
				int temp = dip_data>>4;
				if(temp>9){
					num6 = temp%10;
					num5 = 1;
				}
				else{
					num5=0;
					num6=temp;
				}
			}
			if(push_data & 0x2){
				flag=1;
				isResult=0;
				FND_clear();
				int temp = dip_data&15;
				if(temp>9){
					num6 = temp%10;
					num5 = 1;

				}
				else{
					num5=0;
					num6=temp;
				}
			}
			if(push_data & 0x4){ // +
				flag=1;
				isMinus=0;
				result = (dip_data>>4) + (dip_data&15);
				isResult=1;
			}
			if(push_data & 0x8){ // -
				flag=1;
				isMinus=0;
				if((dip_data>>4)<(dip_data&15)){
					result = (dip_data&15) - (dip_data>>4);
					isMinus=1;
				}
				else{
					result = (dip_data>>4) - (dip_data&15);
				}
				isResult=1;
			}
		}
		else if(flag && !(push_data & 0x1) && !(push_data & 0x2) &&
				!(push_data & 0x4) &&!(push_data & 0x8)){
			flag=0;
		}
		//delay(900000);
	}

	return 0;

}

void delay(int count){
	while(count != 0){
		count--;
	}
}

void WRITE_FND_MINUS(int digit){
	int i;

	GPIO_WRITE(GPIO_PORTC, 0x10 | 0x20 | 0x40 | 0x80,  (0x40 >> 4) & 0xf0);
	GPIO_WRITE(GPIO_PORTG,  0x01 | 0x02 | 0x04 | 0x08 , ((0x40 >> 4) & 0x0f));

	GPIO_WRITE(GPIO_PORTH, 0x01 | 0x02 | 0x04 | 0x08, fnd_pos[digit-1] & 0x0f);
	GPIO_WRITE(GPIO_PORTN, 0x10 | 0x20, fnd_pos[digit-1] & 0xf0);

	for(i=0; i<9999;i++);
}

