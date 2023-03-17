
//
//  main.cpp
//  struct estados
//
//  Created by Luis Navarrete on 11/03/21.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define TAM 8//prueba con 3 luego pueden ser más estados
//las estructuras se declaran abajo de las directivas
struct estados{
    char nom[30];
    int total;
    float temp;
};
//los prototipos van abajo de los struct
void llenar(estados est[TAM]);
void imprimir(estados est[TAM]);
int revisar(estados est[TAM],char estados[30],int j);
void masbaja(estados est[TAM]);//caso 2
void masalta(estados est[TAM]);
float promedio(estados est[TAM]);
int main(int argc,char** argv){
    //declarar un arreglo de tipo de la estructura
    estados est[TAM];
    llenar (est);
    imprimir (est);
    masbaja(est);
    masalta(est);
    float prom=promedio(est);
    printf("\nEl promedio de temperatura es: %.2f\n",prom);
    return 0;
    
}
void llenar(estados est[TAM]){
    printf("\nLlenando vector...");
    char nomedos[12][30]={"jalisco","nayarit","Guanajuato","Michoacan","ed.Mx","puebla","colima","tlaxcala","Nuevo leon","tamaulipas","veracruz","coahuila"};
    int n;
    int band;
    for(int i=0;i<TAM;i++){
        //validacion para que no se repitan estados
        do{
        n=0+rand()%(11-0+1);//genera un aleatorio entre 0 y 11
        band=revisar(est,nomedos[n],i);
        if(band==0)
    strcpy(est[i].nom,nomedos[n]);
                   }while(band==1);
        est[i].total=11+rand()%(160-11+1);//aleatorios entre 11 y 160
        est[i].temp=0.01+rand()/((RAND_MAX)/40-1.0);//aleatorios decimales
    }
   
    }
void imprimir(estados est[TAM]){
    printf("\nImprimiendo vector...");
    printf("\n%-30s %-30s %-30s","Estado","Total de municipios","promedio de temperatura");
    for(int i=0;i<TAM;i++){
        printf("\n%-38s %-38d %-30.2f",est[i].nom,est[i].total,est[i].temp);
}
            }

int revisar(estados est[TAM],char estados[30],int j){
                for(int i=0;i<j;i++){
                    if(strcmp(est[i].nom,estados)==0)
                        return 1;//el estado esta repetido
                }
                return 0;//podemos meter el estado al arreglo
            }
void masbaja(estados est[TAM]){
    float baja;
    int posicion;
    baja=est[0].temp;
    posicion=0;
    for(int i=1;i<TAM;i++){
        if(est[i].temp<baja){
            baja=est[i].temp;
            posicion=i;
        }//fin if
        }//fin for
    printf("\nEstado con la temperatura más baja es: %s con %.2f grados\n",est[posicion].nom,baja);
}
void masalta(estados est[TAM]){
    int posicion;
    float alta;
    alta=est[0].temp;
    posicion=0;
    for(int i=1;i<TAM;i++){
        if(est[i].temp>alta){
            alta=est[i].temp;
            posicion=i;
        }//fin if
        }//fin for
    printf("\nEstado con la temperatura más alta es: %s con %.2f grados\n",est[posicion].nom,alta);
}
float promedio(estados est[TAM]){
    float acum=0;
    for(int i=0;i<TAM;i++){
        acum+=est[i].temp;
    }
    return acum/TAM;
}
