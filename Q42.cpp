#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6 // Number of vertices

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

// Depth-First Search for topological sort
void topologicalSortDFS(struct Graph* graph, int v, bool visited[], int stack[], int* stackIndex) {
    visited[v] = true;

    struct Node* curr = graph->array[v].head;
    while (curr != NULL) {
        if (!visited[curr->dest]) {
            topologicalSortDFS(graph, curr->dest, visited, stack, stackIndex);
        }
        curr = curr->next;
    }

    stack[(*stackIndex)++] = v;
}

void topologicalSort(struct Graph* graph) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int stack[V];
    int stackIndex = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortDFS(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Order: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
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

    printf("Given Graph:\n");
    for (int i = 0; i < V; i++) {
        struct Node* curr = graph->array[i].head;
        printf("Adjacency list of vertex %d: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->dest);
            curr = curr->next;
        }
        printf("NULL\n");
    }

    topologicalSort(graph);

    return 0;
}

