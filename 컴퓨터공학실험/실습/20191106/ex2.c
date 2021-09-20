#include<stdio.h>

#define SIZE 50

int main(void)
{
   int i;
   int sum=0;
   int value;
   char in[SIZE];
   printf("input : ");
   scanf("%s",in);
 

   for(i=0;i<SIZE;i++)
   {
      if(in[i]=='1')
      {   
        sum=sum+1;    
      }
      else if(in[i]=='2')
      {
         sum=sum+2;
      }
      else if(in[i]=='3')
      {
         sum=sum+3;
      }
      else if(in[i]=='4')
      {
         sum=sum+4;
      }
      else if(in[i]=='5')
      {
         sum=sum+5;
      }
      else if(in[i]=='6')
      {
         sum=sum+6;
      }
      else if(in[i]=='7')
      {
         sum=sum+7;
      }
      else if(in[i]=='8')
      {
         sum=sum+8;
      }
      else if(in[i]=='9')
      {
         sum=sum+9;
      }
   }
   printf("number sum = %d\n",sum);
}
