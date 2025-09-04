#include <iostream>
#include "hash.h"

using namespace std;

int Hash::FuncaoHash(Aluno aluno)
{
    return (aluno.obterRA() % max_posicoes); // Utiliza o RA do aluno e calculando com o módulo do maximo de posições do vetor
}
Hash::Hash(int tamanhoVetor, int max) // Funçao Construtora
{
    qt_items = 0;
    max_items = tamanhoVetor;
    max_posicoes = max;
    estrutura = new Aluno[tamanhoVetor];
}

Hash::~Hash() // Função Destrutora
{
    delete[] estrutura;
}

bool Hash::estaCheio()
{
    return (qt_items == max_items); // Se a  quantidade items for igual o tamanho maximo do vetor então significa que está cheio retornando como True
}
int Hash::obterTamanhoAtual()
{
    return (qt_items); // Retorna a quantidade items que o vetor possui atualmente
}
void Hash::inserir(Aluno aluno)
{                                  // Inserindo o Aluno sem colisão aonde vai verificar o local na Função Hash para inserir esse aluno
    int local = FuncaoHash(aluno); // dá como entrada o aluno e a função Hash devolve o local aonde vai ficar esse aluno
    estrutura[local] = aluno;
    qt_items++;
}
void Hash::deletar(Aluno aluno)
{
    int local = FuncaoHash(aluno);
    if (estrutura[local].obterRA() != -1)
    {                                      // Utilizando a estrutura local aonde está esse aluno e compara se é diferente -1 signfica que já foi inserido esse elemento nesse espaço de memória
        estrutura[local] = Aluno(-1, " "); // Aonde está esse aluno é subsituido o Nome por vazio e o  RA por menos -1
        qt_items--;
    }
}
void Hash::buscar(Aluno &aluno, bool &busca)
{ // Vai utilizar o aluno como entrada e vai verificar em qual local caso ele tenha sido inserido
    int local = FuncaoHash(aluno);
    Aluno aux = estrutura[local]; // variavel auxiliar para guardar esse objeto da classe aluno e vai receber o aluno que está no local achado na Função Hash
    if (aluno.obterRA() != aux.obterRA())
    {                  // realiza uma comparação do RA do aluno recebido na entrada é diferente do RA do variavel auxiliar
        busca = false; // se for falsa significa que o aluno nao foi encontrado
    }
    else
    {
        busca = true; // encontrou o aluno
        aluno = aux;  // a variavel auxiliar fica com o mesmo valor do aluno
    }
}
void Hash::print()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++)
    { // i se inicia no 0 e vai até o numero maximo de posições do vetor
        if (estrutura[i].obterRA() != -1)
        { // Se o estrutura for diferente de menos -1 ele imprime
            cout << i << ": RA=" << estrutura[i].obterRA()
                 << " Nome=" << estrutura[i].obterNome() << endl;
        }
    }
}
