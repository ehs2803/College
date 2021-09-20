#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
   FILE *fp;
   int num;
   printf("input number: ");
   scanf("%d",&num);

   fp=fopen("c:\\tempFIO\\ex2.txt","wt");
   if(fp==NULL)
   {
      printf("error exit\n");
      return 1;
   }
   fprintf(fp,"examplefile.\n");
   fprintf(fp,"input number is %d",num);

   fclose(fp);

   printf("success\n");
}
