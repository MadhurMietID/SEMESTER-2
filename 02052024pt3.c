#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Define a structure for the stack
struct Stack {
    struct Node* top;   // Pointer to the top of the stack
};

// Function to create a new node for the stack
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data of the node
    newNode->data = data;
    // Set the next pointer to NULL
    newNode->next = NULL;
    // Return the newly created node
    return newNode;
}

// Function to initialize the stack
struct Stack* createStack() {
    // Allocate memory for the stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    // Set the top of the stack to NULL (empty stack)
    stack->top = NULL;
    // Return the initialized stack
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    // If top is NULL, the stack is empty
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // Set the next pointer of the new node to the current top of the stack
    newNode->next = stack->top;
    // Update the top of the stack to point to the new node
    stack->top = newNode;
    // Print a message indicating successful push operation
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        // If the stack is empty, print an error message and return -1
        printf("Stack is empty\n");
        return -1;
    }
    // Store the data of the top node
    int data = stack->top->data;
    // Store a temporary pointer to the current top of the stack
    struct Node* temp = stack->top;
    // Update the top of the stack to point to the next node
    stack->top = stack->top->next;
    // Free the memory allocated for the previous top node
    free(temp);
    // Return the popped data
    return data;
}

// Function to get the top element of the stack without removing it
int peek(struct Stack* stack) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        // If the stack is empty, print an error message and return -1
        printf("Stack is empty\n");
        return -1;
    }
    // Return the data of the top node
    return stack->top->data;
}

// Main function
int main() {
    // Create a new stack
    struct Stack* stack = createStack();

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Print the top element of the stack
    printf("Top element: %d\n", peek(stack));

    // Pop elements from the stack
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    // Print the top element of the stack
    printf("Top element: %d\n", peek(stack));

    // Pop elements from the stack
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    // Print the top element of the stack
    printf("Top element: %d\n", peek(stack));

    return 0;
}
