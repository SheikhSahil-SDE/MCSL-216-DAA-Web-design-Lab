// Q1 Find the shortest path from A to the rest of vertices
#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices
#define INF 99999 // Infinity

// Find the vertex with minimum distance value, from the set of vertices not yet visited
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the path from source to vertex j using the predecessor array
void printPath(int pred[], int j) {
    if (pred[j] == -1) {
        printf("%c", 'A' + j);
        return;
    }
    printPath(pred, pred[j]);
    printf(" -> %c", 'A' + j);
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Shortest distances from src
    int visited[V];  // Visited vertices
    int pred[V];     // Predecessor array for paths

    // Initialize distances, visited, and predecessors
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        pred[i] = -1;
    }
    dist[src] = 0;

    printf("\nQ2: Dijkstra’s Algorithm from Source B\n");
    printf("\nInitial Distances: ");
    for (int i = 0; i < V; i++)
        printf("%c: %d ", 'A' + i, dist[i] == INF ? -1 : dist[i]);
    printf("\n\n");

    // Process all vertices
    for (int count = 0; count < V; count++) {
        // Pick the minimum distance vertex from unvisited set
        int u = minDistance(dist, visited);
        if (u == -1) break;

        // Mark the vertex as visited
        visited[u] = 1;

        printf("Step %d: Visit vertex %c\n", count + 1, 'A' + u);
        printf("Visited: ");
        for (int v = 0; v < V; v++)
            printf("%c: %s ", 'A' + v, visited[v] ? "T" : "F");
        printf("\n");

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
                printf("Update distance to %c: %d (via %c)\n", 'A' + v, dist[v], 'A' + u);
            }
        }

        printf("Distances: ");
        for (int i = 0; i < V; i++)
            printf("%c: %d ", 'A' + i, dist[i] == INF ? -1 : dist[i]);
        printf("\n\n");
    }

    // Print final results
    printf("Final Shortest Paths from B:\n");
    for (int i = 0; i < V; i++) {
        printf("To %c: Distance = %d, Path = ", 'A' + i, dist[i]);
        printPath(pred, i);
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Graph adjacency matrix (same as Q1)
    int graph[V][V] = {
        {0, 4, 2, INF, INF},      // A
        {4, 0, 1, 5, INF},       // B
        {2, 1, 0, 8, 10},        // C
        {INF, 5, 8, 0, 2},       // D
        {INF, INF, 10, 2, 0}     // E
    };

    dijkstra(graph, 1); // Source is B (vertex 1)
    return 0;
}