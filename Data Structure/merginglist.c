//Merging of two linked list

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

void insert(struct node *h,int value,int pos)
{
    struct node *temp=0;
    struct node *p=0,*q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid!");
        exit(1);
    }
    temp=getnode(value);
    p=h->next;
    q=h;
    for(i=1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    temp->next=p;
    q->next=temp;
    h->info++;
}

void delete(struct node *h,int pos)
{
    struct node *p=0,*q=0;
    int i;
    if(pos>h->info)
    {
        printf("Invalid!");
        exit(1);
    }
    p=h->next;
    q=h;
    for(i=1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    h->info--;
}

int main()
{
    struct node *head1=0, *head2=0, *head3=0;
    int m,n;
    struct node *p1, *p2;
    int i,value;

    initlist(&head1);
    initlist(&head2);
    initlist(&head3);
    printf("How many integers in 1st list: ");
    scanf("%d",&m);

    printf("Enter %d integers for 1st list: ",m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&value);
        append(head1,value);
    }
    printf("\nThe 1st list is: ");
    display(head1);

    printf("\nHow many integers in 2nd list: ");
    scanf("%d",&n);

    printf("Enter %d integers for 2nd list: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        append(head2,value);
    }
    printf("\nThe 2nd list is: ");
    display(head2);

    p1=head1->next;
    p2=head2->next;

    while(p1 && p2)
    {
        if(p1->info < p2->info)
        {
            append(head3,p1->info);
            p1=p1->next;
        }
        else
        {
            append(head3,p2->info);
            p2=p2->next;
        }
    }
    while(p1)
    {
        append(head3,p1->info);
        p1=p1->next;
    }
    while(p2)
    {
        append(head3,p2->info);
        p2=p2->next;
    }

    printf("\nMerging two linked list: ");
    display(head3);
    return 0;
}
