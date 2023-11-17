// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     struct node *prev;
//     int info;
//     struct node *next;
// };

// struct node *getnode(int value)
// {
//     struct node *temp=NULL;
//     temp=(struct node *)malloc(sizeof(struct node));
//     temp->prev=NULL;
//     temp->info=value;
//     temp->next=NULL;
//     return temp;
// }

// void freenode(struct node *p)
// {
//     free(p);
// }

// void initlist(struct node **head)
// {
//     (*head)=getnode(0);
// }

// void append(struct node *head, int value)
// {
//     struct node *temp = getnode(value);
//     struct node *p = head;
//             // Traverse the list to find the last node
//         while(p->next != NULL)
            
//             {
//                 p = p->next;
            
//             }
//             p->next = temp;
//             temp->prev = p;
            
        
//         head -> info++;

//         // Update the pointers to make the new node the last node
        
    
// }

// void display(struct node *head)
// {
//     struct node *p=head->next;
//     while(p)
//     {
//         printf("%d ",p->info);
//         p=p->next;
//     }
// }

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
    struct node *temp=(struct node *)malloc(sizeof(struct node));
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
    (*head)->next=*head;
    (*head)->prev=*head;
    //(*head)->info=0;
}

void append(struct node *head, int value)
{
    struct node *temp = getnode(value);
    struct node *p = head->prev;


        // Update the pointers to make the new node the last node
        temp->next=head;
        temp->prev=p;
        p->next = temp;
        head->prev = temp;
        head -> info++;
    
}

void display(struct node *head)
{
    struct node *p=head->next;
    while(p!=head)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}