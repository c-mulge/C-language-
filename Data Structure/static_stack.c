#include<stdio.h>
#include<stdlib.h>
#define maxsz 100

struct stack
{
    int data[maxsz];
    int top;
};

void initstack(struct stack *s)
{
    s->top=-1;
}

int isfull(struct stack *s)
{
    return s->top==maxsz-1;
}

int isempty(struct stack *s)
{
    return s->top==-1;
}

void push(struct stack *s,int value)
{
    if(isfull(s))
    {
        printf("Stack Overflow!");
        exit(1);
    }
    s->data[++s->top]=value;
}

int pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Stack underflow!");
        exit(1);
    }
    return s->data[s->top--];
}

int stacktop(struct stack *s)
{
    if(isempty(s))
    {
        printf("Stack underflow!");
        exit(1);
    }
    return s->data[s->top];
}

//With using push, pop, stacktop operation 
int main()
{
    int str;
    struct stack stk;
    initstack(&stk);
    int choice;
    while(1)
    {
        printf("\nStack operations: ");
        printf("\n1. Push element in stack.");
        printf("\n2. Pop element from stack.");
        printf("\n3. Stacktop.");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:                                       //Push operation
                printf("Enter element: ");
                scanf("%d",&str);
                push(&stk,str);
                break;
            case 2:                                          //POP operation
                printf("\nPop element: %d",pop(&stk));
                printf("\n");
                break;
            case 3:                                       //stacktop opeartion. It display's / point to the topmost element of the stack.
                printf("Stacktop: %d",stacktop(&stk));
                break;
            case 4:                //exit from program
                exit(0);
                break;
            default: 
                printf("Invalid Choice");          //if user gives incorrect choice then!
                break;
        }
    }return 0;
}



