#include <iostream>
#include "aluno.h"
using namespace std;


Aluno::Aluno()
{
    ra = -1;
    nome = " ";
}


Aluno::Aluno(int r, string n) // construtor para quando cria o  aluno e seu RA
{
    ra = r;
    nome = n;
}
int Aluno::obterRA() {
    return ra;
}
string Aluno::obterNome(){
    return nome;
}


