//
//  main.cpp
//  impresion de tableros
//
//  Created by Luis Navarrete on 04/06/21.
//

#include <iostream>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>

using namespace std;

void imprimir(int *vec, int tam);
void shuffle(int *array, int n);
int **pedirEspacio(int ren, int col);
void llenarTableroHorizontal(int **matriz,int ren, int col);
void mostrar(int **tablero1, int **tablero2, int ren, int col, string titulo, string alias1, string alias2);
void gotoxy(int x,int y);
bool revisar(int *v, int tam, int num);

int main(){
    srand(time(0));
    int **tablero1;
    int **tablero2;
    string alias1 = "Pedro";
    string alias2 = "Marcos";
    string titulo = "Bingo Cuadrado";
    
    tablero1 = pedirEspacio(3,9);
    tablero2 = pedirEspacio(3,9);
    
    llenarTableroHorizontal(tablero1,3,9);
    llenarTableroHorizontal(tablero2,3,9);
    
    mostrar(tablero1,tablero2,3,9,titulo,alias1,alias2);
    
}

void mostrar(int **tablero1, int **tablero2, int ren, int col, string titulo, string alias1, string alias2){
    
    gotoxy(51,3);cout << titulo;
    gotoxy(82,8);cout << alias2;
    gotoxy(28,8);cout << alias1;
    
    
    for(int i=0; i < ren; i++){
        for (int j = 0; j < col; j++){
            gotoxy(10 + j * 5,10 + i);cout << *(*(tablero1 + i) + j);
        }
        cout << endl;
    }
    
    for(int i=0; i < ren; i++){
        for (int j = 0; j < col; j++){
            gotoxy(65 + j * 5,10 + i);cout << *(*(tablero2 + i) + j);
        }
        cout << endl;
    }
}

void llenarTableroHorizontal(int **matriz,int ren, int col){
    int *vec, num;
    vec = new int[100];
    bool bandera;
    
    for(int i=0; i < 100; i++){
        num = 1 + rand () % (100 - 1 + 1);
        bandera = revisar(vec,100,num);
        if(bandera == false){
            vec[i] = num;
        }
    }
    
    int k=0;
    for(int i=0; i < ren; i++){
        for(int j=0; j < col; j++){
            matriz[i][j] = vec[k++];
        }
    }
    
}

bool revisar(int *v, int tam, int num){
    bool band = false;
    for(int i=0; i < tam; i++){
        if(v[i] == num && v[i] == 0){
            band = true;
            break;
        }
    }
    return band;
}

void shuffle (int *array, int n){
    if (n > 1)
    {
        int i;
        for(i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int **pedirEspacio(int ren, int col){
    int **aux;
    aux = new int *[ren];
    for(int i=0; i < ren; i++)
        aux[i] = new int[col];
    return aux;
}
