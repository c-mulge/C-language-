//binary search using array
#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

int binary(int a[],int lb,int ub,int key)
{
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
                ub=mid-1;
            else
                lb=mid+1;
    }
    return -1;
}

int binary(int a[],int ub,int lb,int key)         //for descending order
{
    int mid;
    while(ub<=lb)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
                ub=mid+1;
            else
                lb=mid-1;
    }
    return -1;
}

int main() 
{
    int a[maxsz];
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int i,j;
    int hold;              
    for (i = 1; i < n; i++) 
    {
        hold = a[i];
        for(j = i - 1; j >= 0 && a[j] > hold; j--)        //change sign to a[j] < hold
        {
            a[j + 1] = a[j];
        }
            a[j + 1] = hold;
    }

    printf("Sorted: \n");
            for(int i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }

    int key;

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    int result = binary(a, 0, n - 1, key);

    if (result != -1) 
    {
        printf("Element %d found at index %d.\n", key, result);
    } 
    else 
    {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
