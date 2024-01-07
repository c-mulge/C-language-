//Question- Reverse an given array

#include<stdio.h>                                //dynamic memory allocation is done
#include<stdlib.h>
void reverse(int arr[],int size)
{
    int start=0;                //in this program I have used swapping method to reverse an array
    int end=size-1;
    while(start<end)
    {
        int temp =arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        
        start++;
        end--;
    }
}
int main()
{
    int *a=NULL;
    int n;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    reverse(a, n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}
