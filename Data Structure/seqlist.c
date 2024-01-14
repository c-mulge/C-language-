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

void initlist(struct node **h)
{
    (*h)=getnode(0);
}

void append(struct node *h,int value)
{
    struct node *p=h;
    struct node *temp=getnode(value);
    struct node *q=0;
    int i;
    if(p->next==NULL)
    {
        p->next=temp;
        h->info++;
        return;
    }
    p=h->next;
    q=h;
    for(i=1;i<=h->info && p->info<=value;i++)
    {
        q=p;
        p=p->next;
    }
    temp->next=p;
    q->next=temp;
    h->info++;
}

void display(struct node *h)
{
    h=h->next;
    while(h)
    {
        printf("%d ",h->info);
        h=h->next;
    }
}

int search(struct node *h,int value)
{
    struct node *temp;
    int pos;
    for(temp=h->next,pos=1;temp!=0;temp=temp->next,pos++)
        if(value==temp->info)
            return pos;
    return -1;
}

int main()
{
    struct node *list=NULL;
    initlist(&list);
    int choice;
    int num,key,pos;
    
    while(1)
    {
        printf("\nOperations are: ");
        printf("\n1.Append");
        printf("\n2.Find key");
        printf("\n3.Display");
        printf("\n4.Exit");
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
            printf("Enter key to find: ");
            scanf("%d",&key);
            pos=search(list,key);
            if(pos==-1)
            {
                printf("The %d key did not found in the array.\n",key);
            }
            else
            {
                printf("The %d key is at %d result \n",key,pos);
            }
            break;
        case 3:
            printf("\nElements: ");
            display(list);
            break;
        case 4:
            freenode(list);
            exit(1);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}