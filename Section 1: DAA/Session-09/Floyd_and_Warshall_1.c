#include <stdio.h>
#define V 7
#define INF 99999

// Function to print the matrix
void printMatrix(int dist[V][V], int k) {
    printf("\nD^%d Matrix:\n", k);
    printf("   ");
    for (int i = 0; i < V; i++) printf("%4c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%4s ", "INF");
            else
                printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to print the path from i to j using predecessor matrix
void printPath(int pred[V][V], int i, int j) {
    if (pred[i][j] == -1 || i == j) {
        printf("%c", 'A' + i);
        return;
    }
    printPath(pred, i, pred[i][j]);
    printf(" -> %c", 'A' + j);
}

// Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V], pred[V][V];

    // Initialize distance and predecessor matrices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            pred[i][j] = (graph[i][j] != INF && i != j) ? i : -1;
        }
    }

    printMatrix(dist, 0);

    // Update distances using each vertex as an intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
        printMatrix(dist, k + 1);
    }

    // Check for negative cycles
    printf("\nChecking for Negative Cycles:\n");
    int hasNegativeCycle = 0;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Negative cycle detected involving vertex %c (D[%d][%d] = %d)\n", 'A' + i, i, i, dist[i][i]);
            hasNegativeCycle = 1;
        }
    }

    // Print shortest paths (stable paths among B, C, D, E)
    if (hasNegativeCycle) {
        printf("\nShortest Paths (Stable among vertices B, C, D, E):\n");
        int stableVertices[] = {1, 2, 3, 4}; // B, C, D, E
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    int src = stableVertices[i], dst = stableVertices[j];
                    printf("Shortest path from %c to %c: ", 'A' + src, 'A' + dst);
                    printPath(pred, src, dst);
                    printf(", Distance = %d\n", dist[src][dst]);
                }
            }
        }
        printf("\nNote: Paths involving A, F, G are undefined (distance -> -∞) due to negative cycle A -> F -> A.\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, INF, INF, -3, INF},
        {4, 0, 1, 5, INF, INF, INF},
        {2, 1, 0, 8, 10, INF, INF},
        {INF, 5, 8, 0, 2, INF, INF},
        {INF, INF, 10, 2, 0, INF, INF},
        {-3, INF, INF, INF, INF, 0, -8},
        {INF, INF, INF, INF, INF, -8, 0}
    };

    printf("\nSession 9: Floyd and Warshall’s Algorithm for All-Pairs Shortest Path\n");
    printf("\nQ1: Apply Floyd-Warshall Algorithm\n");
    floydWarshall(graph);
    return 0;
}
