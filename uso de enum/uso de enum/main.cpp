//
//  main.cpp
//  uso de enum
//
//  Created by Luis Navarrete on 30/03/21.
//

#include <iostream>
enum figuras{CUADRADO,TRIANGULO,CIRCULO};
enum suit{DIAMONDS=1,HEARTS,CLUBS,SPADES};
enum {PIEDRA=5,PAPEL,TIJERAS};
using namespace std;
int main(){
    figuras fig2;
    int n;
    cout<<endl<<"Dame un numero entre 0 y 2: ";
    cin>>n;
    //fig2=n ¡no es posible!
    cout<<endl<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    int num=6;
    if(num==PIEDRA){
        cout<<endl<<"Esta usando piedra";
    }
    if(num==TIJERAS){
    cout<<endl<<"Esta usando tijeraS";
    }else
        cout<<endl<<"Esta usando papel";
            
    cout<<endl<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    suit baraja;
    baraja=DIAMONDS;
    cout<<endl<<baraja;
    switch(baraja){
        case DIAMONDS:
            cout<<endl<<"DIAMANTE";
            break;
        case HEARTS:
            cout<<endl<<"CORAZONES";
            break;
        case CLUBS:
            cout<<endl<<"CLUBS";
            break;
        case SPADES:
            cout<<endl<<"ESPADAS";
            break;
    }
    cout<<endl<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    figuras fig;
    fig=CUADRADO;//ok
    cout<<endl<<fig;
    cout<<endl<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    cout<<endl<<CUADRADO;//0
    cout<<endl<<TRIANGULO;//1
    cout<<endl<<CIRCULO;//2
    return 0;
}
