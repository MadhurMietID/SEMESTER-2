/*Wap sum of two numbers using pointer*/
int main() /* program starts here */
{
   int a,b,c; /* declare 3 integers */
   int *p1=&a,*p2=&b; /* pointers to a and b */
   printf("Enter Two numbers:"); /* prompt for 2 numbers */
   scanf("%d%d",p1,p2); /* read 2 numbers into a and b */
   printf("Sum=  %d  ",*p1+*p2); /* print sum of a and b */
   return 0; /* program ends here */
}
/*PS D:\84> cd "d:\84"
PS D:\84> cd "d:\84\" ; if ($?) { gcc 29022024pt1.c -o 29022024pt1 } ; if ($?) { .\29022024pt1 }
Enter Two numbers:345
45623
Sum=  45968 */
/*This is a simple C program that calculates the sum of two numbers entered by the user. The program uses pointers to store and manipulate the memory addresses of the variables.

Here is a breakdown of the code:

The first three lines include the standard input/output library and declare three integer variables a, b, and c, as well as three pointers p1, p2, and p3.
The next line initializes the pointers p1 and p2 with the memory addresses of a and b, respectively.
The program then prompts the user to enter two numbers using the printf() function and reads the input using the scanf() function. The %d%d format specifier in the scanf() function specifies that the function should read two integers, and the addresses of a and b (stored in p1 and p2) are passed as arguments to the function so that it can store the input values in the correct variables.
The program then calculates the sum of the two numbers by dereferencing the pointers p1 and p2 using the * operator and storing the result in the c variable.
Finally, the program prints the sum using the printf() function.
Overall, this program demonstrates how pointers can be used to manipulate memory addresses and variables in C.*/
