//
//  main.cpp
//  retorno de punteros con UNION
//
//  Created by Luis Navarrete on 28/05/21.
//
#include <iostream>

using namespace std;

int *pidememoria(int);
void llenar(int*,int);
int *unir(int*,int,int*,int);
void imprimir2(int*,int,int);
void imprimir(int*,int);

int main()
{
    int *v1, *v2, *v3;
    int t1, t2;
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
    imprimir2 = (static_cast<void>(v3), t1 + t2);
}

int *pidememoria(int n)
{
    return new int[n];
}

void llenar(int* v1, int t1)
{
    for(int i=0; i < t1; i++)
    {
        
    }
}

int *unir(int*v3 ,int t1)
{
    
}
