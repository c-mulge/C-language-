//define program to find value of a and b
#include<stdio.h>
#define Test(x)(x*x)
int main()
{
    int a,b=3;
    a=b+3;
    a=Test(b+3);
    printf("%d %d",a,b);
    return 0;
}//sucessfully runs but didn't understand the code