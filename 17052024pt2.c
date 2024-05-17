// Title: Graph Creation and Display
// Description: This program creates a graph with n vertices and adds edge information to the graph. It then displays the graph.

#include<stdio.h>
#include<stdlib.h>

// Function to initialize the graph with all edges set to 0
void createGraph(int n, int graph[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(int source, int destination, int n, int graph[n][n]) {
    graph[source][destination] = 1;
}

// Function to display the graph
void display(int n, int graph[n][n]) {
    int i, j;
    printf("Adjacency Matrix Representation of the Graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the total number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    createGraph(n, graph);
    addEdge(0, 2, n, graph);
    addEdge(0, 4, n, graph);
    addEdge(1, 2, n, graph);
    addEdge(1, 4, n, graph);
    addEdge(2, 1, n, graph);
    addEdge(2, 4, n, graph);
    addEdge(3, 4, n, graph);
    addEdge(4, 2, n, graph);
    addEdge(4, 3, n, graph);
    addEdge(4, 1, n, graph);
    addEdge(4, 0, n, graph);
    display(n, graph);
    return 0;
}
