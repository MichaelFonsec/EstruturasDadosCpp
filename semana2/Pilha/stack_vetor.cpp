#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    length = 0;
    structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack()
{
    delete [] structure;
}

bool Stack::isEmpty() const{
 return (length == 0); 
}
 bool Stack::isFull() const{
    return (length == MAX_ITEMS);
 }

 void Stack::push(ItemType item){
    if(!isFull()){
        structure[length] = item;
        length++;
    } else{
        throw "A pilha já está cheia.";
    }
 }

 ItemType Stack::pop()
 {
    if(!isEmpty()){
        ItemType aux = structure[length -1];
        length--;
        return aux;
    }
 }

 void Stack::print() const{
    cout << "Pilha = ";
    for (int i = 0; i < length; i++){
        cout << structure[i];
    }
    cout << endl;
 }

