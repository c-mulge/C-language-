/*Program to print largest number from an array using pointer. Function should return 
pointer of largest element in array.*/

#include<stdio.h>
void accept(int num[50], int n);
int *max(int *p, int n);

int main()
{
    int num[50],n,*p;
    printf("How many numbers: ");
    scanf("%d",&n);
    accept(num,n);
    p=max(num,n);
    printf("Largest no.= %d\n",*p);
    return 0;
}

void accept(int num[50], int n)
{
    int i;
    printf("Enter number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        /* code */
    }
}

int *max(int *p, int n)
{
    int i,a,*ptr;
    a=*ptr;
    for (i = 0; i < n; i++)
    {
        if(*(ptr+i)>n)
        {
            a=*(ptr+i);
            ptr=(p+i);
        }
    }
    return ptr;
}