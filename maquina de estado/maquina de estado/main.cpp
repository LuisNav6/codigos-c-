//
//  main.cpp
//  maquina de estado
//
//  Created by Luis Navarrete on 24/08/21.
//

#include <iostream>

using namespace std;




typedef enum {
    Estado_0, // Estado inicial
    Estado_1,
    Estado_2,
    Estado_3,
    Estado_4,
    No_de_Edos
} ESTADOS;

//-- Variable global de estado
ESTADOS Estado_Actual = Estado_0;

//-- Estructura de Maquina de Estados (FSM))
typedef struct {
    ESTADOS Estado;     // Estado miembro del conjunto enumerado ESTADOS
    void (*func)(int); // Acciones asociadas al estado
} FSM;

//-- Prototipos de funciones de estado
void Codigo_EDO_0(int);
void Codigo_EDO_1(int);
void Codigo_EDO_2(int);
void Codigo_EDO_3(int);
void Codigo_EDO_4(int);

//-- CreaciÛn de la estructura de la FSM
FSM Maquina_de_Estados[] = {
    {Estado_0,Codigo_EDO_0},
    {Estado_1,Codigo_EDO_1},
    {Estado_2,Codigo_EDO_2},
    {Estado_3,Codigo_EDO_3},
    {Estado_4,Codigo_EDO_4},
};

//-- Funciones de estado
void Codigo_EDO_0(int sw){
if(sw == 0)
    Estado_Actual = Estado_1;
else
    Estado_Actual = Estado_4;
}

void Codigo_EDO_1(int sw){

if(sw == 0)
    Estado_Actual = Estado_2;
else
    Estado_Actual = Estado_4;
}

void Codigo_EDO_2(int sw){

if(sw == 0)
    Estado_Actual = Estado_3;
else
    Estado_Actual = Estado_1;
}

void Codigo_EDO_3(int sw){
if(sw == 0)
    Estado_Actual = Estado_4;
else
    Estado_Actual = Estado_2;
}

void Codigo_EDO_4(int sw){
if(sw == 0)
    Estado_Actual = Estado_1;
else
    Estado_Actual = Estado_3;
}

int main()
{
    int input;

      cout << "Estado: " << Estado_Actual  << "\n";

       while(1){
           cout << "Input:" << "\n";
           cin >> input;
            (*Maquina_de_Estados[Estado_Actual].func)(input);

            cout << "Estado: " << Estado_Actual  << "\n";

    }

    return 0;
}
