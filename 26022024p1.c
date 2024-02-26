#include<stdio.h>
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
       case 1: // case for creating list
           break;
       case 2: // case for inserting element
       break;
       case 3: // case for displaying list
       break;
       case 4: // case for deleting element
       break;
       case 5: // case for searching number
       break;
       case 6: // case for exiting
       break;
       default:printf("Invalid Choice!!!"); // default case for invalid choice
   } // end of switch statement
 }
} // end of main function