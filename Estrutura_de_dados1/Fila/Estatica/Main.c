#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));

    return 0;
}