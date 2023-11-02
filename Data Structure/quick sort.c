//Quick Sort

#include <stdio.h>
// void swap(int *a, int *b)
// {
//     int temp =*a;
//     *a =*b;
//     *b = temp;
// }

int partition(int arr[], int lb, int ub)
{
    int pivot =arr[ub];
    int i =(lb-1);

    for(int j=lb; j<=ub-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ub]);
    return(i+1);
}

void quicksort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int pi=partition(arr, lb, ub);
        quicksort(arr, lb, pi-1);
        quicksort(arr, pi+1, ub);
    }
}
int main()
{
    int n;
    printf("enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    quicksort(arr, 0, n-1);

    printf("\nSorted array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}