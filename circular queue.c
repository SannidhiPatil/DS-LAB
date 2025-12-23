#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

/* Insert (Enqueue) */
void insert() {
    int item;

    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {   // First insertion
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cqueue[rear] = item;
    printf("Inserted %d into circular queue.\n", item);
}

/* Delete (Dequeue) */
void delete() {
    if (front == -1) {
        printf("Circular Queue Empty! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", cqueue[front]);

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

/* Display elements */
void display() {
    int i;

    if (front == -1) {
        printf("Circular Queue Empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
