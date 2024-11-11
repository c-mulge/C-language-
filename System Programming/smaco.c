#include <stdio.h>
#include <stdlib.h>
int mem[100], reg[4], cond[] = {0, 0, 0, 0, 0, 1}, opc, op1, op2, pc;
FILE *fp;
char fname[20];

void load()
{
    printf("Enter file name: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("File %s not found \n", fname);
        exit(1);
    }
    while (fscanf(fp, "%d", &mem[pc]) != -1)
    {
        pc++;
    }
    printf("File Successfully Loaded");
    fclose(fp);
}

void print()
{
    int i;
    for (i = 0; i < pc; i++)
    {
        printf("%06d\n", mem[i]);
    }
}

void run()
{
    int i;
    pc = 0;
    while (1)
    {
        opc = mem[pc] / 10000;
        op1 = mem[pc] % 10000 / 1000 - 1;
        op2 = mem[pc] % 1000;
        switch (opc)
        {
        case 0:
            return;
        case 1:
            reg[op1] += mem[op2];
            break;
        case 2:
            reg[op1] -= mem[op2];
            break;
        case 3:
            reg[op1] *= mem[op2];
            break;
        case 8:
            reg[op1] /= mem[op2];
            break;
        case 4:
            reg[op1] = mem[op2];
            break;
        case 5:
            mem[op2] = reg[op1];
            break;
        case 6:
            if (reg[op1] < mem[op2])
                cond[0] = 1;
            if (reg[op1] <= mem[op2])
                cond[1] = 1;
            if (reg[op1] == mem[op2])
                cond[2] = 1;
            if (reg[op1] > mem[op2])
                cond[3] = 1;
            if (reg[op1] >= mem[op2])
                cond[4] = 1;
            break;
        case 7:
            if (cond[op1] == 1)
                pc = op2 - 1;
            for (i = 0; i < 5; i++)
                cond[i] = 0;
            break;
        }
    }
}