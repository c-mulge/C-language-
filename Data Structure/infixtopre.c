//Infix to Prefix
//Input should be =  (a+b)
#include <stdio.h>
#include "stack.h"

int isoperand(char ch) {
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
        return 1;
    }
    return 0;
}

int preced(char symb, char stop) {
    if (symb == '^')
        return 1;
    if (symb == '*' || symb == '/') {
        if (stop == '^')
            return -1;
        if (stop == '+' || stop == '-' || stop == '(')
            return 1;
        if (stop == '*' || stop == '/')
            return 0;
    }
    if (symb == '+' || symb == '-') {
        if (stop == '(')
            return 1;
        if (stop == '*' || stop == '/')
            return -1;
        else
            return 0;
    }
    return 0; 
}

void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infix_to_prefix(char infix[], char prefix[])
{
    char symb;
    struct stack stk;
    int i = 0, j = 0; 
    initstack(&stk);
    reverseString(infix); 
    while (infix[i] != '\0') {
        symb = infix[i];
        if (symb == '(')
            push(&stk, symb);
        else if (isoperand(symb))
            prefix[j++] = symb;
        else if (symb == '^') {
            pop(&stk);
            push(&stk, symb);
        } else if (symb == ')') {
            while (!isempty(&stk)) {
                if (stacktop(&stk) != '(')
                    prefix[j++] = pop(&stk);
                else {
                    pop(&stk);
                    break;
                }
            }
        } else {
            while (!isempty(&stk) && preced(symb, stacktop(&stk)) < 0)
                prefix[j++] = pop(&stk);
            push(&stk, symb);
        }
        i++;
    }
    while (!isempty(&stk))
        prefix[j++] = pop(&stk);
    prefix[j] = '\0';
    reverseString(prefix); 
}

int main() {
    char infix[100]; 
    char prefix[100]; 
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infix_to_prefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
