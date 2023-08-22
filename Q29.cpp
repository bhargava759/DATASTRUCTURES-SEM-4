#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value indicating an error
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    int num_elements;

    printf("Enter the number of elements for the first stack: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements for the first stack:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int element;
        scanf("%d", &element);
        push(&stack1, element);
    }

    printf("Enter the number of elements for the second stack: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements for the second stack:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int element;
        scanf("%d", &element);
        push(&stack2, element);
    }

    int bottom1 = pop(&stack1);
    int top1 = stack1.data[stack1.top];

    int bottom2 = pop(&stack2);
    int top2 = stack2.data[stack2.top];

    printf("Bottom of stack 1: %d\n", bottom1);
    printf("Top of stack 1: %d\n", top1);

    printf("Bottom of stack 2: %d\n", bottom2);
    printf("Top of stack 2: %d\n", top2);

    return 0;
}

