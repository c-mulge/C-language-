//Double circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
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
    (*head)->next=*head;
    (*head)->prev=*head;
    //(*head)->info=0;
}

void append(struct node *head, int value)
{
    struct node *temp = getnode(value);
    struct node *p = head->prev;


        // Update the pointers to make the new node the last node
        temp->next=head;
        temp->prev=p;
        p->next = temp;
        head->prev = temp;
        head -> info++;
    
}

void display(struct node *head)
{
    struct node *p=head->next;
    while(p!=head)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

void insert(struct node *h, int value, int pos)
{
    struct node *temp = getnode(value);
    struct node *p = 0,*q=0;
    int i;

    if (pos >h->info)
    {
        printf("Invalid position.\n");
        exit(1);
    }

    p=h->next;

    for(i=1;i<pos;i++)
    {
        p=p->next;
    }

    temp=getnode(value);
    q=p->prev;
    temp->next=p;
    temp->prev=q;
    q->next=temp;
    p->prev=temp;
    h->info++;
    
}

void delete(struct node *h, int pos)
{
    struct node *p = h->next,*q=h;
    int i;

    if (pos >h->info)
    {
        printf("Invalid position.\n");
        exit(1);
    }

    p=h->next;

    for(i=1;i<pos;i++)
    {
        p=p->next;
    }

    q=p->prev;
    q->next=p->next;
    freenode(p);
    h->info--;
}

int main()
{
    int num,i,n,pos,value,d;
    struct node *list=NULL;
    initlist(&list);
    printf("How many number: ");
    scanf("%d",&n);
    printf("Enter number: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        append(list,num);
    }
    printf("The link list: \n");
    display(list);
    printf("\nEnter position to Insert: ");
    scanf("%d",&pos);
    printf("\nEnter value to Insert: ");
    scanf("%d",&value);
    insert(list,value,pos);
    printf("\nUpdated list is: ");
    display(list);
    printf("\nEnter position to Delete: ");
    scanf("%d",&d);
    delete(list,d);
    printf("Updated list is: ");
    display(list);
    freenode(list);
    return 0;
}