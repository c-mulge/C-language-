// Mirror

#include <stdio.h>
#include <stdlib.h>
#define maxsz 100
struct node
{
    struct node *left;
    int info;
    struct node *right;
};

struct node *maketree(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->info = value;
    temp->right = NULL;
    return temp;
}

int isleft(struct node *root)
{
    return root->left != NULL;
}

int isright(struct node *root)
{
    return root->right != NULL;
}

void setleft(struct node *root, int value)
{
    if (isleft(root))
    {
        printf("Left subtree already exists.\n");
        exit(1);
    }
    root->left = maketree(value);
}

void setright(struct node *root, int value)
{
    if (isright(root))
    {
        printf("Right subtree already exists.\n");
        exit(1);
    }
    root->right = maketree(value);
}

struct node *bst(int a[], int n)
{
    struct node *tree = maketree(a[0]);
    struct node *p = NULL;
    int i;
    for (i = 1; i < n; i++)
    {
        p = tree;
        while (1)
        {
            if (p->info <= a[i])
            {
                if (isright(p))
                    p = p->right;
                else
                {
                    setright(p, a[i]);
                    break;
                }
            }
            else
            {
                if (isleft(p))
                    p = p->left;
                else
                {
                    setleft(p, a[i]);
                    break;
                }
            }
        }
    }
    return tree;
}

int ismirror(struct node *tree1, struct node *tree2)
{
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    if (tree1->info == tree2->info)
    {
        return ismirror(tree1->left, tree2->right);
        return ismirror(tree1->right, tree2->left);
    }
    return 0;
}

void mirror(struct node *root)
{
    struct node *temp;
    if (root == NULL)
        return;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

int main()
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int res, choice, n, i;
    int a[maxsz], b[maxsz];

    printf("Size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements for 1st tree: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    root1 = bst(a, n);

    printf("Enter %d elements for 2nd tree: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    root2 = bst(b, n);
    while (1)
    {
        printf("\nOperations are: ");
        printf("\n1. Is Mirror");
        printf("\n2. Create Mirror");
        printf("\n3. Inorder");
        printf("\n4. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            res = ismirror(root1, root2);
            if (res == 1)
            {
                printf("Tree's are Mirror");
            }
            else
                printf("Tree's are not Mirror");
            break;
        case 2:
            mirror(root2);
            break;
        case 3:
            printf("\nInorder of 1st: ");
            inorder(root1);
            printf("\nInorder of 2nd: ");
            inorder(root2);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}