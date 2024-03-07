//a c program for student info
#include <stdio.h>
#include <string.h>

// Define a struct for student information
struct Student {
   int rollNumber;
   char name[15];
   char branch[12];
   float marks;
};

int main() {
   // Create a variable of type Student
   struct Student s1;

   // Prompt and read roll number
   printf("Enter the roll number: ");
   scanf("%d", &s1.rollNumber);

   // Prompt and read name (with a limit of 14 characters, leaving room for null terminator)
   printf("Enter the name: ");
   scanf("%14s", s1.name);

   // Prompt and read branch (with a limit of 11 characters, leaving room for null terminator)
   printf("Enter the branch: ");
   scanf("%11s", s1.branch);

   // Prompt and read marks
   printf("Enter marks: ");
   scanf("%f", &s1.marks);

   // Print out the student information
   printf("RollNumber = %d\n", s1.rollNumber);
   printf("Name = %s\n", s1.name);
   printf("Branch = %s\n", s1.branch);
   printf("Marks = %.2f\n", s1.marks);

   return 0;
}