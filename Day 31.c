# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int minTop;
    int size;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->size = 10000;
    obj->stack = (int*)malloc(sizeof(int) * obj->size);
    obj->minStack = (int*)malloc(sizeof(int) * obj->size);
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;

    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop])
        obj->minStack[++obj->minTop] = val;
    else
        obj->minStack[++obj->minTop] = obj->minStack[obj->minTop];
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
        obj->minTop--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
