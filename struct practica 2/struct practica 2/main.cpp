//
//  main.cpp
//  struct practica 2
//
//  Created by Luis Navarrete on 03/03/21.
//

#include <stdio.h>
//declaracion struct
struct alumno{
    char nombre[40];
    int edad;
    float promedio;
};
//prototipos de funciones
alumno llenar();
void imprimir(alumno aux);//tambien void imprimir(alumno)
int main(){
    //declarando una variable de tipo struct
    alumno al;
    al=llenar();//llamar a funcion llenar
    imprimir(al);//llamar a la funcion imprimir
    //declarando una variable de tipo struct e inicializandola
    alumno mialumno={"el mencho",23,7.2};//el orden debe corresponder al orden de la estructura
    //mandamos a llamar a la funcion imprimir
    imprimir(mialumno);
    
    return 0;
}
alumno llenar(){
    alumno aux;//variable local
    printf("\nDame el nombre del alunmno:\n");
    gets(aux.nombre);
    printf("\nDame la edad:");
    scanf("%d",&aux.edad);
    printf("\nDame el promedio:");
    scanf("%f",&aux.promedio);
    return aux;
}
void imprimir(alumno aux){
    printf("\nImprimiendo....");
    printf("\nNombre: %s",aux.nombre);
    printf("\nEdad: %d",aux.edad);
    printf("\nPromedio: %.2f",aux.promedio);
}
