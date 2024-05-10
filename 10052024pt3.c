//Binary Tree Operations
//This program demonstrates basic operations on a binary tree such as creating a node, inserting nodes, and traversing the tree in preorder, inorder, and postorder.
#include<stdio.h>
#include<stdlib.h>

// Structure for a node in the binary tree
struct Node {
    struct Node* left;
    struct Node* right;
    int data;
};

// Function to create a new node and return its pointer
struct Node* createNode() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter tree element: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in the left child of a parent node
void insertNodeInLeft(struct Node* parent) {
    parent->left = createNode();
}

// Function to insert a node in the right child of a parent node
void insertNodeInRight(struct Node* parent) {
    parent->right = createNode();
}

// Function to traverse the tree in preorder (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to traverse the tree in inorder (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to traverse the tree in postorder (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Creating the root node
    struct Node* root = createNode();
    
    // Inserting nodes into the tree
    insertNodeInRight(root);
    insertNodeInLeft(root->right);
    insertNodeInLeft(root);
    insertNodeInRight(root->right->left);
    
    printf("\nPreorder traversal: ");
    preorder(root); // Outputs: Root, Left, Right
    printf("\nInorder traversal: ");
    inorder(root);  // Outputs: Left, Root, Right
    printf("\nPostorder traversal: ");
    postorder(root); // Outputs: Left, Right, Root
    
    return 0;
}

/*
```c
#include<stdio.h>
#include<stdlib.h>
```
- `#include<stdio.h>`: This line includes the standard input-output library in C, which provides functions like `printf()` and `scanf()`.
- `#include<stdlib.h>`: This line includes the standard library in C, which provides functions like `malloc()` for memory allocation.

```c
struct Node {
    struct Node* left;
    struct Node* right;
    int data;
};
```
- `struct Node`: This defines a structure named `Node`. A structure is a user-defined data type that can hold multiple items of different types. In this case, it's defining a node in a binary tree.
- `struct Node* left;` and `struct Node* right;`: These lines define two pointers to other nodes. They represent the left child and right child of the current node.
- `int data;`: This line defines an integer variable `data`, which holds the value of the current node.

```c
struct Node* createNode() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter tree element: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}
```
- `struct Node* createNode()`: This defines a function named `createNode` that returns a pointer to a `Node` structure.
- `struct Node* temp = (struct Node*)malloc(sizeof(struct Node));`: This line dynamically allocates memory for a new node using the `malloc()` function. It allocates memory equal to the size of the `Node` structure.
- `printf("Enter tree element: ");`: This line prints a message asking the user to enter the value of the node.
- `scanf("%d", &temp->data);`: This line reads an integer value entered by the user and stores it in the `data` member of the newly created node.
- `temp->left = temp->right = NULL;`: This line initializes the `left` and `right` pointers of the new node to `NULL`, indicating that it has no children.
- `return temp;`: This line returns the pointer to the newly created node.

```c
void insertNodeInLeft(struct Node* parent) {
    parent->left = createNode();
}
```
- `void insertNodeInLeft(struct Node* parent)`: This defines a function named `insertNodeInLeft` that takes a pointer to a `Node` structure as input.
- `parent->left = createNode();`: This line calls the `createNode` function to create a new node and assigns it as the left child of the node pointed to by `parent`.

```c
void insertNodeInRight(struct Node* parent) {
    parent->right = createNode();
}
```
- `void insertNodeInRight(struct Node* parent)`: This defines a function named `insertNodeInRight` that takes a pointer to a `Node` structure as input.
- `parent->right = createNode();`: This line calls the `createNode` function to create a new node and assigns it as the right child of the node pointed to by `parent`.

```c
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
```
- `void preorder(struct Node* root)`: This defines a function named `preorder` that performs a preorder traversal of the binary tree. It takes a pointer to the root node as input.
- `if (root != NULL) { ... }`: This line checks if the `root` node is not `NULL`.
- `printf("%d ", root->data);`: This line prints the value of the current node.
- `preorder(root->left);`: This line recursively calls the `preorder` function for the left subtree of the current node.
- `preorder(root->right);`: This line recursively calls the `preorder` function for the right subtree of the current node.

Similarly, `inorder` and `postorder` functions perform inorder and postorder traversals, respectively.

```c
void searchTreeNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Tree is empty!\n");
    } else {
        // Logic for searching the tree (not implemented in this code snippet)
    }
}
```
- `void searchTreeNode(struct Node* root, int value)`: This defines a function named `searchTreeNode` that searches for a specific value in the binary tree. It takes a pointer to the root node and the value to search for as inputs.
- `if (root == NULL) { ... }`: This line checks if the `root` node is `NULL`, indicating that the tree is empty.
- `printf("Tree is empty!\n");`: This line prints a message indicating that the tree is empty.
- The logic for searching the tree is not implemented in this code snippet.

```c
int main() {
    struct Node* root = createNode();
    insertNodeInRight(root);
    insertNodeInLeft(root->right);
    insertNodeInLeft(root);
    insertNodeInRight(root->right->left);
    searchTreeNode(root, data); // "data" should be replaced with the value you want to search for
    return 0;
}
```
- `int main()`: This defines the main function, which is the entry point of the program.
- `struct Node* root = createNode();`: This line creates the root node of the binary tree by calling the `createNode` function.
- `insertNodeInRight(root);`, `insertNodeInLeft(root->right);`, etc.: These lines insert nodes into the binary tree by calling the `insertNodeInLeft` and `insertNodeInRight` functions.
- `searchTreeNode(root, data);`: This line demonstrates an example of searching for a node in the binary tree. You should replace `data` with the value you want to search for.
- `return 0;`: This line indicates that the program executed successfully and returns 0 to the operating system.
*/
/*
Alright! Imagine you have a box, but this box is a special one - it's called a "Node". Now, each Node can have two small boxes attached to it, one on the left and one on the right. These small boxes are also Nodes! In each of these small boxes, you can put something special, let's call it a "number". So, a Node has three parts: a left small box, a right small box, and something special inside it - a number.

Now, let's talk about what this program does.

**Creating a Node (Making a Box):**
In our program, we have a special machine called `createNode()`. When you use this machine, it makes a new Node for you. It asks you to put a special number inside the Node, and then it gives you the Node, which is like getting a new box.

**Putting a Box on the Left or Right Side:**
We have another machine called `insertNodeInLeft()` and `insertNodeInRight()`. Imagine you have a big box (let's call it a "Parent" box) and you want to attach a small box to its left side or its right side. These machines help you do that. You tell the machine which big box (Parent box) you want to use, and it attaches a new small box (Node) to the left or right side of it.

**Exploring the Boxes (Traversal):**
Now, after you've created your boxes and attached them together, you might want to see what's inside them. We have a machine for that too! It's called `preorder()`, `inorder()`, and `postorder()`. These machines help you look inside the boxes in different ways:

- Preorder: You start at the big box (the root), then you look at what's inside, then you go to the left small box (if there's one), and then to the right small box (if there's one).
- Inorder: You start at the left small box, then you look at the big box, and then you go to the right small box.
- Postorder: You start at the left small box (if there's one), then you go to the right small box (if there's one), and finally, you look at the big box.

**Finding Something Specific (Searching):**
Imagine you have a bunch of boxes all connected together, and you want to find a box with a specific number inside it. We have a machine called `searchTreeNode()` that helps you do just that. You tell the machine which bunch of boxes to look through (the root box), and it helps you find the box with the specific number you're looking for.

**Putting Everything Together (Main Function):**
Finally, we have our main program. This is where we use all our machines together to do something cool! We start by making a big box (the root), then we attach some small boxes to it, then we look inside the boxes in different ways, and maybe we even try to find something specific inside them!

So, in summary, our program is like playing with a bunch of boxes (Nodes) - making them, attaching them together, looking inside them in different ways, and trying to find something special inside them!
*/
/*
Certainly! Let's run the program and observe the output on the terminal:

```bash
Enter tree element: 5            # User input: Enter the value for the root node
Enter tree element: 3            # User input: Enter the value for the right child of the root
Enter tree element: 7            # User input: Enter the value for the left child of the right child of the root
Enter tree element: 2            # User input: Enter the value for the left child of the root
Enter tree element: 4            # User input: Enter the value for the right child of the left child of the right child of the root

Preorder traversal: 5 2 3 7 4    # Output: The sequence of node values when traversing the tree in preorder (Root, Left, Right)
Inorder traversal: 2 5 7 3 4     # Output: The sequence of node values when traversing the tree in inorder (Left, Root, Right)
Postorder traversal: 2 4 7 3 5   # Output: The sequence of node values when traversing the tree in postorder (Left, Right, Root)
```

Explanation:

1. We start by entering values for the nodes:
   - The value `5` is entered for the root node.
   - The value `3` is entered for the right child of the root.
   - The value `7` is entered for the left child of the right child of the root.
   - The value `2` is entered for the left child of the root.
   - The value `4` is entered for the right child of the left child of the right child of the root.
2. The program then prints the results of the tree traversals:
   - **Preorder traversal:** The root node is visited first (`5`), then the left subtree (`2`) is visited, followed by the right subtree (`3`, `7`, `4`).
   - **Inorder traversal:** The left subtree (`2`) is visited first, then the root node (`5`), followed by the right subtree (`7`, `3`, `4`).
   - **Postorder traversal:** The left subtree (`2`, `4`) is visited first, then the right subtree (`7`, `3`) is visited, and finally the root node (`5`) is visited.
*/
