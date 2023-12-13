// Linear Search

#include<stdio.h>
#include<stdlib.h>
#define maxsz 50

int linear(int arr[],int size,int element)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
        
    }
   return -1;
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
        printf("\n1.Find element");
        printf("\n2.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter element to find: ");
            scanf("%d",&element);
            index=linear(arr,size,element);
            if(index==-1)
            {
                printf("The %d element did not found in the array.\n",element);
            }
            else
            {
                printf("The %d element is at %d index \n",element,index);
            }
            break;
        case 2:
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
//     int arr[]={2,5,285,35,45,25544,21854,1548,257,2185};
//     int element=0;
//     int size=sizeof(arr)/sizeof(int);
//     int index=linear(arr,size,element);
//     if(index==-1)
//     {
//         printf("The %d element did not found in the array.\n",element);
//     }
//     else
//     {
//         printf("The %d element is at %d index \n",element,index);
//     }  
// }
