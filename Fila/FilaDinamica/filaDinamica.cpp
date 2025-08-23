#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;

    filadinamica::filadinamica(){ //construtor
     primeiro = NULL;
     ultimo = NULL;
    }
    filadinamica::~filadinamica(){ //destrutor
       Node* NoTemporario;
       while (primeiro != NULL)
       {
        NoTemporario = primeiro;
        primeiro = primeiro->proximo;
        delete NoTemporario;
       }
        ultimo = NULL;
    }
    bool filadinamica::filaCheia(){ // isEmpty
     Node* NoTemporario;
     try
     {
        NoTemporario = new Node;
        delete NoTemporario;
        return false;
     }
     catch(bad_alloc exception)
     {
       return true;
     }
     

    }
    bool filadinamica::filaVazia(){ // isFull
       return(primeiro == NULL);
    }
    void filadinamica::enqueue(TipoItem item){ // Inserir ||Push
       if(filaCheia()){
        throw runtime_error ("A fila esta cheia\n");
       }else{
         Node* NoNovo = new Node;
         NoNovo->valor = item;
         NoNovo->proximo = NULL;
         if(primeiro == NULL){
            primeiro = NoNovo;
         } else{
            ultimo->proximo = NoNovo;
         }
         ultimo = NoNovo;
       }
    }
    TipoItem filadinamica::dequeue(){  // Remover||pop
        if(filaVazia()){
            throw runtime_error("A Fila esta vazia\n");
            return 0;
        }else{
           Node* NoTemporario;
           TipoItem item = primeiro->valor;
           primeiro = primeiro->proximo;
           if(primeiro == NULL){
             ultimo = NULL;
           }
         delete NoTemporario;
         return item;
        }

    }
    void filadinamica::print(){
       Node* NoTemporario = primeiro;
       cout << "FILA = [ ";
       while (NoTemporario != NULL)
       {
        cout << NoTemporario->valor << " ";
        NoTemporario = NoTemporario->proximo;
       }

       cout << " ]\n";
       
    }



