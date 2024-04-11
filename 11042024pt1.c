#include<stdio.h> // Include the standard input/output library
#include<stdlib.h> // Include the standard library

#define max 10 // Define the maximum size of the queue

int queue[max], front = -1, rear = -1; // Initialize the queue array and front and rear indices

int isfull() { // Function to check if the queue is full
    return (rear + 1) % max == front;
}

int isempty() { // Function to check if the queue is empty
    return front == -1;
}

void enqueue(int value) { // Function to add an element to the queue
    if (isfull())
        printf("QUEUE OVERFLOW\n");
    else if (front == -1)
        front = rear = 0;
    else if (rear == max - 1 && front > 0)
        rear = 0;
    else
        rear++;
    queue[rear] = value;
    printf("Element added in queue \n");
}

void dequeue() { // Function to remove an element from the queue
    if (isempty())
        printf("Queue Underflow\n");
    else {
        int val = queue[front];
        if (front == rear)
            front = rear = -1;
        else if (front == max - 1)
            front = 0;
        else
            front++;
        printf("%d is dequeue from queue\n", val);
    }
}

void display() { // Function to display the elements in the circular queue
    if (isempty())
        printf("\n Queue Empty \n");
    else {
        printf("\n The elements of the circular queue are : ");
        int i;
        for (i = front; i!= rear; i = (i + 1) % max)
            printf("%d ", queue[i]);
        if (front!= -1) // Check if the queue is not empty
            printf("%d", queue[rear]); // Display the last element
    }
}
int main(){
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        int ch, value;
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter value:");
            scanf("%d", &value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
        system("pause");
    }
}
/*First, let's start with the basic concepts of C programming:

Variables: Variables are used to store data in a program. In C, variables must be declared before they can be used, and they have a specific data type, such as int for integers or float for floating-point numbers.
Functions: Functions are reusable blocks of code that perform a specific task. In C, functions can take parameters and return a value. The main function is the entry point of a C program.
Control structures: Control structures are used to control the flow of execution in a program. In C, control structures include if statements, for loops, and switch statements.
Arrays: Arrays are used to store a collection of data of the same type. In C, arrays are declared with a specific size, and elements can be accessed using an index.
Pointers: Pointers are used to store the memory address of a variable. In C, pointers can be used to manipulate memory directly.
Now, let's explain the code in detail:

The code defines a circular queue using an array of integers with a maximum size of max. The front and rear variables keep track of the beginning and end of the queue, respectively.

The isfull function checks if the queue is full by comparing the rear index with the front index. If the rear index is one less than the front index (modulo max), then the queue is full.

The isempty function checks if the queue is empty by checking if the front index is equal to -1. If the front index is -1, then the queue is empty.

The enqueue function adds an element to the end of the queue. If the queue is full, it prints an error message. Otherwise, it increments the rear index and adds the new element to the queue. If the rear index reaches the end of the array, it wraps around to the beginning of the array.

The dequeue function removes an element from the beginning of the queue. If the queue is empty, it prints an error message. Otherwise, it increments the front index and removes the first element from the queue. If the front index reaches the end of the array, it wraps around to the beginning of the array.

The display function prints out all the elements in the queue. It iterates through the array from the front index to the rear index (modulo max), printing out each element. If the queue is not empty, it also prints out the last element.

The main function presents a simple menu-driven interface that allows the user to perform enqueue, dequeue, display, and exit operations. The user can choose an operation by entering its corresponding number, and the program will execute the chosen operation accordingly. The system("pause") function is used to pause the console window, so that the user can see the output before it disappears.

Here's an algorithm for the enqueue function:

Check if the queue is full. If it is, print an error message and return.
If the front index is -1, set both the front and rear indices to 0.
Otherwise, if the rear index is at the end of the array, set it to 0.
Increment the rear index.
Add the new element to the queue at the rear index.
Print a success message.
And here's an algorithm for the dequeue function:

Check if the queue is empty. If it is, print an error message and return.

Remove the first element from the queue by incrementing the front index.

If the front index is at the end of the array, set it to 0.

Print the removed element.

If the front index is equal to the rear index, set both indices to -1 to indicate that the queue is empty.

Print a success message.*/