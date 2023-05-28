//take input of ages from user and decide who is youngest among 3 brothers or sister
//take name of brother or sister also from user and decide who is younger among 3

//please debug this code using chatGPT

#include<stdio.h>
int main()
{
    int a,b,c;
    char x;
    printf("Do you have brothers or sister?\n(type: B for Brother and S for Sister): ");
    scanf("%c", &x);
    
    if (x=='B')
    {
        printf("Enter the age of your brother: ");
        scanf("%d %d %d", &a, &b, &c);
        
            if (a<b)
            {
                printf("Your brother of age %d is younger\n",a);
            }
            else
                if (b<c)
                {
                    printf("Your brother of age %d is younger\n",b);
                }
                else
                printf("Your brother of age %d is younger\n",c);
                            
    }

    if (x=='S')
    {
        printf("Enter the age of your sister: ");
        scanf("%d %d %d", &a, &b, &c);
        
            if (a<b)
            {
                printf("Your sister of age %d is younger\n",a);
            }
            else
                if (b<c)
                {
                    printf("Your sister of age %d is younger\n",b);
                }
                else
                printf("Your sister of age %d is younger\n",c);
                            
    }
    return 0;
}