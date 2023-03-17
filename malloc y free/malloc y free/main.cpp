//
//  main.cpp
//  malloc y free
//
//  Created by Luis Navarrete on 29/05/21.
//
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


void llenarvec(int *, int);
void imprimirvec (int*, int);
void llenarmat (int **,int,int);
void imprimirmat (int**,int,int);
 
/* la biblioteca estandar de C proporciona las funciiones mallox,calloc,realloc y free para el manejo de memoria dinamica
estas funciones estan definidas en el archivo  del include stdlib */

int main( int argc, char** argv){
    /* la funcion malloc reserva un bloque de memoria y devuelve un puntero void al inicio de la misma
        tiene la siguiente definicion
        
        void malloc(size_t size);
        
        donde el parametro size especigica el numero de bytes a reservar. En caso de que no se pueda realizar la asignacion
        devuelve el valor nulo (definido en la macro NULL) lo que permite saber si hubo errores en la asignacion de memoria
      */
      
      int *ptr1;
      
      ptr1=(int *)malloc(sizeof(int)); //equivale a ptr1 =new int;
      *ptr1=9;
      cout<<endl<<*ptr1;
      cout<<endl;
      
      char *ptr2;
      ptr2=(char *)malloc(sizeof(char)); //equivale a ptr2 =new char;
      *ptr2='s';;
      cout<<endl<<*ptr2;
      cout<<endl;
    
    free(ptr1);//equivale a delete ptr1
    free(ptr2);//equivale a delete ptr2
    
    //vectores dinamicos
    int *v;
    int n;
    cout<<endl<<"De cuantas casillas quieres el vector";
    cin>>n;
    
    //creando espacio para el vector dinamico
    v=(int *)malloc (n*sizeof(int));
    
    llenarvec(v,n);
    imprimirvec(v,n);
    
    //eliminando el espacio de la memoria dinamica
    free(v);
    cout<<endl;
    
    //matrices dinamicas
    int **mat;
    int ren, col;
    
    cout<<endl<<"De cuantos renglones: ";
    cin>>ren;
    cout<<endl<<"De cuantas columnas: ";
    cin>>col;
    
    
    //Creando espacio para la matriz dinamica
    mat= (int **)malloc (ren * sizeof(int *));
    for(int i=0; i<ren; i++){
        mat[i]=(int *)malloc(col *sizeof(int));
        
    }
    
    llenarmat(mat,ren,  col);
    imprimirmat(mat,ren,  col);
    
    //eliminando el espacio e la memoria dinamica
    
    for(int i=0; i<ren; i++){
        free(mat[i]);
    }
    free(mat);
    
    return 0;
}

void llenarvec(int *v, int n){
    cout<<endl<<"llenado vector";
    for(int i=0; i<n; i++){
        v[i]=(i+1) *5;
    }
    cout<<"listo";
}


void imprimirvec (int*v, int n){
    cout<<endl<<"Imprimiendo vector";
    for(int i=0; i<n; i++){
        cout<<v[i]<<"    ";
    }
}


void llenarmat (int **mat ,int r,int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c;j++){
            
            mat[i][j]=i+1*10;
        }
    }
}


void imprimirmat (int**mat ,int r ,int c){
    
    cout<<endl<<"imprimiendo matriz";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<setw(3)<<mat[i][j];
        }
        cout<<endl;
    }
}
