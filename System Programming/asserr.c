//use 1.txt or var.txt to execute

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    char symb[20];
    int decl, used;
    struct node *next;
} NODE;
char optab[][6] = {"STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM", "COMP", "BC",
                   "DIV", "READ", "PRINT"};
NODE *first, *last;

void add_symb1(char *s)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->symb, s);
    p->decl = 1;
    p->used = 0;
    p->next = NULL;
    if (first == NULL)
        first = p;
    else
        last->next = p;
    last = p;
}

void add_symb2(char *s)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->symb, s);
    p->decl = 0;
    p->used = 1;
    p->next = NULL;
    if (first == NULL)
        first = p;
    else
        last->next = p;
    last = p;
}

NODE *search(char *s)
{
    NODE *p;
    p = first;
    while (p != NULL)
    {
        if (strcmp(p->symb, s) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

int search_op(char *s)
{
    int i;
    for (i = 0; i < 11; i++)
        if (strcmp(optab[i], s) == 0)
            return i;
    return -1;
}

int main()
{
    NODE *p;
    FILE *fp;
    char buff[80], t1[20], t2[20], t3[20], t4[20], fname[40];
    int n, i;
    printf("Enter source file name:");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("File %s not found.\n", fname);
        exit(1);
    }
    while (fgets(buff, 80, fp) != NULL)
    {
        n = sscanf(buff, "%s %s %s %s", t1, t2, t3, t4);
        switch (n)
        {
        case 2: // start 100, READ A, PRINT A, Label End
            if (strcmp(t1, "START") == 0)
                break;
            i = search_op(t1);
            if (i == 9 || i == 10)
            {
                p = search(t2);
                if (p == NULL)
                    add_symb2(t2);
                else
                    p->used = 1;
                break;
            }
            p = search(t1);
            if (p == NULL)
                add_symb1(t1);
            else
                p->decl++;
            break;

        case 3: // mover areg A,
            i = search_op(t1);
            if (i >= 1 && i <= 8)
            {
                p = search(t3);
                if (p == NULL)
                    add_symb2(t3);
                else
                    p->used = 1;
                break;
            }
            // A ds 1, B DC 3
            if (strcmp(t2, "DS") == 0 || strcmp(t2, "DC") == 0)
            {
                p = search(t1);
                if (p == NULL)
                    add_symb1(t1);
                else
                    p->decl++;
                break;
            }
            p = search(t1); // label print A or label read A
            if (p == NULL)
                add_symb1(t1);
            else
                p->decl++;
            p = search(t3);
            if (p == NULL)
                add_symb2(t3);
            else
                p->used = 1;
            break;
        case 4: // Label Mover areg C
            p = search(t1);
            if (p == NULL)
                add_symb1(t1);
            else
                p->decl++;
            p = search(t4);
            if (p == NULL)
                add_symb2(t4);
            else
                p->used = 1;
        }
    }
    fclose(fp);
    p = first;
    while (p != NULL)
    {
        if (p->decl != 0 && p->used == 0)
            printf("Symb %s declared but not used.\n", p->symb);
        if (p->used == 1 && p->decl == 0)
            printf("Symb %s used but not declared.\n", p->symb);
        if (p->decl > 1)
            printf("Symb %s redeclared.\n", p->symb);
        p = p->next;
    }
    return 0;
}
