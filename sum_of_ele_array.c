/*Given an array of integers, find the sum of its elements. 
For example, if the array arr=[1,2,3] ,1+2+3=6 , so return 6 .*/

#include<stdio.h>
#define maxsz 50
int main()
{
    int a[maxsz];
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    printf("Enter %d numbers in array: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=a[i];
    }
    printf("Total: %d",sum);
    return sum;

}
