#include <iostream>
#include "grafo.h"

using namespace std;

int main() {
    int max, valorarestanula;
    cout << "Digite a quantidade maxima de vertices:\n";
    cin >> max;
    cout << "Digite o valor para representar a ausencia de aresta:\n";
    cin >> valorarestanula;

    Grafo grafo1(max, valorarestanula);
    TipoItem item1, item2;
    int menu, valor, peso;

    do {
        cout << "\n===== MENU =====\n";
        cout << "0 - Sair\n";
        cout << "1 - Inserir vertice\n";
        cout << "2 - Inserir aresta\n";
        cout << "3 - Imprimir grau de um vertice\n";
        cout << "4 - Imprimir peso de uma aresta\n";
        cout << "5 - Imprimir matriz de adjacencias\n";
        cout << "6 - Imprimir lista de vertices\n";
        cout << "7 - Busca em largura\n";
        cout << "8 - Busca em profundidade\n";
        cout << "================\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Digite o elemento do vertice que sera inserido:\n";
                cin >> item1;
                grafo1.inserirVertice(item1);
                break;

            case 2:
                cout << "Digite o vertice de saida:\n";
                cin >> item1;
                cout << "Digite o vertice de entrada:\n";
                cin >> item2;
                cout << "Digite o peso desta aresta:\n";
                cin >> peso;
                grafo1.insereAresta(item1, item2, peso);
                break;

            case 3:
                cout << "Digite o vertice que sera calculado o grau:\n";
                cin >> item1;
                valor = grafo1.obterGrau(item1);
                cout << "O grau desse vertice e: " << valor << endl;
                break;

            case 4:
                cout << "Digite o vertice de saida:\n";
                cin >> item1;
                cout << "Digite o vertice de entrada:\n";
                cin >> item2;
                valor = grafo1.obterPeso(item1, item2);
                cout << "O peso dessa aresta e: " << valor << endl;
                break;

            case 5:
                grafo1.printMatriz();
                break;

            case 6:
                grafo1.printVertices();
                break;

            case 7:
                cout << "Digite o vertice de origem:\n";
                cin >> item1;
                cout << "Digite o vertice de destino:\n";
                cin >> item2;
                grafo1.buscaemlargura(item1, item2);
                break;

            case 8:
                cout << "Digite o vertice de origem:\n";
                cin >> item1;
                cout << "Digite o vertice de destino:\n";
                cin >> item2;
                grafo1.buscaemprofundidade(item1, item2);
                break;

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (menu != 0);

    return 0;
}
