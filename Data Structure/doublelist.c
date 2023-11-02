//Double Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->info=value;
    temp->next=NULL;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void initlist(struct node **head)
{
    (*head)=getnode(0);
}

void append(struct node **head, int value)
{
    struct node *temp = getnode(value);
    struct node *p = *head;

    if (*head == NULL)
    {
        // If the list is empty, the new node becomes the head
        *head = temp;
    }
    else
    {        // Traverse the list to find the last node
        while (p->next != NULL)
        {
            p = p->next;
        }

        // Update the pointers to make the new node the last node
        p->next = temp;
        temp->prev = p;
    }
}

void display(struct node *head)
{
    while(head)
    {
        printf("%d ",head->info);
        head=head->next;
    }
}

void insert(struct node **head, int value, int pos)
{
    struct node *temp = getnode(value);
    struct node *p = *head;
    int i=0;

    if (pos < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL)
    {
        // If the list is empty and position is 0, the new node becomes the head
        if (pos == 0)
        {
            *head = temp;
        }
        else
        {
            printf("Invalid position.\n");
            freenode(temp); // Free the memory allocated for the new node
        }
    }
    else
    {
        if (pos == 0)
        {
            // Insert at the beginning
            temp->next = *head;
            (*head)->prev = temp;
            *head = temp;
        }
        else
        {
            // Traverse the list to find the node before the specified position
            while (i < pos - 1 && p->next != NULL)
            {
                p = p->next;
                i++;
            }

            // Insert the new node after the p node
            temp->next = p->next;
            temp->prev = p;
            
            if (p->next != NULL)
            {
                p->next->prev = temp;
            }
            
            p->next = temp;
        }
    }
}

void delete(struct node **head, int pos)
{
    struct node *p = *head;
    int i = 0;
    struct node *temp = *head;

    if (*head == NULL)
    {
        printf("The doubly linked list is empty.\n");
        return;
    }

    if (pos < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 0)
    {
        // Delete the first node
        *head = (*head)->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        freenode(temp);
        return;
    }

    // Traverse the list to find the node at the specified position
    while (i < pos && p != NULL)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("Position %d not found in the doubly linked list.\n", pos);
        return;
    }

    // Update the pointers to remove the node
    p->prev->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    freenode(p);
}

void reverse(struct node *head)
{
    if(!head)
    {
        return;
    }
    reverse(head->next);
    printf("%d ",head->info);
}

int main()
{
      int num,i,n,position,value,pos;
    struct node *list=NULL;

    printf("How many number: ");
    scanf("%d",&n);

    i=1;
    printf("Enter number %d: ",i);
    scanf("%d",&num);

    append(&list,num);
    while(i<n)
    {
        i++;
        printf("Enter number %d: ",i);
        scanf("%d",&num);
        append(&list,num);
    }
    printf("The link list: \n");
    display(list);

    
    printf("\nEnter the position to insert: ");
    scanf("%d", &position);
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);

    //insert the value at the given position
    insert(&list, value, position);
    printf("\nUpdated Linked List: \n");
    display(list);

    //to delete the node at the given position
    printf("\nEnter position to delete: ");
    scanf("%d",&pos);
    delete(&list,pos);
    printf("\nUpdated Linked List: ");
    display(list);
    printf("\nReverse list is: ");
    reverse(list);

    freenode(list);
    return 0;
}