#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

/* BFS function */
void bfs(int start) {
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = queue[front++];   // Dequeue
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;   // Enqueue
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
