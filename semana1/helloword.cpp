#include <iostream>

using namespace std;

int main(){
    std::cout << "Ola Mundo" << std::endl;


    int number1;
    int counter = 0;
    int amout = 0;

    while (counter < 10){
       
     cout << "Digite um numero (" <<counter << ")" << endl;
        cin >> number1;

        if (number1 < 5)
        {
            amout++;
        }
        counter++;
    }
     return 0;
}