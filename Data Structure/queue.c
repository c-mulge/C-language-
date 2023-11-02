//Circular Array - Queue Implementation

#include<stdio.h>
#include<stdlib.h>
#define maxsz 10

struct queue
{
    int data[maxsz];
    int front,rear;
};

int isempty(struct queue *q)
{
    return q->rear==q->front;
}

int isfull(struct queue *q)
{
    return q->rear==q->front;
}

void initq(struct queue *q)
{
    q->rear=maxsz-1;
    q->front=maxsz-1;
}

void addq(struct queue *q,int value)
{
    if(q->rear==maxsz-1)
    {
        q->rear=0;
    }
    else{
        q->rear++;
    }
    if(isfull(q))
    {
        printf("Queue overflow!");
        exit(1);
    }
    q->data[q->rear]=value;
}

int deleq(struct queue *q)
{
    if(q->front==maxsz-1)
    {
        q->front=0;
    }
    else{
        q->front++;
    }
    if(isempty(q))
    {
        printf("Queue underflow!");
        exit(1);
    }
    return q->data[q->front];
}

int main() 
{
    struct queue q;
    initq(&q);
    int num,value;
    int n;
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    if (n <= 0 || n > maxsz) 
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the elements to add to the queue:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        addq(&q, num);
    }

    printf("Dequeuing elements from the queue:\n");
    while (!isempty(&q)) 
    {
        value = deleq(&q);
        printf("Dequeued: %d\n", value);
        printf("\n");
    printf("Last deleted value is: %d\n",value);
    }
    return 0;
}