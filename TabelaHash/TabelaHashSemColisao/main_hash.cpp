#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
    cout << "Programa de Tabela Hash:\n";
    int tamanhoVetor, max;
    cout << "Digite o tamanho da Hash:\n";
    cin >> tamanhoVetor;
    cout << "Digite o numero maximo de elementos:\n";
    cin >> max;
    cout << "O fator de carga e: " << (float)max / (float)tamanhoVetor << endl; // faz calculo do fator de carga da hash usando o tamanho do vetor e numero maximo de elementos
    Hash alunoHash(tamanhoVetor, max);                                          // criando a Hash
    int menu;
    int ra;
    string nome;
    bool busca;

    do
    {
        cout << "0 - Sair\n";
        cout << "1 - Inserir aluno\n";
        cout << "2 - Remover aluno\n";
        cout << "3 - Buscar aluno\n";
        cout << "4 - Imprimir Hash\n";
        cin >> menu;

        switch (menu)
        {

        case 1:
        {
            cout << "Qual e o RA do aluno:\n";
            cin >> ra;
            cout << "Qual e o nome do aluno:\n";
            cin >> nome;
            Aluno aluno(ra, nome);
            alunoHash.inserir(aluno);
            break;
        }

        case 2:
        {
            cout << "Qual e o RA do aluno a ser removido:\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            alunoHash.deletar(aluno);
            break;
        }
        case 3:
        {
            cout << "Qual e o RA do aluno a ser buscado:\n";
            cin >> ra;            // corrige: RA vai pra variável certa
            Aluno aluno(ra, " "); // cria objeto aluno com o RA
            alunoHash.buscar(aluno, busca);

            if (busca)
            {
                cout << "Aluno encontrado:\n";
                cout << "RA: " << aluno.obterRA() << "\n" << endl;
                cout << "Nome: " << aluno.obterNome() << "\n" << endl;
            }
            else
            {
                cout << "Aluno nao encontrado\n";
            }
            break;
        }

        case 4:
        {
            alunoHash.print();
            break;
        }

        case 0:
            cout << "Encerrando o programa...\n";
            break;

        default:
            cout << "Opcao Invalida, escolha uma opcao de entre 0 e 4\n";

            break;
        }
    } while (menu != 0);
    return 0;
}