#include<stdio.h>
/*Wap to read and  display the elemnts of an array using pointer*/
int main() /* entry point of the program */
{
   int i, arr[5]; /* declare an array of 5 integers */
   printf("Enter data : ");
   for (i = 0; i < 5; i++) /* loop to read 5 integers */
   {
       scanf("%d", arr+i); /* read an integer and store it in the array */
       //&arr[i] is complete adress . while arr is only address of first block of array
   }
   // Displaying elements using pointers
   printf("\nArray Elements are:\n");
   for (i = 0; i < 5; i++) /* loop to print 5 integers */
   {
       printf("%d\t", *(arr + i)); /* print an integer from the array */
   }
   return 0;
}
/*output
Enter data : 345
54
67
45
78

Array Elements are:
345     54      67      45      78*/
/*This code is written in C and is a simple program that reads five integers from the user, stores them in an array, and then prints out those integers.

The code begins with the function main(), which is the entry point of the program. Inside the main() function, an array arr of five integers is declared, and a loop is used to read five integers from the user and store them in the array.

The line scanf("%d", arr+i); reads an integer from the user and stores it in the ith position of the arr array. The arr+i expression is used to calculate the address of the ith element of the array. This is equivalent to writing &arr[i].

After reading the integers, the code uses a loop to print out each element of the array. The line printf("%d\t", *(arr + i)); prints out the value of the ith element of the arr array. The arr+i expression is used to calculate the address of the ith element of the array, and the * operator is used to dereference the pointer and get the value stored at that address.

Finally, the main() function returns 0 to indicate that the program has executed successfully.*/