#include<stdio.h>

int main(void)
{
   int c;
   printf("input number : ");
   c=getchar();

   if(('A'<=c)&&(c<='z'))
   {
      if(('a'<=c)&&(c<='z'))
      {
           c=c-32;
           putchar(c);
           printf("\n");
      }
      else if(('A'<=c)&&(c<='Z'))
      {
           c=c+32;
           putchar(c); 
           printf("\n");
      }
   }
   else
   {
      printf("error number\n");
   } 
}//error
