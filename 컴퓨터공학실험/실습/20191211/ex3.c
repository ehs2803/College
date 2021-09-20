#include<stdio.h>
#define SQR(x) printf(""#x" is %d\n",((x)*(x)));

int main(void)
{
   int x=5;

   SQR(x);
   SQR(3+4);
}
