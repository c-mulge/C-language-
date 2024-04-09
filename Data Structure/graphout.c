// take adjcency matrix as input and convert it into list
#include <stdio.h>
#include <stdlib.h>
#define maxsz 50

struct edge
{
    int ver;
    struct edge *next;
};
struct edge *getnode(int value)
{
    struct edge *temp = (struct edge *)malloc(sizeof(struct edge));
    temp->ver = value;
    temp->next = NULL;
    return temp;
}

void addedge(struct edge *G[], int v1, int v2, int n)
{
    struct edge *p = NULL;
    if (G[v1] == 0)
    {
        G[v1] = getnode(v2);
        return;
    }
    p = G[v1];
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = getnode(v2);
}

void display(struct edge *G[], int n)
{
    struct edge *p = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        p = G[i];
        printf("%d : ", i);
        while (p != 0)
        {
            printf("%d ", p->ver);
            p = p->next;
        }
        printf("\n");
    }
}

void out(struct edge *G[], int n)
{
    struct edge *temp;
    int i, sum;
    printf("Outdegree: \n");
    for (i = 0; i < n; i++)
    {
        temp = G[i];
        sum = 0;
        while (temp)
        {
            sum = sum + 1;
            temp = temp->next;
        }
        printf("%d: %d\n", i, sum);
    }
}

int main()
{
    int g[maxsz][maxsz];
    struct edge *G[10] = {0};
    int n, i, j;
    printf("How many ver: ");
    scanf("%d", &n);
    printf("Enter matrices: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 1)
                addedge(G, i, j, n);
        }
    }
    printf("Display: ");
    display(G, n);
    printf("\n");
    out(G, n);
    return 0;
}