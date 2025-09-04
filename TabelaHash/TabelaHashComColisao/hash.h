#include "aluno.h"

class Hash
{
private:
    int FuncaoHash(Aluno aluno);
    int max_items;
    int max_posicoes;
    int qt_items;
    Aluno* estrutura; //vetor aonde vai ser armazenado a HASH, com elementos da classe Aluno
public:

    Hash(int tamanhoVetor, int max);
    ~Hash();
    bool estaCheio();
    int obterTamanhoAtual();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void print();
};
