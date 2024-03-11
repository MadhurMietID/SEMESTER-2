#include<stdio.h>
struct student{
    int rollnumber;
    char name[15];
    char branch[12];
    float marks;
};
int main()
{
    struct student s1, *ptr;
    ptr = &s1;
    printf("Enter Roll Number: ");
    scanf("%d",&ptr->rollnumber);
    printf("Enter Name: ");
    fflush(stdin);
    gets(ptr->name);
    printf("\nEnter Branch: ");
    gets(ptr->branch);
    printf("Enter Marks: ");
    scanf("%f",&ptr->marks);
    printf("\nRoll number is %s\n",ptr->rollnumber);
    printf("Name is %s\n",ptr->name);
    printf("Branch is %s\n",ptr->branch);
    printf("Marks: %f, ptr ->marks");
    return 0;
}