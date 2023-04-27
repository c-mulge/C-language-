// loop structure
#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    // int i=0;
    // while(i <=n)    // while loop until n
    // {
    //     printf("%d\n", i);
    //     i++;
    // }

    // for(int i=1; i<=n; i++)     // for loop until n
    // { printf("%d\n",i);}

//     int i=n;
// do{
//     printf("%d\n",i);     //do while loop until n
//     i--;

// } while(i>=n-(n-1));

for(int j=n; j>=1;j--)
{
    sum=sum+j;
    printf("%d\n",j);
    }
    printf("Sum is %d\n",sum);

    // for (int i = n; i>=n-(n-1); i--)
    // {
    //     printf("%d\n",i);
    // }
    

return 0;
}