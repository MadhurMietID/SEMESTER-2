// a C program to create a graph with 'n' vertices and add three edges to the graph. It then displays the graph data.


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int source, destination;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    struct Edge* edgeList;
};

// Function to create a graph with n vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->edgeList = (struct Edge*)malloc(3 * sizeof(struct Edge)); // Allocating memory for three edges

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    if (graph->numEdges < 3) { // Checking if there is space to add more edges
        graph->edgeList[graph->numEdges].source = source;
        graph->edgeList[graph->numEdges].destination = destination;
        graph->numEdges++;
    } else {
        printf("Cannot add more edges. Limit reached.\n");
    }
}

// Function to display the graph data
void displayGraph(struct Graph* graph) {
    printf("Vertices: %d\n", graph->numVertices);
    printf("Edges:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("(%d, %d)\n", graph->edgeList[i].source, graph->edgeList[i].destination);
    }
}

int main() {
    int n; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    // Adding three edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Displaying the graph data
    displayGraph(graph);

    return 0;
}

/*
Explanation:

1. We include necessary header files `stdio.h` and `stdlib.h`.
2. We define the maximum number of vertices as `MAX_VERTICES`.
3. We define structures `Edge` to represent an edge and `Graph` to represent a graph.
4. The `createGraph` function allocates memory for a graph with 'n' vertices and initializes its fields.
5. The `addEdge` function adds an edge to the graph if there is space available.
6. The `displayGraph` function prints the number of vertices and all the edges of the graph.
7. In the `main` function, we take input for the number of vertices.
8. We create a graph using `createGraph`.
9. We add three edges to the graph using the `addEdge` function.
10. Finally, we display the graph data using the `displayGraph` function.


output --

Enter the number of vertices: 4
Vertices: 4
Edges:
(0, 1)
(1, 2)
(2, 3)

     */                     