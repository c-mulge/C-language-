//Sorting of Linked list using Single linked list

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

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
    int num,i,n;
    struct node *list=NULL;
    initlist(&list);
    printf("How many number: ");
    scanf("%d",&n);
    printf("Enter number %d: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        append(list,num);
    }
    printf("The link list: \n");
    display(list);

    printf("\nSorted list is: \n");
    for(i=1;i<n-1;i++)
    { 
        sort(list);
    }
    display(list);
    freenode(list);
    return 0;
}

