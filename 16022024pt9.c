/*WAP to read one integer value,one character and one float value fom userand display them*/
#include<stdio.h>
int main()
{
    int a;
    float b;
    char c;
    scanf("%d%f%c",&a,&b,&c);
    printf("The entered integer is %d\n",a);
    printf("The entered float is %.2f\n",b);
    printf("The entered character is %c\n",c);
}
/*Character input isn't workinghere*/