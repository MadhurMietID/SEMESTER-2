/*Wap to perform swapping of two number using pointer*/
int main()  /* entry point of the program */
{
   int a,b;    /* declare two integers */
   int *p1=&a,*p2=&b; /* pointers for a and b */
   printf("Enter Two numbers:");
   scanf("%d%d",p1,p2);  /* read two numbers */
   printf("Beforte swapping a=  %d and b = %d\n ",*p1,*p2);  /* print values before swap */
   int z =*p1;   /* store a in temp variable */
   *p1 = *p2;   /* swap a with b */
   *p2 = z;    /* swap b with temp variable */
   printf("\nAfter Swapping a= %d and b=%d",*p1,*p2);  /* print values after swap */
   return 0;   /* return from main function */
}/*output
enter Two numbers:1234
45
Beforte swapping a=  1234 and b = 45
 
After Swapping a= 45 and b=1234*/
/*This is a simple C program that swaps the values of two variables using pointers.

The program first declares two integer variables a and b and two pointers p1 and p2 which are initialized to the addresses of a and b respectively.

Next, it prompts the user to enter two numbers, which are then stored in the variables a and b using the pointers p1 and p2 in the scanf function.

Then, it prints the values of a and b before swapping, using the pointers to access the values of the variables.

The actual swapping of the values is done by storing the value of a (which is pointed to by p1) in a temporary variable z, then assigning the value of b (pointed to by p2) to a (pointed to by p1), and finally assigning the value of z to b (pointed to by p2).

Finally, it prints the values of a and b after swapping, again using the pointers to access the values of the variables.

It is important to note that the swapping is done using pointers, which allows the values of the original variables to be changed, rather than just the values stored in the pointers.*/