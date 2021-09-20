#include<stdio.h>
#define PI 3.14

int main(void)
{
   #ifdef PI
    printf("PI is %.2f\n",PI);
   
   #else
    printf("PI no\n");
 
   #endif
    return 0;
}
