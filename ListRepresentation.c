#include<stdio.h>
#include<stdlib.h>
#include"ListRepresentation.h"


AdjacencyList* createAdecency(int n){
    struct AdjacencyList* newAdjacencyList=(struct AdjacencyList*)malloc(sizeof(struct AdjacencyList));;
    newAdjacencyList->key=n;
    newAdjacencyList->next=NULL;
    return newAdjacencyList;
}

void attachVertexToGraph(Graph* myGraph,int key){
    for(int i= 1;i<=key;i++)
        myGraph->adjacencyList[i]=*createAdecency(i);
    
}
void createGraph(Graph* myGraph,int key){
    myGraph->source= createAdecency(1);
    attachVertexToGraph(myGraph,key);
   
}

 Vertex* addDirectedEdge(Vertex* v1,AdjacencyList* v2){
    /* Vertex* tempOne=(struct Vertex*)malloc(sizeof(struct Vertex));
    tempOne=v1->next; */
    if(v1!=NULL)
        v1->next=addDirectedEdge(v1->next,v2);
    else{
        v1=(struct Vertex*)malloc(sizeof(struct Vertex));
        v1->key=v2->key;
        v1->next=NULL;
        return v1;
    }
    return v1;
    
}

void addUndirectedEdge(AdjacencyList* v1,AdjacencyList* v2){
    v1->next=addDirectedEdge(v1->next,v2);
    v2->next=addDirectedEdge(v2->next,v1);
} 

int getNumVertices(Graph* myGraph){
    return (sizeof(myGraph->adjacencyList) /sizeof(myGraph->adjacencyList[0])) - 1;
}

int getNumEdges(Vertex* myAdjacencyList){
    int NumEdges=0;
    if(myAdjacencyList!=NULL)
    {
        NumEdges=NumEdges + getNumEdges(myAdjacencyList->next);
    }
    return NumEdges + 1;
}
int getTotalEdges(Graph* myGraph){
    int totalEdges = 0;
    int numVerteces =getNumVertices(myGraph);
    for (int i = 1; i <= numVerteces; i++)
    {
        totalEdges= totalEdges + getNumEdges(myGraph->adjacencyList[i].next) - 1;
    }
    return totalEdges;
    
}
void getOutNeighbors(Graph* myGraph,AdjacencyList* myVertece){
    List* LinkedListOne = GetNewLink();
    int size = getNumVertices(myGraph);
    int i;
    for (i=1;i<=size;i++){
        if(myVertece->key ==myGraph->adjacencyList[i].key)
            break;
    }
    Vertex* tempOne=(struct Vertex*)malloc(sizeof(struct Vertex));
    tempOne=myGraph->adjacencyList[i].next;
    while (tempOne!=NULL)
    {
        LinkedListOne=printNeighbour(tempOne,LinkedListOne);
        tempOne=tempOne->next;
    }
    printLinkedList(LinkedListOne);
    free(LinkedListOne);
    free(tempOne);
    
}
bool hasEdge(AdjacencyList* v1,AdjacencyList* v2){
    Vertex* tempOne=(struct Vertex*)malloc(sizeof(struct Vertex));
    tempOne=v1->next;
    while(tempOne !=NULL){
        if (tempOne->key == v2->key)
            return true;
        tempOne=tempOne->next;
    }
    return false;
}
void getInNeighbors(Graph* myGraph,AdjacencyList* myVertece){
    List* LinkedListOne = GetNewLink();
    int size = getNumVertices(myGraph);
    for (int i=1;i<=size;i++){
        if (hasEdge(&myGraph->adjacencyList[i],myVertece)==true)
            insert (LinkedListOne,GetNewNode(myGraph->adjacencyList[i].key));
    }
    printLinkedList(LinkedListOne);
    free(LinkedListOne);
}

void getNeighbors(Graph* myGraph,AdjacencyList* myVertece){
    List* LinkedListOne = GetNewLink();
    int size = getNumVertices(myGraph);
    for (int i=1;i<=size;i++){
        if (hasEdge(&myGraph->adjacencyList[i],myVertece)==true)
            insert (LinkedListOne,GetNewNode(myGraph->adjacencyList[i].key));
    }
    int i;
    for (i=1;i<=size;i++){
        if(myVertece->key ==myGraph->adjacencyList[i].key)
            break;
    }
    Vertex* tempOne=(struct Vertex*)malloc(sizeof(struct Vertex));
    tempOne=myGraph->adjacencyList[i].next;
    while (tempOne!=NULL)
    {
        if (SearchInDoubleLinkedList(LinkedListOne,tempOne->key)==0)
            LinkedListOne=printNeighbour(tempOne,LinkedListOne);
        tempOne=tempOne->next; 
    }
    printLinkedList(LinkedListOne);
    free(LinkedListOne);
    free(tempOne);

}

List* printNeighbour(Vertex* myVertece,List* LinkedListOne){
    insert(LinkedListOne,GetNewNode(myVertece->key));
    return LinkedListOne;

}