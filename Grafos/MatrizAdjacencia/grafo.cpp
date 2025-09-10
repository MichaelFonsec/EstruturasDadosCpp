#include <iostream>
#include "grafo.h"

using namespace std;

    Grafo::Grafo(int max, int valorArestaNula) // construtor
    {
        numVertices = 0;
        maxVertices = max;
        arestaNula = valorArestaNula;

        vertices = new TipoItem[maxVertices];

        matrizAdjacencias = new int*[maxVertices]; // criando um vetor para vetores de inteiros chamado de matriz de adjacencias
        for(int i = 0; i < maxVertices; i++){
            matrizAdjacencias[i] = new int[maxVertices];
        }
        for(int i = 0; i < maxVertices; i++){
            for(int j = 0; j < maxVertices; j++){
                matrizAdjacencias[i][j] = arestaNula; //na matriz de adjacencia na linha i e coluna j coloca o arestaNula, indicando que ainda não adicionou nenhuma aresta
            }
        }
    }

    Grafo::~Grafo()
    {
        delete [] vertices;
        for(int i = 0; i < maxVertices; i++){
            delete [] matrizAdjacencias[i];
        }
        delete [] matrizAdjacencias;

    }

    int Grafo::obterIndice(TipoItem item)
    {
        int indice = 0;
        while(item != vertices[indice]){
            indice++;
        }

        // fazer verificação para caso usuario faça um caso errado
        return indice;
    }
    bool Grafo::estaCheio()
    {
        return(numVertices == maxVertices);
    }
    void Grafo::inserirVertice(TipoItem item)
    {
            if(estaCheio()){
                cout << "O Numero maximo de vertices foi alcancado\n";
            } else{
                vertices[numVertices] = item;
                numVertices++;
            }
    }
    void Grafo::insereAresta(TipoItem NodeSaida, TipoItem NodeEntrada, int peso)
    {
        int linha = obterIndice(NodeSaida); // adicionando o Nó de Saida dessa aresta
        int coluna = obterIndice(NodeEntrada); // adicionando o Nó de Entrada dessa aresta

        matrizAdjacencias[linha][coluna] = peso;

        matrizAdjacencias[coluna][linha] = peso; // Remover caso seja direcionado
    }
    int Grafo::obterPeso(TipoItem NodeSaida, TipoItem NodeEntrada)
    {
        int linha = obterIndice(NodeSaida); // adicionando o Nó de Saida dessa aresta
        int coluna = obterIndice(NodeEntrada); // adicionando o Nó de Entrada dessa aresta

        return(matrizAdjacencias[linha][coluna]);
        //colocar verificação para caso usuario pergunte qual o peso de um nó que não existe
        
    }
    int Grafo::obterGrau(TipoItem item)
    {
        int linha = obterIndice(item);
        int grau = 0;
        for(int i = 0; i < maxVertices; i++){
            if(matrizAdjacencias[linha][i] != arestaNula){
                grau++;
            }
        }
        
        return grau;
    }
    void Grafo::printMatriz()
    {
        cout << "Matriz de Adjancencias:\n";
        for(int i = 0; i < maxVertices; i++){
            for(int j = 0; j < maxVertices; j++){
                cout << matrizAdjacencias[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Grafo::printVertices()
    {
        cout << "Lista de Vertices:\n";
        for(int i = 0; i < numVertices; i++ ){
            cout << i << " : " << vertices[i] << endl;
        }
    }