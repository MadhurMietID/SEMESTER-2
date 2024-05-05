/*Implement priority queue using linked list and perform all stack operation like enquee,dequee,peek etc*/
#include <stdio.h>
#include <stdlib.h>

// Macro for defining maximum size of the priority queue
#define MAX_SIZE 5

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Priority Queue structure
struct PriorityQueue {
    struct Node *front;
};

// Function to create a new node
struct Node* newNode(int data, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

// Function to create an empty priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->front == NULL;
}

// Function to check if the priority queue is full
int isFull(struct PriorityQueue* pq) {
    // Since this implementation uses linked list, it doesn't have a fixed size.
    return 0;
}

// Function to enqueue an element into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = newNode(data, priority);
    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* current = pq->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("%d enqueued with priority %d\n", data, priority);
}

// Function to dequeue an element from the priority queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    struct Node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return data;
}

// Function to peek the front element of the priority queue
int peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    return pq->front->data;
}

// Function to display the elements of the priority queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty\n");
        return;
    }
    struct Node* current = pq->front;
    printf("Priority queue elements: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();
    int choice, data, priority;

    do {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(pq, data, priority);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(pq));
                break;
            case 3:
                printf("Front element: %d\n", peek(pq));
                break;
            case 4:
                display(pq);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
