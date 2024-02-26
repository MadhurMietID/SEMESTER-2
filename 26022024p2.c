#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
int list[1000],size;//max size//actual size //global variable
void create()
{
  int i;
  printf("Enter List Size: ");
  scanf("%d",&size);
  if (size>1000)
  {
      printf("List Overflow!!!");
  }
  else{
    printf("Enter Elements;\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&list[i]);
    }
  } 
}
void DisplayList()
{
  int i;
  if(size==0)
      printf("List is Empty!!!\n");
  else{
    printf("\nElements in the List are:\n");
    for(i=0;i<size;i++)
    {
      printf("%d\t",list[i]);
      }

  }    
   
}
int main() // start of main function
{
 while(1) // infinite loop
 {
   printf("1. Create List\n"); // option to create list
   printf("2. Insert element in list \n"); // option to insert element
   printf("3.Display list \n"); // option to display list
   printf("4. Delete an element from the list \n"); // option to delete element
   printf("5. Search for a number in the list \n"); // option to search number
   printf("6. Exit \n"); // option to exit
   int choice; // variable to store user choice
   printf("\n\n Enter your choice : "); // prompt for user choice
   scanf("%d",&choice); // read user choice
   switch(choice) // start of switch statement
   {
       case 1:
           create(); // case for creating list
       break;
       case 2: // case for inserting element
       break;
       case 3: // case for displaying list
       DisplayList();
       break;
       case 4: // case for deleting element
       break;
       case 5: // case for searching number
       break;
       case 6: // case for exiting
           exit(0);
       break;
       default:printf("Invalid Choice!!!"); // default case for invalid choice
   } // end of switch statement
 }
} // end of main function
/*This code is written in C and is a simple implementation of a dynamic array (called a list in this code) with basic operations
 like creating a list, inserting an element, displaying the list, deleting an element, and searching for an element.

The code starts with including the standard input/output library <stdio.h>. It then defines a macro maxsize with a value of 1000,
 which is the maximum size of the list. The list is implemented using a global integer array list of size maxsize and a global 
 variable size to keep track of the actual size of the list.

The function create() is defined to create a list. It prompts the user to enter the size of the list and reads the value using
 scanf(). If the size entered by the user is greater than maxsize, it prints an error message "List Overflow!!!". Otherwise,
  it prompts the user to enter the elements of the list and stores them in the list array.

The main() function starts with an infinite loop that displays a menu to the user with options to create a list, insert an 
element, display the list, delete an element, search for an element, and exit. The user's choice is read using scanf() and 
a switch statement is used to perform the corresponding operation.

The case statements for each option call the appropriate functions to perform the operation. For example, the case statement
 for creating a list calls the create() function. Similarly, the case statements for inserting an element, deleting an element, 
 and searching for an element call the corresponding functions (which are not implemented in the given code).
  The case statement for displaying the list uses a for loop to iterate over the list array and print each element.

Overall, this code provides a basic implementation of a dynamic array with some common operations. 
However, it is incomplete and does not handle some edge cases, such as checking if the list is empty before performing 
certain operations.*/