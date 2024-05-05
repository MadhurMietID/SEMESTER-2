/*Implement queue data structure using linked list and perform all stack operation like enquee,dequee,peek etc.*/
#include <stdio.h>
#include <stdlib.h>

// Macro for defining maximum size of the queue
#define MAX_SIZE 5

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
    int size;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    struct Node* node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

// Function to peek the front element of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = NULL;
    int choice, data;

    do {
        printf("\nMain Menu\n");
        printf("1. Create Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(queue != NULL) {
                    printf("Queue already exists. Please choose another option.\n");
                } else {
                    queue = createQueue();
                    printf("Queue created successfully.\n");
                }
                break;
            case 2:
                if(queue == NULL) {
                    printf("Queue not created yet. Please create queue first.\n");
                } else {
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue(queue, data);
                }
                break;
            case 3:
                if(queue == NULL) {
                    printf("Queue not created yet. Please create queue first.\n");
                } else {
                    printf("Dequeued element: %d\n", dequeue(queue));
                }
                break;
            case 4:
                if(queue == NULL) {
                    printf("Queue not created yet. Please create queue first.\n");
                } else {
                    printf("Front element: %d\n", peek(queue));
                }
                break;
            case 5:
                if(queue == NULL) {
                    printf("Queue not created yet. Please create queue first.\n");
                } else {
                    display(queue);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}