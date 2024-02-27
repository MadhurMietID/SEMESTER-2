/*Write a c program to read a uppercase letter from the user . convert that uppercase letter to lowercase letter by using bitwise operator*/
#include <stdio.h>
int main() {
    char uppercase_letter, lowercase_letter;

    printf("Enter an uppercase letter: ");
    scanf("%c", &uppercase_letter);
    getchar(); // To consume the newline character
    // Convert uppercase letter to lowercase using bitwise operation
    lowercase_letter = uppercase_letter | 0x20;
    printf("Uppercase letter: %c\n", uppercase_letter);
    printf("Lowercase letter: %c\n", lowercase_letter);
    return 0;
}
The following code reads an uppercase letter from the user, converts it to lowercase using a bitwise operator, and prints both the uppercase and lowercase letters.

Step-by-step explanation:
1. The code starts with including the standard input-output header file.
2. Then, the main function is defined and two character variables are declared for storing the uppercase and lowercase letters.
3. The user is prompted to enter an uppercase letter using printf function.
4. The entered letter is read using the scanf function and stored in the uppercase_letter variable.
5. The getchar function is used to consume the newline character left in the input buffer.
6. The uppercase letter is converted to lowercase using the bitwise OR operator and the hexadecimal value 0x20.
7. The lowercase letter is stored in the lowercase_letter variable.
8. Finally, both the uppercase and lowercase letters are printed using printf function. The uppercase letter is printed as it is, while the lowercase letter is printed after conversion.
9. The program ends with returning 0.
