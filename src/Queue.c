#include "../include/Queue.h"
#include <stdio.h>

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->data[++q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return q->data[q->front++];
}
