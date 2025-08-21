#include <iostream>
#include "time.h"
using namespace std;

int main(){

    Time t1(23, 59, 59); 
    t1.print(); // 23:59:59
    t1.setHour(12);
    t1.setMinute(30);
    t1.setSecond(15);

    t1.print(); // 12:30:15
    cout << "Hora:  " << t1.getHour() << endl;
    cout << "Minuto:  " << t1.getMinute() << endl;
    cout << "Segundo:  " << t1.getSecond() << endl;

  Time t2{12};  // lista de inicialização clara
    t2.print(); // 12:00:00

    Time t3(23, 59, 58);
    t3.print(); // 23:59:58
    t3.nextSecond();
    t3.print(); // 23:59:59
    t3.nextSecond();
    t3.print(); // 00:00:00

}