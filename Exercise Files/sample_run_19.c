//to check whether the number is odd or even
#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter any number: ");
    scanf("%d", &n);

    if (n%2==0)
    {
        printf("The number is even\n");
        
    }
    else
        printf("The number is odd");

    return 0;
}