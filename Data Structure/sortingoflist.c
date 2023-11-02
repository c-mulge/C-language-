#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

// void sort(struct node *h)
// {
    // struct node *q=h->next;
    // struct node *p=q->next;
    // struct node *r=h;
    // struct node *tail=NULL;

//     while(h->next!=tail)
//     {
//         while(1)
//         {
//             if(p->info<q->info)
//             {
//                 r->next=p;
//                 q->next=p->next;
//                 p->next=q;
//             }
//             r=p;
//             p=q->next;
//             q->next=q;
//             if(p==h||p==tail)
//             {
//                 tail=q;
//                 break;
//             }
//         }//while(1)
//         q=h->next;
//         p=q->next;
//         r=h;
//     }
// }

void sort(struct node *h) {
        struct node *q=h->next;
    struct node *p=q->next;
    struct node *r=h;
    struct node *tail=NULL;

    while (h->next != tail) {
        q = h->next;
        p = q->next;
        r = h;

        while (p != tail) {
            if (q->info > p->info) {
                r->next = p;
                q->next = p->next;
                p->next = q;
                q = p;
            }
            r = p;
            p = q->next;
        }

        tail = q;
    }
}


int main()
{
    int num,i,n;
    struct node *list=NULL;
    initlist(&list);
    printf("How many number: ");
    scanf("%d",&n);
    printf("Enter number %d: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        append(list,num);
    }
    printf("The link list: \n");
    display(list);

    printf("\nSorted list is: \n");
    sort(list);

    display(list);

    freenode(list);
    return 0;
}

