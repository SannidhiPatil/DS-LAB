#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Stack top */
struct node *top = NULL;

/* Queue front & rear */
struct node *front = NULL;
struct node *rear = NULL;

/* ---------- STACK OPERATIONS ---------- */

/* Push operation */
void push() {
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = top;
    top = newnode;

    printf("Pushed %d into stack.\n", data);
}

/* Pop operation */
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

/* Display stack */
void displayStack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- QUEUE OPERATIONS ---------- */

/* Enqueue operation */
void enqueue() {
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to enqueue: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued %d into queue.\n", data);
}

/* Dequeue operation */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

/* Display queue */
void displayQueue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- MAIN MENU ---------- */
int main() {
    int choice;

    while (1) {
        printf("\n--- STACK & QUEUE USING LINKED LIST ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
