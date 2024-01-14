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

void accept(int a[],int n)
{
    int i,j;
    int hold;
    for(i=0;i<n;i++)
    {
        scanf("%d",&hold);
        for(j=i-1;j>=0&&hold<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=hold;
    }
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int choice;
    int a[maxsz];
    int n,key;
    
    while(1)
    {
        printf("\nOperations are: ");
        printf("\n1.Insert");
        printf("\n2.Find key");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Size of array: ");
            scanf("%d",&n);
            printf("Enter %d numbers: ",n);
            accept(a,n);
            break;
        case 2:
            printf("Enter key to find: ");
            scanf("%d",&key);
            int result=binary(a,0,n-1,key);
            if(result==-1)
            {
                printf("The %d key did not found in the array.\n",key);
            }
            else
            {
                printf("The %d key is at %d result \n",key,result);
            }
            break;
        case 3:
            printf("\nElements: ");
            display(a,n);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
