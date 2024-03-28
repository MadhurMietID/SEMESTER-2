#include <stdio.h>

#define MAX_SIZE 10

// Initialize queue as an array with a maximum size of MAX_SIZE
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int is_empty() {
    return front == rear;
}

// Function to check if the queue is full
int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to add an element to the queue
void enqueue(int value) {
    if (is_full()) {
        printf("Error: queue is full. Cannot add %d to the queue.\n", value);
        return;
    }

    if (front == -1 && rear == -1) {
        // Set front and rear to 0
        front = 0;
        rear = 0;
    } else {
        // Move rear to the next position
        rear = (rear + 1) % MAX_SIZE;
    }

    // Add the value to the queue
    queue[rear] = value;
}

// Function to remove and return the front element of the queue
int dequeue() {
    if (is_empty()) {
        printf("Error: queue is empty. Cannot remove an element.\n");
        return -1;
    }

    int value = queue[front];

    // Move front to the next position
    front = (front + 1) % MAX_SIZE;

    if (front == rear) {
        front = -1;
        rear = -1;
    }

    return value;
}

// Function to print the elements of the queue
void print_queue() {
    if (is_empty()) {
        printf("Queue: [EMPTY]\n");
        return;
    }

    int index = front;

    printf("Queue: [");

    while (index != rear) {
        printf("%d, ", queue[index]);
        index = (index + 1) % MAX_SIZE;
    }

    printf("%d]\n", queue[rear]);
}

// Example usage
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    print_queue();

    dequeue();

    print_queue();

    dequeue();

    print_queue();

    return 0;
}








