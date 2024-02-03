#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct UndirectedGraph {
    int totalNodes;
    int** adjMatrix;
    int* totalNeighbors;
};

typedef struct UndirectedGraph UndirectedGraph;

// prototypes
UndirectedGraph* getUndirectedGraph(int);
bool nodeExists(UndirectedGraph*, int);
void addEdge(UndirectedGraph*, int, int);
void removeEdge(UndirectedGraph*, int, int);
bool isEdge(UndirectedGraph*, int, int);
int* getNeighbors(UndirectedGraph*, int);
int getDegree(UndirectedGraph*, int);
void printUndirectedGraph(UndirectedGraph*);

UndirectedGraph* getUndirectedGraph(int totalNodes) {
    UndirectedGraph* undirectedGraph = (UndirectedGraph*)malloc(sizeof(UndirectedGraph));
    undirectedGraph->totalNodes = totalNodes;
    undirectedGraph->adjMatrix = (int**)malloc(sizeof(int*) * undirectedGraph->totalNodes);
    for (int i = 0; i < undirectedGraph->totalNodes; i++) {
        undirectedGraph->adjMatrix[i] = (int*)malloc(sizeof(int) * undirectedGraph->totalNodes);
        for (int j = 0; j < undirectedGraph->totalNodes; j++) {
            undirectedGraph->adjMatrix[i][j] = 0;
        }
    }
    undirectedGraph->totalNeighbors = (int*)calloc(sizeof(int), undirectedGraph->totalNodes);
    return undirectedGraph;
}

bool nodeExists(UndirectedGraph* undirectedGraph, int node) {
    return undirectedGraph->totalNodes > node;
}

void addEdge(UndirectedGraph* undirectedGraph, int u, int v) {
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return;
    } else {
        if (u != v && !undirectedGraph->adjMatrix[u][v]) {
            undirectedGraph->totalNeighbors[u] += 1;
            undirectedGraph->totalNeighbors[v] += 1;
        }
        undirectedGraph->adjMatrix[u][v] = 1;
        undirectedGraph->adjMatrix[v][u] = 1;
    }
}

void removeEdge(UndirectedGraph* undirectedGraph, int u, int v) {
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return;
    } else {
        if (isEdge(undirectedGraph, u, v)) {
            undirectedGraph->adjMatrix[u][v] = 0;
            undirectedGraph->adjMatrix[v][u] = 0;

            if (u != v) {
                undirectedGraph->totalNeighbors[u] -= 1;
                undirectedGraph->totalNeighbors[v] -= 1;
            }
        }
    }
}

bool isEdge(UndirectedGraph* undirectedGraph, int u, int v) {
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return false;
    } else {
        return (undirectedGraph->adjMatrix[u][v] == 1 && undirectedGraph->adjMatrix[v][u] == 1);
    }
}

int* getNeighbors(UndirectedGraph* undirectedGraph, int u) {
    if (!nodeExists(undirectedGraph, u)) {
        printf("Error: Node %d does not exist in the graph.\n", u);
        return NULL;
    } else {
        int* neighbors = (int*)malloc(sizeof(int) * undirectedGraph->totalNeighbors[u]);
        int counter = 0;
        for (int i = 0; i < undirectedGraph->totalNodes; i++) {
            if (u != i && undirectedGraph->adjMatrix[u][i] == 1) {
                neighbors[counter++] = i;
            }
        }
        return neighbors;
    }
}

int getDegree(UndirectedGraph* undirectedGraph, int u) {
    if (!nodeExists(undirectedGraph, u)) {
        printf("Error: Node %d does not exist in the graph. Cannot calculate degree.\n", u);
        return 0;
    } else {
        return undirectedGraph->totalNeighbors[u];
    }
}

void printGraph(UndirectedGraph* undirectedGraph) {
    printf("Graph (%d):\n", undirectedGraph->totalNodes);

    printf("    ");
    for (int i = 0; i < undirectedGraph->totalNodes; i++) {
        printf("%d ", i);
    }
    printf("\n  +");
    for (int i = 0; i < undirectedGraph->totalNodes; i++) {
        printf("--", i);
    }
    printf("-+\n");

    for (int i = 0; i < undirectedGraph->totalNodes; i++) {
        printf("%d | ", i);
        for (int j = 0; j < undirectedGraph->totalNodes; j++) {
            printf("%d ", undirectedGraph->adjMatrix[i][j]);
        }
        printf("| %d\n", undirectedGraph->totalNeighbors[i]);
    }
    printf("\n");
}

#endif
