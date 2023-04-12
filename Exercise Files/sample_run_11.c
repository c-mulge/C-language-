#include<stdio.h>
int main()
{
    int num[100],i,n,c=0,a;
    printf("How many numbers: ");
    scanf("%d",&n);

    printf("Enter any number: ");
    for(i=0;i<=(n-1);i++)
    {
        scanf("%d",&num[i]);
    }
        printf("To count the occurence of which number: ");
        scanf("%d",&a);
        for(i=0;i<=n-1;i++)
        {
            if(num[i]==a)
                c++;
        }
        printf("%d occurs %d times\n",a,c);
    return 0;
}