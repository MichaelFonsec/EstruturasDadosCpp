#include <iostream>
#include "grafo.h"


using namespace std;

    Grafo::Grafo(int max, int valorArestaNula) // construtor
    {
        numVertices = 0;
        maxVertices = max;
        arestaNula = valorArestaNula;


        marcador = new bool[maxVertices]; //Declara o marcador com um vetor de tamanho do maximo de vertices
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

    // Novos Metodos

    void Grafo::limpaMarcador()
    {
        for(int i = 0; i < maxVertices; i++){
            marcador[i] = false; // percorre todos os indices do marcaodor e deixando ele como false
        }
    }

    void Grafo::buscaemlargura(TipoItem origem, TipoItem destino){
        filadinamica filavertices;
        bool encontrado = false;
        limpaMarcador(); 
        filavertices.enqueue(origem); //insere o vertice de origem na fila aonde vai começar o caminho
        do{
            TipoItem verticeAtual = filavertices.dequeue(); // remove um elemento e chama de verticeAtual
            if(verticeAtual == destino){ // se o vertice Atual for igual o que está procurando retira da fila
                cout << "Visitando: " << verticeAtual << endl;
                cout << "Caminho Encontrado\n";
                encontrado = true; // encontrado fica verdadeiro
            } else{
                // linha e coluna começa do 0 em C++
                int indice = obterIndice(verticeAtual); //pega o indice do verticeAtual  
                cout << "Visitando: " << verticeAtual << endl;
                for(int i=0; i< maxVertices; i++){ // percorre a matriz de adjacencias
                    if(matrizAdjacencias[indice][i] != arestaNula){ // na linha do vertice, pega todos os elementos da linha, e verifica se é diferente de arestaNula, se for diferente então tem caminho
                      if(!marcador[i]){  // verificar no marcador o indice se ele está falso, se tiver então ele entra na fila
                        cout << "Enfileirando: " << vertices[i] << endl;
                        filavertices.enqueue(vertices[i]); // insere o vertice na fila
                        marcador[i] = true; // e marcador o vertice com esse indice tem o marcador como verdadeiro
                      }
                    }
                }
            }
        }
        while (!filavertices.filaVazia() && !encontrado); //se a fila não está vazia e não foi encontrado
        if(!encontrado){
            cout << "Caminho nao encontrado\n";
        }
        
    }

    void Grafo::buscaemprofundidade(TipoItem origem, TipoItem destino){
          pilhaDinamica pilhavertices;
        bool encontrado = false;
        limpaMarcador(); 
        pilhavertices.push(origem); //insere o vertice de origem na fila aonde vai começar o caminho
        do{
            TipoItem verticeAtual = pilhavertices.pop(); // remove um elemento e chama de verticeAtual
            if(verticeAtual == destino){ // se o vertice Atual for igual o que está procurando retira da fila
                cout << "Visitando: " << verticeAtual << endl;
                cout << "Caminho Encontrado\n";
                encontrado = true; // encontrado fica verdadeiro
            } else{
                // linha e coluna começa do 0 em C++
                int indice = obterIndice(verticeAtual); //pega o indice do verticeAtual  
                cout << "Visitando: " << verticeAtual << endl;
                for(int i=0; i< maxVertices; i++){ // percorre a matriz de adjacencias
                    if(matrizAdjacencias[indice][i] != arestaNula){ // na linha do vertice, pega todos os elementos da linha, e verifica se é diferente de arestaNula, se for diferente então tem caminho
                      if(!marcador[i]){  // verificar no marcador o indice se ele está falso, se tiver então ele entra na fila
                        cout << "Empilhando: " << vertices[i] << endl;
                        pilhavertices.push(vertices[i]); // insere o vertice na fila
                        marcador[i] = true; // e marcador o vertice com esse indice tem o marcador como verdadeiro
                      }
                    }
                }
            }
        }
        while (!pilhavertices.pilhavazia() && !encontrado); //se a fila não está vazia e não foi encontrado
        if(!encontrado){
            cout << "Caminho nao encontrado\n";
        }
    }