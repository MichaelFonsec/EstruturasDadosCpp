#include <iostream>
#include "pilhad.h"
#include <cstddef> // NULL
using namespace std;

    pilhad::pilhad(){ //construtor //dynamic stack
        NoTopo = NULL;
    } 
    pilhad::~pilhad(){ //destrutor
        Node* NoTemporario;
        while (NoTemporario != NULL)
        {
            NoTemporario = NoTopo;
            NoTopo = NoTopo-> proximo;
            delete NoTemporario;
        }
        
    } 
    bool pilhad::pilhavazia(){
            return(NoTopo == NULL);
    } //isEmpty
    bool pilhad::pilhaCheia(){
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
    void pilhad::push(TipoItem item){
        if(pilhaCheia()){
            throw runtime_error("Erro: Pilha cheia, impossivel inserir");
        } else{
            Node* NoNovo = new Node;
            NoNovo->valor = item;
            NoNovo-> proximo = NoTopo;
            NoTopo = NoNovo;

        }
    } //inserir
    TipoItem pilhad::pop(){
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
    void pilhad::print(){
        Node* NoTemporario = NoTopo;
        cout << "Pilha Dinamica: [ ";
        while(NoTemporario != NULL){
            cout << NoTemporario->valor << " ";
            NoTemporario = NoTemporario->proximo;
        }
        cout << "]\n";

    }