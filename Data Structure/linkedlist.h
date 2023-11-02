#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void initlist(struct node **head)
{
    (*head)=getnode(0);
}

void append(struct node *head, int value)
{
    struct node *p = head;
    struct node *temp=getnode(value);
    while(p->next)
    {
        p=p->next;
    }
    p->next=temp;
    head->info++;
}

void display(struct node *head)
{
    struct node *p=head->next;
    while(p)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}