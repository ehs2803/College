/*
 * UART_exam
 *
 */

#include "cortex_m4.h"
#include "myLib.h"

int main(void)
{
	uint8_t code;

	float BRD;
	int   BRDI;
	int   BRDF;

	uint32_t ui32SysClock;

	ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
		                               SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
		                               SYSCTL_CFG_VCO_480), 120000000);

	//uart baud rate(p.1339)
	BRD = (float)ui32SysClock / (16 * 115200);
	BRDI = (int)BRD;
	BRDF = (int)(((BRD - (int)BRD)*64) + 0.5);

	UART_init(BRD, BRDI, BRDF);
	LED_init();
	PUSH_init();
	TIMER_init();
	BUZZER_init();
	GPTMCTL = GPTMCTL | 0x41;
	BUZZER_clear();
	WDTinitISR();
	FND_init();
	FND_clear();

	/*
	int push_data, IsLedOn=1;
	while(1) {

		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		code = UART_getkey();

		UART_putch(code);

		if(push_data & 0x01 ){
			IsLedOn = 0;
			GPIO_WRITE(GPIO_PORTL, 0xf, 0x0);
			GPIO_WRITE(GPIO_PORTM, 0xf, 0x0);
		}

		switch(code){
		case '1':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '2':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(D1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '3':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(E1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '4':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(F1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '5':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(G1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '6':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(A1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '7':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(B1);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		case '8':
			GPIO_WRITE(GPIO_PORTD, 0x10, 0x10);
			Play(C2);
			DelayForPlay(DLY_8);
			GPIO_WRITE(GPIO_PORTD, 0x10, ~0x10);
			break;
		}

		if(code == 0){
			continue;
		}
		if(IsLedOn==1){
			GPIO_WRITE(GPIO_PORTL, 0xf, 0x1 <<(code-'1'));
			GPIO_WRITE(GPIO_PORTM, 0xf, 0x1 <<(code-'1')>>4);
		}


		WDT1LOAD = 0xffffffff;
		delay(100000);
	}

	*/

	int push_data;
	int PUSH1=0, PUSH2=0;
	int mode=0;
	int keyCheck=0;
	int digit,num;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		if(push_data & 0x01){
			mode = 1;
		}

		if(push_data & 0x02){
			mode = 2;
		}



		if(mode == 1 ){

			while(1){
				digit = UART_getkey();

				if(digit != 0){
					UART_putch(digit);
					keyCheck = 1;
				}
				if(keyCheck == 1) break;
			}
			mode = 0;
			keyCheck=0;
			PUSH1=1;
		}


		if(mode == 2 ){
			while(1){
				num = UART_getkey();
				if(num != 0){
					UART_putch(num);
					keyCheck = 1;
				}
				if(keyCheck == 1) break;
			}
			mode = 0;
			keyCheck=0;
			PUSH2=1;
		}

		if(PUSH1==1 && PUSH2==1){
			if(num>=97){
				WRITE_FND((digit-'0'),(num-'W'));
			}
			else{
				WRITE_FND((digit-'0'),(num-'0'));
			}
		}

		//delay(1000000);
	}


    return 0;
}





