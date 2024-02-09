/*The ptogram works, even when we replace <> with ""  in # include*/
#include"stdio.h"
int main()
{
    printf("Hello,Students");
    return 0;
}
/*output-
PS D:\madhur> cd "d:\madhur\" ; if ($?) { gcc 09022024pt1.c -o 09022024pt1 } ; if ($?) { .\09022024pt1 }
Hello,Students
PS D:\madhur>
*/