//
//  main.cpp
//  interseccion de dos vectores
//
//  Created by Luis Navarrete on 28/05/21.
//


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *pidememoria(int);
void llenar(int*,int);
int *unir(int*,int,int*,int);
void imprimir2(int*,int);
void imprimir(int*,int);
int * interseccion(int*,int,int*,int, int*);
bool revisar(int *, int, int);

int main()
{
    srand(time(0));
    int *v1, *v2, *v3;
    int t1, t2 ,t3;
    cout << endl << "Dame el valor del vector 1 = ";
    cin >> t1;
    cout << endl << "Dame el valor del vector 2 = ";
    cin >> t2;
    
    v1 = pidememoria(t1);
    v2 = pidememoria(t2);
    
    llenar(v1,t1);
    llenar(v2,t2);
    
    imprimir(v1,t1);
    imprimir(v2,t2);
    
    v3 = unir(v1,t1,v2,t2);
    imprimir2(v3, t1 + t2);
    cout << endl << "Interseccion de los dos vectores ...";
    v3 = interseccion(v1, t1, v2, t2, &t3);
    imprimir(v3,t3);
    
    delete [] v1;
    delete [] v2;
    delete [] v3;
}

int *interseccion(int *v1, int t1,int *v2,int t2,int *t3)
{
    int *aux,cont;
    aux = new int[10];
    for(int i=0; i < t1; i++)
    {
        for(int j=0; j < t2; j++)
        {
            if(v1[i] == v2[j] && v1[i] != 0)
            {
                aux[cont] = v1[i];
                cont++;
            }
        }
    }
    *t3 = cont;
    return aux;
}

bool revisar(int *v, int tam, int num)
{
    bool band = false;
    for(int i=0; i < tam; i++)
    {
        if(v[i] == num)
        {
            band = true;
            break;
        }
    }
    return band;
}

void imprimir2(int* v3,int res)
{
    cout << endl << "Imprimiendo el resultado de la suma de los dos vectores ..." << endl;
    for(int i=0; i < res; i++)
    {
        cout << "[" << v3[i] << "]";
    }
}

int *pidememoria(int n)
{
    return new int[n];
}

void llenar(int* v1, int tam)
{
    int i=0;
    int num;
    bool bandera;
    while (i < tam)
    {
        num = 1 + rand()% (20 - 1 +1);
        bandera = revisar(v1,i,num);
        if(bandera == false)
        {
            v1[i] = num;
            i++;
        }
    }
}

void imprimir(int* v1,int t1)
{
    cout << endl << "Imprimiendo vector ..." << endl;
    for(int i=0; i < t1; i++)
    {
        cout << "[" << v1[i] << "]";
    }
}

int *unir(int*v1 ,int t1, int* v2, int t2)
{
    int *aux;
    aux = pidememoria(t1 + t2);
    for(int i=0; i < t1; i++)
    {
        aux[i] = v1[i];
    }
    
    for(int i = t1; i < t2 + t1; i++)
    {
        aux[i] = v2[i - t1];
    }
    return aux;
}
