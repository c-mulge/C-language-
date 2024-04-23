/*program that accepts the vertices and edges of a
graph and stores it as an adjacency matrix. Display adjacency matrix.*/

#include <stdio.h>
#define maxsz 100

int main()
{
    int vertices, edges;
    int G[maxsz][maxsz] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: v1 v2):\n");
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1; // if we removed this line, it will be an directed graph
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
