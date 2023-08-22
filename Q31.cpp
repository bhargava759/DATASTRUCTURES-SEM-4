#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isStackFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

void initializeQueue(struct Queue *q) {
    initializeStack(&(q->stack1));
    initializeStack(&(q->stack2));
}

int isQueueEmpty(struct Queue *q) {
    return isStackEmpty(&(q->stack1)) && isStackEmpty(&(q->stack2));
}

void enqueue(struct Queue *q, int value) {
    if (isStackFull(&(q->stack1))) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    // Push the element onto stack1
    push(&(q->stack1), value);
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }

    if (isStackEmpty(&(q->stack2))) {
        while (!isStackEmpty(&(q->stack1))) {
            push(&(q->stack2), pop(&(q->stack1)));
        }
    }

    return pop(&(q->stack2));
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int num_elements;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements to enqueue:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int element;
        scanf("%d", &element);
        enqueue(&queue, element);
    }

    printf("Dequeueing elements from the queue:\n");
    while (!isQueueEmpty(&queue)) {
        int dequeuedValue = dequeue(&queue);
        printf("Dequeued value: %d\n", dequeuedValue);
    }

    return 0;
}

