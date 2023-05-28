//Program to find the absolute value of a number entered through the keyboard.
#include<stdio.h>
int main()
{
    int a;
        printf("Enter the number:");
        scanf("%d",&a);

    if(a<0)   //finding weather it is positive or negative
    {
        a= -a;
    }
    printf("the absolute number is:%d",a);
    return 0;
}