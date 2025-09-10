#ifndef NODE_H //Se não está definido um Node.h
#define NODE_H // Defina um Node.h

#include <iostream>

using namespace std;

typedef string TipoItem;

struct Node
{
    TipoItem valor;
    Node* proximo;
};

#endif // Node.h ser chamado em varios lugares ele evita dá conflito nas definições do Node.h 