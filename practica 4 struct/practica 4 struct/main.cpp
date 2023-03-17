//
//  main.cpp
//  practica 4 struct
//
//  Created by Luis Navarrete on 06/03/21.
//

#include <stdio.h>
#define TAM 4
//declaracion de struct
struct alumno{
    char nombre[40];
    int edad;
    float promedio;
};
//prototipo de funciones
void llenar(alumno[]);
void imprimir(alumno []);//o tambien void imprimir alumno;
int main(){
    //declarando un arreglo de estructuras
    alumno arreglo[TAM];
    //llenando el vector
    llenar(arreglo);//pasamos completo el arreglo a la funcion
    imprimir(arreglo);//pasamos completo el arreglo a la funcion
    return 0;
}
void llenar(alumno aux[]){
    printf("\nLlenando el arreglo de estructuras...");
    for(int i=0;i<TAM;i++){
    printf("\nDame el nombre del alumno:\n");
    fflush(stdin);//limpiar buffer de entrada
    gets(aux[i].nombre);
    printf("\nDame la edad:");
    scanf("%d",&aux[i].edad);
    printf("\nDame el promedio:");
    scanf("%f",&aux[i].promedio);
    }//fin for
    /*se le aplica la misma regla que a cualquier arreglo, aunque no lo retorne,al volver al main regresa con los cambios*/
}//fin funcion llenar
void imprimir(alumno aux[]){
    printf("\nImprimiendo el arreglo de estructuras...");
    for(int i=0;i<TAM;i++){
        printf("\n");
        printf("\nNombre: %s",aux[i].nombre);
        printf("\nEdad: %d",aux[i].edad);
        printf("\nPromedio: %.2f",aux[i].promedio);
    }//fin del for
}//fin main

