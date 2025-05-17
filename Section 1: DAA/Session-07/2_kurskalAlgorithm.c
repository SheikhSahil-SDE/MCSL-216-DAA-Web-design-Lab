#include <stdio.h>
#include <stdlib.h>

#define V 7 // Number of vertices
#define INF 99999 // Infinity

// Structure for an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure for the graph
typedef struct {
    Edge edges[V * V];
    int edgeCount;
} Graph;

// Disjoint-Set structure
typedef struct {
    int parent[V];
    int rank[V];
} DisjointSet;

// Initialize disjoint-set
void initDisjointSet(DisjointSet* ds) {
    for (int i = 0; i < V; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

// Find with path compression
int find(DisjointSet* ds, int i) {
    if (ds->parent[i] != i)
        ds->parent[i] = find(ds, ds->parent[i]);
    return ds->parent[i];
}

// Union by rank
void unionSets(DisjointSet* ds, int x, int y) {
    int xroot = find(ds, x);
    int yroot = find(ds, y);
    if (ds->rank[xroot] < ds->rank[yroot])
        ds->parent[xroot] = yroot;
    else if (ds->rank[xroot] > ds->rank[yroot])
        ds->parent[yroot] = xroot;
    else {
        ds->parent[yroot] = xroot;
        ds->rank[xroot]++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm
void kruskalMST(int graph[V][V]) {
    Graph g = { .edgeCount = 0 };
    DisjointSet ds;

    // Convert adjacency matrix to edge list (avoid duplicates)
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INF) {
                g.edges[g.edgeCount].src = i;
                g.edges[g.edgeCount].dest = j;
                g.edges[g.edgeCount].weight = graph[i][j];
                g.edgeCount++;
            }
        }
    }

    // Sort edges by weight
    qsort(g.edges, g.edgeCount, sizeof(Edge), compareEdges);

    printf("\nQ2: Kruskal’s Algorithm to Find Minimum Cost Spanning Tree\n");
    printf("Sorted Edges:\n");
    for (int i = 0; i < g.edgeCount; i++)
        printf("%c - %c: %d\n", 'A' + g.edges[i].src, 'A' + g.edges[i].dest, g.edges[i].weight);
    printf("\n");

    // Initialize disjoint-set
    initDisjointSet(&ds);

    Edge mst[V - 1]; // To store MST edges
    int mstEdgeCount = 0;
    int totalCost = 0;
    int step = 1;

    // Process each edge
    for (int i = 0; i < g.edgeCount && mstEdgeCount < V - 1; i++) {
        int u = g.edges[i].src;
        int v = g.edges[i].dest;
        int weight = g.edges[i].weight;

        int setU = find(&ds, u);
        int setV = find(&ds, v);

        printf("Step %d: Consider edge %c - %c (weight: %d)\n", step++, 'A' + u, 'A' + v, weight);
        if (setU != setV) {
            // No cycle, add to MST
            mst[mstEdgeCount++] = g.edges[i];
            totalCost += weight;
            unionSets(&ds, setU, setV);
            printf("Added to MST\n");
            printf("Current MST Edges: ");
            for (int j = 0; j < mstEdgeCount; j++)
                printf("(%c - %c) ", 'A' + mst[j].src, 'A' + mst[j].dest);
            printf("\n\n");
        } else {
            printf("Cycle detected, skipped\n\n");
        }
    }

    // Print the MST
    printf("Final Minimum Cost Spanning Tree:\n");
    for (int i = 0; i < mstEdgeCount; i++)
        printf("%c - %c: %d\n", 'A' + mst[i].src, 'A' + mst[i].dest, mst[i].weight);
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

    kruskalMST(graph);
    return 0;
}
