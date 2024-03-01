/*Wap to read and  display the elemnts of an array using pointer*/
#include <stdio.h>

int main() {
    int arr[5]; // Array of size 5
    int *ptr = arr; // Pointer to the array

    // Read elements into the array using pointer
    printf("Enter 5 elements of the array: \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    // Display elements of the array using pointer
    printf("Elements of the array: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
/*Output
Enter 5 elements of the array: 
45
54
64
56
56
Elements of the array: 
45 54 64 56 56*/
/*This code is written in C programming language and it demonstrates how to use a pointer to read and display elements of an array. Here's an explanation of the code:

#include <stdio.h>: This line includes the standard input/output library in the program.
int main() { ... }: This is the main function where the program starts executing.
int arr[5];: This line declares an array arr of size 5, which can store 5 integers.
int *ptr = arr;: This line declares a pointer ptr to integers and initializes it with the address of the first element of the array arr.
printf("Enter 5 elements of the array: \n");: This line prompts the user to enter 5 elements of the array.
for (int i = 0; i < 5; i++) { ... }: This is a loop that iterates 5 times.
scanf("%d", ptr + i);: This line reads an integer value from the user and stores it in the i-th element of the array arr using pointer arithmetic.
printf("Elements of the array: \n");: This line prints a message indicating that the elements of the array will be displayed.
for (int i = 0; i < 5; i++) { ... }: This is another loop that iterates 5 times.
printf("%d ", *(ptr + i));: This line prints the i-th element of the array arr using pointer arithmetic.
Overall, this code uses a pointer to read and display elements of an array. It shows how pointer arithmetic can be used to manipulate arrays and access their elements*/