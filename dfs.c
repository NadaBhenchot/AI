#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// DFS function
void dfs(int adj[][MAX], int start, int V, bool visited[]) {
    // Mark the current node as visited and print it
    visited[start] = true;
    printf("%d ", start);

    // Visit all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(adj, i, V, visited);  // Recursively visit adjacent vertices
        }
    }
}

// Function to add an edge in the adjacency matrix
void addEdge(int adj[][MAX], int a, int b) {
    adj[a][b] = 1;
}

int main() {
    int V = 5;
    int adj[MAX][MAX] = {0};  // Adjacency matrix
    bool visited[MAX] = {false};

    // Add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Perform DFS
    dfs(adj, 0, V, visited);

    return 0;
}
