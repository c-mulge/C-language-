//Graph- arr implementation

#include<stdio.h>
#define maxsz 50
int main()
{
    int g[maxsz][maxsz];
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d number: \n",n);
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }

    printf("Number's are: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d \t",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}