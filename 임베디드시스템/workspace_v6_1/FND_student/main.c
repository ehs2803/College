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

	int seg6on=0,set5on=0;
	int seg6num=0,seg5num=1;
	int flag=0, dip_data, push_data;
	int time=0, time1=0;
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


				if(seg6on==1){
					time++;
					if(time==500000){

						if(seg6num==4){

							seg5num=1;
						}

						WRITE_FND(6,seg6num);
						seg6num++;
						if(seg6num==5) seg6num=0;
						time=0;
					}

				}




		        if(!flag){
		           if(push_data & 0x1){
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 1);
		        	   delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f,3);delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 7);delay(2000000);
		        	   GPIO_WRITE(GPIO_PORTM, 0x0f, 15);delay(2000000);
		        	   seg6on=1;
		        	   seg6num=0;
		              flag=1;
		           }
		           if(push_data & 0x02){ //push 2번 누르면 업카운트


		              flag=1;
		           }

		        }
		        else if(flag && !(push_data & 0x1) && !(push_data & 0x2)){
		           flag=0;
		        }
	}

/*
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
		           if(push_data & 0x02){ //push 2번 누르면 업카운트
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
*/

/*
	int num=0, flag=0;
	int push_data, dip_data;
	int i, isCount=0,isUpcount=0, time;
	while(1){
	       //내가만든문제2. 1번 Push Switch를 누르면 Dip Switch의 값을 7-Segment 상에 표기하시오.(십진수로 표시)
	        //            Dip Switch의 값 만큼 LED 업카운트, 다운카운트 하시오.
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

			if(isCount==1 && isUpcount==1){
				time++;
				if(time==100){
					GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
					GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
					time=0;
					i++;
				}

				if(i==num+1) isCount=0;
			}
			else if(isCount==1 && isUpcount==0){
				time++;
				if(time==100){
					GPIO_WRITE(GPIO_PORTL, 0x0f, i&15);
					GPIO_WRITE(GPIO_PORTM, 0x0f, (i>>4)&15);
					time=0;
					i--;
				}

				if(i==-1) isCount=0;
			}

	        if(num>=100){
	           WRITE_FND(6,num%10);
	           WRITE_FND(5,(num/10)%10);
	           WRITE_FND(4,num/100);
	        }
	        else if(num>=10){
	           WRITE_FND(6,num%10);
	           WRITE_FND(5,num/10);
	        }
	        else{
	           WRITE_FND(6,num%10);
	        }

	        if(!flag){
	           if(push_data & 0x1){
	              num=dip_data;
	              GPIO_WRITE(GPIO_PORTL, 0x0f, (num & 0xf)); //하위 4비트 선택
	              GPIO_WRITE(GPIO_PORTM, 0x0f, (num >> 4) & 0xf); //하위4비트 선택
	              flag=1;
	           }
	           if(push_data & 0x02){ //push 2번 누르면 업카운트
	              num=dip_data;
	              isCount=1;
	              isUpcount=1;
	              i=0;
	              time=0;
	              flag=1;
	           }
	           if(push_data & 0x04){ //push 3번 누르면 다운 카운트
	              num=dip_data;
	              isCount=1;
	              isUpcount=0;
	              i=num;
	              time=0;
	              flag=1;
	           }
	           if(push_data & 0x08){  //push 4번누를 때마다 업카운트
	              num++;
	              GPIO_WRITE(GPIO_PORTL, 0x0f, num&15);
	              GPIO_WRITE(GPIO_PORTM, 0x0f, (num>>4)&15);
	              flag=1;
	           }
	        }
	        else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
	           flag=0;
	        }

	}
*/
	/*
	int h=13,m=59,s=53;
	int flag=0;
	int push_data;
	while(1){
		push_data = ~( GPIO_READ(GPIO_PORTP, 0x02) >> 1 ) &
					~( GPIO_READ(GPIO_PORTN, 0x08) >> 2 ) &
					~( GPIO_READ(GPIO_PORTE, 0x20) >> 3 ) &
					~( GPIO_READ(GPIO_PORTK, 0x80) >> 4 );

		WRITE_FND(1,(h/10)%10);
		WRITE_FND_DOT(2,h%10);
		WRITE_FND(3,(m/10)%10);
		WRITE_FND_DOT(4,m%10);
		WRITE_FND(5,(s/10)%10);
		WRITE_FND(6,s%10);

        if(!flag){
          if(push_data & 0x01){
             flag=1;
             s++;
             if(s==60){
             	s=0;
             	if(m==59){
             		m=0;
             		if(h==23) h=0;
             		else h++;
             	}
             	else m++;
             }

          }
          if(push_data & 0x02){
             flag=1;


          }
          if(push_data & 0x04){
        	  flag=1;

          }
          if(push_data & 0x08){
        	  flag=1;

          }
        }
        else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
           flag=0;
        }

	}
	*/

	/*//num1=dip_data>>4; //(dip_data>>4)&0xf
	// pdf 문제
	int flag=0;
	int dip_data, push_data;
	int num=0, num1=0, num2=0;
	int isResult=0, isMinus;
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

	        if(isResult){
	               if(num>=10){
	                 if(isMinus==1){
	                    WRITE_FND_MINUS(4);
	                 }
	                  WRITE_FND(6,num%10);
	                  WRITE_FND(5,num/10);
	               } else {
	                  if(isMinus==1){
	                     WRITE_FND_MINUS(5);
	                 }
	                  WRITE_FND(6,num);
	               }
	        }
	        else{
	               if(num1>=10){
	                  WRITE_FND(6,num1%10);
	                  WRITE_FND(5,num1/10);
	               } else {
	                  WRITE_FND(6,num1);
	               }
	        }

	        if(!flag){
	          if(push_data & 0x01){
	             num1=dip_data&0xf;
	             flag=1;
	             isResult=0;

	          }
	          if(push_data & 0x02){
	             num1=dip_data>>4; //(dip_data>>4)&0xf
	             flag=1;
	             isResult=0;

	          }
	          if(push_data & 0x04){
	        	  isMinus=0;
	            num=(dip_data&0xf) + (dip_data>>4);
	             flag=1;
	             isResult=1;
	          }
	          if(push_data & 0x08){
	            isMinus=0;
	            num=(dip_data>>4) - (dip_data&0xf);
	            if(num<0){
	               num=num*(-1);
	               isMinus=1;
	            }
	             flag=1;
	             isResult=1;
	          }
	        }
	        else if(flag && !(push_data & 0x1) && !(push_data & 0x2) && !(push_data & 0x4) &&!(push_data & 0x8)){
	           flag=0;
	        }

		}
		*/
/*
	int flag=0;
	int dip_data, push_data;
	int num=0;

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

	       //prob 1. Push Switch를 누르면 Dip Switch의 상위 4bit(5~8번) 값을 7-Segment 상에 표기하시오.(십진수로 표시)
	       if(num>=100){
	    	   WRITE_FND(6,num%10);
	    	   WRITE_FND(5,(num/10)%10);
	    	   WRITE_FND(4,((num/10)/10)%10);
	       }
	       else if(num>=10){
	    	   WRITE_FND(6,num%10);
	    	   WRITE_FND(5,1);
	       }
	       else{
	    	   WRITE_FND(6,num);
	       }

			if(!flag){
				if(push_data & 0x1){
					flag=1;
					num=dip_data;
				}

			}
			else if(flag && !(push_data & 0x1)){
				flag=0;
			}

	   }

*/
	/* clock
	int h=16,m=59,s=53;
	int time=0;
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
		WRITE_FND(1,(h/10)%10);
		//WRITE_FND(2,h%10);

		WRITE_FND_DOT(2,h%10);

		WRITE_FND(3,(m/10)%10);
		//WRITE_FND(4,m%10);

		WRITE_FND_DOT(4,m%10);

		WRITE_FND(5,(s/10)%10);
		WRITE_FND(6,s%10);

		time++;
		if(time==100){
			s++;
			if(s==60){
				s=0;
				if(m==59){
					m=0;
					if(h==23) h=0;
					else h++;
				}
				else m++;
			}
			time=0;
		}
	}
	*/

/*
	int dip_data, push_data, flag=0;
	int num5=0, num6=0;
	int result=0;
	int isMinus=0, isResult=0;;
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
*/

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

