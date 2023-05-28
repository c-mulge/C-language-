//check whether a year is leap or not
#include<stdio.h>
int main()
{
    int yr;
    printf("\n Enter year: ");
    scanf("%d", &yr);
    if(yr%100==0)
    {
        if(yr%400==0)
            printf("%d is a Leap year\n",yr);
        else
            printf("%d is not a leap year\n",yr);
    }
else
{
    if(yr%4==0)
        printf("%d is a Leap Year\n",yr);
    else
        printf("%d is not a leap year\n",yr);
}
// {                                           //here it is just sample trail for a year is a odd or even no.
//      if (yr%2==0) 
//     {
//         printf("\nThe number is even");
        
//     }
//     else
//         printf("\nThe number is odd");
// }

    return 0;
}