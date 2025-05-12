<!-- Session 9: Floyd and Warshall’s Algorithm for All Pair Shortest Path
Algorithms -->

## Q1. Apply the Floyd and Warshall’s algorithm for the following graph. Show the matrix 𝐷^5 of the graph and find out the shortest path.

# Floyd-Warshall Algorithm Implementation
# Function to implement Floyd-Warshall Algorithm
def floyd_warshall(graph):
    num_vertices = len(graph)
    dist = [[float('inf')] * num_vertices for _ in range(num_vertices)]

    # Initialize the solution matrix same as input graph matrix
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i == j:
                dist[i][j] = 0
            elif graph[i][j] != 0:
                dist[i][j] = graph[i][j]

    # Adding vertices individually
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist

# Example graph as adjacency matrix (replace with the given graph)
graph = [
    [0, 3, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0],
    [0, 0, 0, 7, 0, 2],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 2, 0, 3],
    [0, 0, 0, 0, 0, 0]
]

# Compute shortest paths
shortest_paths = floyd_warshall(graph)

# Print the D^5 matrix (shortest paths)
print("D^5 Matrix (Shortest Paths):")
for row in shortest_paths:
    print(row)

# Placeholder for Q2 graph
# Replace the graph below with the specific graph for Q2
graph_q2 = [
    # Example graph (replace with the actual graph for Q2)
    [0, 8, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [4, 0, 0, 2, 0],
    [0, 0, 0, 0, 3],
    [0, 0, 0, 0, 0]
]

# Compute shortest paths for Q2
d5_q2 = floyd_warshall(graph_q2)

# Print the D^5 matrix for Q2
print("D^5 Matrix for Q2 (Shortest Paths):")
for row in d5_q2:
    print(row)

## Q2. Apply the Floyd and Warshall’s algorithm to compute the shortest path to the following graph. Compute 𝐷^5 matrix of the graph.

## Q3. Implement the all pair shortest path algorithms using different graphs.

# Example graphs for Q3
# Graph 1
example_graph_1 = [
    [0, 5, 0, 10],
    [0, 0, 3, 0],
    [0, 0, 0, 1],
    [0, 0, 0, 0]
]

# Graph 2
example_graph_2 = [
    [0, 1, 0, 0, 0],
    [0, 0, 2, 0, 0],
    [0, 0, 0, 3, 0],
    [0, 0, 0, 0, 4],
    [0, 0, 0, 0, 0]
]

# Graph 3
example_graph_3 = [
    [0, 2, 0, 0],
    [0, 0, 3, 0],
    [0, 0, 0, 1],
    [1, 0, 0, 0]
]

# Compute shortest paths for each graph
print("Shortest Paths for Graph 1:")
shortest_paths_1 = floyd_warshall(example_graph_1)
for row in shortest_paths_1:
    print(row)

print("\nShortest Paths for Graph 2:")
shortest_paths_2 = floyd_warshall(example_graph_2)
for row in shortest_paths_2:
    print(row)

print("\nShortest Paths for Graph 3:")
shortest_paths_3 = floyd_warshall(example_graph_3)
for row in shortest_paths_3:
    print(row)


