#include<stdio.h>

struct mem{

  unsigned short a;
  unsigned short b;
};

union abc{
   char c[5];
   int ibuf;
   struct mem *ab;
};

int main(void)
{
   struct mem in;
   union abc to;
   to.ab=&in;
   printf("input number: ");
   scanf("%d",to.c);
   to.ibuf=
   printf("high 2byte:%d\n",);
   printf("low 2byte:%d\n",);
   printf("high 1byte asciicode:%c\n",);
   printf("low 1byte asciicode:%c\n",);  
}
