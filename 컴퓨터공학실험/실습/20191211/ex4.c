#include<stdio.h>
#define XN(n) x##n

int main(void)
{
   int XN(1)=10;
   int XN(2)=20;

   printf("x1 is %d\n",x1);
   printf("x2 is %d\n",x2);
}
