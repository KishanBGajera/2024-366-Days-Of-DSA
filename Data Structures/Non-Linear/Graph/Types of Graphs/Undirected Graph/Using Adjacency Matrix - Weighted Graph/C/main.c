#include "UndirectedWeightedGraph.h"

int main(int argc, char const *argv[])
{
    UndirectedWeightedGraph* uwg = getUndirectedWeightedGraph(5);
    addEdge(uwg, 1, 2, 10);
    addEdge(uwg, 1, 3, 1);

    int *neighbors = (int*)malloc(sizeof(int)*getDegree(uwg, 1));
    neighbors = getNeighbors(uwg, 1);

    for (int i = 0; i < getDegree(uwg, 1); i++)
    {
        printf("%d ", neighbors[i]);
    }
    
    printf("\n");

    removeEdge(uwg, 1, 2);

    printGraph(uwg);
    return 0;
}

