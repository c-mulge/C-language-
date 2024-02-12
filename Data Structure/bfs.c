#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int n, i, j, visited[MAX_VERTICES], queue[MAX_VERTICES], front = -1, rear = -1;
int adj[MAX_VERTICES][MAX_VERTICES];

void bfs(int v)
{
    queue[++rear] = v;
    visited[v] = 1;

    while (front != rear)
    {
        v = queue[++front];
        // printf("%d ", v);
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter graph data in matrix form:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    bfs(v);

    printf("\nThe nodes which are reachable are:\n");
    for (i = 0; i < n; i++)
    {
        if (visited[i])
            printf("%d ", i);
    }
    if (rear < n - 1)
        printf("\nBFS is not possible. Not all nodes are reachable.\n");

    return 0;
}