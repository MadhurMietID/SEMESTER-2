/*Write a program to create a singly linked list with N nodes and print all the elements of list in reverse order using recursion.

Input Format

Input the value of N
Input N values in the list
Constraints

1 <= N <= 1000

Output Format

Display all list element in reverse order with space sepearted.

Sample Input 0

5
12 89 45 77 33
Sample Output 0

33 77 45 89 12*/


#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(struct Node** head, int data) {
    if (*head == NULL) {
        *head = newNode(data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode(data);
}

// Function to print elements of the list in reverse order using recursion
void printReverse(struct Node* head) {
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    int N, value;
    scanf("%d", &N);
    struct Node* head = NULL;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insertNode(&head, value);
    }
    
    printReverse(head);
    
    return 0;
}
