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
		delay(2500000); //���� �������� ��ġ�� �˰� �־�� -> �Է���ġ ��� �߿��ϰ� ����
	}
	*/

	// test1-1
	while(1){
		int i=0;

		for(i=0;i<16;i++){ //m��Ʈ LED �ϳ� ���� ������ l��Ʈ 5~8�� LED ���ʷ� 16�� ������ //��, L��Ʈ 16�� X M��Ʈ 16�� ���� 8�ڸ� ��Ʈ 0���� 255���� 256�� ����&�ҵ�
			GPIO_WRITE(GPIO_PORTM, i, 0xf);
			LLED_UPCOUNT();
			GPIO_WRITE(GPIO_PORTM, i, 0x0);
		}

		GPIO_WRITE(GPIO_PORTL, 16, 0xf);
		for(i=15;i>0;i--){ //m��Ʈ LED �ϳ� ���� ������ l��Ʈ 5~8�� LED ���ʷ� 16�� ������ //��, L��Ʈ 16�� X M��Ʈ 16�� ���� 8�ڸ� ��Ʈ 0���� 255���� 256�� ����&�ҵ�
				GPIO_WRITE(GPIO_PORTM, i, 0xf);
				LLED_DOWNCOUNT();
				GPIO_WRITE(GPIO_PORTM, i, 0x0);
		}
	}


	/*
	// test1-2 (�ֻ�����Ʈ �ݴ�)
	int i=0;
	while(1){
		for(i=0;i<16;i++){ //L��Ʈ LED(4~7�� ��Ʈ) �ϳ� ���� ������ M��Ʈ LED 0~3�� ��Ʈ ���ʷ� 16�� ������//��, L��Ʈ 16�� X M��Ʈ 16�� ���� 8�ڸ� ��Ʈ 0���� 255���� 256�� ����&�ҵ�
			GPIO_WRITE(GPIO_PORTL, change(i), 0xf);  //change(i) �����͸� ����� �ڸ�(pin)
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

	LED_init(); 
	LED_clear(); 

	int i=0;

	while(1){
		for(i=0;i<16;i++){ 
				GPIO_WRITE(GPIO_PORTM, i, 0xf);
				LLED_UPCOUNT();

				GPIO_WRITE(GPIO_PORTM, i, 0x0);
			}

	}


}




void LLED_UPCOUNT(){  
	int i=0;

	for(i=0;i<16;i++){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(5000000);
		GPIO_WRITE(GPIO_PORTL, i, 0x0);
	}
}

void LLED_DOWNCOUNT(){  
	int i=15;

	for(i=15;i>=0;i--){

		GPIO_WRITE(GPIO_PORTL, i, 0xf);
		delay(5000000);
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
