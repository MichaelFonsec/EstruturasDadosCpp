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
    max_posicoes = max;
    max_items = tamanhoVetor;
    estrutura = new Aluno[tamanhoVetor];

    // inicializa a tabela hash com "vazio" (-1)
    for (int i = 0; i < tamanhoVetor; i++)
    {
        estrutura[i] = Aluno(-1, " ");
    }
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
{ // Inserindo o Aluno com colisão aonde vai verificar o local na Função Hash para inserir esse aluno
    if (estaCheio())
    {
        cout << "A Tabela Hash esta Cheia\n";
        cout << "O elemento não pode ser inserido\n";
    }
    else
    {
        int local = FuncaoHash(aluno);         // dá como entrada o aluno e a função Hash devolve o local aonde vai ficar esse aluno
        while (estrutura[local].obterRA() > 0) // enquanto o RA do aluno seja positivo, caso seja negativo ele entra no caso quando é vazio ou disponivel
        {
            local = (local + 1) % max_posicoes; // o local aumenta 1 e caso passe o módulo dos maximo de posições do vetor faz retorna para o inicio do vetor
        }
        estrutura[local] = aluno; // vetor que armazena a tabela hash
        qt_items++;
    }
}
void Hash::deletar(Aluno aluno)
{
    int local = FuncaoHash(aluno);
    bool ElementoEncontrado = false;
    while (estrutura[local].obterRA() != -1)
    { // enquanto a posição não for vazia
        if (estrutura[local].obterRA() == aluno.obterRA())
        { // se o RA que está sendo procurado no vetor for igual ao RA do aluno que está sendo buscado para deletar
            cout << "Elemento Removido\n";
            estrutura[local] = Aluno(-2, " "); // Aonde está esse aluno é subsituido o Nome por vazio e o  RA por menos -1
            qt_items--;
            ElementoEncontrado = true;
            break;
        }
        else
        {
            local = (local + 1) % max_posicoes; //
        }
    }

    if (!ElementoEncontrado)
    { // Se não achar o elemento exibir as mensagens que o elemento não foi localizado
        cout << "Elemento Nao Encontrado\n";
        cout << "Nenhum elemento foi Removido\n";
    }
}
void Hash::buscar(Aluno &aluno, bool &busca)
{ // Vai utilizar o aluno como entrada e vai verificar em qual local caso ele tenha sido inserido
    int local = FuncaoHash(aluno);
    busca = false;
    while (estrutura[local].obterRA() != -1)
    { // enquanto o RA do local for diferente de -1 ou seja diferente de vazio
        if (estrutura[local].obterRA() == aluno.obterRA())
        {                             // realiza uma comparação entre o RA do local com o do aluno
            busca = true;             // busca vira verdadeira caso encontre na hash
            aluno = estrutura[local]; // o aluno recebido pela variavel por referencia recebe o aluno encontrado no local
            break;
        }
        else
        {
            local = (local + 1) % max_posicoes;
        }
    }
}
void Hash::print()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++)
    { // i se inicia no 0 e vai até o numero maximo de posições do vetor
        if (estrutura[i].obterRA() > 0)
        { // Se o estrutura for diferente de menos -1 ele imprime
            cout << i << ": RA=" << estrutura[i].obterRA()
                 << " Nome=" << estrutura[i].obterNome() << endl;
        }
    }
}
