// Grafo  Simples Não Direcionado Ponderado

#include <iostream>
#include "pilhaDinamica.h"
#include "filadinamica.h"

using namespace std;

class Grafo
{
private:
   int arestaNula;
   int maxVertices;
   int numVertices;
   TipoItem* vertices;
   int** matrizAdjacencias; // um vetor de vetores do tipo inteiro que é uma matriz
   bool* marcador; //Vetor de booleanos ele verifica a quantidade de vertices e guarda true ou false, aonde ele marca se entrou na fila ou na pilha
public:
    Grafo(int max, int valorArestaNula);
    ~Grafo();
    int obterIndice(TipoItem item);
    bool estaCheio();
    void inserirVertice(TipoItem item);
    void insereAresta(TipoItem NodeSaida, TipoItem NodeEntrada, int peso);
    int obterPeso(TipoItem NodeSaida, TipoItem NodeEntrada);
    int obterGrau(TipoItem item);
    void printMatriz();
    void printVertices();

    //Novos Metodos:
    void limpaMarcador();
    void buscaemlargura(TipoItem origem, TipoItem destino); //Busca em largura recebe dois vertices do Tipo TipoItem
    void buscaemprofundidade(TipoItem origem, TipoItem destino); //Busca em profundidade recebe dois vertices do Tipo TipoItem
};




