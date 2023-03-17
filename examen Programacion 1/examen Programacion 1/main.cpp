//
//  main.cpp
//  examen Programacion 1
//
//  Created by Luis Navarrete on 14/09/21.
//

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstdio>

using namespace std;

typedef struct
{
    int id;
    char *nombre;
    float calificacion;
    float ajusteCali;
}estudiantes;
void submenuBinario();
void menu();
void LeerSecuencial(int a, int p );
float puntos(float cal, int a);
void vaciar(char temp[]);
void copiar(char temp[], int i);
void ajuste(int,int);
int ImprimirBin();
int CrearBin();

// vector dinamico para pasar de archivos secuenciales a binarios
estudiantes *estu;

int main(){
    {
        int a=0, p =0;
        int opc;
        
                    do{
                        submenuBinario();
                        cin >> opc;
                    switch(opc){
                        case 1:
                            LeerSecuencial(a,p);
                            break;
                        case 2:
                            ajuste(a,p);
                            break;
                    }
                }while(opc !=6);
    }
void LeerSecuencial(int a, int p){
    char temp[70];
    char aux;
    int cont=0;
    
    FILE *f;
    f = fopen("estudiantes.txt","r");
    if(f == NULL)
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    while(!feof(f))
    {
        fgets(temp,70,f);
        cont++;
    }
    
    rewind(f);
    
    estu = (estudiantes*)malloc(cont*sizeof(estudiantes));
    if(estu == NULL)
    {
        cout << "No se pudo reservar memoria!" << endl;
        exit(1);
    }
    
    int i = 0, j =0;
    for(i=0; !feof(f); i++)
    {
        vaciar(temp);
        aux = '0';
        for(j=0; aux != ' '; j++)
        {
            aux = fgetc(f);
            if(aux != ' ')
            {
                temp[j] = aux;
            }
        }
        copiar(temp,i);
        fgets(temp,8,f);
        estu[i].id = atoi(temp);
        
        fgets(temp,8,f);
        estu[i].calificacion = atof(temp);
        
        if(estu[i].calificacion >= 9)
        {
        a ++;
        p = i;
        cout<< endl <<"Id --> "<< estu[i].id;
        cout<< endl <<"Nombre --> "<< estu[i].nombre;
        cout<< endl <<"Calificacion --> "<< estu[i].calificacion;
        
        cout<<endl;
        }
    }
    
    ajuste(a,p);
    
    
    system("pause");
}

void copiar(char temp[], int i){
    int n = strlen(temp) + 1;
    estu[i].nombre = (char*)malloc(n*sizeof(char));
    if(estu[i].nombre == NULL)
    {
        cout << "No se pudo reservar memoria!";
        exit(1);
    }
    strcpy(estu[i].nombre,temp);
}

void vaciar(char temp[]){
    for(int i=0; i <= 70; i++)
    {
        temp[i] = '\0';
    }
}

int imprimirBin(){
    fstream archivo;
    
    archivo.open("clientes.dat", ios::binary|ios::in);
    
    if(!archivo)
    {
        cout << "No se pudo abrir el archivo " << endl;
        return 1;
    }
    
    estudiantes estu;
    
    while(!archivo.eof())
    {
        cout << "----------------------------------" << endl;
        cout<< endl <<"Id --> "<< estu.id;
        cout<< endl <<"Nombre --> "<< estu.nombre;
        cout<< endl <<"Calificacion --> "<< estu.calificacion;
        system("pause");
    }
    archivo.read((char *) &estu, sizeof(estudiantes));
    
    archivo.close();
}

int CrearBin(){
    // creando archivo binario
    fstream archivo;
    
    archivo.open("clientes.dat",ios::binary|ios::out);
    
    if(!archivo)
    {
        cerr << "No se pudo abrir el archivo " << endl;
        return 1;
    }
    estudiantes blanco = {0,"",0};
    
    for(int i = 0; i < 10; i++)
    {
        archivo.write(reinterpret_cast<char *> (&blanco), sizeof(estudiantes));
    }
    archivo.close();
}

void ajuste(int a,int b){
    // aplicando ajuste
    int s;
        for(int i= 0;i <= b;i++)
        {
            if(estu[i].calificacion >= 9)
            {
                s = puntos(estu[i].calificacion,a);
                if(s > 10)
                {
                    s = 10;
                }
                estu[i].calificacion = s;
            }
        }
    CrearBin();
    ImprimirBin();
}
float puntos(float cal, int a){
    float suma= 0;
    if(a < 5){
        suma = cal + 8;
        return suma;
    }
    else{
        suma = cal + 4;
        return suma;
    }
}
void submenuBinario(){
    system("cls");
    cout << "------> MENU BINARIO <------" << endl;
    cout << "[1] Leer los datos del archivo secuencial"<< endl;
    cout << "[2] Ajuste" << endl;
    cout << "[6] Regresar al menu anterior" << endl;
    cout << "Dame la opcion a insertar: " << endl;
}
