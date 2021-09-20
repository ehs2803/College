#include<stdio.h>
#include<string.h>


int main(void)
{
   int i;
   int sum=0;
   int a;
   char in[50];
   printf("input : ");
   scanf("%s",in);
   
   a=strlen(in);
   for(i=0;i<a;i++)
   {
      if(('0'<=in[i])&&(in[i]<='9'))
      {
          sum=(sum+(in[i]-'0'));
      }
   }
   printf("input sum = %d\n",sum);
}

   
  
