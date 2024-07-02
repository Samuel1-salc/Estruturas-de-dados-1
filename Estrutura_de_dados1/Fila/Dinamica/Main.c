#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para enfileirar um elemento
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Função para exibir os elementos da fila
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return;
    }

    Node* temp = queue->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    displayQueue(queue);

    printf("Elemento desenfileirado: %d\n", dequeue(queue));
    printf("Elemento desenfileirado: %d\n", dequeue(queue));

    displayQueue(queue);

    return 0;
}