//
//  main.cpp
//  fibonacci
//
//  Created by Luis Navarrete on 31/08/21.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int fac(int n);
int fibo(int n);
int mcd(int,int);
void mostrar(int[],int);
int numSum(int[],int);
int divN(int,int);
int invN(long int, long int );
int sumDig(int);
int multVec(int [],int);

int main()
{
    int op,n,num, vec[5]={1,2,3,4,5};
    int vec2[6]={2,4,5,6,8,9};
    int d, numer;
    int vec3[5]={4,3,2,5,6};
    long int inv, res;
    int dig;
    do
    {
        system("cls");
        cout << "--> RECURSIVIDAD <--";
        cout << endl << "[1] --> Factorial" << endl;
        cout << "[2] --> Fibonacci" << endl;
        cout << "[3] --> MCD" << endl;
        cout << "[4] --> Mostrar un vector" << endl;
        cout << "[5] --> Suma de una arreglo de numeros" << endl;
        cout << "[6] --> Division mediante restas sucesivas" << endl;
        cout << "[7] --> Invertir numero recursivamente" << endl;
        cout << "[8] --> Sumar los digitos de un numero" << endl;
        cout << "[9] --> Multiplicar los elementos de un vector" << endl;
        cout << "[10] --> Salir" << endl;
        cout << endl << "Inserta la opcion que deseas: ";
        cin >> op;
        switch(op)
        {
            case 1 :
                cout << "De que numero quieres el factorial: " << endl;
                cin >> n;
                cout << "El factorial de " << n << " es --> " << fac(n) << endl;
                system("pause");
                break;
            case 2 :
                cout << "Inserta la cantidad de numeros fibonacci que deseas: ";
                cin >> num;
                cout << "N = " << num;
                cout << " Su serie es la siguiente: " << endl;
                for(int i=0; i <= num; i++)
                {
                    cout << "[" << fibo(i) << "] ";
                }
                cout << endl;
                system("pause");
                break;
            case 3 :
                int m, nn;
                cout << "Inserte los numeros del MCD: ";
                cin >>m>>nn;
                cout << "El MCD de " << m << " y "<< nn << " es " << mcd(m,nn) << endl;
                system("pause");
                break;
            case 4 :
                cout << "El contenido de el vector es: ";
                mostrar(vec,4);
                cout << endl;
                system("pause");
                break;
            case 5 :
                cout << "El contenido del vector el cual es: [2,4,5,6,8,9]" << endl;
                cout << "Su suma es: " << numSum(vec2,6) << endl;
                system("pause");
                break;
            case 6 :
                cout << "Inserta el valor del numerador: " << endl;
                cin >> numer;
                cout <<"Inserta el valor del denominador: " << endl;
                cin >> d;
                cout << "El valor de division es: " << divN(numer,d) << endl;
            case 7 :
                cout << "Ingrese un numero: "<< endl;
                cin >> inv;
                cout << "El numero invertido es: " << endl;
                res = invN(inv,0);
                cout << endl;
                system("pause");
                break;
            case 8 :
                cout << "Ingrese los digitos que desea que se sumen (sin espacios): " << endl;
                cin >> dig;
                cout << "La suma de sus digitos es: " << sumDig(dig) << endl;
                system("pause");
                break;
            case 9 :
                cout << "El contenido del vector el cual es: [4,3,2,5,6]" << endl;
                cout << "Su multiplicacion es: " << multVec(vec3,4) << endl;
                system("pause");
                break;
            default :
                cout << "Inserte una opcion valida!";
                system("pause");
                break;
        }
    }while(op != 10);
}

int multVec(int vec[], int n)
{
    if(n == 0)
    {
        return vec[0];
    }else
    {
        return vec[n] * multVec(vec,n - 1);
    }
}

int sumDig(int num)
{
    if(num == 0)
    {
        return 0;
    }else
    {
        return sumDig(num / 10) + num % 10;
    }
}

int invN(long int a, long int b)
{
    if( a == 0)
    {
        return 0;
    }else
    {
        b = a % 10;
        a = a / 10;
        cout  << b ;
        return invN(a,b);
    }
}

int divN(int n, int d)
{
    if(d > n)
    {
        return 0;
    }else
    {
        return divN(n - d, d)     + 1;
    }
}


int numSum(int vec[], int n)
{
    if(n == 1)
    {
        return vec[0];
    }else
    {
        return vec[n - 1] + numSum(vec,n - 1);
    }
}

int mcd(int m, int n)
{
    if(m % n == 0)
    {
        return n;
    }else
    {
        return mcd(n,m % n);
    }
}

void mostrar(int vec[], int n)
{
    if(n ==0)
    {
        cout <<vec[0] << " ";
    }else
    {
        mostrar(vec,n - 1);
        cout << vec[n] << " ";
    }
}

int fibo(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }else
    {
        return fibo(n -1) + fibo(n -2);
    }
}

int fac(int n)
{
    if(n == 1)
    {
        return 1;
    }else
    {
        return (n*fac(n-1));
    }
}
