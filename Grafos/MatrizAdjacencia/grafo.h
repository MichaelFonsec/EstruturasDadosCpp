// Grafo  Simples Não Direcionado Ponderado

#include <iostream>
using namespace std;

typedef string TipoItem; // utiliza o tipo item e vai simbolizar as strings que serão armazenados nele

class Grafo
{
private:
   int arestaNula;
   int maxVertices;
   int numVertices;
   TipoItem* vertices;
   int** matrizAdjacencias; // um vetor de vetores do tipo inteiro que é uma matriz
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
};




