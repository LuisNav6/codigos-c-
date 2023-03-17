//
//  main.cpp
//  Libreria union struct enum
//
//  Created by Luis Navarrete on 09/04/21.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string.h>
#define TAM 15
using namespace std;
enum tipopublicacion{LIBROS=1,REVISTAS,PERIODICO};
union informacion{/*Es decir una variable del tipo enum solo se puede utilizar una de las 3 struct, notar que cada struct tiene su variable de trabajo, el struct datosrevista se trabaja con la variable drev, el struct datosperiodico se trabaja con la variable dperiodico, y el struct datoslibro se trabaja con al variable dlibro*/
    struct datosrevista{
        int numero;
        int mes;
        int anio;
    
    }drev;
    struct datosperiodico{
        float precio;
        int totalejemplares;
      
    }dperiodico;
    struct datoslibro{
        int totalpaginas;
        char categoria[30];//no es posible usar del tipo string dentro del struct que es campo de una union,se tiene que trabajar la varible como vector de char
     
    }dlibro;
};
struct publicaciones{
    string nompub;//un struct si acepta el tipo de dato string
    tipopublicacion tipo; //campo del tipo del enum;
    informacion inf; //inf es un campo del tipo de la union, solo se puede usar uno de los struct a la vez, para poder utilizar este campo seguir esta sintaxis, por ejemplo si quieres el precio de un periodico: cin>> pub[i].inf.dperiodico.precio; notar que se teclea inf que es el campo de la union y se teclea dperiodico que es la  variable de trabajo de ese struct y finalmente el dato que les interesa
};
//prototipos
void imprimir(publicaciones pub[TAM]);
void consulta(publicaciones pub[TAM]);
void llenar(publicaciones pub[TAM]);
void lista(publicaciones pub[TAM],int cat);
void catlibro(publicaciones pub[TAM],char catlib[30]);
void nombre(publicaciones pub[TAM],string publ);
void rev(publicaciones pub[TAM],int a);
int per(publicaciones pub[TAM]);
int main(){
    srand(time_t(0));
    publicaciones pub[TAM];
    int cat;
    char catlib[30];
    string publ;
    int a;
    int total;
    llenar(pub);
    imprimir(pub);
    cout<<endl<<"--------------------------------------------"<<endl;
    cout<<endl<<"Dame la categoria que deseas (1)LIBROS, (2)REVISTAS, (3)PERIÓDICO: ";
    cin>>cat;
    lista(pub,cat);
    cout<<endl<<"--------------------------------------------"<<endl;
    consulta(pub);
    cout<<endl<<"--------------------------------------------"<<endl;
    cout<<endl<<"Dame la categoría a buscar en LIBROS: ";
    cin.getline(catlib,30);
    catlibro(pub,catlib);
    cout<<endl<<"--------------------------------------------"<<endl;
    cout<<endl<<"Dame el nombre de la publicación a buscar: ";
    getline(cin,publ);
    nombre(pub,publ);
    cout<<endl<<"--------------------------------------------"<<endl;
    cout<<endl<<"Dame el año a utilizar: ";
    cin>>a;
    rev(pub,a);
    cout<<endl<<"--------------------------------------------"<<endl;
    total=per(pub);
    cout<<endl<<"El total de periódicos registrados son: "<<total;
    //completar el main
    return 0;
}
int per(publicaciones pub[TAM]){
    int cont=0;
    for(int i=0;i<TAM;i++){
        switch(pub[i].tipo){
            case PERIODICO:
                cont++;
                break;
        }
    }
        return cont;
}
void rev(publicaciones pub[TAM],int a){
    int band=0;
    for(int i=0;i<TAM;i++){
        if(pub[i].inf.drev.anio==a){
            band=1;
            cout<<endl<<"REVISTA";
            cout<<endl<<"Nombre: "<<pub[i].nompub;
            cout<<endl<<"Numero: "<<pub[i].inf.drev.numero;
            cout<<endl<<"Mes: "<<pub[i].inf.drev.mes;
            cout<<endl<<"Año: "<<pub[i].inf.drev.anio;
        }
    }
    if(band==0){
        cout<<endl<<"No hay revistas de ese año!"<<endl;
    }
}
void nombre(publicaciones pub[TAM],string publ){
    int band=0;
    for(int i=0;i<TAM;i++){
        if(pub[i].nompub==publ){
            band=1;
            switch(pub[i].tipo){
                case LIBROS:
                    cout<<endl<<"LIBRO";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Categoria: "<<pub[i].inf.dlibro.categoria;
                    cout<<endl<<"Numero de paginas: "<<pub[i].inf.dlibro.totalpaginas;
                    break;
                case REVISTAS:
                    cout<<endl<<"REVISTA";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Numero: "<<pub[i].inf.drev.numero;
                    cout<<endl<<"Mes: "<<pub[i].inf.drev.mes;
                    cout<<endl<<"Año: "<<pub[i].inf.drev.anio;
                    break;
                case PERIODICO:
                    cout<<endl<<"PERIÓDICO";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Precio: "<<pub[i].inf.dperiodico.precio;
                    cout<<endl<<"Total de ejemplares: "<< pub[i].inf.dperiodico.totalejemplares;
                    break;
            }
        }
    }
    if(band==0){
        cout<<endl<<"Nombre no registrado!"<<endl;
    }
}
void catlibro(publicaciones pub[TAM],char catlib){
    int band=0;
    for(int i=0;i<TAM;i++){
        if(strcmp(pub[i].inf.dlibro.categoria,catlib)==0){
            band=1;
            cout<<endl<<"LIBROS";
            cout<<endl<<"Nombre: "<<pub[i].nompub;
            cout<<endl<<"Categoria: "<<pub[i].inf.dlibro.categoria;
            cout<<endl<<"Numero de páginas : "<<pub[i].inf.dlibro.totalpaginas;
        }//fin if
    }//fin for
    cout<<endl<<"No existen ejemplares!";
}
void lista(publicaciones pub[TAM],int cat){
    int band=0;
    for(int i=0;i<TAM;i++){
        if(pub[i].tipo==cat){
        band=1;
            switch(pub[i].tipo){
                case LIBROS:
                    cout<<endl<<"LIBROS";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Categoria: "<<pub[i].inf.dlibro.categoria;
                    cout<<endl<<"Numero de páginas : "<<pub[i].inf.dlibro.totalpaginas;
                   
                    break;
                case REVISTAS:
                    cout<<endl<<"REVISTAS";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Número: "<<pub[i].inf.drev.numero;
                    cout<<endl<<"Mes: "<<pub[i].inf.drev.mes;
                    cout<<endl<<"Año: "<<pub[i].inf.drev.anio;
                    
                    break;
                case PERIODICO:
                    cout<<endl<<"PERIÓDICO";
                    cout<<endl<<"Nombre: "<<pub[i].nompub;
                    cout<<endl<<"Precio:  "<<pub[i].inf.dperiodico.precio;
                    cout<<endl<<"Total de ejemplares: "<<pub[i].inf.dperiodico.totalejemplares;
                    break;
            }//fin switch
        }//fin if
    }//fin for
    if(band==0){
        cout<<endl<<"No hay ejemplares existentes!"<<endl;
    }
}//fin funcion
void imprimir(publicaciones pub[TAM]){
    cout<<endl<<endl<<"---------------REPORTE DE PUBLICACIONES-----------------";
    for(int i=0;i<TAM;i++){
        cout<<endl<<endl<<"Datos de la publicación guardada en la posición#"<<i<<endl;
        switch(pub[i].tipo){
                
            case LIBROS:
                cout<<endl<<"LIBROS";
                cout<<endl<<"Nombre: "<<pub[i].nompub;
                cout<<endl<<"Categoria: "<<pub[i].inf.dlibro.categoria;
                cout<<endl<<"Numero de páginas : "<<pub[i].inf.dlibro.totalpaginas;
                break;
            case REVISTAS:
                cout<<endl<<"REVISTAS";
                cout<<endl<<"Nombre: "<<pub[i].nompub;
                cout<<endl<<"Número: "<<pub[i].inf.drev.numero;
                cout<<endl<<"Mes: "<<pub[i].inf.drev.mes;
                cout<<endl<<"Año: "<<pub[i].inf.drev.anio;
                break;
            case PERIODICO:
                cout<<endl<<"PERIÓDICO";
                cout<<endl<<"Nombre: "<<pub[i].nompub;
                cout<<endl<<"Precio:  "<<pub[i].inf.dperiodico.precio;
                cout<<endl<<"Total de ejemplares: "<<pub[i].inf.dperiodico.totalejemplares;
                break;
        }
    }
}
void consulta(publicaciones pub[TAM]){
    int cont1=0,cont2=0,cont3=0;
    cout<<endl<<endl<<"-----TOTAL DE PUBLICACIONES--------";
    for(int i=0;i<TAM;i++){
        switch(pub[i].tipo){
    
            case LIBROS:
                cont1++;
                break;
            case REVISTAS:
                cont2++;
                break;
            case PERIODICO:
                cont3++;
                break;
        }//fin switch
    }//fin for
    cout<<endl<<endl<<"Total de publicaciones: "<<TAM;
    cout<<endl<<"Total de Libros: "<<cont1;
    cout<<endl<<"Total de Revistas: "<<cont2;
    cout<<endl<<"Total de Periodicos: "<<cont3;
}
void llenar(publicaciones pub[TAM]){
    int aleatorio1, aleatorio2,aux;
    cout << endl << "Llenando el vector...";
    string nompub[10]={"Padre Rico y Padre pobre","El Cov-19","El dólar","El principito","TvyNovelas","Forbes","El sol de Aguascalientes","El heraldo","La vuelta al mundo","El mencho"};
    string nomrev[10]={"El curioso","ESPN","El gol","Ciencia","El mundo salvaje","La vacuna","La oreja de Van Gogh", "El mencho","El policia"};
    string nomper[10]={"El heraldo","El sol de Ags","El misterioso","New York times","El tiempo","El espectador","Código Rojo","La bolsa","Salud y Ciencia","Encuentralo ya"};
    string nomlib[10]={"Padre rico y Padre pobre","Inquebrantable","tiende tu cama","El quiubole","Bob esponja","Atlas","El alquimista","Maléfica","Porque los hombres aman a las cabronas","Los juegos del hambre"};
    char  cat[10][30]={"Economía","Literatura","Infantil","Narcotráfico","Salud","Seguridad","Farándula","Mitología","arte","Aleatorio"};
    for(int i=0; i < TAM; i++){
        aleatorio1=0+rand()%(9-0+1);
        aleatorio2=0+rand()%(9-0+1);
        aux=1+rand()%(3-1+1);
        switch(aux){
            case LIBROS:
                pub[i].nompub=nomlib[aleatorio1];
                pub[i].inf.dlibro.totalpaginas=100+rand()%(800-100+1);
                strcpy(pub[i].inf.dlibro.categoria,cat[aleatorio1]);
                pub[i].tipo=LIBROS;
                break;
            case REVISTAS:
                pub[i].nompub=nomrev[aleatorio2];
                pub[i].inf.drev.numero=1+rand()%(600-1+1);
                pub[i].inf.drev.anio=1800+rand()%(2021-1800+1);
                pub[i].inf.drev.mes=1+rand()%(11-1+1);
                pub[i].tipo = REVISTAS;
                break;
            case PERIODICO:
                pub[i].nompub=nomper[aleatorio1];
                pub[i].inf.dperiodico.totalejemplares=1+rand()%(1000-1+1);
                pub[i].inf.dperiodico.precio=aleatorio1+aleatorio2/100.0;
                pub[i].tipo = PERIODICO;
                break;
        }
    }
}



