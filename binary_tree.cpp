#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the Binary Tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) { // If tree is empty, create root
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the Binary Tree
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0; // Not found
    }
    if (root->data == key) {
        return 1; // Found
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Traversal Functions
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("%d found in the tree.\n", key);
                else
                    printf("%d not found in the tree.\n", key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}