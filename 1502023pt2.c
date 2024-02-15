/*WAP to declare the size n and read n element from the user and store it in an array.And print the sum of all the elements in array*/
#include<stdio.h>
int main()
{
    int n,a[n];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the number of elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[n]);
    }
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum = sum + a[n];
    }
    printf("The sum of numbers is %d",sum);
}