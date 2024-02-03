#include "UndirectedGraph.h"

int main() {
    UndirectedGraph* graph = getUndirectedGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("Neighbors of node 3: ");
    int* neighbors = getNeighbors(graph, 3);
    if (neighbors != NULL) {
        for (int i = 0; i < getDegree(graph, 3); i++) {
            printf("%d ", neighbors[i]);
        }
        free(neighbors);
    }
    printf("\n\n");

    removeEdge(graph, 1, 3);

    printGraph(graph);

    return 0;
}
