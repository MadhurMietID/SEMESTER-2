/*Wap to perform swapping of two number using pointer*/
// This C program takes two numbers as input, swaps their values using a function, and then prints the swapped values.
#include <stdio.h> // for printf and scanf

int swap(int* a, int* b) // function to swap two numbers
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

int main()
{
   int num1, num2;
   printf("Enter two numbers: ");
// prompt user for input
   scanf("%d %d", &num1, &num2);
// read input from user
   printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
   swap(&num1, &num2); // swap the numbers
   printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
   return 0;
}
/*PS D:\84> cd "d:\84"
PS D:\84> cd "d:\84\" ; if ($?) { gcc 29022024pt2.c -o 29022024pt2 } ; if ($?) { .\29022024pt2 }
Enter two numbers: 432
56
Before swapping: num1 = 432, num2 = 56
After swapping: num1 = 56, num2 = 432 */
/*This code is a simple C program that swaps two numbers entered by the user. Here's an explanation of the code:

The first line #include <stdio.h> includes the standard input/output library in the program.

The function swap takes two integer pointers as arguments and swaps their values using a temporary variable temp.

In the main function, we declare two integer variables num1 and num2 and prompt the user to enter two numbers using the printf function and scanf function.

We then print the values of num1 and num2 before swapping using printf function.

We call the swap function with the addresses of num1 and num2 as arguments, so that the function can modify the original values of num1 and num2.

After the function call, we print the values of num1 and num2 again to show that they have been swapped.

Finally, the program returns 0 to indicate successful execution.

Overall, this code demonstrates how to swap two variables in C using pointers.*/