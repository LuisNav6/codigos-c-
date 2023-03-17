//
//  main.cpp
//  practica 6 struct
//
//  Created by Luis Navarrete on 10/03/21.
//
/*Aprende a usar variables globales con los struct,pero no estaremos usando este estilo durante el curso */
#include <stdio.h>

struct{//notar que el struct no tiene nombre
    char nom[30];
    float prom;
}est;//notar que hay una varible est
//esta variable es global y puede ser utilizado en cualquier parte del programa
void llenar();
int main(){
    llenar();
    /*notar que se esta usando la variable global que previamente capturamos
     datos desde la función llenar*/
    printf("\nNombre: %s ",est.nom);
    printf("\tPromedio: %.2f\n",est.prom);
}
void llenar(){
    /*notar que en esta funcion no hay declaraciones de variables del tipo del
     struct que se esta usando la variable global est*/
    printf("\nDame el nombre del estudiante:\n");
    gets(est.nom);
    printf("\nDame su promedio:");
    scanf("%f",&est.prom);
    
}

