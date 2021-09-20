#include<stdio.h>
#define SUB(X,Y) X-Y
#define PRINTF(X) printf("resulr is %d\n",X);

int main(void)
{
  int result;

  int num1=30, num2=12;
 
  result=SUB(num1,num2);
  PRINTF(result);

}
