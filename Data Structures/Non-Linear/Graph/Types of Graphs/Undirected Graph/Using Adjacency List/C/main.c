#include "UndirectedGraph.h"

int main(int argc, char const *argv[])
{
    UndirectedGraph* undirectedGraph = getUndirectedGraph(5);
    addEdge(undirectedGraph, 1, 2);
    addEdge(undirectedGraph, 2, 3);
    addEdge(undirectedGraph, 1, 3);
    addEdge(undirectedGraph, 1, 4);
    printGraphEdges(undirectedGraph);

    int* neighbors = getNeighbors(undirectedGraph, 1);
    for (int i = 0; i < getDegree(undirectedGraph, 1); i++)
    {
        printf("%d ", neighbors[i]);
    }

    return 0;
}

