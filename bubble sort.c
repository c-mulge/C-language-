//Bubble Sort

#include<stdio.h>
void bubblesort(int arr[], int n)
{
    int temp;
    int i,j;
    int swapping = 1;

    for ( i = 1; i < n && swapping; i++)
    {
            swapping =0;
        for ( j = 0; j < n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapping = 1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
}
int main()
{
    int n;
    int arr[n];

    printf("How many numbers: ");
    scanf("%d",&n);
    printf("Enter numbers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Original numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    bubblesort(arr, n);

    printf("\nSorted numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}