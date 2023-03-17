//
//  main.cpp
//  enum-juego crabs
//
//  Created by Luis Navarrete on 29/03/21.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
enum Status {CONTINUA,GANA,PIERDE};
int tiradados(void);//prototipo de la funcion
using namespace std;
int main(){
    int suma;
    int mipunto = 0;
    char resp='s';
    Status estadojuego;//puede contener CONTINUA,GANA,PIERDE
    //RANDOMIZA EL GENERADOR DE NUMEROS ALEATORIOS MEDIANTE TIME
    srand(time_t(0));//semillero de randoms
    while(resp=='s'){
        system("cls");
        suma=tiradados();//primer tirada de dados
        //determine el estatus del juego y la puntuacion en base a suma de puntos del dado
        switch(suma){
                //gana al primer tiro
            case 7:
            case 11:
                estadojuego=GANA;
                break;
                //pierde en el primer tiro
            case 2:
            case 3:
            case 12:
                estadojuego=PIERDE;
                break;
                //recauda puntos
            default:
                estadojuego=CONTINUA;
                mipunto=suma;
                cout<<"\n Tu punto es: "<<mipunto<<" sigues jugando\n"<<endl;
                break;//opcional
        }//fin del switch
        
        //mientras el juego no se complete
        while(estadojuego==CONTINUA){
            suma=tiradados();//tira dados nuevamente
            //determina el estado del juego
            if(suma==mipunto)//gana por puntos
                estadojuego=GANA;
            else
                if(suma==7)
                    estadojuego=PIERDE;
            
        }//fin while
        //despliega msj de ganador o perdedor
        if(estadojuego==GANA)
            cout<<endl<<"jugador gana";
        else
            cout<<endl<<"jugador pierde";
        cout<<endl<<"Deseas jugar de nuevo(s/n): ";
        fflush(stdin);
        cin>>resp;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}//fin del main

//tira dados,calcula la suma y despliega el resultado
int tiradados(){
    int dado1;
    int dado2;
    int sumatrabajo;
    dado1=1+rand()%6;
    dado2=1+rand()%6;
    sumatrabajo=dado1+dado2;
    //despliegue los datos del tiro
    cout<<endl<<"Jugador tiro: "<<dado1<<"+"<<dado2<<"="<<sumatrabajo<<endl;
    return sumatrabajo;//devuelve la suma de los dados
}//fin de la funcion tiradados()





