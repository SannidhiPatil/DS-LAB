bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Build adjacency list
    int* adjCount = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        adjCount[edges[i][0]]++;
        adjCount[edges[i][1]]++;
    }
   int** adjList = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(adjCount[i] * sizeof(int));
        adjCount[i] = 0; // reset for filling
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[u][adjCount[u]++] = v;
        adjList[v][adjCount[v]++] = u;
    }
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
stack[++top] = source;
    visited[source] = true;
    while (top >= 0) {
        int node = stack[top--];
        if (node == destination) {
            return true;
        }
        for (int i = 0; i < adjCount[node]; i++) {
            int neighbor = adjList[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack[++top] = neighbor;
            }   } }
    return false;
} 
