#include <iostream>
#include "graph.h"
#include "stack.h"
#include "queue.h"

using namespace std;

// Implementação da busca em profundidade
void depthFirstSearch(Graph &graph, Vertex origem, Vertex destino)
{
    Stack vertexStack;  // Pilha para armazenar os vértices a serem visitados
    bool found = false; // Indica se o destino foi encontrado
    Vertex vertex;
    graph.clearMarks();       // Limpa as marcações dos vértices
    vertexStack.push(origem); // Empilha o vértice de origem
    do
    {
        vertex = vertexStack.pop(); // Desempilha o vértice do topo da pilha
        if (vertex.getNome() == destino.getNome())
        { // Verifica se é o destino
            cout << "Encontrado: " << vertex.getNome() << ";" << endl;
            found = true; // Marca que o destino foi encontrado
        }
        else
        {
            if (!graph.isMarked(vertex))
            {
                graph.marksVertex(vertex); // Marca o vértice como visitado
                cout << "Visitando: " << vertex.getNome() << endl;
                Queue adjacents;                       // Fila para armazenar os vértices adjacentes
                graph.getAdjacents(vertex, adjacents); // Obtém os vértices adjacentes
                while (!adjacents.isEmpty())
                {
                    Vertex adjacent = adjacents.dequeue(); // Desenfileira um vértice adjacente
                    if (!graph.isMarked(adjacent))
                    {
                        cout << "Empilhando: " << adjacent.getNome() << endl;
                        vertexStack.push(adjacent); // Empilha o vértice adjacente
                    }
                }
            }
        }
    } while (!vertexStack.isEmpty() && !found); // Continua enquanto a pilha não estiver vazia e o destino não for encontrado
    if (!found)
    {
        cout << "Caminho não localizado." << endl;
    }
}

void breadthFirstSearch(Graph &graph, Vertex origem, Vertex destino)
{
    Queue vertexQueue;
    bool found = false;
    Vertex vertex;
    graph.clearMarks();
    vertexQueue.enqueue(origem);
    do
    {
        vertex = vertexQueue.dequeue();
        if (vertex.getNome() == destino.getNome())
        {
            cout << "Encontrado: " << vertex.getNome() << ";" << endl;
            found = true;
        }
        else
        {
            if (!graph.isMarked(vertex))
            {
                graph.marksVertex(vertex);
                cout << "Visitando: " << vertex.getNome() << endl;
                Queue adjacents;
                graph.getAdjacents(vertex, adjacents);
                while (!adjacents.isEmpty())
                {
                    Vertex adjacent = adjacents.dequeue();
                    if (!graph.isMarked(adjacent))
                    {
                        cout << "Enfileirando: " << adjacent.getNome() << endl;
                        vertexQueue.enqueue(adjacent);
                    }
                }
            }
        }
    } while (!vertexQueue.isEmpty() && !found);
    if (!found)
    {
        cout << "Caminho não localizado." << endl;
    }
}


int main() {
  Graph graph;

  Vertex a = Vertex("a");
  Vertex b = Vertex("b");
  Vertex c = Vertex("c");
  Vertex d = Vertex("d");
  Vertex e = Vertex("e");
  Vertex f = Vertex("f");
  Vertex g = Vertex("g");
  Vertex h = Vertex("h");
  Vertex i = Vertex("i");

  graph.addVertex(a);
  graph.addVertex(b);
  graph.addVertex(c);
  graph.addVertex(d);
  graph.addVertex(e);
  graph.addVertex(f);
  graph.addVertex(g);
  graph.addVertex(h);
  graph.addVertex(i);
  
  graph.addEdge(a, b, 2);
  graph.addEdge(a, g, 4);
  graph.addEdge(b, c, 4);
  graph.addEdge(b, d, 2);
  graph.addEdge(b, g, 6);
  graph.addEdge(c, d, 3);
  graph.addEdge(d, e, 5);
  graph.addEdge(d, f, 3);
  graph.addEdge(e, f, 3);
  graph.addEdge(e, h, 4);
  graph.addEdge(f, g, 5);
  graph.addEdge(f, h, 4);
  graph.addEdge(g, i, 2);
  graph.addEdge(h, i, 3);

  graph.printMatrix(); 

  /******************************************************************
    Obtendo os vértices adjacentes a um dado nó.
  *******************************************************************/
  Queue adjacents;
  graph.getAdjacents(a, adjacents);
  while (!adjacents.isEmpty()) {
    cout << adjacents.dequeue().getNome() << ", ";
  }
  cout << endl;

  /******************************************************************
    Chamada de DepthFirstSearch
  *******************************************************************/
  depthFirstSearch(graph, a, h);

  /******************************************************************
    Chamada de BreadthFirstSearch
  *******************************************************************/
  breadthFirstSearch(graph, a, h);

  
  cout << "Saindo" << endl;
}
