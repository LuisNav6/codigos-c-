//
//  main.cpp
//  promedio con struct
//
//  Created by Luis Navarrete on 03/03/21.
//

#include <stdio.h>
//declaracion de struct
struct alumno{
    char nombre[40];
    int edad;
    float promedio;
};
//prototipos de funciones
int main(){
    //declarando una variable de tipo struct
    alumno al;
    //capturando datos para la variable al
    printf("\nDame el nombre del alumno:\n");
    gets(al.nombre);
    printf("\nDame la edad:");
    scanf("%d",&al.edad);
    printf("\nDame el promedio:");
    scanf("%f",&al.promedio);
    //imprimiendo los datos de la variable al;
    printf("\nImprimiendo...");
    printf("\nNombre %s",al.nombre);
    printf("\nEdad %d",al.edad);
    printf("\nPromedio %.2f",al.promedio);
    return 0;
}

