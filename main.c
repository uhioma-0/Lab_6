#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
#include"ListRepresentation.c"

int main(){
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    createGraph(newGraph,num);

    //adding directional egdes between nodes
    newGraph->adjacencyList[1].next=addDirectedEdge(newGraph->adjacencyList[1].next,&newGraph->adjacencyList[2]);
    newGraph->adjacencyList[2].next=addDirectedEdge(newGraph->adjacencyList[2].next,&newGraph->adjacencyList[4]);
    newGraph->adjacencyList[3].next=addDirectedEdge(newGraph->adjacencyList[3].next,&newGraph->adjacencyList[4]);
    newGraph->adjacencyList[4].next=addDirectedEdge(newGraph->adjacencyList[4].next,&newGraph->adjacencyList[5]);
    newGraph->adjacencyList[5].next=addDirectedEdge(newGraph->adjacencyList[5].next,&newGraph->adjacencyList[3]);


    //adding NON-directional egdes between nodes
    addUndirectedEdge(&newGraph->adjacencyList[1],&newGraph->adjacencyList[3]);
    int NumVerteces= getNumVertices(newGraph);
    int NumEdges= getTotalEdges(newGraph);
/*     getOutNeighbors(newGraph,&newGraph->adjacencyList[1]);
    getInNeighbors(newGraph,&newGraph->adjacencyList[1]); */
    getOutNeighbors(newGraph,&newGraph->adjacencyList[5]);
    getInNeighbors(newGraph,&newGraph->adjacencyList[5]);
    getNeighbors(newGraph,&newGraph->adjacencyList[5]);
    getNeighbors(newGraph,&newGraph->adjacencyList[1]);
    return 0;
} 