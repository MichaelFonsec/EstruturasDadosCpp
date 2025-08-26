#include <iostream>
#include "search_tree.h"
#include <string>

using namespace std;

const int NUM_ALUNOS = 8;

int main(){
     search_tree Search_tree;

     int ras[NUM_ALUNOS] = {20, 18, 58, 7 , 19 , 26, 25, 30};
     string nomes[NUM_ALUNOS] = {"Pedro", "Raul","Paulo","Carlos","Lucas","Maria","Samantha","Ulisses"};
     Aluno alunos[NUM_ALUNOS];

     for(int i = 0; i < NUM_ALUNOS; i++){
        alunos[i] = Aluno(ras[i], nomes[i]);
        Search_tree.inserirAluno(alunos[i]);
     }

     // Imprimindo a saida padrão
     cout << " Pre: ";
     Search_tree.printPreOrder();
     cout << endl;
     cout << " In: ";
     Search_tree.printInOrder();
     cout << endl;
     cout << " Pos: ";
     Search_tree.printPostOrder();
     cout << endl;

     // Removendo o aluno da Raiz

    Search_tree.deleteAluno(alunos[0].getRa());
    cout << "****************" << endl;
    cout << " Pre: ";
    Search_tree.printPreOrder();
    cout << endl;
    cout << " In: ";
    Search_tree.printInOrder();
    cout << endl;
    cout << " Pos: ";
    Search_tree.printPostOrder();
    cout << endl;

}