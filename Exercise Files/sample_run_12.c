#include<stdio.h>
void swap1(int x, int y);
void swap2(int *ptr1, int *ptr2);
int main()
{
    int a,b;
    printf("Enter the value of a and b: ");
    scanf("%d %d",&a,&b);

    printf("Before: a=%d, b=%d\n",a,b);
    swap1(a,b);
    swap2(&a,&b);
    printf("After: a=%d, b=%d\n",a,b);
    
    return 0;
}

void swap1(int x, int y)
{
int temp;
temp = x;
x = y;
y = temp;
}

void swap2(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
