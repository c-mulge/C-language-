//convert given year into its roman equivalent
#include<stdio.h>
int romanise(int,int,char);
int main()
{
    int num;
    printf("\nEnter year: ");
    scanf("%d", &num);
    num=romanise(num,1000,'m');
    num=romanise(num,500,'d');
    num=romanise(num,100,'c');
    num=romanise(num,50,'l');
    num=romanise(num,10,'x');
    num=romanise(num,5,'v');
    num=romanise(num,1,'i');
    return 0;
}

int romanise(int y,int k,char ch)
{
    int i,j;
    j=y/k;
    for(i=1;i<=j;i++)
        printf("%c",ch);
    return(y%k);
}