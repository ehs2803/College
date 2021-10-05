#include "cortex_m4.h"
#include "MyLib.h"

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

	/*
	while(1){
		//GPIO_WRITE(GPIO_PORTL, 0x3, 0x2);
		GPIO_WRITE(GPIO_PORTL, 0xf, 0xf); // 1 1 1 1 -> pin 0 1 2 3
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, 0xf, 0xf);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
		delay(2500000);
		GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
		delay(2500000); //각자 경험적인 수치를 알고 있어야 -> 입력장치 경우 중요하게 역할
	}
	*/

	// test1-1
	while(1){
		int i=0;

		for(i=0;i<16;i++){ //m포트 LED 하나 켜질 때마다 l포트 5~8번 LED 차례로 16번 켜지기 //즉, L포트 16번 X M포트 16번 으로 8자리 비트 0부터 255까지 256번 점등&소등
			GPIO_WRITE(GPIO_PORTM, i, 0xf);
			LLED_UPCOUNT();
			GPIO_WRITE(GPIO_PORTM, i, 0x0);
		}

		GPIO_WRITE(GPIO_PORTL, 16, 0xf);
		for(i=15;i>0;i--){ //m포트 LED 하나 켜질 때마다 l포트 5~8번 LED 차례로 16번 켜지기 //즉, L포트 16번 X M포트 16번 으로 8자리 비트 0부터 255까지 256번 점등&소등
				GPIO_WRITE(GPIO_PORTM, i, 0xf);
				LLED_DOWNCOUNT();
				GPIO_WRITE(GPIO_PORTM, i, 0x0);
		}
	}


	/*
	// test1-2 (최상위비트 반대)
	int i=0;
	while(1){
		for(i=0;i<16;i++){ //L포트 LED(4~7번 비트) 하나 켜질 때마다 M포트 LED 0~3번 비트 차례로 16번 켜지기//즉, L포트 16번 X M포트 16번 으로 8자리 비트 0부터 255까지 256번 점등&소등
			GPIO_WRITE(GPIO_PORTL, change(i), 0xf);  //change(i) 데이터를 출력할 자리(pin)
			MLED_DOWNCOUNT();
			GPIO_WRITE(GPIO_PORTL, change(i), 0x0);
		}
	}
	*/


	/*//test2
	while(1){
			LLED_UPCOUNT();
			delay(3500000);
			LLED_DOWNCOUNT();
	}
	*/

	/*//test3
	while(1){
		int i=0,j=0;

		for(i=0;i<16;i++){
			for(j=0;j<i;j++){
				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(4300000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
				delay(4300000);

			}
		}

		i =15;
		delay(3500000);

		for(i=15;i>0;i--){
			for(j=0;j<i;j++){
				GPIO_WRITE(GPIO_PORTL, i, 0xf);
				delay(3500000);
				GPIO_WRITE(GPIO_PORTL, i, 0x0);
				delay(3500000);

			}
		}

	}
	*/

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

void LLED_UPCOUNT();


void LED_Binary_Up_Counting(){

	uint32_t g_ui32SysClock;

	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
									   	 SYSCTL_OSC_MAIN   |
									     SYSCTL_USE_PLL    |
									     SYSCTL_CFG_VCO_480),
									     120000000);

	LED_init();  //GPIO설정
	LED_clear(); //일단 LED 소등

	int i=0;

	while(1){
		for(i=0;i<16;i++){ //m포트 LED 하나 켜질 때마다 l포트 5~8번 LED 차례로 16번 켜지기
						   //즉, L포트 16번 X M포트 16번 으로 8자리 비트 0부터 255까지 256번 점등&소등
				GPIO_WRITE(GPIO_PORTM, i, 0xf);
				LLED_UPCOUNT();

				GPIO_WRITE(GPIO_PORTM, i, 0x0);
			}

	}


}




void LLED_UPCOUNT(){  //M포트 LED 점등&소등 (업카운팅 순서대로)
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(5000000);
		GPIO_WRITE(GPIO_PORTL, i, 0x0);
	}
}

void LLED_DOWNCOUNT(){  //L포트 LED 점등&소등 (업카운팅 순서대로)
	int i=15;

	for(i=15;i>=0;i--){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(5000000);
		GPIO_WRITE(GPIO_PORTL, 0x0f, 0x0);
	}
}

int change(int num){
	/*******************************LED 비트 뒤집는 함수****************************************
	10진수 숫자를 받아 &비트 연산으로 각 비트를 떼어내고
	(&연산을 하면 원래 수의 그 비트가 0이든 1이든 그 자리값은 그대로 보존하고 나머지 자리의 값은 무시)
	각 자리를 1>4 / 2>3 / 3>2 / 4>1 로 바꿔준다.
	이유는 코드상 0001값을 전달하면 1번 LED에 전달되는데, 보드에서 1번 LED가 가장 최상위 비트에 있어 뒤집혀서 출력 된다.
	***************************************************************************************/

	int a = 0b0000, b = 0b0000, c = 0b0000, d = 0b0000;  //a,b,c,d가 각 3,2,1,0번째 자리
	int result =0b0000;

	a = num & 0b1000;  //10진수와 2진수 비트연산하면 10진수가 알아서 2진수로 변환되어 연산되는 듯
	a = a>>3;		   //자리 이동
	b = num & 0b0100;
	b = b>>1;
	c = num & 0b0010;
	c = c<<1;
	d = num & 0b0001;
	d = d<<3;

	//&연산으로 해당 자리의 값만 보존하고, shift연산으로 자리까지 이동했으면 4비트 값 다 더하기
	result = a+b+c+d;  //각 변수가 4비트 중 한 자리의 비트값만 담고 있으니 그냥 더하기 연산해도 오버플로X
	return result;
}


void MLED_DOWNCOUNT(){  //M포트 LED 점등&소등 (업카운팅 순서대로)
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTM, change(i), 0xf);
		delay(4300000);
		GPIO_WRITE(GPIO_PORTM, change(i), 0x0);
	}
}
