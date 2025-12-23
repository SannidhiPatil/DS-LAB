#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Initialize hash table */
void init() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

/* Insert key using linear probing */
void insert(int key) {
    int index = key % m;

    if (hashTable[index] == -1) {
        hashTable[index] = key;
        printf("Key %d inserted at address %d\n", key, index);
    } else {
        printf("Collision occurred at address %d\n", index);

        int i = 1;
        while ((index + i) % m != index) {
            int newIndex = (index + i) % m;
            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                printf("Key %d inserted at address %d using linear probing\n", key, newIndex);
                return;
            }
            i++;
        }
        printf("Hash table overflow! Cannot insert key %d\n", key);
    }
}

/* Display hash table */
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : EMPTY\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
