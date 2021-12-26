/*
 * cortexm4.h
 *
 *  Created on: 2015. 2. 23.
 *      Author: ESL-LKH
 */

#pragma once

#ifndef CORTEXM4_H_
#define CORTEXM4_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"

#define PIN0  (0x01)
#define PIN1  (0x01 << 1)
#define PIN2  (0x01 << 2)
#define PIN3  (0x01 << 3)
#define PIN4  (0x01 << 4)
#define PIN5  (0x01 << 5)
#define PIN6  (0x01 << 6)
#define PIN7  (0x01 << 7)

#define GPIO_RUN_A (0x01 << 0)
#define GPIO_RUN_B (0x01 << 1)
#define GPIO_RUN_C (0x01 << 2)
#define GPIO_RUN_D (0x01 << 3)
#define GPIO_RUN_E (0x01 << 4)
#define GPIO_RUN_F (0x01 << 5)
#define GPIO_RUN_G (0x01 << 6)
#define GPIO_RUN_H (0x01 << 7)
#define GPIO_RUN_J (0x01 << 8)
#define GPIO_RUN_K (0x01 << 9)
#define GPIO_RUN_L (0x01 << 10)
#define GPIO_RUN_M (0x01 << 11)
#define GPIO_RUN_N (0x01 << 12)
#define GPIO_RUN_P (0x01 << 13)
#define GPIO_RUN_Q (0x01 << 14)
#define GPIO_RUN_R (0x01 << 15)
#define GPIO_RUN_S (0x01 << 16)
#define GPIO_RUN_T (0x01 << 17)

#define GPIO_PORTA   		(0x40058000)
#define GPIO_PORTB 	    	(0x40059000)
#define GPIO_PORTC 		    (0x4005A000)
#define GPIO_PORTD 		    (0x4005B000)
#define GPIO_PORTE 		    (0x4005C000)
//#define GPIO_PORTF 		    (0x40025000)
#define GPIO_PORTF 		    (0x4005D000)
#define GPIO_PORTG 		    (0x4005E000)
#define GPIO_PORTH 		    (0x4005F000)
#define GPIO_PORTJ 		    (0x40060000)
#define GPIO_PORTK 		    (0x40061000)
#define GPIO_PORTL 		    (0x40062000)
#define GPIO_PORTM 		    (0x40063000)
#define GPIO_PORTN 		    (0x40064000)
#define GPIO_PORTP 		    (0x40065000)
#define GPIO_PORTQ 		    (0x40066000)

#define GPIO_PORTA_DEN 		(*(volatile unsigned *)(GPIO_PORTA + 0x51C))
#define GPIO_PORTB_DEN 		(*(volatile unsigned *)(GPIO_PORTB + 0x51C))
#define GPIO_PORTC_DEN 		(*(volatile unsigned *)(GPIO_PORTC + 0x51C))
#define GPIO_PORTD_DEN 		(*(volatile unsigned *)(GPIO_PORTD + 0x51C))
#define GPIO_PORTE_DEN 		(*(volatile unsigned *)(GPIO_PORTE + 0x51C))
//#define GPIO_PORTF_DEN 		(*(volatile unsigned *)(GPIO_PORTF + 0x51C))
#define GPIO_PORTF_DEN 		(*(volatile unsigned *)(GPIO_PORTF + 0x51C))
#define GPIO_PORTG_DEN 		(*(volatile unsigned *)(GPIO_PORTG + 0x51C))
#define GPIO_PORTH_DEN 		(*(volatile unsigned *)(GPIO_PORTH + 0x51C))
#define GPIO_PORTJ_DEN 		(*(volatile unsigned *)(GPIO_PORTJ + 0x51C))
#define GPIO_PORTK_DEN 		(*(volatile unsigned *)(GPIO_PORTK + 0x51C))
#define GPIO_PORTL_DEN 		(*(volatile unsigned *)(GPIO_PORTL + 0x51C))
#define GPIO_PORTM_DEN 		(*(volatile unsigned *)(GPIO_PORTM + 0x51C))
#define GPIO_PORTN_DEN 		(*(volatile unsigned *)(GPIO_PORTN + 0x51C))
#define GPIO_PORTP_DEN 		(*(volatile unsigned *)(GPIO_PORTP + 0x51C))
#define GPIO_PORTQ_DEN 		(*(volatile unsigned *)(GPIO_PORTQ + 0x51C))

#define GPIO_PORTA_DIR 		(*(volatile unsigned *)(GPIO_PORTA + 0x400))
#define GPIO_PORTB_DIR 		(*(volatile unsigned *)(GPIO_PORTB + 0x400))
#define GPIO_PORTC_DIR 		(*(volatile unsigned *)(GPIO_PORTC + 0x400))
#define GPIO_PORTD_DIR 		(*(volatile unsigned *)(GPIO_PORTD + 0x400))
#define GPIO_PORTE_DIR 		(*(volatile unsigned *)(GPIO_PORTE + 0x400))
//#define GPIO_PORTF_DIR 		(*(volatile unsigned *)(GPIO_PORTF + 0x400))
#define GPIO_PORTF_DIR 		(*(volatile unsigned *)(GPIO_PORTF + 0x400))
#define GPIO_PORTG_DIR      (*(volatile unsigned *)(GPIO_PORTG + 0x400))
#define GPIO_PORTH_DIR 		(*(volatile unsigned *)(GPIO_PORTH + 0x400))
#define GPIO_PORTJ_DIR 		(*(volatile unsigned *)(GPIO_PORTJ + 0x400))
#define GPIO_PORTK_DIR 		(*(volatile unsigned *)(GPIO_PORTK + 0x400))
#define GPIO_PORTL_DIR 		(*(volatile unsigned *)(GPIO_PORTL + 0x400))
#define GPIO_PORTM_DIR 		(*(volatile unsigned *)(GPIO_PORTM + 0x400))
#define GPIO_PORTN_DIR 		(*(volatile unsigned *)(GPIO_PORTN + 0x400))
#define GPIO_PORTP_DIR 		(*(volatile unsigned *)(GPIO_PORTP + 0x400))
#define GPIO_PORTQ_DIR 		(*(volatile unsigned *)(GPIO_PORTQ + 0x400))

#define GPIO_PORTA_AFSEL 		(*(volatile unsigned *)(GPIO_PORTA + 0x420))
#define GPIO_PORTB_AFSEL 		(*(volatile unsigned *)(GPIO_PORTB + 0x420))
#define GPIO_PORTC_AFSEL 		(*(volatile unsigned *)(GPIO_PORTC + 0x420))
#define GPIO_PORTD_AFSEL		(*(volatile unsigned *)(GPIO_PORTD + 0x420))
#define GPIO_PORTE_AFSEL 		(*(volatile unsigned *)(GPIO_PORTE + 0x420))
//#define GPIO_PORTF_AFSEL 		(*(volatile unsigned *)(GPIO_PORTF + 0x420))
#define GPIO_PORTF_AFSEL 		(*(volatile unsigned *)(GPIO_PORTF + 0x420))
#define GPIO_PORTG_AFSEL        (*(volatile unsigned *)(GPIO_PORTG + 0x420))
#define GPIO_PORTH_AFSEL 		(*(volatile unsigned *)(GPIO_PORTH + 0x420))
#define GPIO_PORTJ_AFSEL 		(*(volatile unsigned *)(GPIO_PORTJ + 0x420))
#define GPIO_PORTK_AFSEL 		(*(volatile unsigned *)(GPIO_PORTK + 0x420))
#define GPIO_PORTL_AFSEL 		(*(volatile unsigned *)(GPIO_PORTL + 0x420))
#define GPIO_PORTM_AFSEL 		(*(volatile unsigned *)(GPIO_PORTM + 0x420))
#define GPIO_PORTN_AFSEL 		(*(volatile unsigned *)(GPIO_PORTN + 0x420))
#define GPIO_PORTP_AFSEL 		(*(volatile unsigned *)(GPIO_PORTP + 0x420))
#define GPIO_PORTQ_AFSEL 		(*(volatile unsigned *)(GPIO_PORTQ + 0x420))

#define GPIO_PORTA_PCTL 		(*(volatile unsigned *)(GPIO_PORTA + 0x52C))
#define GPIO_PORTB_PCTL 		(*(volatile unsigned *)(GPIO_PORTB + 0x52C))
#define GPIO_PORTC_PCTL 		(*(volatile unsigned *)(GPIO_PORTC + 0x52C))
#define GPIO_PORTD_PCTL	    	(*(volatile unsigned *)(GPIO_PORTD + 0x52C))
#define GPIO_PORTE_PCTL 		(*(volatile unsigned *)(GPIO_PORTE + 0x52C))
//#define GPIO_PORTF_PCTL 		(*(volatile unsigned *)(GPIO_PORTF + 0x52C))
#define GPIO_PORTF_PCTL 		(*(volatile unsigned *)(GPIO_PORTF + 0x52C))
#define GPIO_PORTG_PCTL         (*(volatile unsigned *)(GPIO_PORTG + 0x52C))
#define GPIO_PORTH_PCTL 		(*(volatile unsigned *)(GPIO_PORTH + 0x52C))
#define GPIO_PORTJ_PCTL 		(*(volatile unsigned *)(GPIO_PORTJ + 0x52C))
#define GPIO_PORTK_PCTL 		(*(volatile unsigned *)(GPIO_PORTK + 0x52C))
#define GPIO_PORTL_PCTL 		(*(volatile unsigned *)(GPIO_PORTL + 0x52C))
#define GPIO_PORTM_PCTL 		(*(volatile unsigned *)(GPIO_PORTM + 0x52C))
#define GPIO_PORTN_PCTL 		(*(volatile unsigned *)(GPIO_PORTN + 0x52C))
#define GPIO_PORTP_PCTL 		(*(volatile unsigned *)(GPIO_PORTP + 0x52C))
#define GPIO_PORTQ_PCTL 		(*(volatile unsigned *)(GPIO_PORTQ + 0x52C))

#define GPIO_PORTA_PC 		(*(volatile unsigned *)(GPIO_PORTA + 0xFC4))
#define GPIO_PORTB_PC 		(*(volatile unsigned *)(GPIO_PORTB + 0xFC4))
#define GPIO_PORTD_PC 		(*(volatile unsigned *)(GPIO_PORTD + 0xFC4))
#define GPIO_PORTE_PC 		(*(volatile unsigned *)(GPIO_PORTE + 0xFC4))
#define GPIO_PORTF_PC 		(*(volatile unsigned *)(GPIO_PORTF + 0xFC4))
#define GPIO_PORTJ_PC 		(*(volatile unsigned *)(GPIO_PORTJ + 0xFC4))
#define GPIO_PORTK_PC 		(*(volatile unsigned *)(GPIO_PORTK + 0xFC4))
#define GPIO_PORTL_PC 		(*(volatile unsigned *)(GPIO_PORTL + 0xFC4))
#define GPIO_PORTM_PC 		(*(volatile unsigned *)(GPIO_PORTM + 0xFC4))
#define GPIO_PORTN_PC 		(*(volatile unsigned *)(GPIO_PORTN + 0xFC4))
#define GPIO_PORTP_PC 		(*(volatile unsigned *)(GPIO_PORTP + 0xFC4))
#define GPIO_PORTQ_PC 		(*(volatile unsigned *)(GPIO_PORTQ + 0xFC4))

#define GPIO_PORTA_DR2R 		(*(volatile unsigned *)(GPIO_PORTA + 0x500))
#define GPIO_PORTB_DR2R 		(*(volatile unsigned *)(GPIO_PORTB + 0x500))
#define GPIO_PORTD_DR2R 		(*(volatile unsigned *)(GPIO_PORTD + 0x500))
#define GPIO_PORTE_DR2R 		(*(volatile unsigned *)(GPIO_PORTE + 0x500))
#define GPIO_PORTF_DR2R 		(*(volatile unsigned *)(GPIO_PORTF + 0x500))
#define GPIO_PORTJ_DR2R 		(*(volatile unsigned *)(GPIO_PORTJ + 0x500))
#define GPIO_PORTK_DR2R 		(*(volatile unsigned *)(GPIO_PORTK + 0x500))
#define GPIO_PORTL_DR2R 		(*(volatile unsigned *)(GPIO_PORTL + 0x500))
#define GPIO_PORTM_DR2R 		(*(volatile unsigned *)(GPIO_PORTM + 0x500))
#define GPIO_PORTN_DR2R 		(*(volatile unsigned *)(GPIO_PORTN + 0x500))
#define GPIO_PORTP_DR2R 		(*(volatile unsigned *)(GPIO_PORTP + 0x500))
#define GPIO_PORTQ_DR2R 		(*(volatile unsigned *)(GPIO_PORTQ + 0x500))

#define GPIO_PORTA_DR4R 		(*(volatile unsigned *)(GPIO_PORTA + 0x504))
#define GPIO_PORTB_DR4R 		(*(volatile unsigned *)(GPIO_PORTB + 0x504))
#define GPIO_PORTD_DR4R 		(*(volatile unsigned *)(GPIO_PORTD + 0x504))
#define GPIO_PORTE_DR4R 		(*(volatile unsigned *)(GPIO_PORTE + 0x504))
#define GPIO_PORTF_DR4R 		(*(volatile unsigned *)(GPIO_PORTF + 0x504))
#define GPIO_PORTJ_DR4R 		(*(volatile unsigned *)(GPIO_PORTJ + 0x504))
#define GPIO_PORTK_DR4R 		(*(volatile unsigned *)(GPIO_PORTK + 0x504))
#define GPIO_PORTL_DR4R 		(*(volatile unsigned *)(GPIO_PORTL + 0x504))
#define GPIO_PORTM_DR4R 		(*(volatile unsigned *)(GPIO_PORTM + 0x504))
#define GPIO_PORTN_DR4R 		(*(volatile unsigned *)(GPIO_PORTN + 0x504))
#define GPIO_PORTP_DR4R 		(*(volatile unsigned *)(GPIO_PORTP + 0x504))
#define GPIO_PORTQ_DR4R 		(*(volatile unsigned *)(GPIO_PORTQ + 0x504))

#define GPIO_PORTA_DR8R 		(*(volatile unsigned *)(GPIO_PORTA + 0x508))
#define GPIO_PORTB_DR8R 		(*(volatile unsigned *)(GPIO_PORTB + 0x508))
#define GPIO_PORTD_DR8R 		(*(volatile unsigned *)(GPIO_PORTD + 0x508))
#define GPIO_PORTE_DR8R 		(*(volatile unsigned *)(GPIO_PORTE + 0x508))
#define GPIO_PORTF_DR8R 		(*(volatile unsigned *)(GPIO_PORTF + 0x508))
#define GPIO_PORTJ_DR8R 		(*(volatile unsigned *)(GPIO_PORTJ + 0x508))
#define GPIO_PORTK_DR8R 		(*(volatile unsigned *)(GPIO_PORTK + 0x508))
#define GPIO_PORTL_DR8R 		(*(volatile unsigned *)(GPIO_PORTL + 0x508))
#define GPIO_PORTM_DR8R 		(*(volatile unsigned *)(GPIO_PORTM + 0x508))
#define GPIO_PORTN_DR8R 		(*(volatile unsigned *)(GPIO_PORTN + 0x508))
#define GPIO_PORTP_DR8R 		(*(volatile unsigned *)(GPIO_PORTP + 0x508))
#define GPIO_PORTQ_DR8R 		(*(volatile unsigned *)(GPIO_PORTQ + 0x508))

#define GPIO_PORTA_SLR 	    	(*(volatile unsigned *)(GPIO_PORTA + 0x518))
#define GPIO_PORTB_SLR 	    	(*(volatile unsigned *)(GPIO_PORTB + 0x518))
#define GPIO_PORTD_SLR 	    	(*(volatile unsigned *)(GPIO_PORTD + 0x518))
#define GPIO_PORTE_SLR 		    (*(volatile unsigned *)(GPIO_PORTE + 0x518))
#define GPIO_PORTF_SLR 	    	(*(volatile unsigned *)(GPIO_PORTF + 0x518))
#define GPIO_PORTJ_SLR 	    	(*(volatile unsigned *)(GPIO_PORTJ + 0x518))
#define GPIO_PORTK_SLR 	    	(*(volatile unsigned *)(GPIO_PORTK + 0x518))
#define GPIO_PORTL_SLR 	    	(*(volatile unsigned *)(GPIO_PORTL + 0x518))
#define GPIO_PORTM_SLR 	    	(*(volatile unsigned *)(GPIO_PORTM + 0x518))
#define GPIO_PORTN_SLR 	    	(*(volatile unsigned *)(GPIO_PORTN + 0x518))
#define GPIO_PORTP_SLR 	    	(*(volatile unsigned *)(GPIO_PORTP + 0x518))
#define GPIO_PORTQ_SLR 	    	(*(volatile unsigned *)(GPIO_PORTQ + 0x518))


#define GPIO_PORTA_DR12R 		(*(volatile unsigned *)(GPIO_PORTA + 0x53C))
#define GPIO_PORTB_DR12R 		(*(volatile unsigned *)(GPIO_PORTB + 0x53C))
#define GPIO_PORTD_DR12R 		(*(volatile unsigned *)(GPIO_PORTD + 0x53C))
#define GPIO_PORTE_DR12R 		(*(volatile unsigned *)(GPIO_PORTE + 0x53C))
#define GPIO_PORTF_DR12R 		(*(volatile unsigned *)(GPIO_PORTF + 0x53C))
#define GPIO_PORTJ_DR12R 		(*(volatile unsigned *)(GPIO_PORTJ + 0x53C))
#define GPIO_PORTK_DR12R 		(*(volatile unsigned *)(GPIO_PORTK + 0x53C))
#define GPIO_PORTL_DR12R 		(*(volatile unsigned *)(GPIO_PORTL + 0x53C))
#define GPIO_PORTM_DR12R 		(*(volatile unsigned *)(GPIO_PORTM + 0x53C))
#define GPIO_PORTN_DR12R 		(*(volatile unsigned *)(GPIO_PORTN + 0x53C))
#define GPIO_PORTP_DR12R 		(*(volatile unsigned *)(GPIO_PORTP + 0x53C))
#define GPIO_PORTQ_DR12R 		(*(volatile unsigned *)(GPIO_PORTQ + 0x53C))

#define UART_BASE0              0x4000C000
#define UART_BASE3              0x4000F000
#define UARTIBRD_UART0          (*(volatile unsigned *)(UART_BASE0 + 0x24))
#define UARTIBRD_UART3          (*(volatile unsigned *)(UART_BASE3 + 0x24))

#define UARTFBRD_UART0          (*(volatile unsigned *)(UART_BASE0 + 0x28))
#define UARTFBRD_UART3          (*(volatile unsigned *)(UART_BASE3 + 0x28))

#define UARTLCRH_UART0          (*(volatile unsigned *)(UART_BASE0 + 0x2C))
#define UARTLCRH_UART3          (*(volatile unsigned *)(UART_BASE3 + 0x2C))

#define UARTCTL_UART0           (*(volatile unsigned *)(UART_BASE0 + 0x30))
#define UARTCTL_UART3           (*(volatile unsigned *)(UART_BASE3 + 0x30))

#define UARTCC_UART0            (*(volatile unsigned *)(UART_BASE0 + 0x30))
#define UARTCC_UART3            (*(volatile unsigned *)(UART_BASE3 + 0x30))

#define UART0_DATA              (*(volatile unsigned *)(UART_BASE0))
#define UART3_DATA              (*(volatile unsigned *)(UART_BASE3))

#define UART0FR                 (*(volatile unsigned *)(UART_BASE0 + 0x18))
#define UART3FR                 (*(volatile unsigned *)(UART_BASE3 + 0x18))

#define RCGCGPIO     		    (*(volatile unsigned *)(0x400FE608))
#define RCGCUART                (*(volatile unsigned *)(0x400FE618))

#define UART0  (0x01 << 0)
#define UART3  (0x01 << 3)

#define WDT_BASE0              0x40000000
#define WDT_BASE1              0x40001000

#define WDT0LOAD                (*(volatile unsigned *)(WDT_BASE0 + 0x00))
#define WDT1LOAD                (*(volatile unsigned *)(WDT_BASE1 + 0x00))

#define WDT0VALUE				(*(volatile unsigned *)(WDT_BASE0 + 0x04))
#define WDT1VALUE				(*(volatile unsigned *)(WDT_BASE1 + 0x04))

#define WDT0CTL                 (*(volatile unsigned *)(WDT_BASE0 + 0x08))
#define WDT1CTL                 (*(volatile unsigned *)(WDT_BASE1 + 0x08))

#define WDT0LOCK                (*(volatile unsigned *)(WDT_BASE0 + 0xC00)) //0x1ACC.E551
#define WDT1LOCK                (*(volatile unsigned *)(WDT_BASE1 + 0xC00)) //0x1ACC.E551

#define WDT0ICR                 (*(volatile unsigned *)(WDT_BASE0 + 0x00C))
#define WDT1ICR                 (*(volatile unsigned *)(WDT_BASE1 + 0x00C))


#define HIBCALCTL				(*(volatile unsigned *)(0x400FC300))
#define HIBCTL				    (*(volatile unsigned *)(0x400FC010))
#define HIBCALLD0               (*(volatile unsigned *)(0x400FC320))
#define HIBCALLD1               (*(volatile unsigned *)(0x400FC324))
#define HIBCAL0                 (*(volatile unsigned *)(0x400FC310))
#define HIBCAL1                 (*(volatile unsigned *)(0x400FC314))
#define HIBLOCK                 (*(volatile unsigned *)(0x400FC360)) //0xA3359554
#define HIBCC                   (*(volatile unsigned *)(0x400FCFC8)) //0xA3359554


#define ALTCLKCFG               (*(volatile unsigned *)(0x400FE138))

#define SRWD                    (*(volatile unsigned *)(0x400FE500))

#define RCGCWD                  (*(volatile unsigned *)(0x400FE600))
#define RCGCGPIO     		    (*(volatile unsigned *)(0x400FE608))
#define RCGCHIB                 (*(volatile unsigned *)(0x400FE614))
#define RCGCUART                (*(volatile unsigned *)(0x400FE618))
#define RCGCPWM                 (*(volatile unsigned *)(0x400FE640))
#define RCGCTIMER               (*(volatile unsigned *)(0x400FE604))

#define PCGPIO       		    (*(volatile unsigned *)(0x400FE908))
#define PPHIB                   (*(volatile unsigned *)(0x400FE314))

#define INTEN0                  (*(volatile unsigned *)(0xE000E100))
#define INTEN2                  (*(volatile unsigned *)(0xE000E108))

#define INTDIS0                 (*(volatile unsigned *)(0xE000E180))
#define INTDIS2                 (*(volatile unsigned *)(0xE000E188))

#define INTPEND0                (*589(volatile unsigned *)(0xE000E200))
#define INTPEND2                (*(volatile unsigned *)(0xE000E208))

#define INTUNPEND0              (*(volatile unsigned *)(0xE000E280))
#define INTUNPEND2              (*(volatile unsigned *)(0xE000E288))

#define PWM_BASE                0x40028000
#define PWMGEN0_OFFSET          0x040
#define PWMGEN1_OFFSET          0x080
#define PWMGEN2_OFFSET          0x0C0
#define PWMGEN3_OFFSET          0x100

#define PWM0CTL                  (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET))
#define PWM1CTL                  (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET))
#define PWM2CTL                  (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET))
#define PWM3CTL                  (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET))

#define PWM0GENA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET + 0x20))
#define PWM1GENA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET + 0x20))
#define PWM2GENA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET + 0x20))
#define PWM3GENA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET + 0x20))

#define PWM0GENB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET + 0x24))
#define PWM1GENB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET + 0x24))
#define PWM2GENB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET + 0x24))
#define PWM3GENB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET + 0x24))

#define PWM0LOAD                 (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET + 0x10))
#define PWM1LOAD                 (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET + 0x10))
#define PWM2LOAD                 (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET + 0x10))
#define PWM3LOAD                 (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET + 0x10))

#define PWM0CMPA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET + 0x18))
#define PWM1CMPA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET + 0x18))
#define PWM2CMPA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET + 0x18))
#define PWM3CMPA                 (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET + 0x18))

#define PWM0CMPB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN0_OFFSET + 0x1C))
#define PWM1CMPB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN1_OFFSET + 0x1C))
#define PWM2CMPB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN2_OFFSET + 0x1C))
#define PWM3CMPB                 (*(volatile unsigned *)(PWM_BASE + PWMGEN3_OFFSET + 0x1C))

#define PWMENABLE                (*(volatile unsigned *)(PWM_BASE + 0x008))
#define PWMCC                    (*(volatile unsigned *)(PWM_BASE + 0xFC8))

#define TIMER_BASE5              0x40035000

#define TIMER_RUN_5              (1<<5)

#define GPTMCFG                  (*(volatile unsigned *)(TIMER_BASE5 + 0x000))

#define GPTMTAMR                 (*(volatile unsigned *)(TIMER_BASE5 + 0x004))

#define GPTMCTL                  (*(volatile unsigned *)(TIMER_BASE5 + 0x00C))

#define GPTMTAPR                 (*(volatile unsigned *)(TIMER_BASE5 + 0x038))

#define GPTMTAILR                (*(volatile unsigned *)(TIMER_BASE5 + 0x028))

#define GPTMTMATCHR              (*(volatile unsigned *)(TIMER_BASE5 + 0x030))

#define GPTMCC                   (*(volatile unsigned *)(TIMER_BASE5 + 0xFC8))

#endif /* CORTEXM4_H_ */



#define GPIO_WRITE(reg_addr, pin, data)    (*(volatile unsigned *)(reg_addr + ((pin)<<2))) = data
#define GPIO_READ(reg_addr, pin)           (*(volatile unsigned *)(reg_addr + ((pin)<<2)))
