/*Write a c program to create a simple calculator by calling user defined function through switch cases.*/
#include <stdio.h>
// Function declarations
float add(float num1,float num2);
float subtract(float num1,float num2);
float multiply(float num1,float num2);
float divide(float num1,float num2);
void calculate(char operator,float num1,float num2);
float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
int main() 
{
    char operator;
    float num1, num2;
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    calculate(operator, num1, num2);
    return 0;
}
void calculate(char operator, float num1, float num2) 
{
    float result;

    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operator\n");
            return;
    }

    printf("Result: %.2f\n", result);
}
