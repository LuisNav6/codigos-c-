//
//  main.cpp
//  practica 5 struct
//
//  Created by Luis Navarrete on 09/03/21.
//
//asuntos varios de los struct
#include <stdio.h>
#include <string.h>
struct dispositivo{
    char tipo[30];
    float precio;
    int existencia;
};
void imprimir(dispositivo);
int main(){
    dispositivo dis1={"laptop",18000,13};
    dispositivo dis2,dis3;
    printf("\n\nImprimiendo el contenido de dis1:");
    imprimir(dis1);
    dis2=dis1;//ok valido
    printf("\n\nImprimiendo el contenido de dis2:");
    imprimir(dis2);
    //declarar un arreglo de estructuras e inicializarlo
    dispositivo d[3]={{"laptop",18000,13},{"mouse",600,20},{"impresora",1600,8}};
    printf("\nImprimiendo el contenido del arreglo de estructuras\n");
    for(int i=0;i<3;i++){
        imprimir(d[i]);
        printf("\n");
    }
    //pasando el contenido del arreglo en su posicion 2 a una variable del tipo
    //struct
    dis3=d[2];//ok valido
    printf("\n\nImprimiendo el contenido de dis3:");
    imprimir(dis3);
    //al reves tambien
    dispositivo dis4={"tableta",15000,4};
    d[0]=dis4;
    printf("\n\nImprimiendo el arreglo en su posición 0: ");
    imprimir(d[0]);
    //sacando a variables sencillas el contenido de los campos de su struct
    char tipod[30];float precio; int existencia;
    strcpy(tipod,dis3.tipo);
    precio=dis3.precio;
    existencia=dis3.existencia;
    printf("\nImprimiendo las variables donde pasamos los datos del struct: ");
    printf("\n%s %.2f %d",tipod,precio,existencia);
}
void imprimir(dispositivo aux){
    printf("\n%s %.2f %d",aux.tipo,aux.precio,aux.existencia);
}
