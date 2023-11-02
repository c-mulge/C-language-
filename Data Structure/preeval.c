//Preeval program
//It contains reverse function so put input as posteval but in rev

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isoperand(char ch) 
{
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^') 
    {
        return 1;
    }
    return 0;
}

void reverseString(char str[]) 
{
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) 
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int evaluate(char oper, int opnd1, int opnd2) 
{
    int result = 0; 
    switch (oper) 
    {
        case '+':
            result = opnd1 + opnd2;
            break;
        case '-':
            result = opnd1 - opnd2;
            break;
        case '*':
            result = opnd1 * opnd2;
            break;
        case '/':
            result = opnd1 / opnd2;
            break;
        case '^':
            result = 1;
            for (int i = 0; i < opnd2; i++) 
            {
                result *= opnd1;
            }
            break;
    }
    return result;
}

int preeval(char prefix[]) 
{
    struct stack stk;
    int opnd1, opnd2, result;
    char opndstr[5];
    int len = strlen(prefix);
    initstack(&stk);
    reverseString(prefix); 
    int i = len - 1; 
    while (i >= 0) { 
        if (isoperand(prefix[i])) 
        {
            opndstr[0] = prefix[i];
            opndstr[1] = '\0';
            push(&stk, atoi(opndstr));
        } else 
        {
            opnd1 = pop(&stk);
            opnd2 = pop(&stk);
            result = evaluate(prefix[i], opnd1, opnd2);
            push(&stk, result);
        }
        i--; 
    }
    return pop(&stk);
    reverseString(prefix); 
}

int main() 
{
    char str[100];
    int res;
    printf("Enter a prefix expression: ");
    scanf("%s", str);
    res = preeval(str);
    printf("Result: %d\n", res);
    return 0;
}
