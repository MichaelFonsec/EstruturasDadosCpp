#include <iostream>

using namespace std;

class Aluno
{
private:
    int ra;
    string nome;

public:
    Aluno(); // construtor a ser chamada quando criar a HASH
    Aluno(int r, string n); // construtor para quando cria o  aluno e seu RA
    int obterRA();
    string obterNome();
};
