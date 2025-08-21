#include <iostream>
#include "pilhaDinamica.h";

using namespace std;

int main(){

    pilhaDinamica pilhad1;
    TipoItem item;
    int menu;

    cout << "Programa de geração de Pilha Dinamica:\n";
    
    do {
        cout << "\nDigite 0 para parar o programa \n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a Pilha!\n";
        cout << "Escolha: ";
        cin >> menu;

        try
        {
            if (menu == 1) {
            cout << "Digite o Elemento a ser inserido: ";
            cin >> item;
            pilhad1.push(item);

        } else if(menu == 2){
            item = pilhad1.pop();
            cout << "Elemento removido: " << item << endl;

        } else if(menu == 3){
            pilhad1.print();
        }

        }
        catch(const std::exception& e)
        {
            cout << "Exceção Reconhecida: " << e.what() << endl;
        }
    

    } while(menu != 0);

    return 0;
}
