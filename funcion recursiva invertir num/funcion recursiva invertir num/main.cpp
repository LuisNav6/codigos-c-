//
//  main.cpp
//  funcion recursiva invertir num
//
//  Created by Luis Navarrete on 19/02/21.
//

#include <stdio.h>

void invertir(int);
void binario(int);
void menu(int);

int main(){
    invertir(8569);
    printf("\n");
    invertir(78);
    printf("\n");
    invertir(290);
    printf("\n");
    
    binario(18);
    printf("\n");
    binario(6);
    printf("\n");
    binario(74);
    printf("\n");
    
    menu(0); // cualquier numero entero que no sea la opcion de salir del menu
}

void menu(int opc){
    if(opc != 3){
        printf("\n1 Altas");
        printf("\n2 Bajas");
        printf("\n3 Salir");
        printf("\nCual opcion deseas?: ");
        scanf("%d",&opc);
        switch(opc){
            case 1: printf("Seleccionaste Altas");break;
            case 2: printf("Seleccionaste Bajas");break;
            case 3: printf("Buenas noches ...");break;
            default: printf("Coloca un numero valido!");break;
        }
        menu(opc);
    }
}

void invertir(int n){
    int cociente,res=0;
    cociente = n /10;
    res = n % 10;
    printf("%d",res);
    if(cociente != 0){
        invertir(cociente);
    }
}

void binario(int n){
    int cociente,res=0;
    cociente = n / 2;
    res = n % 2;
    if(cociente !=0){
        binario(cociente);
    
    }
    printf("%d",res);
}
