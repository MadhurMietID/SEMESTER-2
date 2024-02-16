#include<stdio.h>
int main()
{
    int x;
    printf("Enter Number:");
    scanf("%d",&x);
    printf("%d\n",x);
    int a;
    printf("Enter Number:");
    scanf("%d",&a);
    printf("%d\n",a);
    int b;
    printf("Enter Number:");
    scanf("%d",&b);
    printf("%d\n",b);
    int c;
    printf("Enter Number:");
    scanf("%d",&c);
    printf("%d\n",c);
}
/*PS D:\84> cd "d:\84\" ; if ($?) { gcc 16022024pt10.c -o 16022024pt10 } ; if ($?) { .\16022024pt10 }
Enter Number:23 43 43 88
23
Enter Number:43
Enter Number:43
Enter Number:88*/
/*Here we gave extra output and it went to buffer and other scanf took value from the buffer*/