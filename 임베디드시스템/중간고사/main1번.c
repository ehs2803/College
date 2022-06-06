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
	FND_init();
	LED_init();


	int num=0;
	int index=3;
	int flag=0, dip_data, push_data;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
							~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
							~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
							~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );
		dip_data = ( GPIO_READ(GPIO_PORTA, 0x08) >> 3 ) |
					( GPIO_READ(GPIO_PORTA, 0x40) >> 5 ) |
					( GPIO_READ(GPIO_PORTA, 0x80) >> 5 ) |
					( GPIO_READ(GPIO_PORTB, 0x08) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x40) >> 2 ) |
					( GPIO_READ(GPIO_PORTQ, 0x20) >> 0 ) |
					( GPIO_READ(GPIO_PORTQ, 0x10) << 2 ) |
					( GPIO_READ(GPIO_PORTG, 0x40) << 1 );


				WRITE_FND(index,num);

		        if(!flag){
		           if(push_data & 0x1){
		        	  num = dip_data&0x0f;
		              flag=1;
		           }
		           if(push_data & 0x02){ 
		        	   if(dip_data&0x80){
		        		   index++;
		        		   if(index==7) index=1;
		        	   }
		        	   else{
		        		   index--;
		        		   if(index==0) index=6;
		        	   }

		              flag=1;
		           }

		        }
		        else if(flag && !(push_data & 0x1) && !(push_data & 0x2)){
		           flag=0;
		        }
	}

	


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

