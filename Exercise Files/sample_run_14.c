#include<stdio.h>
int main()
{
    int num[5],*ptr,i,n,sum=0;
    printf("How many numbers: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    ptr=&num[n-1];
    printf("Reverse Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*ptr);
        ptr--;
    }
    return 0;
}