//
//  main.cpp
//  diagonal principal
//
//  Created by Luis Navarrete on 24/05/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void llenarMatriz(int**,int);
void imprimirMatriz(int**,int);

int main()
{
srand(time_t(0));
int **m1;
int **m2;
int n;

//generar tamaño de matriz
n = rand()%(6-3+1)+3;

//asignar tamaño a matriz
m1 = new int* [n];
for (int i = 0; i < n; i++)
{
m1[i] = new int[n];
}

m2 = new int* [n];
for (int i = 0; i < n; i++)
{
m2[i] = new int[n];
}

llenarMatriz(m1,n);
llenarMatriz(m2,n);

imprimirMatriz(m1,n);
cout<<endl<<endl;
imprimirMatriz(m2,n);

}

void llenarMatriz(int **m,int n)
{
int num;
int aux = 0;
//generar valores para matriz
for(int i = 0; i < n; i++)
{
for(int j = 0; j < n; j++)
{
num = rand()%(99-1+1)+1;

while(aux<j)
{
if(num!=m[i][j])
{
aux++;
}
else
{
num = rand()%(99-1+1)+1;
aux = 0;
}
}
m[i][j]=num;
}
}
}

void imprimirMatriz(int **m,int n)
{
//imprimir matriz
for(int i = 0; i < n; i++)
{
for(int j = 0; j < n; j++)
{
cout<<m[i][j]<<" ";
}
cout<<endl;
}
}
