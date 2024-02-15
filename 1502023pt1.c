/*write a c program to find maximum of three numbers using nested if*/
#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        if(c>a)
        {
            printf("%d is the greatest number",c);
        }
        else
        {
            printf("%d is the greatest number",a);
        }
    }
    else
    {
        if(c>b)
        {
            printf("%d is the greatest number",c);
        }
        else
        {
            printf("%d is the greatest number",b);
        }
    }
    return 0;
}