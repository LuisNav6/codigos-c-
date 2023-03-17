//
//  main.cpp
//  Tfecha clase
//
//  Created by Luis Navarrete on 21/09/21.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
class Tfecha{
private:
    int dia,mes,year;
public:
    Tfecha();
    Tfecha(int,int,int);
    bool laborable();//solo tomaremos 6 dias que marca la ley del trabajo
    bool festivo();//10 de mayo,23 de agosto,15 de mayo
    void mañana();//a partir de la fecha del objeto que manda a llamar al metodo, que dia es mañana
    void ayer();//a partir de la fecha del objeto que manda a llamar al metodo, que dia fue ayer
    bool esBisiesto();//año con un dia más 
};
