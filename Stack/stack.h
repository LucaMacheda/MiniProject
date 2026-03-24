#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack{
    void* stack;
    int element_size;
    int size;
    int top;
}Stack;

void initStack(Stack* s, int size, int element_size);

int isEmptyStack(Stack* s);

void resizeStack(Stack* s);

void push(Stack* s, void* data);

void pop(Stack* s, void* out_value);

void destroyStack(Stack* s);