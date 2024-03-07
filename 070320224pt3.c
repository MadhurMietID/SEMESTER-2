#include <stdio.h>
#include <string.h>

struct student
{
    int rollnumber;
    char name[15];
    char branch[12];
    float marks;
};

int main()
{
    int size, i;
    struct student slist[100]; // declare the array
    printf("Enter the array size: ");
    scanf("%d", &size);
    if(size > 100) // check if size is within limit
    {
        printf("Size is too large. Maximum size is 100.\n");
        return 1;
    }
    for (i = 0; i < size; i++)
    {
        printf("Enter the rollnumber: ");
        scanf("%d", &slist[i].rollnumber);
        printf("Enter the name : ");
        fgets(slist[i].name, sizeof(slist[i].name), stdin); // use fgets instead of gets
        slist[i].name[strcspn(slist[i].name, "\n")] = 0; // remove newline character
        printf("\nEnter the branch: ");
        fgets(slist[i].branch, sizeof(slist[i].branch), stdin); // use fgets instead of gets
        slist[i].branch[strcspn(slist[i].branch, "\n")] = 0; // remove newline character
        printf("Enter the marks : ");
        scanf("%f", &slist[i].marks);
    }
    printf("Student Records are : \n");
    for (i = 0; i < size; i++)
    {
        printf("%15d %15s %15s %15.2f \n", slist[i].rollnumber, slist[i].name, slist[i].branch, slist[i].marks);
    }
    return 0;
}