#include "deque.h"

void initDeque(Deque* dq,int size, int element_size)
{
    dq->data = malloc(size * element_size);
    dq->size = size;
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
    dq->element_size = element_size;
}

int isEmptyDeque(Deque* dq)
{
    return dq->count == 0;
}

int isFullDeque(Deque* dq)
{
    return dq->count == dq->size;
}

void resizeDeque(Deque* dq)
{
    int new_size = dq->size * 2;

    void* new_data = realloc(dq->data, new_size * dq->element_size);
    if (!new_data)
    {
        printf("Realloc failed\n");
        exit(1);
    }

    if (dq->front > dq->rear)
    {
        memmove((char*)new_data + (dq->size * dq->element_size),new_data,(dq->rear + 1) * dq->element_size);
        dq->rear += dq->size;
    }

    dq->data = new_data;
    dq->size = new_size;
}

void insertFront(Deque* dq, void* value)
{
    if (isFullDeque(dq))
    {
        resizeDeque(dq);
    }

    dq->front = (dq->front - 1 + dq->size) % dq->size;

    void* target = (char*)dq->data + (dq->front * dq->element_size);
    memcpy(target, value, dq->element_size);

    dq->count++;
}

void insertRear(Deque* dq, void* value)
{
    if (isFullDeque(dq))
    {
        resizeDeque(dq);
    }

    dq->rear = (dq->rear + 1) % dq->size;

    void* target = (char*)dq->data + (dq->rear * dq->element_size);
    memcpy(target, value, dq->element_size);

    dq->count++;
}

void deleteFront(Deque* dq, void* out_value)
{
    if (isEmptyDeque(dq))
    {
        printf("Deque empty\n");
        return;
    }

    void* source = (char*)dq->data + (dq->front * dq->element_size);
    memcpy(out_value, source, dq->element_size);

    dq->front = (dq->front + 1) % dq->size;
    dq->count--;
}

void deleteRear(Deque* dq, void* out_value)
{
    if (isEmptyDeque(dq))
    {
        printf("Deque empty\n");
        return;
    }

    void* source = (char*)dq->data + (dq->rear * dq->element_size);
    memcpy(out_value, source, dq->element_size);

    dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    dq->count--;
}

void destroyDeque(Deque* dq)
{
    free(dq->data);
}