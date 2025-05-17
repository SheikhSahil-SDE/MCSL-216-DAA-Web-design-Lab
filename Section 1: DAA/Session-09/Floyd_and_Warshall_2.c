#include <stdio.h>
#define V 5
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

// Function to print the path from i to j
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

    // Update distances
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
    if (!hasNegativeCycle) {
        printf("No negative cycles detected.\n");
    }

    // Print shortest paths
    printf("\nShortest Paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && dist[i][j] != INF) {
                printf("Shortest path from %c to %c: ", 'A' + i, 'A' + j);
                printPath(pred, i, j);
                printf(", Distance = %d\n", dist[i][j]);
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 5, INF, INF},
        {INF, 0, 2, 1, INF},
        {3, 9, 0, 2, INF},
        {2, INF, INF, 0, 4},
        {7, INF, INF, 6, 0}
    };

    printf("\nSession 9: Floyd and Warshall’s Algorithm for All-Pairs Shortest Path\n");
    printf("\nQ2: Apply Floyd-Warshall Algorithm\n");
    floydWarshall(graph);
    return 0;
}
