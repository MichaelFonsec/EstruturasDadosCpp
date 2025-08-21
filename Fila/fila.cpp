#include <iostream>
#include "fila.h";

using namespace std;

fila::fila()
{ // construtor
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_items];
}
fila::~fila()
{ // destrutor
    delete[] estrutura;
}
bool fila::filaCheia()
{ // isEmpty
    return (ultimo - primeiro == max_items);
}
bool fila::filaVazia()
{ // isFull
    return (primeiro == ultimo);
}
void fila::enqueue(TipoItem item)
{ // Inserir ||Push|
    if (filaCheia())
    {
        throw runtime_error("A fila esta cheia");
    }
    else
    {
        estrutura[ultimo % max_items] = item;
        ultimo++;
    }
}
TipoItem fila::dequeue()
{ // Remover||pop
    if (filaVazia())
    {
        throw runtime_error("Fila esta vazia");
        return 0;
    }
    else
    {
        primeiro++;
        return estrutura[(primeiro - 1) % max_items];
    }
}
void fila::print()
{
    cout << "Fila: [ ";
    for (int i = primeiro; i < ultimo; i++)
    {
        cout << estrutura[i % max_items] << " ";
    }
    cout << "]\n";
}
