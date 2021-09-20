#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
   FILE *fp;
   
   fp=fopen("c:\\Temp\\sample.txt","w");
   if(fp==NULL)
   {
      printf("error exit\n");
      return 1;
   }

   fprintf(fp,"example.");
   fclose(fp);

   printf("success\n");
}
