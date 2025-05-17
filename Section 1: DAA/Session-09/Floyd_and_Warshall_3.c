#include <stdio.h>
#include <string.h>

// Define INF as a large value
#define INF 99999

// Function to print the matrix
void printMatrix(int V, int dist[][V], int k) {
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
void printPath(int V, int pred[][V], int i, int j) {
    if (pred[i][j] == -1 || i == j) {
        printf("%c", 'A' + i);
        return;
    }
    printPath(V, pred, i, pred[i][j]);
    printf(" -> %c", 'A' + j);
}

// Floyd-Warshall algorithm
void floydWarshall(int V, int graph[][V], char* graphName) {
    int dist[V][V], pred[V][V];

    // Initialize distance and predecessor matrices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            pred[i][j] = (graph[i][j] != INF && i != j) ? i : -1;
        }
    }

    printf("\n\n--- %s ---\n", graphName);
    printMatrix(V, dist, 0);

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
        printMatrix(V, dist, k + 1);
    }

    // Check for negative cycles
    printf("\nChecking for Negative Cycles:\n");
    int hasNegativeCycle = 0;
    int verticesInCycle[V];
    int numVerticesInCycle = 0;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Negative cycle detected involving vertex %c (D[%d][%d] = %d)\n", 'A' + i, i, i, dist[i][i]);
            verticesInCycle[numVerticesInCycle++] = i;
            hasNegativeCycle = 1;
        }
    }
    if (!hasNegativeCycle) {
        printf("No negative cycles detected.\n");
    }

    // Print shortest paths
    printf("\nShortest Paths:\n");
    if (hasNegativeCycle) {
        printf("Paths involving vertices in negative cycles are undefined (distance -> -∞):\n");
        for (int i = 0; i < numVerticesInCycle; i++) {
            printf("%c ", 'A' + verticesInCycle[i]);
        }
        printf("\nShowing paths among other vertices:\n");
        for (int i = 0; i < V; i++) {
            int iInCycle = 0;
            for (int x = 0; x < numVerticesInCycle; x++) {
                if (i == verticesInCycle[x]) {
                    iInCycle = 1;
                    break;
                }
            }
            if (iInCycle) continue;
            for (int j = 0; j < V; j++) {
                int jInCycle = 0;
                for (int x = 0; x < numVerticesInCycle; x++) {
                    if (j == verticesInCycle[x]) {
                        jInCycle = 1;
                        break;
                    }
                }
                if (jInCycle || i == j || dist[i][j] == INF) continue;
                printf("Shortest path from %c to %c: ", 'A' + i, 'A' + j);
                printPath(V, pred, i, j);
                printf(", Distance = %d\n", dist[i][j]);
            }
        }
    } else {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && dist[i][j] != INF) {
                    printf("Shortest path from %c to %c: ", 'A' + i, 'A' + j);
                    printPath(V, pred, i, j);
                    printf(", Distance = %d\n", dist[i][j]);
                }
            }
        }
    }
}

int main() {
    // Graph 1: Small, undirected, positive weights, no cycles
    int V1 = 3;
    int graph1[3][3] = {
        {0, 4, 2},
        {4, 0, 1},
        {2, 1, 0}
    };

    // Graph 2: Medium, directed, positive weights, with cycles
    int V2 = 5;
    int graph2[5][5] = {
        {0, 10, 5, INF, INF},
        {INF, 0, 2, 1, INF},
        {3, 9, 0, 2, INF},
        {2, INF, INF, 0, 4},
        {7, INF, INF, 6, 0}
    };

    // Graph 3: Medium, undirected, negative weights, with negative cycle
    int V3 = 7;
    int graph3[7][7] = {
        {0, 4, 2, INF, INF, -3, INF},
        {4, 0, 1, 5, INF, INF, INF},
        {2, 1, 0, 8, 10, INF, INF},
        {INF, 5, 8, 0, 2, INF, INF},
        {INF, INF, 10, 2, 0, INF, INF},
        {-3, INF, INF, INF, INF, 0, -8},
        {INF, INF, INF, INF, INF, -8, 0}
    };

    printf("\nSession 9: Floyd and Warshall’s Algorithm for All-Pairs Shortest Path\n");
    printf("\nQ3: Implement Floyd-Warshall on Different Graphs\n");

    floydWarshall(V1, graph1, "Graph 1: Small, Undirected, Positive Weights");
    floydWarshall(V2, graph2, "Graph 2: Medium, Directed, Positive Weights");
    floydWarshall(V3, graph3, "Graph 3: Medium, Undirected, Negative Weights with Negative Cycle");

    return 0;
}
