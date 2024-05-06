/*
Title: Doubly Linked List Operations

Description:
This program demonstrates various operations on a doubly linked list such as creation, insertion, deletion, and display.

Author: [Your Name]

Date: [Date]

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node* prv;
    int data;
    struct Node* next;
};

struct Node* head = NULL, *tail = NULL;

// Function to create a new node
struct Node* createNode() {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &t->data);
    t->prv = NULL;
    t->next = NULL;
    return t;
}

// Function to create a doubly linked list
void createDoublyLinkedList() {
    int n, i;
    printf("Enter No of Nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {  // Corrected the loop condition
        struct Node* newNode = createNode();
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prv = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// Function to display the list from the beginning
void displayListFromBeg() {
    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

// Function to insert a node at the beginning
void insertNodeAtBeg() {
    struct Node* newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prv = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end
void insertNodeAtEnd() {
    struct Node* newNode = createNode();
    if (tail == NULL) {
        head = tail = newNode;
    }
    else {
        newNode->prv = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node at any position
void insertNodeAtAnyLoc() {
    if (head == NULL) {
        printf("List Is empty!!!!!\n");
    }
    else {
        int pos;
        printf("Enter position:");
        scanf("%d", &pos);
        if (pos == 1) {
            struct Node* newNode = createNode();
            newNode->next = head;
            head->prv = newNode;
            head = newNode;
        }
        else {
            int cnt = 1;
            struct Node* temp = head;
            while (temp != NULL && cnt < pos) {  // Corrected the condition
                cnt++;
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Invalid position!!!!!\n");
            }
            else {
                struct Node* newNode = createNode();
                newNode->next = temp;
                newNode->prv = temp->prv;
                if (temp->prv != NULL)
                    temp->prv->next = newNode;
                temp->prv = newNode;
            }
        }
    }
}

// Function to delete a node from any position
void deleteNodeFromAnyPos() {
    if (head == NULL) {
        printf("List is empty!!!!!");
    }
    else {
        int pos;
        printf("Enter Position");
        scanf("%d", &pos);
        if (pos == 1) {
            head = head->next;
            if (head != NULL)
                head->prv = NULL;
        }
        else {
            int cnt = 1;
            struct Node* temp = head;
            while (temp != NULL && cnt < pos) {
                cnt++;
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Invalid Position!!!!!!\n");
            }
            else {
                temp->prv->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prv = temp->prv;
                }
            }
        }
    }
}

int main() {
    createDoublyLinkedList();
    while (1) {
        int choice;
        printf("1.Insert Node in beginning\n");
        printf("2.Insert Node at end\n");
        printf("3.Insert Node at any position\n");
        printf("4.Delete Node from any position\n");
        printf("5.\n");
        printf("6.Display\n");
        printf("7.\n");
        printf("8.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insertNodeAtBeg();
            break;
        case 2:
            insertNodeAtEnd();
            break;
        case 3:
            insertNodeAtAnyLoc();
            break;
        case 4:
            deleteNodeFromAnyPos();
            break;
        case 5:
            //searchNode();
            break;
        case 6:
            displayListFromBeg();
            break;
        case 7:

            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!!!!!!\n");
        }
        printf("\n");
        system("pause");
        system("cls");
    }
}
