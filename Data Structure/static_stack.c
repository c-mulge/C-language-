#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
// #define maxsz 100

// struct stack
// {
//     int data[maxsz];
//     int top;
// };

// void initstack(struct stack *s)
// {
//     s->top=-1;
// }

// int isfull(struct stack *s)
// {
//     return s->top==maxsz-1;
// }

// int isempty(struct stack *s)
// {
//     return s->top==-1;
// }

// void push(struct stack *s,int value)
// {
//     if(isfull(s))
//     {
//         printf("Stack Overflow!");
//         exit(1);
//     }
//     s->data[++s->top]=value;
// }

// int pop(struct stack *s)
// {
//     if(isempty(s))
//     {
//         printf("Stack underflow!");
//         exit(1);
//     }
//     return s->data[s->top--];
// }

// int stacktop(struct stack *s)
// {
//     if(isempty(s))
//     {
//         printf("Stack underflow!");
//         exit(1);
//     }
//     return s->data[s->top];
// }

int main()
{
    char str[maxsz];
    int i=0;
    struct stack stk;
    initstack(&stk);
    printf("Enter a string: ");
    scanf("%s",str);
    while(str[i]!='\0')
    {
        push(&stk,str[i]);
        i++;
    }
    while(!isempty(&stk))
    printf("%c",pop(&stk));
    printf("\n");
    return 0;
}

