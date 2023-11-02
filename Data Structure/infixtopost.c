// //Infix to Postfix Program

#include <stdio.h>
#include "stack.h"
int isoprand(char ch)
{
    if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/')
    {    
        return 1;
    }

    return 0;
}

int preced(char symb, char stop) 
{
    if (symb == '^')
        return 1;
    if (symb == '*' || symb == '/') 
    {
        if (stop == '^')
            return -1;
        if (stop == '+' || stop == '-' || stop == ')')
            return 1;
        if (stop == '*' || stop == '/')
            return 0;
    }
    if (symb == '+' || symb == '-') 
    {
        if (stop == '(')
            return 1;
        if (stop == '*' || stop == '/')
            return -1;
        else
            return 0;
    }
    return 0; 
}

void infix_to_postfix(char infix[], char post[]) 
{
    char symb;
    struct stack stk;
    int i = 0, j = 0; 
    initstack(&stk);
    while (infix[i] != '\0') 
    {
        symb = infix[i];
        if (symb == '(')
            push(&stk, symb);
        else if (isoprand(symb))
            post[j++] = symb;
        else if (symb == '^')
            push(&stk, symb);
        else if (symb == ')') 
        {
            while (!isempty(&stk)) 
            {
                if (stacktop(&stk) != '(')
                    post[j++] = pop(&stk);
                else 
                {
                    pop(&stk);
                    break;
                }
            }
        }
        else 
        {
            while (!isempty(&stk) && preced(symb, stacktop(&stk)) <= 0)
                post[j++] = pop(&stk);
            push(&stk, symb);
        }
        i++;
    }
    while (!isempty(&stk))
        post[j++] = pop(&stk);
    post[j] = '\0';
}


int main()
{
    char infix[100]; 
    char postfix[100]; 
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
  