// descending priority queue- insert operation

#include<stdio.h>
#include<stdlib.h>
#include "dynamic_queue.h"

void apqinsert(struct queue *q,int value)
{
    struct node *temp=getnode(value);
    struct node *p=q->front;
    struct node *r=NULL;
    while(p!=NULL && p->info > value)
    {
        r=p;
        p=p->next;
    }
    if(r==NULL)
    {
        q->front=temp;
        temp->next=p;
        if(q->rear==NULL)
        {
            q->rear=temp;
        }
        return;
    }
    temp->next=p;
    r->next=temp;
    if(p==NULL)
    {
        q->rear=temp;
    }
}

int main()
{
    struct queue q;
    initq(&q);
    int choice,temp;
    while(1)
    {
        printf("\nOperations are: ");
        printf("\n1. Add");
        printf("\n2. Delete");
        printf("\n3. Front");
        printf("\n4. Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                    printf("Enter the number to add: ");
                    scanf("%d",&temp);
                    apqinsert(&q,temp);
                    break;
            case 2:
                    printf("Deleted number: %d\n",deleq(&q));
                    break;
            case 3:
                    if(isempty(&q))
                    {
                        printf("Queue is Empty.");
                        exit(0);
                    }
                    printf("Front of Queue is: %d\n",(q.front)->info);
                    break;
            case 4:
                    if(isempty(&q))
                    {
                        printf("Queue is Empty.");
                        exit(0);
                    }
                    printf("Rear of Queue is: %d\n",(q.rear)->info);
                    break;
            case 5:
                    printf("Queue elements are: ");
                    display(&q);
                    printf("\n");
                    break;
            case 6:
                    exit(0);
                    break;
            default:
                    printf("Invalid choice.\n");
                    break;
        }
    }
}