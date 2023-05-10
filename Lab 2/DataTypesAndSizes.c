#include <stdio.h>
#include <limits.h>
#include<float.h>

int main() {
int p=0;


printf("Data Type|Value|Size(ib Byte)|Min|max|\n");
printf("SIGNED CHAR 'A'  %d  %d  %d  \n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
printf("SHORT INT  300 %d %d %d \n", sizeof(short int),SHRT_MIN,SHRT_MAX);
printf("CHAR 'A' %d %d %d \n", sizeof(char),CHAR_MIN,CHAR_MAX);
printf("INT  100 %d %d %d \n", sizeof(int),INT_MIN,INT_MAX);
printf("LONG INT  1000000 %d%ld%ld\n", sizeof(long int),LONG_MIN,LONG_MAX);
printf("LONG LONG INT  1111111111 %d  %d  %d\n", sizeof(long long int),LLONG_MIN,LLONG_MAX);
printf("UNSIGNED CHAR  'a'%d %d %d\n", sizeof(unsigned char),p,UCHAR_MAX);
printf("UNSIGNED SORT INT  65530 %d  %d  %d\n", sizeof(unsigned short int),p,USHRT_MAX);
printf("UNSIGNED  INT  50 %d  %d  %d\n", sizeof(unsigned  int),p,UINT_MAX);
printf("UNSIGNED LONG  INT  30 %d  %d  %d\n", sizeof(unsigned long int),p,ULONG_MAX);
printf("UNSIGNED LONG LONG INT  10000000 %d  %d  %llu\n", sizeof(unsigned long long int),p,ULONG_LONG_MAX);
printf("FLOAT  15.75 %d  %f  %f\n", sizeof(float),FLT_MIN,FLT_MAX);
printf("DOULBLE  100.1 %d  %llx  %llx\n", sizeof(double),DBL_MIN,DBL_MAX);

  
   return 0;
}
