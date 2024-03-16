#include <stdio.h>
#include <stdlib.h>
#define maxsz 50

struct edge
{
    int ver;
    struct edge *link;
};

struct edge *getnode(int val)
{
    struct edge *temp = (struct edge *)malloc(sizeof(struct edge));
    temp->ver = val;
    temp->link = NULL;
    return temp;
}

struct edge *addedge(struct edge *G[], int num)
{
    int i = 0;
    if (G[num % 10] == 0)
    {
        return getnode(num);
    }
    struct edge *p = G[num % 10];
    struct edge *temp = getnode(num);
    while (p->link != NULL && p->link->ver < num)
    {
        p = p->link;
        i++;
    }
    if (i == 0 && p->ver > num)
    {
        temp->link = p->link;
        p->link = temp;
        return G[num % 10];
    }
}

void print(struct edge *G[])
{
    int i;
    struct edge *p;
    for (i = 0; i <= 9; i++)
    {
        printf("\nG[%d]: ", i);
        p = G[i];
        while (p != NULL)
        {
            printf("%d ", p->ver);
            p = p->link;
        }
    }
}

struct edge *search(struct edge *h, int value)
{
    struct edge *p = h;
    if (p == NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
        if (p->ver == value)
        {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

int main()
{
    int n, num;
    struct edge *arr[10] = {0};
    int choice;
    while (1)
    {
        printf("\n1. Insert hash");
        printf("\n2. Display hash");
        printf("\n3. Search element");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How many integer: ");
            scanf("%d", &n);
            printf("Enter values: ");
            int i;
            for (i = 0; i < n; i++)
            {
                scanf("%d", &num);
                arr[num % 10] = addedge(arr, num);
            }
            break;
        case 2:
            print(arr);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &num);
            struct edge *k = search(arr[num % 10], num);
            k ? printf("\nElement found %d", k->ver) : printf("Element not found;");
            break;
        case 4:
            exit(0);
            break;
        }
    }
}