#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct UndirectedGraph
{
    int total_nodes;
    int total_edges;
    int** edges;
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

UndirectedGraph* getUndirectedGraph(int total_nodes){
    UndirectedGraph* undirectedGraph = (UndirectedGraph*)malloc(sizeof(UndirectedGraph));
    undirectedGraph->total_nodes = total_nodes;
    undirectedGraph->total_edges = 0;
    undirectedGraph->edges = (int**)malloc(sizeof(int*)*total_nodes);
    return undirectedGraph;
}

bool nodeExists(UndirectedGraph* undirectedGraph, int node){
    return undirectedGraph->total_nodes > node;
}

bool isEdge(UndirectedGraph* undirectedGraph, int u, int v){
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return false;
    }
    else{
        for (int i = 0; i < undirectedGraph->total_edges; i++)
        {
            if(
                (undirectedGraph->edges[i][0] == u && undirectedGraph->edges[i][1] == v) ||
                (undirectedGraph->edges[i][1] == u && undirectedGraph->edges[i][0] == v)
            ){
                return true;
            }
        }
        return false;
    }
}

void addEdge(UndirectedGraph* undirectedGraph, int u, int v){
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return;
    }
    else {
        if(!isEdge(undirectedGraph, u, v)){
            undirectedGraph->edges = realloc(undirectedGraph->edges, sizeof(int*)*(++undirectedGraph->total_edges));
            undirectedGraph->edges[undirectedGraph->total_edges-1] = (int*)malloc(sizeof(int)*2);
            undirectedGraph->edges[undirectedGraph->total_edges-1][0] = u;
            undirectedGraph->edges[undirectedGraph->total_edges-1][1] = v;
            printf("Edge (%d, %d) added\n", u, v);
        }
        else{
            printf("EdgeAlreadyExistsException: No need to add reversed edge, since it is an undirected graph.\n");
        }
    }
}

void removeEdge(UndirectedGraph* undirectedGraph, int u, int v) {
    if (!nodeExists(undirectedGraph, u) || !nodeExists(undirectedGraph, v)) {
        printf("Error: Node(s) %d or %d does not exist in the graph.\n", u, v);
        return;
    } else {
        if (isEdge(undirectedGraph, u, v)) {
            for (int i = 0; i < undirectedGraph->total_edges; i++) {
                if ((undirectedGraph->edges[i][0] == u && undirectedGraph->edges[i][1] == v) ||
                    (undirectedGraph->edges[i][0] == v && undirectedGraph->edges[i][1] == u)) {
                    free(undirectedGraph->edges[i]);
                    undirectedGraph->edges[i] = undirectedGraph->edges[undirectedGraph->total_edges - 1];
                    undirectedGraph->total_edges--;
                    undirectedGraph->edges = realloc(undirectedGraph->edges, sizeof(int*) * undirectedGraph->total_edges);
                    break;
                }
            }
        }
    }
}

int getDegree(UndirectedGraph* undirectedGraph, int u){
    int degree = 0;
   
    for (int i = 0; i < undirectedGraph->total_edges; i++)
    {
        if(undirectedGraph->edges[i][0] != undirectedGraph->edges[i][1] && (undirectedGraph->edges[i][0] == u || undirectedGraph->edges[i][1] == u)){
            degree++;
        }
    }
    
    return degree;
}

int* getNeighbors(UndirectedGraph* undirectedGraph, int u){
    int total_neighbors = getDegree(undirectedGraph, u);
    int* neighbors = (int*)malloc(sizeof(int)*total_neighbors);

    int counter = 0;
    for (int i = 0; i < undirectedGraph->total_edges; i++)
    {
        if(undirectedGraph->edges[i][0] != undirectedGraph->edges[i][1] && (undirectedGraph->edges[i][0] == u || undirectedGraph->edges[i][1] == u)){
            neighbors[counter++] = undirectedGraph->edges[i][0] == u ? undirectedGraph->edges[i][1] : undirectedGraph->edges[i][1];
        }
    }
    
    return neighbors;
}

void printGraphEdges(UndirectedGraph* undirectedGraph){
    printf("Graph:\n");
    for (int i = 0; i < undirectedGraph->total_edges; i++)
    {
        printf("\tEdge: (%d, %d)\n", undirectedGraph->edges[i][0], undirectedGraph->edges[i][1]);
    }   
}

#endif
