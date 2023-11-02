#include <stdio.h>
#define maxsz 50

void display(int *a,int n)   // display function to printf the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[maxsz];
    i = low;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])       //change the sign to make the code for descending
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (i = low,k=0; i <= high; i++,k++)
        a[i] = b[k]; 
}

void mergesort(int a[], int low, int high)
{
    int mid; 
    if(low<high)
    {
        mid = (low + high) /2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int i, a[maxsz],n;
    printf("How many numbers: ");
        scanf("%d",&n);
    printf("Enter %d numbers: \n",n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    mergesort(a, 0, n-1);
    printf("\nSorted list is: ");
    display(a,n);
    return 0;
}





