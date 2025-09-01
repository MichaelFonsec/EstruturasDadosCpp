#include <iostream>
#include "AVLsearch_Tree.h"
#include <string>

using namespace std;

void AVLSearchTree::destroyTree(NodeType *&tree)
{

    // Exempo de Caminhamento Pós-Ordem
    if (tree != NULL)
    {
        destroyTree(tree->esquerda);
        destroyTree(tree->direita);
        delete tree;
    }
}

bool AVLSearchTree::isEmpty() const
{
    // verifica se a raiz é nula
    return (root == NULL);
}

bool AVLSearchTree::isFull() const
{

    // verifica se há memória disponivel para alocar um novo nó
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

// Função para buscar um aluno na Árvore Binária de Busca
void AVLSearchTree::retrieveAluno(NodeType *tree, Aluno &aluno, bool &found) const
{
    //
    if (tree == NULL)
        found = false;
    else if (aluno.getRa() < tree->aluno.getRa())
        retrieveAluno(tree->esquerda, aluno, found);
    else if (aluno.getRa() > tree->aluno.getRa())
        retrieveAluno(tree->direita, aluno, found);
    else
    {
        aluno = tree->aluno;
        found = true;
    }
}

// Função para inserir um aluno na Árvore Binária de Busca
void AVLSearchTree::insertAluno(NodeType *&tree, Aluno aluno, bool &isTaller)
{
    if (tree == NULL)
    {
        tree = new NodeType;
        tree->direita = NULL;
        tree->esquerda = NULL;
        tree->aluno = aluno;
        tree->fatorBalanceamento = 0;
        isTaller = true; // A árvore ficou mais alta
        return;
    }
    else if (aluno.getRa() < tree->aluno.getRa())
    {
        insertAluno(tree->esquerda, aluno, isTaller);
        if (isTaller)
            tree->fatorBalanceamento = tree->fatorBalanceamento - 1; // Árvore ficou mais alta na subárvore esquerda
    }
    else
    {
        insertAluno(tree->direita, aluno, isTaller);
        if (isTaller)
            tree->fatorBalanceamento = tree->fatorBalanceamento + 1; // Árvore ficou mais alta na subárvore direita
    }

    performRotations(tree); // Realiza as rotações necessárias para balancear a árvore
    if (isTaller && tree->fatorBalanceamento == 0)
    {
        isTaller = false; // A árvore não mudou de altura
    }
}

// Função para realizar a rotação simples à esquerda
void AVLSearchTree::rotateToLeft(NodeType *&tree) const
{
    NodeType *p = tree->direita; // Ponteiro que vai apontar para o No que será a raiz
    tree->direita = p->esquerda;
    p->esquerda = tree;
    tree = p;
}
// Função para realizar a rotação simples à direita
void AVLSearchTree::rotateToRight(NodeType *&tree) const
{
    NodeType *p = tree->esquerda; // Ponteiro que vai apontar para o No que será a raiz
    tree->esquerda = p->direita;
    p->direita = tree;
    tree = p;
}

// Função para realizar a rotação dupla à esquerda
void AVLSearchTree::rotateToLeftAndRight(NodeType *&tree) const
{
    NodeType *child = tree->esquerda; // Aponta para o filho a esquerda
    rotateToLeft(child);
    tree->esquerda = child;
    rotateToRight(tree);
}

// Função para realizar a rotação dupla à direita
void AVLSearchTree::rotateToRightAndLeft(NodeType *&tree) const
{
    NodeType *child = tree->direita; // Aponta para o filho a direita
    rotateToRight(child);
    tree->direita = child;
    rotateToLeft(tree);
}

void AVLSearchTree::performRotations(NodeType *&tree) const
{
    NodeType *child;
    NodeType *grandChild;

    // Desbalanceado para a esquerda
    if (tree->fatorBalanceamento == -2)
    {
        child = tree->esquerda;

        switch (child->fatorBalanceamento)
        {
        case -1: // Rotação simples à direita
            tree->fatorBalanceamento = 0;
            child->fatorBalanceamento = 0;
            rotateToRight(tree);
            break;

        case 0: // Caso raro na remoção
            tree->fatorBalanceamento = -1;
            child->fatorBalanceamento = 1;
            rotateToRight(tree);
            break;

        case 1: // Rotação dupla: esquerda-direita
            grandChild = child->direita;

            if (grandChild->fatorBalanceamento == -1)
            {
                tree->fatorBalanceamento = 1;
                child->fatorBalanceamento = 0;
            }
            else if (grandChild->fatorBalanceamento == 1)
            {
                tree->fatorBalanceamento = 0;
                child->fatorBalanceamento = -1;
            }
            else
            { // == 0
                tree->fatorBalanceamento = 0;
                child->fatorBalanceamento = 0;
            }
            grandChild->fatorBalanceamento = 0;

            rotateToLeftAndRight(tree);
            break;
        }
    }

    // Desbalanceado para a direita
    else if (tree->fatorBalanceamento == 2)
    {
        child = tree->direita;

        switch (child->fatorBalanceamento)
        {
        case 1: // Rotação simples à esquerda
            tree->fatorBalanceamento = 0;
            child->fatorBalanceamento = 0;
            rotateToLeft(tree);
            break;

        case 0: // Caso raro na remoção
            tree->fatorBalanceamento = 1;
            child->fatorBalanceamento = -1;
            rotateToLeft(tree);
            break;

        case -1: // Rotação dupla: direita-esquerda
            grandChild = child->esquerda;

            if (grandChild->fatorBalanceamento == 1)
            {
                tree->fatorBalanceamento = -1;
                child->fatorBalanceamento = 0;
            }
            else if (grandChild->fatorBalanceamento == -1)
            {
                tree->fatorBalanceamento = 0;
                child->fatorBalanceamento = 1;
            }
            else
            { // == 0
                tree->fatorBalanceamento = 0;
                child->fatorBalanceamento = 0;
            }
            grandChild->fatorBalanceamento = 0;

            rotateToRightAndLeft(tree);
            break;
        }
    }
}

// Imprimir a Árvore Binária de Busca em Pré-Ordem
void AVLSearchTree::printPreOrder(NodeType *tree) const
{
    if (tree != NULL)
    {
        cout << tree->aluno.getNome() << " , ";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
}

// Imprimir a Árvore Binária de Busca em Ordem
void AVLSearchTree::printInOrder(NodeType *tree) const
{
    if (tree != NULL)
    {
        printInOrder(tree->esquerda);
        cout << tree->aluno.getNome() << " , ";
        printInOrder(tree->direita);
    }
}

// Imprimir a Árvore Binária de Busca em Pós-Ordem
void AVLSearchTree::printPostOrder(NodeType *tree) const
{
    if (tree != NULL)
    {
        printPostOrder(tree->esquerda);
        printPostOrder(tree->direita);
        cout << tree->aluno.getNome() << " , ";
    }
}

// Função para remover aluno, localizando o aluno a ser removido na Árvore Binária de Busca
void AVLSearchTree::deleteAluno(NodeType *&tree, int aluno, bool &isShorter)
{

    if (tree == NULL)
    {
        isShorter = false;
        return;
    }
    if (aluno < tree->aluno.getRa())
        deleteAluno(tree->esquerda, aluno, isShorter);
    if (isShorter)
        tree->fatorBalanceamento += 1;
    else if (aluno > tree->aluno.getRa())
        deleteAluno(tree->direita, aluno, isShorter);
    if (isShorter)
        tree->fatorBalanceamento -= 1;
    if (isShorter)
        tree->fatorBalanceamento = tree->fatorBalanceamento + 1;
    else
    {
        deleteNode(tree, isShorter);
        isShorter = true;
    }

    performRotations(tree); // Realiza as rotações necessárias para balancear a árvore
}

// Removendo o Nó que não possui filhos ou que possui um filho, substituindo o nó pai pelo filho e removemos
void AVLSearchTree::deleteNode(NodeType *&tree, bool &isShorter)
{
    Aluno data;
    NodeType *tempPtr;
    tempPtr = tree;
    if (tree->esquerda == NULL)
    {
        tree = tree->direita;
        delete tempPtr;
    }
    else if (tree->direita == NULL)
    {
        tree = tree->esquerda;
        delete tempPtr;
    }
    else
    {
        getSuccessor(tree, data);
        tree->aluno = data;
        bool shorter = false;
        deleteAluno(tree->direita, data.getRa(), shorter);

        if (shorter)
            tree->fatorBalanceamento -= 1;
    }
}

// Função para encontrar o sucessor do nó a ser removido, que é o filho mais a esquerda da subárvore direita
void AVLSearchTree::getSuccessor(NodeType *tree, Aluno &data)
{
    tree = tree->direita;
    while (tree->esquerda != NULL)
        tree = tree->esquerda;
    data = tree->aluno;
}