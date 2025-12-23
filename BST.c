#include <stdio.h>
#include <stdlib.h>

/* Structure of BST node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create new node */
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Insert node into BST */
struct node* insert(struct node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

/* In-order traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Pre-order traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Post-order traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int n, data, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        printf("\n--- Binary Search Tree Traversals ---\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Pre-order: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
