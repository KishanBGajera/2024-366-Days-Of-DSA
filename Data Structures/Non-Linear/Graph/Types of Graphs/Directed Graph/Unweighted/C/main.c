#include "directedUnweightedGraph.h"

int main(){
    DirectedUnweightedGraph* dug = getDUG(5);
    addEdge(dug, 1, 2);
    addEdge(dug, 2, 1);
    addEdge(dug, 2, 3);

    removeEdge(dug, 1, 2);

    printGraph(dug);
    return 0;
}
