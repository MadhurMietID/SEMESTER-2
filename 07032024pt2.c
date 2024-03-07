#include <stdio.h>
struct student{
    int rollnumber;
    char name[15];
    char branch[12];
    float marks;
};
int main()
{
    struct  student s1,s2;
    printf("Enter the roll number:");
    scanf("%d",&s1.rollnumber);
    printf("\nEnter the name of the student: ");
    fflush(stdin);
    gets(s1.name);
    printf("\nEnter the branch of the student: ");
    gets(s1.branch);
    printf("\nEnter the marks of the student: ");
    scanf("%f", &s1.marks);
    printf("roll number=%d\n" , s1.rollnumber);
    printf("Name= %s\n" , s1.name);
    printf("Branch = %s\n" , s1.branch);
    printf("Marks = %f\n" , s1.marks);
    printf("Enter the roll number of student 2 :");
    scanf("%d",&s2.rollnumber);
    printf("\nEnter the name of the student 2: ");
    fflush(stdin);
    gets(s2.name);
    printf("\nEnter the branch of the student 2: ");
    gets(s2.branch);
    printf("\nEnter the marks of the student 2: ");
    scanf("%f", &s2.marks);
    printf("roll number=%d\n" , s2.rollnumber);
    printf("Name= %s\n" , s2.name);
    printf("Branch = %s\n" , s2.branch);
    printf("Marks = %f\n" , s2.marks);
    return 0;
}