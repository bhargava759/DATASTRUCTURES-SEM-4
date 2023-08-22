#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

void printAdjacencyMatrix(int graph[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix (%d x %d) of the graph:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printAdjacencyMatrix(graph);

    int totalEdges = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] == 1)
                totalEdges++;
        }
    }

    printf("Minimum edges required to traverse all vertices: %d\n", totalEdges);

    return 0;
}

