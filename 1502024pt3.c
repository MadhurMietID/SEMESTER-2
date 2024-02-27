/*WAP to find even or odd by calling the user defined function through if statements*/
#include<stdio.h>
void evenodd(int n)
{
    if(n%2==0)
    {
        printf("Even number");
    }
    else{
        printf("odd number");
    }
}
int main()
{
    int n;
    printf("Even the value of n");
    scanf("%d",&n);
    evenodd(n);
}
