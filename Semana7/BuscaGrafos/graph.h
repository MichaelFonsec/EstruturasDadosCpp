#ifndef GRAPH_H 
#define GRAPH_H 

#include "queue.h"

class Graph
{
private:
    int NULL_EDGE; // valor que representa a ausência de aresta
    int maxVertices; // número máximo de vértices
    int numVertices; // número atual de vértices
    Vertex* vertices; // array de vértices  
    int** edges; // matriz de adjacências
    bool* marks; // marks[i] marca se vertices [i] foi usado
    int getIndex(Vertex);
public:
    Graph( int max = 50, int null = 0); // construtor
    ~Graph(); // destrutor
     
    void addVertex(Vertex);
    void addEdge(Vertex, Vertex, int);
    int getWeight(Vertex, Vertex);
    void getAdjacents(Vertex, Queue&);
    void clearMarks();
    void marksVertex(Vertex);
    bool isMarked(Vertex);
    void printMatrix();
    
};

#endif