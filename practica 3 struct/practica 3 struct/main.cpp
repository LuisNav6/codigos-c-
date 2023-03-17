//
//  main.cpp
//  practica 3 struct
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
alumno llenar();
void imprimir(alumno aux);//o tambien void imprimir alumno;
int main(){
    //declarando un arreglo de estructuras
    alumno al[TAM];
    //llenando el vector
    for(int i=0;i<TAM;i++){
        printf("\nAlumno #%d\n",i);
        al[i]=llenar();
        }//fin for
//imprimiendo el vector
    printf("\nImprimiendo vector");
    for(int i=0;i<TAM;i++){
        imprimir(al[i]);//llamamos a funcion imprimir pasando vector en su casilla i
    }//fin for
    return 0;
}
alumno llenar(){
    alumno aux;//variable local
    printf("\nDame el nombre del alumno:\n");
    fflush(stdin);//limpiar buffer de entrada
    gets(aux.nombre);
    printf("\nDame la edad:");
    scanf("%d",&aux.edad);
    printf("\nDame el promedio:");
    scanf("%f",&aux.promedio);
    return aux;
}
void imprimir(alumno aux){
    printf("\nNombre: %s",aux.nombre);
    printf("\nEdad: %d",aux.edad);
    printf("\nPromedio: %.2f",aux.promedio);
}
