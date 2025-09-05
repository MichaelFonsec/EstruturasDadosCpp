#include <iostream>
#include "aluno.h"

struct Node // Struct é semelhante a classe porém toda informação contida nela fica como publica
{
    Aluno aluno;
    Node * filhoesquerda; // Ponteiro para o nó filho da esquerda e como subsequente é o nó que aponta para a subarvore esquerda
    Node* filhodireita; // Ponteiro para o nó filho da direita e como subsequente é o nó que aponta para a subarvore direita
};


class BST //BST = Binary Search Tree = Arvore Binaria de Busca
{
private:
    Node* raiz; // a variavel raiz é um ponteiro que aponta para o primeiro nó adicionado a arvore binaria de busca
public:
    BST();
    ~BST();
    void deletarArvore(Node* Nodeatual);
    Node* obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void printPreOrdem(Node* Nodeatual);
    void printInOrdem(Node* Nodeatual);
    void printPosOrdem(Node* Nodeatual);
};
