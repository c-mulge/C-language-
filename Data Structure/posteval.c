//PostEval Program with working power function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isoperand(char ch) {
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^') {
        return 1;
    }
    return 0;
}

int evaluate(char oper, int opnd1, int opnd2) 
{
    int result=1;
    switch (oper) {
        case '+':
            return opnd1 + opnd2;
        case '-':
            return opnd1 - opnd2;
        case '*':
            return opnd1 * opnd2;
        case '/':
            return opnd1 / opnd2;
        case '^':
            // Calculate opnd1 to the power of opnd2
            for (int i = 0; i < opnd2; i++) {
                result *= opnd1;
            }
            return result;
    }
    return 0;
}

int posteval(char postfix[]) {
    struct stack stk;
    int opnd1, opnd2, result;
    char opndstr[5];
    int i = 0;
    int len = strlen(postfix);
    initstack(&stk);
    while (i < len) {
        if (isoperand(postfix[i])) {
            opndstr[0] = postfix[i];
            opndstr[1] = '\0';
            push(&stk, atoi(opndstr));
        } else {
            opnd2 = pop(&stk);
            opnd1 = pop(&stk);
            result = evaluate(postfix[i], opnd1, opnd2);
            push(&stk, result);
        }
        i++;
    }
    return pop(&stk);
}

int main() {
    char str[100];
    int res;
    printf("Enter an expression: ");
    scanf("%s", str);
    res = posteval(str);
    printf("Result: %d\n", res);
    return 0;
}
