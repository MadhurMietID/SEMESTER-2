// C program that takes input from the user to create an array, uses a macro to set the maximum size 
//as 100, sorts the array using the bubble sort algorithm in ascending order, and then prints the sorted result:
#include<stdio.h>
// Define maximum size of the array using a macro
#define MAX_SIZE 100
// Function to perform bubble sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    // Title
    printf("Bubble Sort Program in C\n\n");

    int arr[MAX_SIZE];
    int n;

    // Prompt user to enter the number of elements
    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Check if size exceeds maximum allowed size
    if (n > MAX_SIZE) {
        printf("Error: Size exceeds maximum allowed size.\n");
        return 1;
    }

    // Prompt user to enter elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array
    bubbleSort(arr, n);

    // Printing the sorted array
    printf("\nSorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
