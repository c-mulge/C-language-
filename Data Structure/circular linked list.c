
//Single Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *getnode(int value)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
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
    (*head)->next=*head;
}

void append(struct node **head, int value)
{
    struct node *p = getnode(value);
    if (*head == NULL)
    {
        *head = p;
        p->next = p; // Make it point to itself in a circular manner
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = *head; // Make it circular
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The circular linked list is empty.\n");
        return;
    }

    struct node *temp = head;
    while (1)
    {
        printf("%d ", temp->info);
        temp = temp->next;
        if (temp == head)
            break;
    }
    printf("\n");
}


void insert(struct node **head,int value,int pos) 
{
    struct node* p = *head;
    struct node* q = NULL;
    int count = 0;
    struct node *temp = getnode(value);
    if (pos < 0) 
    {
        printf("Invalid position.\n");
        return;
    } 

    if (pos == 0) 
    {
        struct node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        temp->next = *head;
        *head = temp;
        last->next = temp;

        printf("Inserted %d at position 0.\n", value);
        return;
    }

    //traverse the list to find the node before the given position
    while (p != NULL && count < pos) 
    {
        q = p;
        p = p->next;
        count++;
    }

    if (count == pos) 
    {
        //insert the new node at the given position
        q->next = temp;
        temp->next = p;
        printf("Inserted %d at position %d.\n", value, pos);
    } 
    else 
    {
        printf("Position %d not found in the linked list.\n", pos);
    }
}

void delete(struct node **head, int position) 
{
    struct node* p = *head;
    struct node* q = NULL;
    int count = 0;
    if (*head == NULL) 
    {
        printf("The linked list is empty.\n");
        return;
    }
    if (position == 0) 
    {

         struct node *temp = *head;
        struct node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head; // Update the circular linkage
        freenode(temp);
        return;

        printf("Deleted the node at position 0.\n");
        return;
    }

    //traverse the list to find the node at the specified position
    while (p != NULL && count < position) 
    {
        q = p;
        p = p->next;
        count++;
    }

    if (p != NULL) 
    {
        //update the previous node's next pointer
        q->next = p->next;
        free(p);
        printf("Deleted the node at position %d.\n", position);
    } 
    else 
    {
        printf("Position %d not found in the linked list.\n", position);
    }
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

    freenode(list);
    return 0;
}