/* Estrutura usada para guardar a informação e os endereços das subarvores*/
#include "aluno.h"

struct NodeType
{
    Aluno aluno;
    NodeType *esquerda;
    NodeType *direita;
};

class search_tree
{
private:
 void destroyTree(NodeType*& tree);
 void retrieveAluno(NodeType* tree, Aluno& item, bool& found) const;
 void inserirAluno(NodeType*& tree, Aluno item);
 void deleteAluno(NodeType*& tree, int item);
 void deleteNode(NodeType*& tree);
 void getSuccessor(NodeType* tree, Aluno& data);
 void printTree(NodeType* tree) const;
 void printPreOrder(NodeType* tree) const;
 void printInOrder(NodeType* tree) const;
 void printPostOrder(NodeType* tree) const;

 // Raiz da Arvore Binaria de Busca
 NodeType* root;
 
public:
    search_tree() { root = NULL;}
    ~search_tree(){ destroyTree(root);}
    bool isEmpty() const;
    bool isFull() const;
    void retrieveAluno(Aluno& item, bool& found) const{ 
        retrieveAluno(root, item, found);
    }
    void inserirAluno(Aluno item){ inserirAluno(root, item); }
    void deleteAluno(int item) { deleteAluno(root, item); }
    void printPreOrder() const { printPreOrder(root); }
    void printInOrder() const { printInOrder(root); }
    void printPostOrder()const { printPostOrder(root); }
};

