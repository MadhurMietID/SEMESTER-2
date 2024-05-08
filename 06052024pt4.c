
/*A linked list is a data structure made up of a sequence of elements, where each element contains a reference (or link) to the next element in the sequence. Unlike arrays, linked lists do not have a fixed size in memory and can easily grow or shrink as needed.*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some elements into the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}

/*
||#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
    };||
/*struct Node* next; is a member of the struct Node. This member represents a pointer to the next node in the linked list.

Let's break it down:

struct Node*: This declares a pointer to a structure of type Node. The struct Node refers to the structure defined earlier in the code, which represents a node in the linked list.
next: This is the name of the member variable. It holds the address (or pointer) to the next node in the linked list.
So, each node in the linked list contains two pieces of information: the actual data (int data in this case) and a pointer to the next node in the sequence (struct Node* next). This pointer links each node to the next node in the list, hence the name "linked list".

I see what you mean now. In C, when you declare a pointer variable like `struct Node* next;`, you are reserving space for a pointer that can hold the address of a `struct Node`, but you're not actually creating a new instance of `struct Node`.

In the provided code, the pointer `next` inside the `struct Node` is declared as `struct Node* next;`. This declares `next` as a pointer to another `struct Node`. When you create a new instance of `struct Node` using `malloc` in the `createNode` function, memory is allocated for both the `data` and `next` members. However, `next` is not explicitly initialized to point to anything specific. It's left uninitialized initially.

So, when you create a new node using `createNode`, the memory for `next` is allocated, but its value is indeterminate (it could be any garbage value). To ensure that it's pointing to nothing (or NULL), which indicates the end of the list, you explicitly set `next` to `NULL` in the `createNode` function:

```c
newNode->next = NULL;
```

This initializes `next` to NULL, ensuring that the newly created node is the last node in the list initially. Later, when you insert new nodes into the list, you update the `next` pointer accordingly to maintain the structure of the linked list.



||
// Function to create a new node
struct Node* createNode(int data)  ||
 /*
  In the function declaration `struct Node* createNode(int data)`, the `int data` inside the parentheses represents a parameter of the function. Let's break it down:

- `struct Node*`: This is the return type of the function. It means that the function `createNode` returns a pointer to a `struct Node`.

- `createNode`: This is the name of the function.

- `(int data)`: These are the parameters of the function. In this case, the function takes an integer `data` as a parameter. This integer data represents the value that will be stored in the `data` member of the newly created node.

So, when you call the `createNode` function, you need to pass an integer value as an argument, which will be stored in the `data` member of the newly created node.

Regarding your question about using `int` or `void` as the return type:

- If you use `int` as the return type, it typically means that the function will return an integer value. However, in the case of `createNode`, it's more common to return a pointer to the newly created node, so `struct Node*` is used as the return type.

- If you use `void` as the return type, it means that the function does not return any value. In this case, if you are creating a new node and don't need to return any specific information about the creation process, you could use `void` as the return type.

So, it's not necessary to use `int` or `void` as the return type for `createNode`. Instead, it's more common to use `struct Node*` to indicate that the function returns a pointer to a newly created node.
The parameters of the function are the inputs that the function accepts. They are enclosed in parentheses after the function name. In C, parameters are specified inside the parentheses, and their types are declared before their names.

For example, in the function declaration `void myFunction(int x, float y)`, `int x` and `float y` are the parameters. This means that `myFunction` takes two parameters: an integer `x` and a float `y`. 

When you call `myFunction` elsewhere in your code, you need to provide arguments for each parameter in the same order as they are declared. For instance:

```c
int main() {
    int a = 5;
    float b = 3.14;
    myFunction(a, b);
    return 0;
}
```

In this example, `a` is passed as the argument for `x`, and `b` is passed as the argument for `y` when calling `myFunction`.  
  
  
||
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    ||
  
  Ah, got it. Let me explain!

In C, the `malloc` function is used to dynamically allocate memory at runtime. Here's what's happening in that line of code:

1. `sizeof(struct Node)`: This part determines the size (in bytes) of the memory block to be allocated. `struct Node` is the type of data structure you want to allocate memory for. `sizeof(struct Node)` calculates the size of a single `struct Node` object in memory.

2. `malloc`: This is a function in C that stands for "memory allocation". It allocates a block of memory of the specified size (in bytes) and returns a pointer to the beginning of that block.

3. `(struct Node*)`: This part is a typecast. The return type of `malloc` is `void*`, which is a generic pointer type. In C, it's good practice to explicitly cast the pointer returned by `malloc` to the appropriate type. Here, `(struct Node*)` casts the `void*` pointer returned by `malloc` to a pointer to a `struct Node`. This tells the compiler that the memory allocated by `malloc` will be used to store `struct Node` objects.

So, putting it all together, `(struct Node*)malloc(sizeof(struct Node))` dynamically allocates memory for a single `struct Node` object, and returns a pointer to that allocated memory. This pointer is then assigned to `newNode` in your code.
  
When we talk about "runtime" in programming, we're referring to the period during which a program is executing. In other words, runtime encompasses the time when the program is actually running, as opposed to when it's being compiled or when it's not actively doing anything.

In the context of memory allocation using `malloc`, "runtime" means that memory is being allocated dynamically while the program is running. Unlike static memory allocation, where memory is allocated at compile time and remains fixed throughout the execution of the program, dynamic memory allocation with `malloc` allows memory to be allocated and deallocated as needed during runtime.

So, when you use `malloc` to allocate memory, you're doing it during the execution of your program, i.e., at runtime. This allows your program to adapt to varying memory requirements and utilize memory more efficiently.  

 ||
    if (newNode == NULL)
    ||
    /*In C, `NULL` is a macro that represents a null pointer constant. It is often used to indicate that a pointer does not point to a valid memory address. 

When `malloc` fails to allocate memory (for example, due to insufficient memory available), it returns a null pointer (`NULL`). Checking if `newNode == NULL` in your code is a way to verify if the memory allocation was successful.

So, in the line `if (newNode == NULL)`, the code is checking if `newNode` is a null pointer, which would indicate that the memory allocation with `malloc` failed. If `newNode` is `NULL`, it means that there was not enough memory available to create a new node, and the program may need to handle this error condition appropriately.
||
{
        printf("Memory allocation failed!\n");
        exit(1);
}
||        
      /*In C, the `exit` function is used to terminate the program immediately. It's typically used when an unrecoverable error occurs or when a program needs to terminate for some reason. The integer argument passed to `exit` is called the exit status or exit code. This value indicates the reason for termination and can be used by the calling process to determine the outcome of the terminated program.

Conventionally, an exit status of `0` indicates successful termination, while a non-zero exit status indicates an error or abnormal termination. However, the specific meaning of non-zero exit codes can vary depending on the context and the programmer's preference.

In the code provided, `exit(1);` is used to indicate an error condition. By convention, a non-zero exit status, such as `1`, is often used to signal that an error occurred during the execution of the program. This helps the calling process (such as a shell script or another program) to detect and handle the error appropriately.
||    
    newNode->data = data;
    newNode->next = NULL;
    /*In the code snippet provided:
}    
||
```c
newNode->data = data;
newNode->next = NULL;
```

Here's what's happening:

- `newNode->data = data;`: This line is assigning the value of `data` to the `data` member of the `newNode` structure. `newNode` is a pointer to a `struct Node`, and the `->` operator is used to access members of a structure through a pointer. So, `newNode->data` means "access the `data` member of the structure that `newNode` points to" and then assign the value of `data` to it.

- `newNode->next = NULL;`: Similarly, this line is assigning `NULL` to the `next` member of the `newNode` structure. Here, `newNode->next` means "access the `next` member of the structure that `newNode` points to" and then assign `NULL` to it. This sets the `next` pointer to `NULL`, indicating that `newNode` is currently the last node in the linked list.

The `->` operator in C is used specifically with pointers to structures to access members of the structure. It's essentially a shorthand notation for dereferencing a pointer and accessing a member of the pointed-to structure in a single step.
    return newNode;
    /*In the context of the code provided, `return newNode;` is the return statement of the `createNode` function. Let's break it down:

- `newNode`: This is a pointer to the newly created node, which is of type `struct Node*`. When you use `return newNode;`, you're instructing the function to return this pointer.

In other words, when you call the `createNode` function, it dynamically allocates memory for a new node, initializes its `data` member with the provided value, sets its `next` pointer to `NULL`, and then returns a pointer to this newly created node.

This allows you to assign the returned pointer to a variable or use it directly in other parts of your code, such as when inserting the new node into a linked list. For example:

```c
struct Node* head = createNode(10);
```

In this example, the `head` pointer is assigned the value returned by `createNode`, which is a pointer to a newly created node containing the data value `10`.
The "return" part refers to the action of the function returning a value to the calling code. In this case, the function returns a pointer to the newly created node. This returned pointer can then be used by the calling code to access and manipulate the newly created node.

For example, if you call createNode(10), the function will return a pointer to a newly created node with its data member set to 10 and its next pointer set to NULL. You can then use this returned pointer to assign the newly created node to a variable or to insert it into a linked list, like so:
struct Node* newNode = createNode(10);
Here, newNode will now hold the address of the newly created node, allowing you to work with it further in your code.
||
// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
||
// The double asterisks `**` in C are used to declare a pointer to a pointer. It's often referred to as a "pointer to pointer".

In the context of the provided code, `struct Node** headRef` in the `insertAtBeginning` function is a pointer to a pointer to a `struct Node`.

Let's break it down:

- `struct Node*`: This is a pointer to a `struct Node`, meaning it can store the memory address of a `struct Node`.
- `headRef`: This is the name of the pointer variable.
- `*`: This is the dereference operator, used to access the value pointed to by a pointer.
- So, `struct Node** headRef` means "a pointer to a pointer to a `struct Node`".

When you pass a pointer to a pointer to a function, you can modify the original pointer (from the calling function) within the called 
function. This allows you to make changes to the original pointer's value, such as updating it to point to a different memory location.
When you pass a pointer to a pointer to a function, you're effectively passing the address of a pointer variable. This allows the function to directly modify the pointer itself, not just the data it points to. 

Let's break it down:

1. **Pointer to a Pointer:**
   - When you declare a parameter in a function to be of type `struct Node**`, you're saying that this parameter will hold the memory address of a pointer to a `struct Node`.
   - This means you're passing a pointer variable (which holds an address in memory) that itself holds the address of some data (in this case, the address of a `struct Node`).

2. **Ability to Modify the Original Pointer:**
   - Since you're passing the address of a pointer variable, any changes made to this pointer variable within the function will affect the original pointer variable that was passed.
   - In C, when you dereference a pointer to a pointer (`*headRef`), you're accessing the value of the pointer it points to. By assigning a new value to `*headRef`, you're essentially changing the value of the pointer variable passed to the function.
   - Because the address of the original pointer is passed to the function, modifications made to it within the function persist after the function returns to its caller.

So, by passing a pointer to a pointer to a function, you provide the function with the ability to not only access but also modify the pointer variable itself, allowing for more flexible manipulation of data structures like linked lists. This is particularly useful when you need to update the head of a linked list or change the value of a pointer in the calling function's scope.


 In the context of linked lists, this is often used when you want to modify the `head` pointer of the list, which may need to 
 change if you're inserting a new node at the beginning of the list
 
 In the context of a singly linked list, the "beginning" typically refers to the front of the list, where new nodes are added. When 
 nodes are inserted, they become the new "first node," and the existing first node becomes the second node in the list. 
 This concept aligns with the idea of inserting elements at the head or front of the list, which is a common operation in linked list
  implementations. So, in the context of a linked list, the "beginning" refers to the side where new elements are added or inserted.

  In the function signature `void insertAtBeginning(struct Node** headRef, int data)`, the `struct Node** headRef` parameter might look a bit complex, but it's actually not too complicated. Let's break it down:

- `struct Node*`: This part declares a pointer to a `struct Node`. It means that the variable of this type can store the memory address of a `struct Node`.

- `* headRef`: Here, the asterisk (*) is used to declare `headRef` as a pointer. So, `headRef` is a pointer variable.

- `struct Node**`: The double asterisks (**) denote a pointer to a pointer to a `struct Node`. This means `headRef` itself is a pointer that points to another pointer which, in turn, points to a `struct Node`.

In simpler terms, `struct Node** headRef` is a pointer that holds the memory address of another pointer, which in turn holds the address of a `struct Node`. 

This is commonly used in situations where you want to modify a pointer variable itself inside a function. In this specific case,
 `insertAtBeginning` function wants to modify the `head` pointer in `main()`, which is why it takes a pointer to a pointer as an argument. By doing so, any changes made to `headRef` within `insertAtBeginning` will also reflect in the `head` pointer outside of the function. This allows the function to update the caller's reference to the head of the linked list.
 //
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}
||
// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some elements into the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
*/
/*To see the output of the provided code on the terminal, you can compile and run the code using a C compiler like `gcc`. Here's how you can do it:

1. Save the code into a file, for example, `linked_list.c`.

2. Open your terminal and navigate to the directory where the file is saved.

3. Compile the code using `gcc`:

```
gcc linked_list.c -o linked_list
```

4. Run the compiled executable:

```
./linked_list
```

You should see the output printed on the terminal:

```
Linked List: 15 -> 10 -> 5 -> NULL
```

This output represents the elements inserted into the linked list in reverse order because the `insertAtBeginning` function inserts elements at the beginning of the list. So, 15 was inserted first, then 10, and finally 5.*/
