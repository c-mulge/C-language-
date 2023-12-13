//binary search using array
#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

int binary(int arr[],int size,int element)
{
    int low,mid,high;
    low=0;
    high=size-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

void bubblesort(int a[],int n)
{
    int temp;
    int i,j,swapping=1;
        for(i=1;i<n && swapping;i++)            // swapping=1 means swap
        {                                       // swapping = 0 means no swap
            swapping=0;
            for(j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])             //change the sign to make the code in descending order
                {
                    swapping=1;           // if it is true then swapping is necessary
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
}

int main()
{
    int choice;
    int arr[maxsz];
    int size,element,index;
    printf("Size of array: \n");
    scanf("%d",&size);
    printf("Enter %d elements: \n",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    while(1)
    {
        printf("\nOperations are: ");
        printf("\n1.Sort Array");
        printf("\n2.Find element");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: 
            bubblesort(arr,size);
            printf("Sorted: \n");
            for(int i=0;i<size;i++)
            {
                printf("%d ",arr[i]);
            }
            break;
        case 2:
            printf("Enter element to find: ");
            scanf("%d",&element);
            index=binary(arr,size,element);
            if(index==-1)
            {
                printf("The %d element did not found in the array.\n",element);
            }
            else
            {
                printf("The %d element is at %d index \n",element,index);
            }
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}