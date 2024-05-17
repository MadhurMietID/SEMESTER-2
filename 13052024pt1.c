// Title: Binary Search Tree Operations
// Description: This program implements various operations on a binary search tree (BST) including insertion, traversal, searching, and deletion.

#include<stdio.h>
#include<stdlib.h>

// Structure to represent a node in BST
struct Node {
    struct Node *left;
    struct Node *right;
    int data;
};

// Function to create a new node
struct Node *createNode() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter tree element: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode();
    else if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Function for pre-order traversal
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for in-order traversal
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for post-order traversal
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the BST
int search(struct Node *root, int value) {
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

// Function to delete an element from the BST
struct Node *deleteElement(struct Node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data) {
        root->left = deleteElement(root->left, key);
        return root;
    }
    else if (key > root->data) {
        root->right = deleteElement(root->right, key);
        return root;
    }
    if (root->left == NULL) {
        return root->right;
    }
    else if (root->right == NULL) {
        return root->left;
    }
}

int main() {
    struct Node *root = NULL;
    while (1) {
        int choice, key;
        printf("\n********** Binary Search Tree **************\n");
        printf("1. Insert Node in binary search tree\n");
        printf("2. Pre-order traversal \n");
        printf("3. In-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Search element in binary search tree\n");
        printf("6. Delete element from a binary tree\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                if (search(root, key) == 1)
                    printf("Found!\n");
                else
                    printf("Not found!\n");
                break;
            case 6:
                // Functionality to be added for deleting an element
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice!\n");
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    return 0;
}
