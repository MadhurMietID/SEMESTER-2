#include <stdio.h>

#include <stdlib.h>

#define SIZE 4

int top = -1, inp_array[SIZE];
void push();
void pop();
void show();

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", inp_array[top]);
        top = top - 1;
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}
/*
This code is an implementation of a basic integer stack using arrays in C. It includes the following functions:

push(): adds an element to the top of the stack
pop(): removes the top element from the stack
show(): displays the current state of the stack
The stack has a fixed size of 4, defined by #define SIZE 4. The variable top keeps track of the index of the top element in the stack.

In the main() function, the user is presented with a menu to choose from the following options:

Push an element onto the stack
Pop an element from the stack
Display the current state of the stack
End the program
The user's choice is read using the scanf() function and then the corresponding function is called based on the user's choice in a switch-case statement. If the user enters an invalid choice, the message "Invalid choice!!" is printed. The program ends when the user chooses to end it by entering 4.*/