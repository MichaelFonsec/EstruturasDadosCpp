#include <iostream>
#include "search_tree.h"
#include <string>

using namespace std;

void search_tree::destroyTree(NodeType*& tree)
{

    // Exempo de Caminhamento Pós-Ordem
    if(tree != NULL){
        destroyTree(tree->esquerda);
        destroyTree(tree->direita);
        delete tree;
    }
}

bool search_tree::isEmpty() const{
    //verifica se a raiz é nula
    return ( root == NULL);
}

bool search_tree::isFull() const{

    // verifica se há memória disponivel para alocar um novo nó
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
    
}

// Função para buscar um aluno na Árvore Binária de Busca
 void search_tree::retrieveAluno(NodeType* tree, Aluno& aluno, bool& found) const{
    //
    if(tree == NULL)
        found = false;
    else if(aluno.getRa() < tree->aluno.getRa())
    retrieveAluno(tree->esquerda, aluno, found);
    else if(aluno.getRa() > tree->aluno.getRa())
    retrieveAluno(tree->direita, aluno, found);
    else{
        aluno = tree->aluno;
        found = true;
    }
 }

 // Função para inserir um aluno na Árvore Binária de Busca
 void search_tree::inserirAluno(NodeType*& tree, Aluno aluno){
    if(tree == NULL){
        tree = new NodeType;
        tree->direita = NULL;
        tree->esquerda = NULL;
        tree->aluno = aluno;
    } else if(aluno.getRa() < tree->aluno.getRa())
     inserirAluno(tree->esquerda, aluno);
     else{
        inserirAluno(tree->direita, aluno);
     }
 }

 // Imprimir a Árvore Binária de Busca em Pré-Ordem
 void search_tree::printPreOrder(NodeType* tree) const{
    if(tree != NULL){
        cout << tree->aluno.getNome() << " , ";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
 }

// Imprimir a Árvore Binária de Busca em Ordem
 void search_tree::printInOrder(NodeType* tree) const{
    if(tree != NULL){
        printInOrder(tree->esquerda);
        cout << tree->aluno.getNome() << " , ";
        printInOrder(tree->direita);
    }
 }

 // Imprimir a Árvore Binária de Busca em Pós-Ordem
 void search_tree::printPostOrder(NodeType* tree) const{
    if(tree != NULL){
        printPostOrder(tree->esquerda);
        printPostOrder(tree->direita);
        cout << tree->aluno.getNome() << " , " ;
    }
 }


 // Função para remover aluno, localizando o aluno a ser removido na Árvore Binária de Busca
 void search_tree::deleteAluno(NodeType*& tree, int aluno){
    if(aluno < tree->aluno.getRa() )
    deleteAluno(tree->esquerda, aluno);
    else if(aluno > tree->aluno.getRa())
    deleteAluno(tree->direita, aluno);
    else if(aluno == tree->aluno.getRa())
    deleteNode(tree);
 }

// Removendo o Nó que não possui filhos ou que possui um filho, substituindo o nó pai pelo filho e removemos
 void search_tree::deleteNode(NodeType*& tree){
    Aluno data;
    NodeType* tempPtr;
    tempPtr = tree;
    if(tree->esquerda == NULL){
        tree = tree->direita;
        delete tempPtr;
    } else if(tree->direita == NULL){
        tree = tree->esquerda;
        delete tempPtr;
    } else{
        getSuccessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->direita, data.getRa());
    }
 }

 // Função para encontrar o sucessor do nó a ser removido, que é o filho mais a esquerda da subárvore direita
 void search_tree::getSuccessor(NodeType* tree, Aluno& data){
     tree = tree->direita;
  while (tree->esquerda != NULL)
    tree = tree->esquerda;
  data = tree->aluno;
 }