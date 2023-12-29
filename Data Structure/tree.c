//Binary Tree

#include<stdio.h>
#include<stdlib.h>

struct root                 
{
    int info;
    struct root *left;
    struct root *right;
};

struct root *getnode(int value)
{
    struct root *root=(struct root *)malloc(sizeof(struct root));
    root->info = value;
    root->left=NULL;
    root->right=NULL;
    return root;
}

void display(struct root *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        display(root->left);
        display(root->right);
    }
}

int main()
{
    struct root *root=getnode(2);
    root->left=getnode(4);
    root->right=getnode(6);

    printf("Display: ");
    display(root);
    printf("\n");
    return 0;
}
