#include<stdio.h>

int main()
{
int x=2,a=2,b=3,c=6;
poly(x,a,b,c);
}

int poly(int x,int a,int b,int c)
{
int n =(a*x*x)+(b*x)+c;
printf("the value of the equation is %d",n);

}