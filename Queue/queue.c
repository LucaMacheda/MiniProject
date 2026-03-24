#include "queue.h"

void initQueue(Queue* q,int size, int element_size)
{
    q->data = malloc(size * element_size);
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->element_size = element_size;
}

int isEmptyQueue(Queue* q)
{
    return q->count == 0;
}

int isFullQueue(Queue* q)
{
    return q->count == q->size;
}

void resizeQueue(Queue* q)
{
    int new_size = q->size * 2;

    void* new_data = realloc(q->data, new_size * q->element_size);
    if (!new_data)
    {
        printf("Realloc failed\n");
        exit(1);
    }

    if (q->front > q->rear)
    {
        memmove((char*)new_data + (q->size * q->element_size),new_data,(q->rear + 1) * q->element_size);
        q->rear += q->size;
    }

    q->data = new_data;
    q->size = new_size;
}

void enqueue(Queue* q, void* value)
{
    if (isFullQueue(q))
    {
        resizeQueue(q);
    }

    q->rear = (q->rear + 1) % q->size;

    void* target = (char*)q->data + (q->rear * q->element_size);
    memcpy(target, value, q->element_size);

    q->count++;
}

void dequeue(Queue* q, void* out_value)
{
    if (isEmptyQueue(q))
    {
        printf("Queue empty\n");
        return;
    }

    void* source = (char*)q->data + (q->front * q->element_size);
    memcpy(out_value, source, q->element_size);

    q->front = (q->front + 1) % q->size;
    q->count--;
}

void destroyQueue(Queue* q)
{
    free(q->data);
}
