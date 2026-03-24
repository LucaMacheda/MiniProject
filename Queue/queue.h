#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    void* data;
    int size;
    int front;
    int rear;
    int count;
    int element_size;
} Queue;

void initQueue(Queue* q, int size, int element_size);

int isEmptyQueue(Queue* q);

int isFullQueue(Queue* q);

void resizeQueue(Queue* q);

void enqueue(Queue* q, void* value);

void dequeue(Queue* q, void* out_value);

//void display(Queue* q);

void destroyQueue(Queue* q);