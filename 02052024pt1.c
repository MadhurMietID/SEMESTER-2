#include<stdio.h>
#include<stdlib.h>

// Define a structure for a singly linked list node
struct Node{
    int data;
    struct Node* next;
};

// Initialize the head of the linked list to NULL
struct Node* head = NULL;

// Function to create a new node for the linked list
struct Node* createNode(){
    // Allocate memory for the new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // Prompt user to enter data for the node
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    // Set the next pointer of the new node to NULL
    temp->next = NULL;
    // Return the newly created node
    return temp;
}

// Function to create a linked list with user-defined size and data
void createList(){
    // Variables to store the size of the list and loop counter
    int n, i;
    // Prompt user to enter the size of the list
    printf("Enter total size of list: ");
    scanf("%d", &n);
    // Pointer to keep track of the last node in the list
    struct Node* temp = NULL;
    // Loop to create nodes and append them to the list
    for(i = 1; i <= n; i++){
        // Create a new node
        struct Node* newNode = createNode();
        // If the list is empty, set the head to the new node
        if(head == NULL)
            head = temp = newNode;
        // Otherwise, append the new node to the end of the list
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Function to insert a node at any position in the linked list
void insertNodeAtAnyPos(){
    // Check if the list is empty
    if(head == NULL){
        printf("List is Empty!!!!!!\n");
    }
    else{
        // Variables to store the position of insertion and loop counter
        int pos;
        // Prompt user to enter the position of insertion
        printf("Enter Position: ");
        scanf("%d", &pos);
        // If position is 1, insert node at the beginning of the list
        if(pos == 1){
            // Create a new node
            struct Node* newNode = createNode();
            // Adjust pointers to insert the new node at the beginning
            newNode->next = head;
            head = newNode;
        }
        else{
            // Variables to track the current position and traverse the list
            int cnt = 1;
            struct Node* temp = head;
            // Traverse the list to find the position before the insertion point
            while(temp->next != NULL && cnt < pos - 1){
                cnt++;
                temp = temp->next;
            }
            // If position is beyond the size of the list, print error message
            if(cnt != pos - 1){
                printf("Invalid position!!!!!!!!\n");
            }
            else{
                // Create a new node
                struct Node* newNode = createNode();
                // Adjust pointers to insert the new node at the specified position
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

// Function to delete a node at any position in the linked list
void deleteNodeAtAnyPos(){
    // Variable to store the position of deletion
    int pos;
    // Prompt user to enter the position of deletion
    printf("Enter the position: ");
    scanf("%d", &pos);
    // If the list is empty, print error message
    if(head == NULL)
        printf("List is empty!\n");
    else{
        // If position is 1, delete the first node
        if(pos == 1){
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        else{
            // Variables to track the current position and traverse the list
            int cnt = 1;
            struct Node* temp = head;
            // Traverse the list to find the node before the deletion point
            while(temp->next != NULL && cnt < pos - 1){
                cnt++;
                temp = temp->next;
            }
            // If position is beyond the size of the list, print error message
            if(temp->next == NULL)
                printf("Invalid position!\n");
            else{
                // Adjust pointers to delete the node at the specified position
                struct Node* delNode = temp->next;
                temp->next = delNode->next;
                free(delNode);
            }
        }
    }
}

// Function to display the elements of the linked list
void display(){
    // If the list is empty, print error message
    if(head == NULL)
        printf("List is empty!\n");
    else{
        // Traverse the list and print each node's data
        struct Node* temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main(){
    int choice;
    // Infinite loop to display menu and perform operations
    while(1){
        // Display menu options
        printf("1. Create list\n");
        printf("2. Insert node at any position\n");
        printf("3. Delete node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        // Prompt user to enter choice
        printf("Enter the choice: ");
        scanf("%d", &choice);
        // Switch case to perform corresponding operation based on user choice
        switch(choice){
            case 1:
                createList();
                break;
            case 2:
                insertNodeAtAnyPos();
                break;
            case 3:
                deleteNodeAtAnyPos();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
