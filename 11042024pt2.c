#include <stdio.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 
 
void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
      
        Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
/*This code is a simple implementation of a queue data structure using an array in C. A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, where the first element added to the queue will be the first one to be removed.

The code defines four functions:

enqueue(): This function adds an element to the end of the queue.
dequeue(): This function removes an element from the front of the queue.
show(): This function displays the elements currently in the queue.
main(): This function contains the main logic of the program, which displays a menu to the user to choose an operation to perform on the queue.
The main() function displays a menu to the user to choose an operation to perform on the queue. The user can choose to enqueue an element, dequeue an element, display the queue, or exit the program. The user's choice is stored in the ch variable, and the program uses a switch statement to execute the corresponding function.

The enqueue() function adds an element to the end of the queue. It first checks if the queue is full by comparing the Rear variable to the SIZE constant. If the queue is full, it displays an error message. Otherwise, it increments the Rear variable and adds the new element to the array.

The dequeue() function removes an element from the front of the queue. It first checks if the queue is empty by comparing the Front and Rear variables. If the queue is empty, it displays an error message. Otherwise, it increments the Front variable and removes the first element from the array.

The show() function displays the elements currently in the queue. It first checks if the queue is empty by comparing the Front and Rear variables. If the queue is empty, it displays an error message. Otherwise, it loops through the array from the Front variable to the Rear variable and prints each element.

Overall, this code provides a simple and effective implementation of a queue data structure in C.*/