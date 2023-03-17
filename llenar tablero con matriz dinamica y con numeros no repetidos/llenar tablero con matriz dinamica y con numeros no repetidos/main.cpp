//
//  main.cpp
//  llenar tablero con matriz dinamica y con numeros no repetidos
//
//  Created by Luis Navarrete on 27/05/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void imprimir(int *vec,int tam);
void shuffle(int *array,int n);
int **pedirespacio(int ren, int col);
void llenartablerohorizontal(int **mat,int ren, int col);
void imprimirtablero(int **mat,int ren, int col);
bool revisartablero(int numero,int **m,int ren,int col,int *v,int  &indice);
bool revisarsigana(int **m,int ren, int col);
int main(int argc, const char * argv[]) {
    srand(time_t(0));
    int **tablero1;
    int **tablero2;
    tablero1=pedirespacio(3,9);
    tablero2=pedirespacio(3,9);
    llenartablerohorizontal(tablero1,3,9);
    llenartablerohorizontal(tablero2,3,9);
    cout<<endl<<"Alias 1"<<endl<<endl;
    imprimirtablero(tablero1,3,9);
    cout<<endl<<"Alias 2"<<endl<<endl;
    imprimirtablero(tablero2,3,9);
    //meter los numeros del 1 al 100 en una bolsita
    int *bolsa=new int[100];
    for(int i=0;i<100;i++){
        bolsa[i]=i+1;
    }
    //revolver la bolsita
    shuffle(bolsa,100);
    //revisar que tablero cubre primeros los numeros
    bool tabla1=false,tabla2=false;
    int numerosok1[100],indice1=0;
    int numerosok2[100],indice2=0;
    
    for(int i=0;i<100;i++){
        cout<<endl<<"Salio el numero: "<<bolsa[i];
        cout<<endl<<"revisando tablero 1";
        tabla1=revisartablero(bolsa[i],tablero1,3,9,numerosok1,indice1);
        cout<<endl<<"revisando tablero 2";
        tabla2=revisartablero(bolsa[i],tablero2,3,9,numerosok2,indice2);
        if(tabla1==true){
            cout<<endl<<"El tablero 1 se completo con los siguientes numeros: ";
            for(int j=0;j<indice1;j++)
                cout<<endl<<numerosok1[j]<<" ";
            break;
        }
        if(tabla2==true){
            cout<<endl<<"El tablero 2 se completo con los siguientes numeros: ";
            for(int j=0;j<indice2;j++)
                cout<<endl<<numerosok2[j]<<" ";
            break;
        }
    }
    return 0;
}
void imprimir(int *vec,int tam){
    cout<<endl;
    for(int i=0;i<tam;i++){
        cout<<vec[i]<<" ";
        //sleep(1000);
    }
}
void shuffle(int *array,int n){
    if(n>1){
        int i;
        for(i=0;i<n-1;i++){
            int j=i+rand()/(RAND_MAX/(n-i)+1);
            int t=array[j];
            array[j]=array[i];
            array[i]=t;
        }
    }
}
int **pedirespacio(int ren, int col){
    int **aux;
    aux=new int *[ren];
    for(int i=0;i<ren;i++)
        aux[i]=new int[col];
    return aux;
}
void imprimirtablero(int **mat,int ren, int col){
for(int i=0;i<ren;i++){
    for(int j=0;j<col;j++){
        cout<<setw(4)<<mat[i][j];
}
    cout<<endl;
}
}
void llenartablerohorizontal(int **mat,int ren, int col){
    int *vec;
    vec=new int[100];
    
    for(int i=0;i<100;i++){
        vec[i]=i+1;
    }
    shuffle(vec,100);//revuelve los 100 numeros
    int *aux;
    aux=new int[9];
    int inicio=0;
    int fin=5;
    
    for(int r=0;r<ren;r++){
    for(int i=0;i<9;i++){
        aux[i]=0;
    }
        int cont=0;
        
    for(int i=inicio;i<fin;i++){
        aux[cont]=vec[i];
        cont++;
    }
    shuffle(aux,9);
        for(int c=0;c<col;c++){
            mat[r][c]=aux[c];
        }//fin ciclo c
        inicio=fin;
        fin+=5;
        
    }//fin ciclo r
    
}
bool revisartablero(int numero,int **m,int ren,int col,int *v,int  &indice){
    bool exito=false;
    for(int i=0;i<ren;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]==numero){
                //el numero si esta en el tablero
                cout<<endl<<endl<<numero<<" Esta en el tablero\n";
                v[indice]=numero;
                indice++;
                m[i][j]=0;
                imprimirtablero(m,3,9);
                exito=revisarsigana(m,3,9);
                if(exito==true){
                    return true;
                }
            }
    }
}
    return false;
}
bool revisarsigana(int **m,int ren, int col){
    bool bandera=false;
    int cont;
    
    for(int i=0;i<ren;i++){
        cont=0;
        for(int j=0;j<col;j++){
            if(m[i][j]==0){
                cont++;
            }
            }
        if(cont==9){
            bandera=true;
            break;//rompe el ciclo de los renglones
        }
    }
    return bandera;
}
