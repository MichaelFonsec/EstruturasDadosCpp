#include <iostream>
#include "pilhaDinamica.h"
#include <cstddef> // NULL
using namespace std;

    pilhaDinamica::pilhaDinamica(){ //construtor //dynamic stack
        NoTopo = NULL;
    } 
    pilhaDinamica::~pilhaDinamica(){ //destrutor
        Node* NoTemporario;
        while (NoTemporario != NULL)
        {
            NoTemporario = NoTopo;
            NoTopo = NoTopo-> proximo;
            delete NoTemporario;
        }
        
    } 
    bool pilhaDinamica::pilhavazia(){
            return(NoTopo == NULL);
    } //isEmpty
    bool pilhaDinamica::pilhaCheia(){
        Node* NoNovo;
        try
        {
            NoNovo = new Node;
            delete NoNovo;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    } //isFull
    void pilhaDinamica::push(TipoItem item){
        if(pilhaCheia()){
            throw runtime_error("Erro: Pilha cheia, impossivel inserir");
        } else{
            Node* NoNovo = new Node;
            NoNovo->valor = item;
            NoNovo-> proximo = NoTopo;
            NoTopo = NoNovo;

        }
    } //inserir
    TipoItem pilhaDinamica::pop(){
        if(pilhavazia()){
            throw runtime_error("Erro: Pilha vazia, impossivel remover");
            return 0;
        } else{
            Node* NoTemporario = NoTopo;
            TipoItem item = NoTopo->valor;
            NoTopo = NoTopo->proximo;
            delete NoTemporario;
            return item;
        }
    } // remover
    void pilhaDinamica::print(){
        Node* NoTemporario = NoTopo;
        cout << "Pilha Dinamica: [ ";
        while(NoTemporario != NULL){
            cout << NoTemporario->valor << " ";
            NoTemporario = NoTemporario->proximo;
        }
        cout << "]\n";

    }