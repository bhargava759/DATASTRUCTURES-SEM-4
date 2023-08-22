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

// Breadth-First Search traversal
void bfs(struct Graph* graph, int startVertex) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int queue[V];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from vertex %d: ", startVertex);
    while (front != rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        struct Node* curr = graph->array[vertex].head;
        while (curr != NULL) {
            if (!visited[curr->dest]) {
                visited[curr->dest] = true;
                queue[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
    printf("\n");
}

// Depth-First Search traversal
void dfsRecursive(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* curr = graph->array[vertex].head;
    while (curr != NULL) {
        if (!visited[curr->dest]) {
            dfsRecursive(graph, curr->dest, visited);
        }
        curr = curr->next;
    }
}

void dfs(struct Graph* graph, int startVertex) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsRecursive(graph, startVertex, visited);
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

    int startVertex;
    printf("Enter the starting vertex for BFS and DFS traversal: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);
    dfs(graph, startVertex);

    return 0;
}

