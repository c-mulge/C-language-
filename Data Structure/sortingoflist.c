//Sorting of Linked list using Single linked list

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
#define maxsz 50

void sort(struct node *h)
{
    struct node *r=h;
    struct node *q=h->next;
    struct node *p=q->next;
    struct node *tail=NULL;
    while(h->next!=tail)
    {
        while(1)
        {
            if(q->info > p->info)
            {
                r->next=p;
                q->next=p->next;
                p->next=q;
            
                r=p;
                p=q->next;
            }
            else
            {
                r=q;
                q=q->next;
                p=q->next;  
            }
            if(p==tail)
            {
                tail=q;
                return;
            }
         }
         r=h;
         q=h->next;
         p=q->next;
         
    }
}

int main()
{
    int num,i;
    struct node *list=NULL;
    initlist(&list);
    int choice;
    while(1)
    {
        printf("\nLinked List Operations: \n");
        printf("1. Append Linked List\n");
        printf("2. Sort Linked list\n");
        printf("3. Display Linked List\n");
        printf("4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter number: ");
                    scanf("%d",&num);
                    append(list,num);
                break;
            case 2:
                printf("\nThe List is Sorted now.\n");
                for(i=1;i<maxsz-1;i++)
                { 
                    sort(list);
                }
                break;
            case 3:
                printf("\nThe link list: \n");
                display(list);
                printf("\n");
                break;
            case 4:
                freenode(list);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

// int main()
// {
//     int num,i;
//     struct node *list=NULL;
//     initlist(&list);
//     printf("Enter number: ");
//     for(i=0;i<maxsz;i++)
//     {
//         scanf("%d",&num);
//         append(list,num);
//     }
//     printf("\nSorted list is: \n");
    // for(i=1;i<maxsz-1;i++)
    // { 
    //     sort(list);
    // }
//     display(list);
//     freenode(list);
//     return 0;
// }

// int main()
// {
//     int num,i,n;
//     struct node *list=NULL;
//     initlist(&list);
//     printf("How many number: ");
//     scanf("%d",&n);
//     printf("Enter number %d: ",n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&num);
//         append(list,num);
//     }
//     printf("The link list: \n");
//     display(list);
//     printf("\nSorted list is: \n");
//     for(i=1;i<n-1;i++)
//     { 
//         sort(list);
//     }
//     display(list);
//     freenode(list);
//     return 0;
// }
