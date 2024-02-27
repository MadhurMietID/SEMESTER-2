#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int size = 0;

void createList() {
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    
    if (size > MAX_SIZE) {
        printf("List size exceeds the maximum limit.\n");
        size = 0;
        return;
    }
    
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    
    printf("List created successfully.\n");
}

void insert(int value, int position) {
    if (size >= MAX_SIZE) {
        printf("List is full. Cannot insert.\n");
        return;
    }
    
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    
    for (int i = size; i > position; i--) {
        list[i] = list[i - 1];
    }
    
    list[position] = value;
    size++;
    printf("Element inserted successfully.\n");
}

void delete(int position) {
    if (size == 0) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return;
    }
    
    for (int i = position; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    
    size--;
    printf("Element deleted successfully.\n");
}

int linearSearch(int key) {
    for (int i = 0; i < size; i++) {
        if (list[i] == key) {
            return i;
        }
    }
    return -1;
}

void displayList() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("Elements in the list are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int choice, value, position, key, result;

    while (1) {
        printf("\n1. Create list\n2. Insert element\n3. Delete element\n4. Search element\n5. Display list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert(value, position);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 4:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = linearSearch(key);
                if (result != -1) {
                    printf("Element found at position %d.\n", result);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}