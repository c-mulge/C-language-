//Exercise 1 
//Set B
//Q.2
#include <stdio.h>

void dtob(int n) //decimal to binary function
{
    int bnum[32];
    int i = 0;
    while(n > 0)
    {
        bnum[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Binary number: ");
    for(int j = i - 1; j >= 0; j--)
    { 
        printf("%d", bnum[j]);
    }
    printf("\n");
}

void dtoo(int n) //decimal to octal function
{
    int onum[32];
    int i = 0;
    while(n > 0)
    {
        onum[i] = n % 8;
        n = n / 8;
        i++;
    }
    printf("Octal number: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", onum[j]);
    }
    printf("\n");
}

void dtoh(int n) //decimal to hexadecimal function
{
    char hnum[32];
    int i = 0;
    while(n > 0)
    {
        int remainder = n % 16;
        if(remainder < 10)
        {
            hnum[i] = remainder + 48;
        }else
        {
            hnum[i] = remainder + 55;
        }
        n = n / 16;
        i++;
    }
    printf("Hexadecimal number: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%c", hnum[j]);
    }
    printf("\n");
}

int main()
{
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    dtob(decimal_num);
    dtoo(decimal_num);
    dtoh(decimal_num);
    return 0;
}
