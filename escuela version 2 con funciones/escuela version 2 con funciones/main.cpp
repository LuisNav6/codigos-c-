//
//  main.cpp
//  escuela version 2 con funciones
//
//  Created by Luis Navarrete on 08/04/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>///<-------------------------- funcion convert pasar de un dato numerico a cadena

#define TAM 15

using namespace std;

enum tpersona {ALUMNOS=1, MAESTROS, SECRETARIAS};

union campo{
    float promedio;
    float salario;
    float compensacion;
};

struct escuela{
    string nombre;
    string direccion;
    string telefono;
    
    tpersona tipo;//el campo tipo es del tipo del enum
    campo dato;//el campo dato es del tipo de la union
};

void llenar(escuela miescuela[TAM]);
void imprimir(escuela miescuela[TAM]);
void consultar(escuela miescuela[TAM],int aux);
string convert (int number);///<--------------------------
void total(escuela miescuela[TAM]);
void promedio(escuela miescuela[TAM]);
float sueldos(escuela miescuela[TAM]);
void compensacion(escuela miescuela[TAM], float liminf, float limsup);
int main(){
    srand(time_t(0));///<--------------------------
    char resp;///<--------------------------
    int aux;
    escuela miescuela[TAM];//arreglo de estructuras
    llenar(miescuela);
    imprimir(miescuela);
    cout << endl << "***************************************";
    total(miescuela);
    cout << endl << "***************************************";
    cout<<endl<<"Alumnos con promedio mayor a 8: ";
    promedio(miescuela);
    cout << endl << "***************************************";
    cout<<endl<<" La sumatoria de sueldos de MAESTROS es: "<<sueldos(miescuela);
    cout << endl << "***************************************";
    float liminf, limsup;
    cout<<endl<<"Dame el limite inferior: ";
    cin>>liminf;
    do{
    cout<<endl<<"Dame el limite superior: ";
    cin>>limsup;
    }while(limsup<liminf);
    
    compensacion(miescuela,liminf,limsup);
    do{ ///<--------------------------
    
        do{
        
         cout<<endl<<"Que quieres consultar 1 ALUMNOS 2 MAESTROS 3 SECRETARIAS ";
         cin>>aux;
        
        }while(aux<1 || aux>3);
        
        consultar(miescuela,aux);
        
        cout<<endl<<"otra consulta s/n ";///<----------------------------
        fflush(stdin);///<----------------------------
        cin>>resp;///<----------------------------
        
    }while(resp=='s');///<----------------------------
    
    return 0;
}//fin main

void total(escuela miescuela[TAM])
{
    int contA,contM,contS;
    contA=contM=contS= 0;
    for(int i=0; i < TAM; i++)
    {
        switch(miescuela[i].tipo)
        {
            case ALUMNOS : contA++; break;
            case MAESTROS : contM++; break;
            case SECRETARIAS :contS++; break;
        }
    }
    cout << endl << "Total de Alumnos: " << contA;
    cout << endl << "Total de Maestros: " << contM;
    cout << endl << "Total de Secretarias: " << contS;
}

void consultar(escuela miescuela[TAM],int aux){
   if (aux==ALUMNOS)
       cout<<endl<<"Reporte de alumnos";
       else if( aux == MAESTROS)
              cout<<endl<<"Reporte de maestros";
              else
               cout<<endl<<"Reporte de secretarias";
    for (int i=0; i<TAM; i++){
        if ( miescuela[i].tipo == aux){
            cout<<endl<<"Nombre: "<<miescuela[i].nombre;
            cout<<endl<<"Direccion: "<<miescuela[i].direccion;
            cout<<endl<<"Telefono: "<<miescuela[i].telefono;
            switch ( miescuela[i].tipo   ){
             case ALUMNOS: cout<<endl<<"Alumno su promedio es "<<miescuela[i].dato.promedio;
                          break;
              case  MAESTROS: cout<<endl<<"Maestro su salario es "<<miescuela[i].dato.salario;
                            break;
             case SECRETARIAS: cout<<endl<<"Secretaria tu compensacion es "<<miescuela[i].dato.compensacion;
                              break;
            
            }//fin switch
            cout<<endl;
        }//fin if
    }//fin for
}//fin funcion


void imprimir(escuela miescuela[TAM]){
    cout<<endl<<"Imprimiendo datos "<<endl<<endl;
    for (int i=0; i<TAM; i++){
        cout<<endl<<"Persona # "<<i+1;
        cout<<endl<<"Nombre: "<<miescuela[i].nombre;
        cout<<endl<<"Direccion: "<<miescuela[i].direccion;
        cout<<endl<<"Telefono: "<<miescuela[i].telefono;
        switch ( miescuela[i].tipo   ){
            case ALUMNOS: cout<<endl<<"Alumno su promedio es "<<miescuela[i].dato.promedio;
                          break;
            case  MAESTROS: cout<<endl<<"Maestro su salario es "<<miescuela[i].dato.salario;
                            break;
            case SECRETARIAS: cout<<endl<<"Secretaria tu compensacion es "<<miescuela[i].dato.compensacion;
                              break;
            
        }//fin switch
        cout<<endl;
    }//fin for
    
}//fin de imprimir


void llenar(escuela miescuela[TAM]){ ///<---------------------------- cambio la mayor parte de la funcion, no acepta capturas por teclado
    
    int aux, aleatorio1, aleatorio2;
    
    string nom [20]={"Alejandro ","Luci ","Victor ","Anabel ","Pablo ","Gaby ","Patricio ","Rocio ","Cristobal ","Flor ","Mario ","Johana ","Daniel ","Dulce ","Angel ","Miranda ","Esteban ","Vanessa","Alberto ","Julia "};
    string apellidos[20] ={"Barba","Delgado","Diaz","Jimenez","Avila","Alva","Hernandez","Garcia","Martinez","Lopez","Gonzalez","Perez","Rodriguez","Sanchez","Cruz","Ramirez","Flores","Gomez","salazar","comte"};
    string direcciones[22]={"lima","peru","dorado","navarrete","lopez mateos","golondrinas","argentina","montevideo","campeche","paris","londres","sierra nevada","montes apalaches","sierra pintada","avenida universidad","circunvalacion sur","circunvalacion norte","madero","centro","nieto","allende","victoria"};
    
    cout<<endl<<"Generando datos aleatoriamente ... ";
    for (int i=0; i<TAM; i++){
        
        
        aleatorio1= 0+rand()%(19-0+1);
        aleatorio2= 0+rand()%(19-0+1);
        
        //colocar nombre
        miescuela[i].nombre= nom[aleatorio1]+" "+apellidos[aleatorio2];
        //cout<<endl<<miescuela[i].nombre;
        
        //colocar direccion
        aleatorio1= 0+rand()%(21-0+1);
        aleatorio2=100 + rand()%(999-100+1); //aleatorio para el numero de la calle
    
        miescuela[i].direccion=direcciones[aleatorio1]+" "+convert(aleatorio2);
        //cout<<endl<<miescuela[i].direccion;
        
        //colocar telefono
        aleatorio1=1000000+rand()%(1200000-1000000+1);
        miescuela[i].telefono="449 "+convert(aleatorio1);
        //cout<<endl<<miescuela[i].telefono;
        
        aux=1 + rand()%(3-1+1); //aleatorio para el tipo de persona
        
        switch(aux){
            case ALUMNOS:    miescuela[i].tipo=ALUMNOS;
                             //generando promedio aleatoriamente
                             aleatorio1 = 6 + rand()%(10-6+1);//para parte entera
                             aleatorio2 = 10 + rand()%(99-10+1); //para los decimales
                         
                             miescuela[i].dato.promedio=aleatorio1+aleatorio2/100.0;
                             break;
                             
            case MAESTROS:   miescuela[i].tipo = MAESTROS;
                             //generando salario aleatoriamente
                             miescuela[i].dato.salario=1200+rand()%(15000-1200+1);
                             break;
                                
            case SECRETARIAS: miescuela[i].tipo = SECRETARIAS;
                            //generando compensacion aleatoriamente
                              miescuela[i].dato.compensacion=600+rand()%(1500-600+1);
                              break;
        }//fin switch
    }//fin de for
    cout<<endl<<"Listo ... "<<endl<<endl;
}//fin de funcion llenar


string convert (int number){
    ostringstream buff;
    buff<<number;
    
    return buff.str();
}
void promedio(escuela miescuela[TAM]){
    int band=0;
    for(int i=0;i<TAM;i++){
        if(miescuela[i].tipo==ALUMNOS){
            if(miescuela[i].dato.promedio>=8){
                band=1;
                cout<<endl<<"Nombre: "<<miescuela[i].nombre;
                cout<<endl<<"Promedio: "<<miescuela[i].dato.promedio;
            }//fin if
        }//fin if
    }//fin for
    if(band==0)
        cout<<endl<<"No hay alumnos con promedio mayor a 8";
}//fin funcion
float sueldos(escuela miescuela[TAM]){
    float suma=0;
    for(int i=0;i<TAM;i++){
        if(miescuela[i].tipo==MAESTROS){
            suma+=miescuela[i].dato.salario;
        }//fin if
    }//fin for
    return suma;
}//fin funcion
void compensacion(escuela miescuela[TAM], float liminf, float limsup){
    int cont=0;
    cout<<endl<<"LIsta de secretarias con compensacion entre: "<<liminf<<" y "<<limsup<<" pesos ";
    for(int i=0;i<TAM;i++){
        if(miescuela[i].tipo==SECRETARIAS){
            if(miescuela[i].dato.compensacion>=liminf && miescuela[i].dato.compensacion<=limsup){
                cont++;
                cout<<endl;
                cout<<endl<<"Nombre: "<<miescuela[i].nombre;
                cout<<endl<<"Direccion: "<<miescuela[i].direccion;
                cout<<endl<<"Telefono: "<<miescuela[i].telefono;
                cout<<endl<<"Tu  compensacion: "<<miescuela[i].dato.compensacion;
            }//fin if
        }//FIN IF
    }//fin for
    if(cont==0){
    cout<<endl<<"Ninguna secretaria tiene una compensacion en ese rango!";
    }else
        cout<<endl<<"El total de secretarias que cumplen con los requerimientos son : "<<cont;
    
}//fin funcion
