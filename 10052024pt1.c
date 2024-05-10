#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // You can traverse, insert, delete, search, and perform various operations on this tree.
    
    return 0;
}
/*
Of course! Let's go through the code step by step:

```c
#include <stdio.h>
#include <stdlib.h>
```

Here, we include necessary header files. `stdio.h` is included for input/output operations, and `stdlib.h` is included for dynamic memory allocation using `malloc()` and `free()` functions.

```c
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
```

This defines a structure named `Node`. Each node contains an integer data value (`data`) and two pointers to other nodes: `left` and `right`, representing the left and right children of the current node, respectively.

```c
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
```

The `createNode` function dynamically allocates memory for a new node using `malloc()`. It takes an integer `data` as an argument, assigns it to the `data` member of the new node, and initializes the `left` and `right` pointers to `NULL`. It then returns a pointer to the newly created node.

```c
int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // You can traverse, insert, delete, search, and perform various operations on this tree.
    
    return 0;
}
```

In the `main` function:
- We create a binary tree with five nodes.
- The first line creates the root node with data `1`.
- Then, we create left and right children for the root with data `2` and `3`, respectively.
- Further, we create left and right children for the node with data `2`, creating a subtree rooted at this node.
- You can perform various operations on this tree, such as traversal, insertion, deletion, searching, etc. These operations can be implemented using recursive algorithms.

This code sets up a simple binary tree structure with a root node and four child nodes. You can expand upon this structure to implement different operations and algorithms on binary trees.
*/
/*
Sure! Let's break it down in a more visual and simple way.

### 1. What's a Node?

Imagine a tree as a bunch of boxes stacked on top of each other. Each box is a node.

![Tree Nodes](https://i.imgur.com/NTmV9n0.png)

Each box (node) has:
- A number inside it (the `data`).
- Two arrows coming out of it (the `left` and `right` pointers). These arrows point to other boxes (nodes).

### 2. Creating a Node

When we create a node, we're making a new box and putting a number in it.

![Creating a Node](https://i.imgur.com/QMMaJqW.png)

For example, when we call `createNode(1)`, we're creating a box with `1` inside it.

### 3. Linking Nodes

Now, let's see how we connect these boxes.

![Linking Nodes](https://i.imgur.com/3sQ8XH8.png)

- The first box we create is the root. Let's call it Box 1.
- We create two more boxes, Box 2 and Box 3. Box 2 is on the left of Box 1, and Box 3 is on the right.
- Box 2 and Box 3 are linked to Box 1 with arrows.

### 4. Adding More Nodes

We can keep adding more boxes (nodes) to our tree!

![Adding More Nodes](https://i.imgur.com/KKbiAWp.png)

- For example, we add Box 4 and Box 5 to the left of Box 2.
- Each box can have its own left and right boxes, and the pattern continues.

That's the basic idea! We create boxes (nodes) with numbers in them and link them together to form a tree structure. Later, we can do fun stuff like finding numbers, adding more boxes, or removing boxes from our tree.
*/
/*
Output---
      1
     / \
    2   3
   / \
  4   5
```

Explanation:

- `1` is the root node of the tree.
- `2` and `3` are children of the root node `1`.
- `4` and `5` are children of node `2`.
- Nodes `4` and `5` are leaf nodes since they have no children.

In the `main` function:
- We create a binary tree with five nodes.
- The first line creates the root node with data `1`.
- Then, we create left and right children for the root with data `2` and `3`, respectively.
- Further, we create left and right children for the node with data `2`, creating a subtree rooted at this node.

This text-based representation helps in visualizing the structure of the binary tree and understanding the relationships between its nodes.
*/
