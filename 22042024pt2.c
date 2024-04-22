#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;             // Store the value of the node
    struct Node *next;    // Pointer to the next node in the linked list
};

int main() {
    // Dynamically allocate memory for the first node
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Return non-zero to indicate failure
    }
    // Prompt the user to enter data for the first node
    printf("Enter Data for the first node: ");
    scanf("%d", &t->data);  // Read data from the user
    t->next = NULL;  // Set the next pointer to NULL since it's the only node for now

    // Dynamically allocate memory for the second node
    struct Node *t1 = (struct Node*)malloc(sizeof(struct Node));
    if (t1 == NULL) {
        printf("Memory allocation failed.\n");
        free(t);  // Free previously allocated memory before returning
        return 1;  // Return non-zero to indicate failure
    }
    // Prompt the user to enter data for the second node
    printf("Enter data for the second node: ");
    scanf("%d", &t1->data);  // Read data from the user
    t1->next = NULL;  // Set the next pointer to NULL for now

    // Link the first node to the second node
    t->next = t1;

    // Dynamically allocate memory for the third node
    struct Node *t2 = (struct Node*)malloc(sizeof(struct Node));
    if (t2 == NULL) {
        printf("Memory allocation failed.\n");
        free(t);  // Free previously allocated memory before returning
        free(t1); // Free previously allocated memory before returning
        return 1;  // Return non-zero to indicate failure
    }
    // Prompt the user to enter data for the third node
    printf("Enter data for the third node: ");
    scanf("%d", &t2->data);  // Read data from the user
    t2->next = NULL;  // Set the next pointer to NULL for now

    // Link the second node to the third node
    t1->next = t2;

    // Print the data of all three nodes
    printf("Data entered for the nodes: %d -> %d -> %d\n", t->data, t1->data, t2->data);

    // Free dynamically allocated memory before exiting
    free(t);
    free(t1);
    free(t2);

    return 0;  // Return 0 to indicate successful completion
}
