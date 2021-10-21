/*
 * MyLib.h
 *
 *  Created on: 2018. 03. 08.
 *      Author: ESL-KMC
 */

#ifndef FND_STUDENT_MYLIB_H_
#define FND_STUDENT_MYLIB_H_

static unsigned char fnd_num[17] = {
//	0		1		2		3		4		5		6		7
	0x3f,	0x06,	0x5b,	0x4f,	0x66,	0x6d,	0x7d,	0x27,
//	8		9		a		b		c		d		e		f
	0x7f,	0x67,	0x5f,	0x7c,	0x39,	0x5e,	0x79,	0x71,
//	off
	0x00
};

static unsigned char fnd_pos[6] = {
//	D1		D2		D3		D4		D5		D6
	0x01,	0x02,	0x04,	0x08,	0x10,	0x20
};

void FND_write(int digit, int seg_out);
void FND_write_dot(int digit, int seg_out);
void FND_clear();
void FND_init();

#endif /* FND_STUDENT_MYLIB_H_ */
