/*Create a singly linked list with N nodes and write a program to delete the middle node of the linked list. The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Input Format

Input Size of SLL i.e N
Inputs N elements in SLL
Constraints

1 <= N <= 1000

Output Format

Display the modify list affter deleting middle element.

Sample Input 0

4
1 2 3 4
Sample Output 0

1 2 4
*/
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

1
#include <stdio.h>
2
#include <stdlib.h>
3
​
4
// Structure for linked list node
5
struct Node {
6
    int data;
7
    struct Node *next;
8
};
9
​
10
// Function to create a new node
11
struct Node* newNode(int data) {
12
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
13
    newNode->data = data;
14
    newNode->next = NULL;
15
    return newNode;
16
}
17
​
18
// Function to insert a new node at the end of the list
19
void insertNode(struct Node** head, int data) {
20
    if (*head == NULL) {
21
        *head = newNode(data);
22
        return;
23
    }
24
    struct Node* temp = *head;
25
    while (temp->next != NULL) {
26
        temp = temp->next;
27
    }
28
    temp->next = newNode(data);
29
}
30
​
31
// Function to delete the middle node of the list
32
void deleteMiddle(struct Node** head) {
33
    if (*head == NULL || (*head)->next == NULL) // If list is empty or has only one node
34
        return;
35
    
36
    struct Node *slowPtr = *head; // Slow pointer
37
    struct Node *fastPtr = *head; // Fast pointer
38
    struct Node *prev = NULL; // Pointer to previous node
39
    
40
    while (fastPtr != NULL && fastPtr->next != NULL) {
41
        fastPtr = fastPtr->next->next;
42
        prev = slowPtr;
43
        slowPtr = slowPtr->next;
44
    }
45
    
46
    // Delete the middle node
47
    prev->next = slowPtr->next;
48
    free(slowPtr);
49
}
50
​
51
// Function to print the modified list
52
void printList(struct Node* head) {
53
    struct Node* temp = head;
54
    while (temp != NULL) {
55
        printf("%d ", temp->data);
56
        temp = temp->next;
57
    }
58
}
59
​
60
int main() {
61
    int N, value;
62
    scanf("%d", &N);
63
    struct Node* head = NULL;
64
    
65
    for (int i = 0; i < N; i++) {
66
        scanf("%d", &value);
67
        insertNode(&head, value);
68
    }
69
    
70
    deleteMiddle(&head);
71
    printList(head);
72
    
73
    return 0;
74
}
