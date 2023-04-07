// find value of a and b
#include<stdio.h>
int main()
{
    int a=10, b=20;
    add(&a, b);
    printf("a=%d\nb=%d\n",a,b);
}

void add(int *a,int b)
{
    *a=*a+1;
    b=b+1;
}//sucessfully runs