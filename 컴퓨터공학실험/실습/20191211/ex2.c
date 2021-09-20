#include<stdio.h>
#define SQR(x) x*x
#define PRINT(x) printf("result is %d\n",x);

int main(void)
{
   int result;
   int x=5;

   result=SQR(10);
   PRINT(result);
   result=SQR(x);
   PRINT(result);
   result=SQR(x+3);
   PRINT(result);
}


