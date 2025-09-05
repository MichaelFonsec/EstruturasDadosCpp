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
                if(estaCheio()){
                    cout << "Arvore está cheia!\n";
                    cout << "Não foi possivel inserir esse elemento\n";
                }else{
                    Node* NodeNovo = new Node;
                    NodeNovo->aluno = aluno; //nesse nó o aluno será o aluno que o usuario irá inserir
                    NodeNovo->filhodireita = NULL; // ponteiro para o nó filho a direita está apontando para NULL pois não há um nó  
                    NodeNovo->filhoesquerda = NULL; // ponteiro para o nó filho a esquerda está apontando para NULL pois não há um nó
                    if(raiz == NULL){
                        raiz =  NodeNovo; // a raiz vai apontar para esse nó novo
                    } else{
                        Node* temp = raiz; // cria um nó temporario que vai receber a raiz
                        while (temp != NULL)
                        {
                            if(aluno.obterRa() < temp->aluno.obterRa()) // faz uma verificação se o RA do aluno que está sendo inserido for menor que o RA que está dentto do aluno do nó temporario
                            {
                                    if(temp->filhoesquerda == NULL){ // se for menor realiza uma outra verificação se o nó filho da esquerda é NULL
                                        temp->filhoesquerda = NodeNovo; // armazena o nó novo no nó do filho esquerdo
                                        break;                                        
                                    } else{
                                             temp = temp->filhoesquerda; // caso o no filho esquerdo não esteja NULL ele  vai para o nó esquerdo desse nó que ele verificou
                                    }
                            } else{
                                if(temp->filhodireita == NULL){  //se for maior realiza uma outra verificação se o nó filho da direita é NULL
                                    temp->filhodireita = NodeNovo; // armazena o nó novo no nó do filho direito
                                    break;
                                } else{
                                    temp = temp->filhodireita; //caso o no filho direito não esteja NULL ele  vai para o nó direito desse nó que ele verificou
                                }

                            }
                        }
                        
                    }
                }
                 
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