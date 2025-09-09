#include <iostream>
#include "aluno.h"

struct Node // Struct é semelhante a classe porém toda informação contida nela fica como publica
{
    Aluno aluno;
    Node * filhoesquerda; // Ponteiro para o nó filho da esquerda e como subsequente é o nó que aponta para a subarvore esquerda
    Node* filhodireita; // Ponteiro para o nó filho da direita e como subsequente é o nó que aponta para a subarvore direita

    int fatorB; // Fator de Balanceamento de cada Nó
};


class ArvoreAVL 
{
private:
    Node* raiz; // a variavel raiz é um ponteiro que aponta para o primeiro nó adicionado a arvore binaria de busca
public:
    ArvoreAVL();
    ~ArvoreAVL();
    void deletarArvore(Node* Nodeatual);
    Node* obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerBusca(Aluno aluno, Node*& NoAtual, bool& diminuiu); // O NoAtual ele é o ponteiro para o NoAtual
    void deletarNode(Node*& NoAtual, bool& diminuiu);
    void obterSucessor(Aluno& AlunoSucessor, Node* temp);
    void buscar(Aluno& aluno, bool& busca);
    void printPreOrdem(Node* Nodeatual);
    void printInOrdem(Node* Nodeatual);
    void printPosOrdem(Node* Nodeatual);

    //Novos Metodos
    void rotacaodireita(Node*& tree);
    void rotacaoesquerda(Node*& tree);
    void rotacaoesquerdadireita(Node*& tree);
    void rotacaodireitaesquerda(Node*& tree);
    void realizarotacao(Node*& tree); // para fazer a rotação ela é chamada e verifica o fator de balaceamento para verificar qual rotação vai ser necessaria
    void insererecursivo(Node*& Nodeatual, Aluno aluno, bool& cresceu); //conforme vai chamando o inserindo ele vai comparando e vai inserindo tanto para esquerda como para a direita, até achar um lugar vazio e atualizando o fator de balanceamento
    // cresceu é uma variavel booleana que indica que quando insere elemento retorna ele como true e retorna para o nó pai atualizando o fator de balanceamento para ele e o restante dos nós
};
