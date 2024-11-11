//use 2.txt file to execute

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MNT
{
    char mname[10];
    int mdtp, kpdtp, pp, kp;
} mnt;

struct MDT
{
    char op[10], value[30];
} mdt[10];

struct KPDT
{
    char key[10], def[10];
} kpdt[5];

char pnt[10][10];

int pnt_cnt, mdt_cnt, kpdt_cnt;
void print_pnt()
{
    int i;
    printf("#\tpname\n");
    for (i = 0; i < pnt_cnt; i++)
        printf("%d\t%s\n", i + 1, pnt[i]);
}
void print_mnt()
{
    printf("\n#MNT\n\tmname\tmdtp\tkpdtp\t#pp\t#kp\n");
    printf("1\t%s\t%d\t%d\t%d\t%d\n",mnt.mname, mnt.mdtp, mnt.kpdtp, mnt.pp, mnt.kp);
}

void print_mdt()
{
    int i;
    printf("\nMDT\n#\topcode\tvalue\n");
    for (i = 0; i < mdt_cnt; i++)
        printf("%d\t%s\t%s\n",i + 1, mdt[i].op, mdt[i].value);
}

void print_kpdt()
{
    int i;
    printf("\nKPDT\n#\tkey\tdef\n");
    for (i = 0; i < kpdt_cnt; i++)
        printf("%d\t%s\t%s\n",
               i + 1, kpdt[i].key, kpdt[i].def);
}

int search(char *s)
{
    int i;
    for (i = 0; i < pnt_cnt; i++)
        if (strcmp(pnt[i], s) == 0)
            return i;
    return -1;
}

void make_pnt_kpdt(char *s)
{
    int i = 0, j = 0, k = 0, f = 0;
    char temp1[10], temp2[10] = "";
    strcat(s, ",");
    while (s[i] != '\0') //&X=,&Y=,&OP=ADD,&REG=AREG,
    {
        if (s[i] == '=')
        {
            temp1[j] = '\0';
            j = 0;
            f = 1;
        }
        else if (s[i] == ',')
        {
            temp2[k] = '\0';
            k = 0;
            f = 0;
            strcpy(pnt[pnt_cnt++], temp1);
            if (strlen(temp2) > 0)
            {
                strcpy(kpdt[kpdt_cnt].key, temp1);   //&OP
                strcpy(kpdt[kpdt_cnt++].def, temp2); // ADD
            }
        } //&X=,&Y=,&OP=ADD,&REG=AREG,
        else
        {
            if (f == 0)
                temp1[j++] = s[i];
            else
                temp2[k++] = s[i];
        }
        i++;
    }
    mnt.pp = pnt_cnt - kpdt_cnt;
    mnt.kp = kpdt_cnt;
}

int main()
{
    FILE *fp;
    char fname[20], buff[80], t1[40], t2[40], t3[40];
    int i, j;

    printf("Enter source file name:");
    scanf("%s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("File %s not found\n", fname);
        exit(1);
    }

    while (fgets(buff, 80, fp) != NULL)
    {
        sscanf(buff, "%s %s %s", t1, t2, t3);
        if (strcmp(t1, "MACRO") == 0)
        {
            fgets(buff, 80, fp); // INCR &X=,&Y=,&OP=ADD,&REG=AREG
            sscanf(buff, "%s %s", t1, t2);
            printf("\nMACRO NAME:%s t2=%s\n", t1, t2);
            strcpy(mnt.mname, t1);
            mnt.mdtp = mnt.kpdtp = 1;
            make_pnt_kpdt(t2);
        }
        else if (strcmp(t1, "MEND") == 0)
        {
            strcpy(mdt[mdt_cnt++].op, t1);
        }
        else
        {
            if (t1[0] == '&')
            {
                i = search(t1);
                sprintf(mdt[mdt_cnt].op, "(P, %d)", i + 1);
            }
            else
            {
                strcpy(mdt[mdt_cnt].op, t1);
            }

            // t2[strlen(t2)-1]='\0';
            i = search(t2);
            j = search(t3);
            sprintf(mdt[mdt_cnt++].value, "(P, %d), (P, %d)", i + 1, j + 1);
        }
    }

    fclose(fp);
    print_pnt();
    print_mnt();
    print_kpdt();
    print_mdt();

    return 0;
}
