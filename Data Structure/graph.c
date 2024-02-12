// Graph- arr implementation

#include <stdio.h>
#define maxsz 50
int main()
{
    int g[maxsz][maxsz];
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d number: \n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    int count;
    printf("Out degree: \n");
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
            // if(g[i][j]!=0)
            count += g[i][j];
        printf("%d: %d \n", i, count);
        printf("\n");
    }

    printf("In degree: \n");
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
            // if(g[j][i]!=0)
            count += g[j][i];
        printf("%d: %d \n", i, count);
        printf("\n");
    }
    return 0;
}
