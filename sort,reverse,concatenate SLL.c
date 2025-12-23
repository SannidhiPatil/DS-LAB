#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Create a linked list */
struct node* create() {
    int n, data;
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

/* Display list */
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Sort linked list */
struct node* sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL)
        return head;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

/* Reverse linked list */
struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Concatenate two lists */
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;

    printf("\nCreate First Linked List\n");
    list1 = create();

    printf("\nCreate Second Linked List\n");
    list2 = create();

    printf("\nFirst List:\n");
    display(list1);

    printf("\nSecond List:\n");
    display(list2);

    printf("\nSorted First List:\n");
    list1 = sortList(list1);
    display(list1);

    printf("\nReversed First List:\n");
    list1 = reverseList(list1);
    display(list1);

    printf("\nConcatenated List:\n");
    list1 = concatenate(list1, list2);
    display(list1);

    return 0;
}
