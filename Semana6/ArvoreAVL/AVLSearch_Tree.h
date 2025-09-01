#include "aluno.h"

struct NodeType {
    Aluno aluno;
    int fatorBalanceamento; // Fator de balanceamento
    NodeType* esquerda;
    NodeType* direita;
};

class AVLSearchTree{
    private:
    void destroyTree(NodeType*& tree);
    void retrieveAluno(NodeType* tree, Aluno& item, bool& found) const;
    void insertAluno(NodeType*& tree, Aluno item, bool& isTaller);
    void deleteAluno(NodeType*& tree, int item, bool& isShorter);
    void deleteNode(NodeType*& tree, bool& isShorter);
    void getSuccessor(NodeType* tree, Aluno& data);
    void printTree(NodeType *tree) const;
    void printPreOrder(NodeType* tree) const;
    void printInOrder(NodeType* tree) const;
    void printPostOrder(NodeType* tree) const;
    void rotateToLeft(NodeType*& tree) const; // Rotação simples à esquerda

    void rotateToRight(NodeType*& tree) const; // Rotação simples à direita
    void rotateToLeftAndRight(NodeType*& tree) const; // Rotação dupla à esquerda
    void rotateToRightAndLeft(NodeType*& tree) const; // Rotação dupla à direita

    void performRotations(NodeType*& tree) const; // Realiza as rotações necessárias para balancear a árvore

     // Raiz da Arvore Binaria de Busca
        NodeType* root;

    public:
     AVLSearchTree(){ root = NULL; }
     ~AVLSearchTree(){ destroyTree(root); }
     bool isEmpty() const;
     bool isFull() const;
      void retrieveAluno(Aluno& item, bool& found) const{ 
        retrieveAluno(root, item, found);
    }
    void insertAluno(Aluno item){
        bool isTaller; // Arvore ficou mais alta
        insertAluno(root, item, isTaller);
    }
    void deleteAluno(int item){
        bool isShorter; // Arvore diminuiu
        deleteAluno(root, item, isShorter);
    }

     void printPreOrder() const { printPreOrder(root); }
    void printInOrder() const { printInOrder(root); }
    void printPostOrder()const { printPostOrder(root); }
};