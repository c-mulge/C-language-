//Double Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // if (temp == NULL)
    // {
    //     printf("Memory allocation failed.\n");
    //     exit(1);
    // }
    temp->prev = NULL;
    temp->info = value;
    temp->next = NULL;
    return temp;
}

void freenode(struct node *p)
{
    free(p);
}

void initlist(struct node **head)
{
    (*head)=getnode(0);
    (*head)->next=*head;
    (*head)->prev=*head;
}

void append(struct node **head, int value)
{
    struct node *temp = getnode(value);

    if (*head == NULL)
    {
        // If the list is empty, the new node becomes the head
        temp->next = temp;
        temp->prev = temp;
        *head = temp;
    }
    else
    {
        struct node *p = (*head)->prev;

        // Update the pointers to insert the new node at the end
        p->next = temp;
        temp->prev = p;
        temp->next = *head;
        (*head)->prev = temp;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The doubly circular linked list is empty.\n");
        return;
    }
    struct node *p = head;
    printf("Doubly Circular Linked List: ");
    
    while (1)
    {
        printf("%d ", p->info);
        p = p->next;

        if (p == head)
            break;
    }

    printf("\n");
}


void insert(struct node **head, int value, int pos)
{
    struct node *temp = getnode(value);
    struct node *p = *head;
        int i = 0;

    if (*head == NULL)
    {
        if (pos == 0)
        {
            // If the list is empty and position is 0, the new node becomes the head
            temp->next = temp;
            temp->prev = temp;
            *head = temp;
        }
        else
        {
            printf("Invalid position.\n");
            freenode(temp);
        }
    }
    else
    { 
        if (pos == 0)
        {
            // Insert at the beginning
            temp->next = p;
            temp->prev = p->prev;
            p->prev->next = temp;
            p->prev = temp;
            *head = temp;
        }
        else
        {
            while (i < pos - 1 && p->next != *head)
            {
                p = p->next;
                i++;
            }

            if (i == pos - 1)
            {
                temp->next = p->next;
                temp->prev = p;
                p->next->prev = temp;
                p->next = temp;
            }
            else
            {
                printf("Invalid position.\n");
                freenode(temp);
            }
        }
    }
}

void delete(struct node **head, int pos)
{
    struct node *temp = *head;
    int i = 0;
    if (*head == NULL)
    {
        printf("The doubly circular linked list is empty.\n");
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
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        *head = temp->next;
        freenode(temp);
        return;
    }
    
    while (i < pos && temp->next != *head)
    {
        temp = temp->next;
        i++;
    }

    if (i == pos)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        freenode(temp);
    }
    else
    {
        printf("Position %d not found in the doubly circular linked list.\n", pos);
    }
}

int main()
{
    int num, i, n, position, value, pos;
    struct node *list = NULL;

    printf("How many numbers: ");
    scanf("%d", &n);

    i = 1;
    printf("Enter number %d: ", i);
    scanf("%d", &num);

    append(&list, num);
    while (i < n)
    {
        i++;
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        append(&list, num);
    }
    printf("The doubly circular linked list: \n");
    display(list);

    printf("\nEnter the position to insert: ");
    scanf("%d", &position);
    printf("\nEnter the value to insert: ");
    scanf("%d", &value);

    // Insert the value at the given position
    insert(&list, value, position);
    printf("\nUpdated Doubly Circular Linked List: \n");
    display(list);

    // To delete the node at the given position
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    delete(&list, pos);
    printf("\nUpdated Doubly Circular Linked List: ");
    display(list);

    // Free memory for the doubly circular linked list (not included in this code)

    return 0;
}
