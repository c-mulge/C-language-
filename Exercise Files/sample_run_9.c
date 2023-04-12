#include<stdio.h>
void accept(int a[20], int n);
void display(int a[20], int);
int main()
{
    int arr[20],i,n;
    printf("How much attempting: ");
    scanf("%d",&n);
    accept(arr,n);
    display(arr,n);
    return 0;
}

void accept(int a[20], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the number of %d is: ",i);
        scanf("%d",&a[i]);
    }
}

void display(int a[20], int n)
{
    int i;
    n--;
    for(i=n;i>=0;i--)
    {
        printf("The value of %d is= %d \n",i,a[i]);
    }
}