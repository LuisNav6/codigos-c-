//
//  main.cpp
//  matriz de char
//
//  Created by Luis Navarrete on 26/05/21.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>
// las matrices char pueden trabajarse con un solo ciclo a diferencia de las matrices numericas que requieren  los dos ciclos

void llenar(char **nombre, int ren);
void imprimir(char **nombre, int ren);
void ordenar(char **nombre, int ren);

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time_t(0));//semillero aleatorios
    char **nombre;//declaracion de un puntero a un puntero
    int n;
    do{
        cout<<endl<<"cuantos nombres quieres guardar (3-10): ";
        cin>>n;
    }while(n<3||n>10);
//creacion de una matriz numerica de n*30;
    nombre=new char* [n];
    for(int i=0;i<n;i++)
    nombre[i]=new char[30];
    llenar(nombre,n);
    imprimir(nombre,n);
    ordenar(nombre,n);
    imprimir(nombre,n);
}
void llenar(char **nombre, int ren){
    char nom[15][30]={"luis","humberto","jose","antonio","janeth","martha","alan","christian","fernando","leslie","sthepanie","juan","arturo","misael","galilea"};
    int posicion;
    for(int i=0;i<ren;i++){
        posicion=0+rand()%(14-0+1);//genera aleatorios entre 0 y 14
        strcpy(nombre[i],nom[posicion]);//copia la matriz en su posicion i, y el nombre que este en la matriz nom en su casilla posicion, los nombres se pueden repetir en la matriz nom, no se tiene la validacion que lo impida
    }
}
void imprimir(char **nombre, int ren){
    cout<<endl<<"Imprimiendo nombres....."<<endl;
    for(int i=0;i<ren;i++){
        cout<<endl<<setw(4)<<i+1<<" "<<nombre[i];//imprime el nombre que este en el renglon 1
    }
}
void ordenar(char **nombre, int ren){
    cout<<endl<<"Ordenando Ascendentemente...."<<endl;
    char *aux;
    int comp;
    //metodo de la ordenacion de la  burbuja
    for(int i=0;i<ren-1;i++){
        for(int j=i+1;j<ren;j++){
            comp=strcmp(nombre[i],nombre[j]);
            if(comp>0){
                aux=nombre[i];
                nombre[i]=nombre[j];
                nombre[j]=aux;
            }
        }
    }
}
