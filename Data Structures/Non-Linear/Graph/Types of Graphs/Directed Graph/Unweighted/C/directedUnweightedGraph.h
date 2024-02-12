#ifndef DIRECTEDUNWEIGHTEDGRAPH_H
#define DIRECTEDUNWEIGHTEDGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DirectedUnweightedGraph{
    int totalVertices;
    int totalEdges;
    int **adjList;
};

typedef struct DirectedUnweightedGraph DirectedUnweightedGraph;

// `totalVertices` = `n` : a graph will contain `0` to `n - 1` valued nodes/vertices
DirectedUnweightedGraph* getDUG(int totalVertices){
    DirectedUnweightedGraph* dug = (DirectedUnweightedGraph*)malloc(sizeof(DirectedUnweightedGraph));
    dug->totalVertices = totalVertices;
    dug->totalEdges = 0;
    dug->adjList = (int**)malloc(sizeof(int*)*dug->totalEdges);
    return dug;
}

bool isVertex(DirectedUnweightedGraph* dug, int u){
    return u < dug->totalVertices;
}

bool isEdge(DirectedUnweightedGraph* dug, int u, int v){
    for (int i = 0; i < dug->totalEdges; i++)
    {
        if(dug->adjList[i][0] == u && dug->adjList[i][1] == v){
            return true;
        }
    }
    return false;
}

int* searchEdge(DirectedUnweightedGraph* dug, int u, int v){
    for (int i = 0; i < dug->totalEdges; i++)
    {
        if(dug->adjList[i][0] == u && dug->adjList[i][1] == v){
            return dug->adjList[i];
        }
    }
    return NULL;
}

// direction `u` -> `v` (`u` to `v`)
void addEdge(DirectedUnweightedGraph* dug, int u, int v){
    if(u != v && !(isVertex(dug, u) && isVertex(dug, v))){
        return;
    }
    else{
        // no self-loop (edge) or duplicate edges
        if(isEdge(dug, u, v)){
            return;
        }
        else{
            dug->adjList = (int**)realloc(dug->adjList, sizeof(int*)*(++dug->totalEdges));
            dug->adjList[dug->totalEdges-1] = (int*)malloc(sizeof(int)*2);
            
            dug->adjList[dug->totalEdges-1][0] = u;
            dug->adjList[dug->totalEdges-1][1] = v;
        }
    }
}

void removeEdge(DirectedUnweightedGraph* dug, int u, int v){
    if(!(isVertex(dug, u) && isVertex(dug, v))){
        return;
    }
    else{
        int* edge = searchEdge(dug, u, v);
        if(!edge){
            return;
        }
        else{
            edge[0] = dug->adjList[dug->totalEdges-1][0];
            edge[1] = dug->adjList[dug->totalEdges-1][1];
        }
        dug->adjList = (int**)realloc(dug->adjList, sizeof(int*)*(--dug->totalEdges));
    }
}

void printGraph(DirectedUnweightedGraph* dug){
    for (int i = 0; i < dug->totalEdges; i++)
    {
        printf("Edge: %d -> %d\n", dug->adjList[i][0], dug->adjList[i][1]);
    }
    
}

#endif
