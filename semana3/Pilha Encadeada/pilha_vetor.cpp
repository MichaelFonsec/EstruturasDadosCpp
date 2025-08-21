#include "pilha.h"
#include <iostream>
using namespace std;

Stack::~Stack()
{
    structure = NULL;
}

Stack::~Stack()
{
    NodeType *ponteiroTemporario;
    while (structure != NULL)
    {
        ponteiroTemporario = structure;
        structure = structure->next;
        delete ponteiroTemporario;
    }
}

bool Stack::isEmpty() const
{
    return (structure == NULL);
}

bool Stack::isFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (const std::exception &e)
    {
        return true;
    }
}

void Stack::push(ItemType item)
{
    if (!isFull())
    {
        NodeType *location;
        location = new NodeType;
        location->info = item;
        location->next = structure;
        structure = location;
    }
    else
    {
        throw "A pilha já está cheia.";
    }
}

ItemType Stack::pop()
{
    if (!isEmpty())
    {
        NodeType *ponteiroTemporario;
        ponteiroTemporario = structure;
        ItemType item = structure->info;
        structure = structure->next;
        delete ponteiroTemporario;
        return item;
    }
    else
    {
        throw "A pilha está Vazia.";
    }
}

void Stack::print() const
{
    NodeType *ponteiroTemporario = structure;
    while (ponteiroTemporario != NULL)
    {
        cout << ponteiroTemporario->info;
        ponteiroTemporario = ponteiroTemporario->next;
    }
    cout << endl;
}

