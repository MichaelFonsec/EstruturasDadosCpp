#include <iostream>
#include "pilha.h"

using namespace std;

    pilha::pilha()// funcao construtora
    {
        tamanho = 0;
        estrutura = new TipoItem[max_items];

    }
    pilha::~pilha()// funcao destrutora 
    {
        delete [] estrutura;

    }
    bool pilha::pilhacheia()//verficar se está cheia a pilha
    {
        return(tamanho == max_items);
    }
    bool pilha::pilhavazia()//verificar se está vazia
    {
        return(tamanho == 0);
    }
    void pilha::push(TipoItem item)// função de inserir
    {
        if(pilhacheia()){
            throw runtime_error("Erro: a pilha esta cheia, não é possivel inserir!");
        } else{
            estrutura[tamanho] = item;
            tamanho++;
        }
    }
    
    TipoItem pilha::pop()// função de remoção
    {
        if(pilhavazia()){
            throw runtime_error("Erro: a pilha está vazia, nao é possivel remover!");
            return 0;
        } else{
            tamanho--; 
            return estrutura[tamanho];
        }

    }
    void pilha::print(){
            cout << "Pilha: [ ";
            for(int i=0; i <tamanho;  i++){
                cout << estrutura[i] << " ";

            }
            cout << "]\n";
    }
    int pilha::length(){
        return tamanho;
    }