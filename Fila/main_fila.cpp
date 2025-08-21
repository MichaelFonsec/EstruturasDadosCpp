#include <iostream>
#include "fila.h";

using namespace std;

int main()
{
    fila fila1;
    int menu;
    TipoItem item;
    cout << "Programa de FILA:\n";

    do
    {
        cout << "Digite 0 para parar o programa \n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a FILA!\n";
        cout << "Escolha: ";

        cin >> menu;

        try
        {
            if (menu == 1)
            {
                cout << "Digite o elemento a ser inserido na fila:\n ";
                cin >> item;
                fila1.enqueue(item);
            }
            else if (menu == 2)
            {
                item = fila1.dequeue();
                cout << "O elemento removido e: " << item << endl;
            }
            else if (menu == 3)
            {
                fila1.print();
            }
        }
        catch (const std::exception &e)
        {
            cout << "Erro: " << e.what() << endl;
        }

    } while (menu != 0);

    return 0;
}