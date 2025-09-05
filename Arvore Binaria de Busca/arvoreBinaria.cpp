#include <iostream>
#include <cstddef> // Para Trabalhar com Ponteiro apontando para NULL
#include "arvoreBinaria.h"

using namespace std;

    BST::BST(){ // Construtor
        raiz = NULL;
    }
    BST::~BST(){ // Destrutor

    }
    void BST::deletarArvore(Node* Nodeatual){

    }
    Node* BST::obterRaiz(){
        return raiz;
    }
    bool BST::estaVazio(){
        return (raiz == NULL);
    }
    bool BST::estaCheio(){
        try
        {
           Node* temp = new Node; // cria um ponteiro temporario e cria um espaço para guardar um Nó, se achar um espaço na memoria para guardar esse Nó então não está cheio
           delete temp; // deleta esse espaço da memoria
           return false;

        }
        catch(bad_alloc exception)
        {
             cout << "Erro: memória insuficiente para alocar um novo nó. Árvore cheia.\n";
           return true;
        }
        
    }
    void BST::inserir(Aluno aluno){

    }
    void BST::remover(Aluno aluno){

    }
    void BST::buscar(Aluno& aluno, bool& busca){

    }
    void BST::printPreOrdem(Node* Nodeatual){

    }
    void BST::printInOrdem(Node* Nodeatual){
        
    }
    void BST::printPosOrdem(Node* Nodeatual){

    }