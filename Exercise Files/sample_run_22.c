//take input from user as the angles and verify it forms a triange or not.

#include<stdio.h>
int main()
{

    int a,b,c,sum;
    printf("Enter the angles: ");
    scanf("%d %d %d",&a, &b, &c);

    sum=a+b+c;

    if(sum==180)
   { printf("It is a triange.\n");
   }
    else
    printf("It is not a triange.\n");
    
    return 0;
}