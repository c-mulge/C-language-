// Binary Tree

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

void rev(struct node *root)
{
    if (root == NULL)
        return;
    rev(root->right);
    printf("%d ", root->info);
    rev(root->left);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

int leafcount(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leafcount(root->left) + leafcount(root->right);
}

int non_leafcount(struct node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    else
        return 1 + non_leafcount(root->left) + non_leafcount(root->right);
}

struct node *search(struct node *tree, int key)
{
    struct node *root = tree;
    while (root != NULL)
    {
        if (root->info == key)
            return root;
        else if (root->info > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int total(struct node *root)
{
    if (root == NULL)
        return 0;
    return 1 + total(root->left) + total(root->right);
}

int main()
{
    struct node *root = NULL;
    int choice, n, i, key;
    struct node *res = NULL;
    int a[maxsz];
    while (1)
    {
        printf("\n");
        printf("\nOperations are: ");
        printf("\n1. Create Binary Tree");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Reverse Traversal");
        printf("\n6. Binary Tree Search");
        printf("\n7. Leaf Count");
        printf("\n8. Non leaf count");
        printf("\n9. Total nodes present");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Size of array: ");
            scanf("%d", &n);
            printf("Enter elements: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            root = bst(a, n);
            break;
        case 2:
            printf("Preorder: ");
            preorder(root);
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            break;
        case 5:
            printf("Reverse: ");
            rev(root);
            break;
        case 6:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            res = search(root, key);
            if (res != NULL)
                printf("Elememt %d is present\n", key);
            else
                printf("Elememt is not present\n");
            break;
        case 7:
            printf("Leaf Count: %d", leafcount(root));
            break;
        case 8:
            printf("Non Leaf Count: %d", non_leafcount(root));
            break;
        case 9:
            printf("Total Node Present in the Tree: %d", total(root));
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    }
    return 0;
}
