#include<stdio.h>

int main(void)
{
   FILE *fp;
   int num1, num2;
   printf("1. input number : ");
   scanf("%d",&num1);
   printf("2. input number : ");
   scanf("%d",&num2);

   fp=fopen("ex3.txt","wt");
   if(fp==NULL)
   {
      printf("error exit\n");
      return 1;
   }
   fprintf(fp,"%d + %d fourcal result.\n",num1,num2);
   fprintf(fp,"%d + %d = %d\n",num1,num2,num1+num2);
   fprintf(fp,"%d - %d = %d\n",num1,num2,num1-num2);
   fprintf(fp,"%d * %d = %d\n",num1,num2,num1*num2);
   fprintf(fp,"%d / %d = %d\n",num1,num2,num1/num2);

   fclose(fp);
  
   printf("success\n");
}
