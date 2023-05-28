//calculate profit or loss
#include<stdio.h>
int main()
{
    // char a;
    //     printf("Enter value of a: ");
    //     scanf("%c", &a);

    // printf("%c",a);
    float cp,sp,p,l;
    printf("\nEnter cost price and selling price: ");
    scanf("%f %f", &cp, &sp);
        p=sp-cp;
        l=cp-sp;
    if (p>0)
    {
        printf("The seller made a profit of Rs. %f\n",p);
        }

    if (l>0)
    {
        printf("The seller made a loss of Rs. %f\n",l);
        
    }

    if (p==0)
    {
        printf("There is no loss, no profit\n");
    }
     return 0;
}