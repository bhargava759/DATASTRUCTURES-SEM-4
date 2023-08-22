#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5 // Number of vertices

// A structure to represent an adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// A structure to represent a graph
struct Graph {
    struct AdjList* array;
};

// Create a new adjacency list node
struct Node* newAdjListNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Depth-First Search to print all paths
void printAllPathsDFS(struct Graph* graph, int src, int dest, bool visited[], int path[], int pathLen) {
    visited[src] = true;
    path[pathLen] = src;
    pathLen++;

    if (src == dest) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        struct Node* curr = graph->array[src].head;
        while (curr != NULL) {
            if (!visited[curr->dest]) {
                printAllPathsDFS(graph, curr->dest, dest, visited, path, pathLen);
            }
            curr = curr->next;
        }
    }

    visited[src] = false;
}

void printAllPaths(struct Graph* graph, int src, int dest) {
    bool visited[V];
    int path[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    printAllPathsDFS(graph, src, dest, visited, path, 0);
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter %d edges (source destination):\n", numEdges);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int src, dest;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    printf("Enter destination vertex: ");
    scanf("%d", &dest);

    printf("Valid paths from %d to %d:\n", src, dest);
    printAllPaths(graph, src, dest);

    return 0;
}

