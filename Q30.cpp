#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue *q) {
    return q->front == -1;
}

int isQueueFull(struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

void push(struct Queue *q1, struct Queue *q2, int value) {
    if (isQueueFull(q1)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    if (!isQueueEmpty(q1)) {
        enqueue(q1, value);
    } else {
        enqueue(q2, value);
    }
}

int pop(struct Queue *q1, struct Queue *q2) {
    if (isQueueEmpty(q1) && isQueueEmpty(q2)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Queue *nonEmptyQueue = q1;
    struct Queue *emptyQueue = q2;
    if (isQueueEmpty(q1)) {
        nonEmptyQueue = q2;
        emptyQueue = q1;
    }

    while (nonEmptyQueue->front != nonEmptyQueue->rear) {
        enqueue(emptyQueue, dequeue(nonEmptyQueue));
    }

    return dequeue(nonEmptyQueue);
}

int main() {
    struct Queue queue1, queue2;
    initializeQueue(&queue1);
    initializeQueue(&queue2);

    int num_elements;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements to push onto the stack:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int element;
        scanf("%d", &element);
        push(&queue1, &queue2, element);
    }

    printf("Popping elements from the stack:\n");
    while (!isQueueEmpty(&queue1) || !isQueueEmpty(&queue2)) {
        int poppedValue = pop(&queue1, &queue2);
        printf("Popped value: %d\n", poppedValue);
    }

    return 0;
}

