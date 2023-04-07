// Addition of two matrices
#include<stdio.h>
void accept(int[10][10],int,int);
void add(int[10][10],int[10][10],int,int);
void display(int[10][10],int,int);
int main()
{
    int a[10][10];
    int b[10][10];
    int r1,r2,c1,c2;
    printf("Enter numbers of rows and cols for 1st Matrix:\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter numbers of rows and cols for 2nd Matrix:\n");
    scanf("%d %d",&r2,&c2);

    printf("Enter elements for 1st Matrix:\n");
    accept(a,r1,c1);
    printf("Enter elements for 2nd Matrix:\n");
    accept(b,r2,c2);

        if((r1==r2)&&(c1==c2))
        {
            add(a,b,r1,c1);
        }
        else
        {
            printf("Addition not Possible\n");
        }
        
}

void accept(int a[10][10],int r1,int c1)
{
    int i,j;
    for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
}

void add(int a[10][10],int b[10][10],int r1,int c1)
{
    int i,j;
    int d[10][10]
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            d[][]=a[i][j]+b[i][j];
        }
    }
        printf("Addition is:\n");
        display(d,r1,c1);
}

void display(int a[10][10],int r1,int c1)
{
    int i,j;
    for(i=0;i<r1;i++)
    {
    for(j=0;j<c1;j++)
    {
        printf("%d\n",a[i][j]);
    }
        printf("\n");
    }
}