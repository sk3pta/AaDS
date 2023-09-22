#include <stdlib.h>
#include <stdio.h>


static const unsigned INITSIZE = 20;
static const unsigned MULTIPLIER = 2;

typedef struct Stack{
    unsigned capacity;
    int *data;
    unsigned top;
} Stack;


void init(Stack *stack) {
    stack->capacity = INITSIZE;
    stack->top = 0;
    stack->data = malloc(sizeof(int) * INITSIZE);
}


void push(Stack *stack, int val) {
    if (stack->top + 1 > stack->capacity) {
        stack->capacity *= MULTIPLIER;
        stack->data = realloc(stack->data, sizeof(int) * stack->capacity);
        if (stack->data == NULL) {
            exit(-100);
        }
    }
    stack->data[stack->top] = val;
    stack->top++;
}


int pop(Stack *stack) {
    if (stack->top == -1)   exit(-100);
    stack->top--;
    return stack->data[stack->top];
}


void delete(Stack *stack) {
    free((stack)->data);
    stack = NULL;
}


void stackPrint(Stack *stack) {
    for (int i = stack->top -1; i >= 0; i--) {
        printf("%d ",stack->data[i]);
    }
    printf("\n");
}


int main() {
    Stack stack;
    init(&stack);
    push(&stack, -5);
    push(&stack, 192);
    push(&stack,121);
    stackPrint(&stack);
    printf("%d %d\n", stack.data[1], stack.top);
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    delete(&stack);

}