#include "pilha.h"
#include <iostream>
using namespace std;

int Main()
{

    ItemType character;
    Stack stack;
    ItemType stackItem;

    cout << "Adicione uma String." << endl;
    cin.get(character);

    bool isMatched = true;

    while(isMatched && character != '\n'){
        if(character == '{' || character =='(' || character== '['){
                stack.push(character);
        }
        if(character =='}' || character== ')' || character== ']'){
            if(stack.isEmpty()){
                isMatched = false;
            } else{
                stackItem = stack.pop();
                isMatched = (
                    (character == '}' && stackItem== '{')
                    || (character== ')' && stackItem== '(')
                    || (character== ']' && stackItem=='[')
                );
            }
            cin.get(character);
        }
 if(isMatched && stack.isEmpty() ){
    cout << "Bem Formada \n";
 } else{
    cout << "Mal formada \n";
 }

    while (character != '\n')
    {
         stack.push(character);
        cin.get(character);
    }

    while (!stack.isEmpty())
    {
       stackItem = stack.pop();
        cout << stackItem;
    }

}
    }
  
