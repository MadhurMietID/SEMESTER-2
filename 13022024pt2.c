#include<stdio.h>
int main()
{
    int x=10,20,30;
    printf("X=%d",x);
    return 0;
}
/*Output is Error. Compiler considers 20 , 30 as variable initialization . 20,30 do not follow the variable naming rules*/
/*PS D:\84> cd "d:\84\" ; if ($?) { gcc 13022024pt2.c -o 13022024pt2 } ; if ($?) { .\13022024pt2 }
13022024pt2.c: In function 'main':
13022024pt2.c:4:14: error: expected identifier or '(' before numeric constant
     int x=10,20,30;
              ^~*/