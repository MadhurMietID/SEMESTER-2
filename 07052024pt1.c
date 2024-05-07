//single list circular
#include<stdio.h>
#include<stdlib.h>

// Define structure for a Node
struct Node {
    int data;
    struct Node *next;
};

// Declare head and tail pointers for the linked list
struct Node *head = NULL, *tail;

// Function to create a new node
struct Node *createNode() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}

// Function to create a circular linked list
void createList() {
    int n, i;
    printf("Enter total size of list: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        struct Node *newNode = createNode();
        if (head == NULL)
            head = tail = newNode; // Set head and tail to the first node
        else
            tail->next = newNode; // Link the last node to the new node
        tail = newNode; // Update the tail to the new node
    }
    tail->next = head; // Make the list circular
}

// Function to insert a node at the beginning
void insertNodeAtBeg() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

// Function to insert a node at the end
void insertNodeAtEnd() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

// Function to insert a node at any position
void insertNodeAtAnyPos() {
    if (head == NULL) {
        printf("List is Empty!!!!!!\n");
    } else {
        int pos;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1) {
            insertNodeAtBeg();
        } else {
            int cnt = 1;
            struct Node *temp = head;
            do {
                if (cnt == pos - 1) {
                    break;
                } else {
                    cnt++;
                    temp = temp->next;
                }
            } while (temp != head);
            if (temp == head) {
                printf("Invalid position!!!!!!!!\n");
            } else {
                struct Node *newNode = createNode();
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

// Function to delete a node from any position
void deleteNodeAtAnyPos() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (head == NULL)
        printf("List is empty.\n");
    else {
        if (pos == 1) {
            head = head->next;
            tail->next = head;
        } else {
            int cnt = 1;
            struct Node *temp = head;
            do {
                if (cnt == pos - 1)
                    break;
                else {
                    cnt++;
                    temp = temp->next;
                }
            } while (temp->next != head);
            if (temp->next == NULL)
                printf("Invalid position!\n");
            else {
                temp->next = temp->next->next;
            }
        }
    }
}

// Function to display the linked list
void display() {
    if (head == NULL)
        printf("List is empty.\n");
    else {
        struct Node *temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// Function to search for a node
void searchNode() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        int val;
        printf("Enter the element to search: ");
        scanf("%d", &val);
        struct Node *temp = head;
        do {
            if (temp->data == val) {
                printf("Element found.\n");
                return;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Element not found.\n");
    }
}

int main() {
    createList(); // Create the circular linked list
    while (1) {
        int choice;
        printf("\n1. Insert Node at Beginning\n");
        printf("2. Insert Node at End\n");
        printf("3. Insert Node at Any Position\n");
        printf("4. Delete Node from Any Position\n");
        printf("5. Search Node\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertNodeAtBeg();
                break;
            case 2:
                insertNodeAtEnd();
                break;
            case 3:
                insertNodeAtAnyPos();
                break;
            case 4:
                deleteNodeAtAnyPos();
                break;
            case 5:
                searchNode();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
