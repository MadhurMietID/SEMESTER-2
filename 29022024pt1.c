/*Wap sum of two numbers using pointer*/
#include<stdio.h>
int main()
{
    int a,b,c;
    int *p1=&a,*p2=&b;
    printf("Enter Two numbers:");
    scanf("%d%d",p1,p2);
    printf("Sum=  %d  ",*p1+*p2);
    return 0;
}
