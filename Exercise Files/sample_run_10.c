#include<stdio.h>
int main()
{
    int arr[100],n;
    void accept(int a[100], int n);
    int find(int a[100], int n);
    accept(arr,n);
    find(arr,n);

}

void accept(int a[100], int n)
{
    int c;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    printf("Enter %d intger: ",n);
    for(c=0;c<n;c++)
    {
        scanf("%d",&a[c]);
    }
}

int find(int a[100], int n)
{
    int search,c;
    printf("Enter a number to search: ");
    scanf("%d",&search);
    for(c=0;c<n;c++)
    {
    if(a[c]==search)
    {
        printf("%d is present at location %d.\n",search,c+1);
        break;
    }
    }
    if(c==n)
    printf("-1\n",search);
    return 0;
}