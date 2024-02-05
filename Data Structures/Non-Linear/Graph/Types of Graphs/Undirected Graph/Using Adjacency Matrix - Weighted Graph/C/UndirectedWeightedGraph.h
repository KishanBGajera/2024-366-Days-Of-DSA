#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct UndirectedWeightedGraph
{
    int totalNodes;
    int** matrix;
    int* totalNeighbors;
};

typedef struct UndirectedWeightedGraph UndirectedWeightedGraph;

UndirectedWeightedGraph* getUndirectedWeightedGraph(int totalNodes){
    UndirectedWeightedGraph* undirectedWeightedGraph = (UndirectedWeightedGraph*)malloc(sizeof(UndirectedWeightedGraph));

    undirectedWeightedGraph->totalNodes = totalNodes;
    undirectedWeightedGraph->totalNeighbors = (int*)malloc(sizeof(int)*totalNodes);

    undirectedWeightedGraph->matrix = (int**)malloc(sizeof(int*)*totalNodes);
    for (int i = 0; i < totalNodes; i++)
    {
        undirectedWeightedGraph->totalNeighbors[i] = 0;
        undirectedWeightedGraph->matrix[i] = (int*)malloc(sizeof(int)*totalNodes);
        for (int j = 0; j < totalNodes; j++)
        {
            undirectedWeightedGraph->matrix[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    return undirectedWeightedGraph;
}

bool isNode(UndirectedWeightedGraph* uwg, int u){
    return uwg->totalNodes > u;
}

bool isEdge(UndirectedWeightedGraph* uwg, int u, int v){
    return uwg->matrix[u][v] != INT_MAX;
}

void addEdge(UndirectedWeightedGraph* uwg, int u, int v, int weight){
    if(!isNode(uwg, u) || !isNode(uwg, v)){
        return;
    }
    else{
        if(u == v){
            printf("Error: Can't add edge-to-self\n");
            exit(0);
            return;
        }
        else{
            uwg->matrix[u][v] = weight;
            uwg->matrix[v][u] = weight;
            uwg->totalNeighbors[u] += 1;
            uwg->totalNeighbors[v] += 1;
        }
    }
}

void removeEdge(UndirectedWeightedGraph* uwg, int u, int v){
    if(!isNode(uwg, u) || !isNode(uwg, v)){
        printf("Error: Edge doesn't exist\n");
        return;
    }
    else{
        if(isEdge(uwg, u, v)){
            uwg->matrix[u][v] = INT_MAX;
            uwg->matrix[v][u] = INT_MAX;
            uwg->totalNeighbors[u] -= 1;
            uwg->totalNeighbors[v] -= 1;
        }
    }
}

int getDegree(UndirectedWeightedGraph* uwg, int u){
    if(!isNode(uwg, u)){
        return 0;
    }
    else{
        return uwg->totalNeighbors[u];
    }
}

int* getNeighbors(UndirectedWeightedGraph* uwg, int u){
    int* neighbors = (int*)malloc(sizeof(int)*getDegree(uwg, u));
    int counter = 0;
    for (int i = 0; i < uwg->totalNodes; i++)
    {
        if(uwg->matrix[u][i] != INT_MAX && uwg->matrix[u][i] != 0){
            neighbors[counter++] = i;
        }
    }
    return neighbors;
}

void printGraph(UndirectedWeightedGraph* uwg){
    for (int i = 0; i < uwg->totalNodes; i++)
    {
        for (int j = 0; j < uwg->totalNodes; j++)
        {
            if(uwg->matrix[i][j] == INT_MAX){
                printf("-- ");
            }
            else{
                // two-digits specific
                printf("%02d ", uwg->matrix[i][j]);
            }
        }
        printf("\n");  
    }
}

#endif
