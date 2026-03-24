#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Deque {
    void* data;
    int size;
    int front;
    int rear;
    int count;
    int element_size;
} Deque;

void initDeque(Deque* dq, int size, int element_size);

int isEmptyDeque(Deque* dq);

int isFullDeque(Deque* dq);

void resizeDeque(Deque* dq);

void insertFront(Deque* dq, void* value);

void insertRear(Deque* dq, void* value);

void deleteFront(Deque* dq, void* out_value);

void deleteRear(Deque* dq, void* out_value);

void destroyDeque(Deque* dq);