#include<stdio.h>
#define SIZE 10
int stack[SIZE],top=-1;
int isEmpty(){
    return(top ==-1)? 1:0;
}
int isFull()
{
    return (top==SIZE -1) ? 1:0;
}
int push()
{
   if(isFull)
      return 0;
    else{
        top++;
        int val;
        printf("Enter Value :");
        scanf("%d",&val);
        stack[top]=val;
        return 1;
    }  
}
int main(){

}