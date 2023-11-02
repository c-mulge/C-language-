//Ganpati Bappa Morya

//Linked list

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
