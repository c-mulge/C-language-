#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
int ismatch(char close,char open)
{
    if((close=='}' && open=='{')||(close==']'&& open=='[')||(close==')'&& open=='('))
    return 1;
    else
    return 0;
}

int isparent(char expr[])
{
    struct stack stk;
    int i=0;
    initstack(&stk);
    while(expr[i]!='\0')
    {
        if(expr[i]=='{'||expr[i]=='['||expr[i]=='(')
        {
            push(&stk,expr[i]);
        }
        else if(expr[i]=='}'||expr[i]==']'||expr[i]==')')
        {
            if(isempty(&stk) && ismatch(expr[i],pop(&stk)))
            {
                return 0;
            }
        }
        i++;
    }
    // if(isempty(&stk))
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
    isempty(&stk)?1:0;
}


int main()
{
    char expr[maxsz];
    printf("Enter the expression: ");
    gets(expr);
    if(isparent(expr))
    {
        printf("Expression is Parenthesized");
    }
    else
    {
        printf("Expression is not Parenthesized");
    }
}