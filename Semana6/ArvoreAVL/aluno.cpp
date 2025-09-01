#include <iostream>
#include "aluno.h"
#include <string>

using namespace std;

        Aluno::Aluno(){
            this->ra = -1 ;
            this->nome = "";
        }
        Aluno::Aluno(int ra, std::string nome){
            this->ra = ra;
            this->nome = nome;
        }
        string Aluno::getNome() const{
          return nome;
        }
        int Aluno::getRa() const{
            return ra;
        }