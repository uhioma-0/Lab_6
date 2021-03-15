#include<stdio.h>
#include <stdbool.h>
#include"Vertex.h"
#include"LinkedList.c"
#define num 5
typedef struct AdjacencyList{
  int key;
  Vertex* next;
}AdjacencyList;

typedef struct Graph{
  AdjacencyList* source;
  AdjacencyList adjacencyList[num + 1];
    
}Graph;

void createGraph(Graph* myGraph,int key);
Vertex* addDirectedEdge(Vertex* v1,AdjacencyList* v2);
void addUndirectedEdge(AdjacencyList* v1,AdjacencyList* v2);
int getNumVertices(Graph* myGraph); //Returns the number of vertices in graph G
int getTotalEdges(Graph* myGraph); //Returns the total number of edges of graph G
int getNumEdges(Vertex* myAdjacencyList);//Returns the total number of edges of AdjecencyList
void getOutNeighbors(Graph* myGraph,AdjacencyList* myVertece); //Returns all vertices connected to node v with any edge
AdjacencyList* createAdecency(int key);
List* printNeighbour(Vertex* myVertece,List* LinkedListOne);
bool hasEdge(AdjacencyList* v1,AdjacencyList* v2);// Returns true (1) if there is an edge between v1 and v2 and false (0) otherwise
void getInNeighbors(Graph* myGraph,AdjacencyList* myVertece);//Returns a list of all vertices v' connected to node v with an edge (v', v)
void getNeighbors(Graph* myGraph,AdjacencyList* myVertece);// Returns all vertices connected to node v with any edge

