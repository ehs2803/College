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



/* 문제1
	int i;
	while(1){
		for(i=0;i<=255;i++){
			GPIO_WRITE(GPIO_PORTL, 0xf, i&0x0f);
			GPIO_WRITE(GPIO_PORTM, 0xf, (i>>4)&0x0f);
			delay(2500000);
		}
	}
*/

/* 문제2
	int i;
	while(1){
		for(i=0;i<=15;i++){
			GPIO_WRITE(GPIO_PORTL, 0xf, i);
			delay(2500000);
		}
		for(i=14;i>=1;i--){
			GPIO_WRITE(GPIO_PORTL, 0xf, i);
			delay(2500000);
		}
	}
*/
/*
	   int ledL=0x1;
	   int ledM=0x1;



	   while(1){
	      if(ledL>0x8) { /////////////////  >=을 >로
	         if(ledM>0x8){ ///////////////////    >=을 >로
	            ledM=1;
	            ledL=1;
	            //GPIO_WRITE(GPIO_PORTL, 0xf, ledL);
	            GPIO_WRITE(GPIO_PORTM, 0xf, 0);
	            GPIO_WRITE(GPIO_PORTL, 0xf, ledL);
	            ledL=ledL<<1;
	         }
	         else{
	           //////////////////////////////////////////////////////
	            GPIO_WRITE(GPIO_PORTM, 0xf, ledM);
	            GPIO_WRITE(GPIO_PORTL, 0xf, 0);
	            ledM=ledM<<1; /////////////////////////////
	         }
	      }
	      else{
	         //////////////////////
	         GPIO_WRITE(GPIO_PORTL, 0xf, ledL);
	         ledL=ledL<<1;//////////////////////////////////
	      }

	      delay(2500000);

	   }
	   */

	//prob1_run();

	/* // prob1과제1 - prob1
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
	*/
	/*//prob1_2
	while(1){
		int i=1;
		int j=8;

		GPIO_WRITE(GPIO_PORTL, 0xf, i);
		GPIO_WRITE(GPIO_PORTM, 0xf, j);
		delay(2500000);
		i=i<<1;
		j=j>>1;

		GPIO_WRITE(GPIO_PORTL, 0xf, i);
		GPIO_WRITE(GPIO_PORTM, 0xf, j);
		delay(2500000);
		i=i<<1;
		j=j>>1;

		GPIO_WRITE(GPIO_PORTL, 0xf, i);
		GPIO_WRITE(GPIO_PORTM, 0xf, j);
		delay(2500000);
		i=i<<1;
		j=j>>1;

		GPIO_WRITE(GPIO_PORTL, 0xf, i);
		GPIO_WRITE(GPIO_PORTM, 0xf, j);
		delay(2500000);
		i=i<<1;
		j=j>>1;

	}
	*/

	/*//prob2  과제1 - prob2
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
	*/

	   /*
	   int i;
	while(1){
		for(i=0;i<16;i++){

				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(1000000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
		}

		for(i=15;i>=0;i--){

				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(1000000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
		}
	}*/

/*
	// 시프트 1~8~1 반복

	while(1){
		int L=1;
		int M=1;
		int i;
		for(i=0;i<4;i++){
			GPIO_WRITE(GPIO_PORTL, 0xf, L);
			delay(3000000);
			L = L<<1;
		}
		GPIO_WRITE(GPIO_PORTL, 0xf, 0);
		for(i=0;i<4;i++){
			GPIO_WRITE(GPIO_PORTM, 0xf, M);
			delay(3000000);
			M = M<<1;
		}

		M = 8;
		L = 8;
		for(i=0;i<3;i++){
			M = M>>1;
			GPIO_WRITE(GPIO_PORTM, 0xf, M);
			delay(3000000);
		}
		GPIO_WRITE(GPIO_PORTM, 0xf, 0);
		for(i=0;i<4;i++){
			GPIO_WRITE(GPIO_PORTL, 0xf, L);
			delay(3000000);
			L = L>>1;
		}
	}

// 업카운트 되면서 숫자만큼 깜빡임
	   while(1){
	   		int i=0,j,k, num=0;
	   		for(i=0;i<16;i++){
	   			for(j=0;j<16;j++){
	   				for(k=0;k<num;k++){
	   					GPIO_WRITE(GPIO_PORTM, i, 0xf);
	   					GPIO_WRITE(GPIO_PORTL, j, 0xf);
	   					delay(3000000);
	   					GPIO_WRITE(GPIO_PORTM, i, 0x0);
	   					GPIO_WRITE(GPIO_PORTL, j, 0x0);
	   					delay(3000000);
	   				}
	   				num++;
	   			}

	   		}

	   		num--;
	   		GPIO_WRITE(GPIO_PORTL, 16, 0xf);
	   		for(i=15;i>0;i--){
	   			for(j=14;j>=0;j--){
	   				for(k=0;k<num;k++){
	   					GPIO_WRITE(GPIO_PORTM, i, 0xf);
	   					GPIO_WRITE(GPIO_PORTL, j, 0xf);
	   					delay(3000000);
	   					GPIO_WRITE(GPIO_PORTM, i, 0x0);
	   					GPIO_WRITE(GPIO_PORTL, j, 0x0);
	   					delay(3000000);
	   				}
	   				num--;
	   			}
	   		}
	   	}
*/
	return 0;
}

void LLED_UPCOUNT(){  //M포트 LED 점등&소등 (업카운팅 순서대로)
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(1000000);
		GPIO_WRITE(GPIO_PORTL, i, 0x0);
	}
}

void LLED_DOWNCOUNT(){  //L포트 LED 점등&소등 (업카운팅 순서대로)
	int i=15;

	for(i=15;i>=0;i--){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(1000000);
		GPIO_WRITE(GPIO_PORTL, 0x0f, 0x0);
	}
}

int change(int num){


	int a = 0b0000, b = 0b0000, c = 0b0000, d = 0b0000;
	int result =0b0000;

	a = num & 0b1000;
	a = a>>3;
	b = num & 0b0100;
	b = b>>1;
	c = num & 0b0010;
	c = c<<1;
	d = num & 0b0001;
	d = d<<3;

	result = a+b+c+d;
	return result;
}


void MLED_DOWNCOUNT(){
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTM, change(i), 0xf);
		delay(4300000);
		GPIO_WRITE(GPIO_PORTM, change(i), 0x0);
	}
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


