#include<stdio.h>
int main()
{
    int x=(10,20,30);
    printf("x=%d",x);
    return 0;
}
/*PS D:\84> cd "d:\84"
PS D:\84> cd "d:\84\" ; if ($?) { gcc 13022024pt3.c -o 13022024pt3 } ; if ($?) { .\13022024pt3 }
X=30
PS D:\84>*/
/*x is assigned 10 then 20 then 30 . In brackets last value is assigned*/