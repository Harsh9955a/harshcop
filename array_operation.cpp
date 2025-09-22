#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n = 0; // Number of elements in array

void create() {
    int i;
    printf("\nEnter the number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n < 0) {
        printf("Invalid size! Must be between 0 and %d.\n", MAX);
        n = 0;
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

void display() {
    int i;
    if (n == 0) {
        printf("\nArray is empty.\n");
        return;
    }

    printf("\nArray elements are:\n");
    printf("Index\tValue\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, arr[i]);
    }
}

void insert() {
    int elem, pos, i;
    if (n == MAX) {
        printf("\nArray is full. Cannot insert new element.\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &elem);
    printf("Enter the position (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = elem;
    n++;
    printf("Element inserted successfully.\n");
}

void del() {
    int pos, i;
    if (n == 0) {
        printf("\nArray is empty. Cannot delete.\n");
        return;
    }

    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Element deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}