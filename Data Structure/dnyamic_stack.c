#include<stdio.h>
#include<stdlib.h>
#define maxsz 10

struct stack
{
    int info;
    struct node *next;
};

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

void push(struct stack **s,int value)
{
    struct node *temp=getnode(value);
    temp->next=*s;
    *s=temp;
}

int pop(struct stack **s)
{
    int value;
    struct stack *temp;

    if(*s==NULL)
    {
        printf("Stack Underflow!");
        return 1;
    }
    value=(*s)->info;
    temp=*s;
    (*s)=(*s)->next;
    freenode(temp);
}

int isempty(struct stack **s)
{
    return (*s)==NULL;
}

int main()
{
    char str[maxsz];
    int i=0;
    struct stack stk;
    //initstack(&stk);
    printf("Enter a string: ");
    scanf("%s",str);
    while(str[i]!='\0')
    {
        push(&stk,str[i]);
        i++;
    }
    while(!isempty(&stk))
    printf("%c ",pop(&stk));
    printf("\n");
    return 0;
}