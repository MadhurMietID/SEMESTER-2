/*In c Implement stack data structure using linked list and perform all stack operation like push,pop,peek etc. */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // You can change this value to set the maximum stack size

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function prototypes
struct Stack* createStack();
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void display(struct Stack* stack);

int main() {
    int choice, data;
    struct Stack* stack = createStack();

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Create Stack  // Removed as stack is already created with macro\n");
        printf("2. Display Stack\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Peek\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Stack already created with maximum size %d\n", MAX_SIZE);
                break;

            case 2:
                if (isEmpty(stack)) {
                    printf("Stack is empty!\n");
                } else {
                    display(stack);
                }
                break;

            case 3:
                if (isFull(stack)) {
                    printf("Stack overflow!\n");
                } else {
                    printf("Enter the data to push: ");
                    scanf("%d", &data);
                    push(stack, data);
                    printf("Data pushed successfully\n");
                }
                break;

            case 4:
                if (isEmpty(stack)) {
                    printf("Stack underflow!\n");
                } else {
                    data = pop(stack);
                    printf("Popped data: %d\n", data);
                }
                break;

            case 5:
                if (isEmpty(stack)) {
                    printf("Stack is empty!\n");
                } else {
                    data = peek(stack);
                    printf("Top element: %d\n", data);
                }
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to create a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Check if the stack is full (using MAX_SIZE macro)
int isFull(struct Stack* stack) {
    return stack->top->next == NULL && MAX_SIZE > 0;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // Check for overflow if max_size is set
    if (isFull(stack)) {
        return;
    }

    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed element: %d\n", data);
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;  // Indicate error (optional)
    }

    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Peek at the top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;  // Indicate error (optional)
    }

    return stack->top->data;
}

// Display the stack contents
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = stack->top;
    printf("Stack elements (top to bottom):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

