// Linear Search

#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

int linear(int a[],int n,int key)
{
    int i;
    for (i = 0; i < n && a[i]<key; i++);
    if(a[i]==key)
        return i;    
    return -1;
}

int main()
{
    int choice;
    int a[maxsz];
    int n,key;
    printf("Size of array: \n");
    scanf("%d",&n);
    printf("Enter %d elements: \n",n);
    for (int i = 0; i < n; i++)
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
    while(1)
    {
        printf("\nOperations are: ");
        printf("\n1.Find key");
        printf("\n2.Display");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter key to find: ");
            scanf("%d",&key);
            int result=linear(a,n,key);
            if(result==-1)
            {
                printf("The %d key did not found in the array.\n",key);
            }
            else
            {
                printf("The %d key is at %d result \n",key,result);
            }
            break;
        case 2:
            printf("\nElements: ");
            for (i = 0; i < n; i++) 
            {
                printf("%d ", a[i]);
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

// int main()
// {
//     int a[]={2,5,285,35,45,25544,21854,1548,257,2185};
//     int key=0;
//     int n=sizeof(a)/sizeof(int);
//     int result=linear(a,n,key);
//     if(result==-1)
//     {
//         printf("The %d key did not found in the array.\n",key);
//     }
//     else
//     {
//         printf("The %d key is at %d result \n",key,result);
//     }  
// }
