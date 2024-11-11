//use 3.txt file to execute

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MDT
{
    char op[10], value[30];
} mdt[] = {
    {"MOVER", "AREG, (P, 1)"},
    {"(P, 3)", "AREG, (P, 2)"},
    {"MOVEM", "AREG, (P, 1)"},
    {"MEND"}};

char pnt[][10] = {"&A", "&B", "&OP"};

struct MNT
{
    char mname[10];
    int mdtp, kpdtp, pntp, kp, pp;
} mnt = {"CALC", 0, 0, 0, 1, 2};

struct KPDT
{
    char key[10], def[10];
} kpdt = {"&OP", "ADD"};

int pnt_cnt;

void make_apt(char *s)
{
    int i = 0, j = 0;
    char temp[10];

    pnt_cnt = 0;
    strcat(s, ",");

    while (s[i] != '\0' && s[i] != '=')
    {
        if (s[i] == ',')
        {
            temp[j] = '\0';
            j = 0;
            strcpy(pnt[pnt_cnt++], temp);
        }
        else
        {
            temp[j++] = s[i];
        }
        i++;
    }

    while (s[i] != '\0')
    {
        if (s[i] == '=')
        {
            j = 0;
        }
        else if (s[i] == ',')
        {
            temp[j] = '\0';
            j = 0;
            strcpy(pnt[mnt.pp], temp);
        }
        else
        {
            temp[j++] = s[i];
        }
        i++;
    }
}

void expand()
{
    int mec;
    char t1[10], t2[10], t3[10];

    mec = mnt.mdtp;
    /*	{"MOVER","AREG, (P, 1)"},
        {"(P, 3)", "AREG, (P, 2)"},
        {"MOVEM", "AREG, (P, 1)"},
        {"MEND"}};*/
    while (strcmp(mdt[mec].op, "MEND") != 0)
    {
        if (mdt[mec].op[0] == '(') //(P, 3)
        {
            sscanf(mdt[mec].op, "%s %s", t1, t2); //(P, 3)
            printf("+%s ", pnt[atoi(t2) - 1]);
        }
        else
        {
            printf("+%s ", mdt[mec].op);
        }

        sscanf(mdt[mec].value, "%s %s %s", t1, t2, t3); // AREG, (P, 1)
        printf("%s %s\n", t1, pnt[atoi(t3) - 1]);

        mec++;
    }
}

int main()
{
    FILE *fp;
    char fname[20], buff[80], t1[30], t2[30];

    printf("Enter file name:");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("File %s not found.\n", fname);
        exit(1);
    }

    while (fgets(buff, 80, fp) != NULL)
    {
        sscanf(buff, "%s %s", t1, t2);
        strcpy(pnt[mnt.pp], kpdt.def);
        make_apt(t2);
        expand();
    }

    fclose(fp);

    return 0;
}
