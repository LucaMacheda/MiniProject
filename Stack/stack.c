#include "stack.h"

void initStack(Stack* s,int size, int element_size)
{
    s->stack = malloc(size * element_size);
    s->element_size = element_size;
    s->size = size;
    s->top = -1;
}

int isEmptyStack(Stack* s)
{
    return s->top == -1;
}

void resizeStack(Stack* s)
{
    int new_size = s->size * 2;

    void* new_stack = realloc(s->stack, new_size * s->element_size);
    if(!new_stack)
    {
        printf("Realloc failed\n");
        exit(1);
    }

    s->stack = new_stack;
    s->size = new_size;
}

void push(Stack* s, void* data)
{
    if(s->top == s->size - 1)
    {
        resizeStack(s);
    }

    s->top++;
    void* target = (char*)s->stack + (s->top * s->element_size);
    memcpy(target,data,s->element_size);
}

void pop(Stack* s, void* out_value)
{
    if(isEmptyStack(s))
    {
        printf("Empty\n");
        return;
    }

    void* target = (char*)s->stack + (s->top * s->element_size);
    memcpy(out_value,target,s->element_size);
    s->top--;
}

void destroyStack(Stack* s)
{
    free(s->stack);
}
