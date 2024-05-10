#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node* createNode() {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insertInRight(struct Node *parent) {
    parent->right = createNode();
}

void insertInLeft(struct Node *parent) {
    parent->left = createNode();
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data); // Printing data of the current node
        preorder(root->left);      // Recursively traverse left subtree
        preorder(root->right);     // Recursively traverse right subtree
    }
}

int main() {
    struct Node *root = NULL;
    root = createNode(); // Creating the root node

    // Inserting nodes
    insertInLeft(root);
    insertInRight(root);

    // Traversing the tree in preorder
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}
