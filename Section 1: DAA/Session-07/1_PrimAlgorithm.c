#include <stdio.h>
#include <limits.h>

#define V 7 // Number of vertices (A, B, C, D, E, F, G)
#define INF 99999 // Infinity

// Find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Prim's algorithm to find the Minimum Cost Spanning Tree
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the MST
    int key[V];    // Key values to pick minimum weight edge
    int mstSet[V]; // Vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    // Start with vertex A (0)
    key[0] = 0;
    parent[0] = -1;

    printf("\nQ1: Prim’s Algorithm to Find Minimum Cost Spanning Tree\n");
    printf("Starting vertex: A\n");
    printf("Initial Keys: ");
    for (int i = 0; i < V; i++)
        printf("%c: %d ", 'A' + i, key[i] == INF ? -1 : key[i]);
    printf("\n\n");

    // Construct MST with V vertices
    for (int count = 0; count < V; count++) {
        // Pick the minimum key vertex not in MST
        int u = minKey(key, mstSet);
        if (u == -1) break;

        // Add the vertex to MST
        mstSet[u] = 1;

        printf("Step %d: Add vertex %c to MST\n", count + 1, 'A' + u);
        if (parent[u] != -1)
            printf("Edge added: %c - %c (weight: %d)\n", 'A' + parent[u], 'A' + u, graph[u][parent[u]]);
        printf("Vertices in MST: ");
        for (int v = 0; v < V; v++)
            if (mstSet[v])
                printf("%c ", 'A' + v);
        printf("\n");

        // Update key values and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                printf("Update key for %c: %d (via %c)\n", 'A' + v, key[v], 'A' + u);
            }
        }

        printf("Keys: ");
        for (int i = 0; i < V; i++)
            printf("%c: %d ", 'A' + i, key[i] == INF ? -1 : key[i]);
        printf("\n\n");
    }

    // Print the MST
    printf("Minimum Cost Spanning Tree Edges:\n");
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        printf("%c - %c: %d\n", 'A' + parent[i], 'A' + i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    // Graph adjacency matrix (undirected)
    int graph[V][V] = {
        {0, 4, 2, INF, INF, -3, INF},      // A
        {4, 0, 1, 5, INF, INF, INF},       // B
        {2, 1, 0, 8, 10, INF, INF},        // C
        {INF, 5, 8, 0, 2, INF, INF},       // D
        {INF, INF, 10, 2, 0, INF, INF},    // E
        {-3, INF, INF, INF, INF, 0, -8},   // F
        {INF, INF, INF, INF, INF, -8, 0}   // G
    };

    primMST(graph);
    return 0;
}
