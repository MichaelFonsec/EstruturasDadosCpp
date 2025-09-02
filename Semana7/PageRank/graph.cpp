#include <iostream>
#include "graph.h"

Graph::Graph(int max, int null_edge) {
  NULL_EDGE   = null_edge; 
  maxVertices = max;  
  numVertices = 0;
  vertices = new Vertex[maxVertices];
  marks = new bool[maxVertices];
  edges = new int* [maxVertices];
  
  // Criando matriz de adjacências
  for (int row = 0; row < maxVertices; row++)
    edges[row] = new int[maxVertices];  
  // Populando matriz de adjacências com valor nulo     
  for (int row = 0; row < maxVertices; row++)
    for (int col = 0; col < maxVertices; col++)
      edges[row][col] = NULL_EDGE;
}

Graph::~Graph() {
  delete [] vertices;
  delete [] marks;
  for (int row = 0; row < maxVertices; row++){
    delete [] edges[row];
  }
  delete [] edges;
}

int Graph::getIndex(Vertex vertex) {
  int index = 0;
  while (!(vertex.getNome() == vertices[index].getNome())){
    index++;
  }
  return index;
}

void Graph::addVertex(Vertex vertex){
  vertices[numVertices] = vertex;
  numVertices++;
}

void Graph::addEdge(Vertex fromVertex,
		    Vertex toVertex,
		    int weight){
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);

  edges[row][col] = weight;
  // Remover se grafo direcionado. 
}

int Graph::getWeight(Vertex fromVertex,
		     Vertex toVertex){
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);
  return edges[row][col];
}

void Graph::getAdjacents(Vertex vertex,
			 Queue &adjVertices){
  int fromIndex;
  int toIndex;
  fromIndex = getIndex(vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      // Uma cópia do elemento é adicionada no array.
      adjVertices.enqueue(vertices[toIndex]);
}

void Graph::clearMarks(){
  for (int i = 0; i < numVertices; i++)
    marks[i] = false;    
}
void Graph::markVertex(Vertex vertex){
  int index = getIndex(vertex);
  marks[index] = true;
}
bool Graph::isMarked(Vertex vertex){
  int index = getIndex(vertex);
  return marks[index];  
}

void Graph::printMatrix(){
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      std::cout << edges[i][j] << ",";
    }
    std::cout << std::endl;
  }
}

void Graph::getPageRanks(float* pageRanks){
  // Computando graus de saída
  int* outputDegree = new int[numVertices]; // Grau de saída de cada vértice
  for (int i = 0; i < numVertices; i++) {
    outputDegree[i] = 0; // Inicializando
    for (int j = 0; j < numVertices; j++) {
      if (edges[i][j] != NULL_EDGE) { // Há uma aresta saindo de i
	outputDegree[i] += 1; // Incrementa grau de saída
      }
    }
  }
  
  // Computando pageRanks.
  float* pr_previous = new float[numVertices]; // PageRank do passo anterior
  float* pr          = new float[numVertices]; // PageRank do passo atual
  
  // Inicializando
  for (int i = 0; i < numVertices; i++) { 
    pr_previous[i] = 1.0/numVertices;
  }

  // Fator de amortecimento
  float d = .85; 
  for (int numIter = 0; numIter < 100; numIter++){    // 100 iterações
    // Passo Iterativo
    for (int i = 0; i< numVertices; i++){ // Para cada vértice
      // Calculo do PageRank
      pr[i] = 0;
      for (int j = 0; j < numVertices; j++){
          // Para cada vértice j que aponta para i
	if (edges[j][i] != NULL_EDGE){
    // Incrementa PageRank de i
	  pr[i] += pr_previous[j]/outputDegree[j];
	}
      }

      // Aplica fator de amortecimento
      pr[i] = (1-d)/numVertices + d*pr[i];
    }
    // Atualiza pr_previous
    for (int i = 0; i< numVertices; i++){
      pr_previous[i] = pr[i];
    }
  }
// Copiando resultado para o array de saída
  for (int i = 0; i< numVertices; i++){
    pageRanks[i] = pr[i];
  }

  // Liberando memória
  delete [] pr_previous;
  delete [] pr;
  delete [] outputDegree;
  
}
