//
//  main.cpp
//  colas circulares
//
//  Created by Luis Navarrete on 31/08/21.
//

#include <stdio.h>
#include <iostream>

using namespace std;

bool cola_llena(int, int, int);
bool cola_vacia(int);
void cola_inserta(int &fi,int &fr, int cola[], int dato, int);
int elimina_cola(int[],int&,int&,int);
void mostrar_cola(int *cola, int fi, int fr, int max);

int main()
{
    int max= 5, dato;
    int cola[max], fr =-1, fi =-1;
    bool band = false;
    int opc =0;
    
    do
    {
        system("cls");
        cout << endl << "        MENU        ";
        cout << endl << "1 -> Cola llena!";
        cout << endl << "2 -> Cola vacia!";
        cout << endl << "3 -> Inserta";
        cout << endl << "4 -> Elimina";
        cout << endl << "5 -> Mostrar cola";
        cout << endl << "6 -> Salir";
        cout << endl << "Inserte la opcion que desee: ";
        cin >> opc;
        
        switch(opc)
        {
            case 1 :
                band = cola_llena(fi,max,fr);
                if(band)
                {
                    cout << endl << "Cola llena!" << endl;
                }else
                {
                    cout << endl << "Tu cola no esta llena!" << endl;
                }
                system("pause");
                break;
            case 2 :
                band = cola_vacia(fr);
                if(band)
                {
                    cout << endl << "Cola vacia!" << endl;
                }else
                {
                    cout << endl << "Tu cola no esta vacia!" << endl;
                }
                system("pause");
                break;
            case 3 :
                cout << endl << "Dato a insertar: ";
                cin >> dato;
                cola_inserta(fi, fr, cola, dato, max);
                system("pause");
                break;
            case 4 :
                dato = elimina_cola(cola,fr,fi,max);
                cout << endl << "Tu dato eliminado fue: " << dato << endl;
                system("pause");
                break;
            case 5 :
                mostrar_cola(cola,fi,fr,max);
                cout << endl;
                system("pause");
                break;
            case 6 :
                cout << endl << "Gracias!!" << endl;
                break;
            default :
                cout << endl << "Seleccion erronea!" << endl;
                break;
        }
        
    }while(opc != 6);
}

bool cola_llena(int fi, int max, int fr)
{
    if(fr == 0 && fi == max - 1 || fi + 1 == fr)
    {
        return true;
    }else
    {
        return false;
    }
}

bool cola_vacia(int fr)
{
    if(fr == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

void cola_inserta(int &fi,int &fr, int cola[], int dato, int max)
{
    if(!cola_llena(fi, fr, max)){
        if(fi == max-1){
            fi=0;
        }
        else{
            fi++;
            cola[fi]=dato;
        }
        if(fi == 0){
            fr=0;
        }
    }
    else{
        cout<<endl<<"Desbordamiento";
    }
}

int elimina_cola(int cola[], int &fr, int &fi, int max)
{
    int dato = -1;
    if(!cola_vacia(fr))
    {
        dato = cola[fr];
        if(fr == fi)
        {
            fr = fi = -1;
        }else
        {
            if(fr == (max - 1))
            {
                fr =0;
            }
            fr++;
        }
    }else
    {
        cout << endl << "Subdesbordamiento - Cola vacia";
    }
    return dato;
}

void mostrar_cola(int *cola, int fi, int fr, int max)
{
    if(cola_vacia(fr)) {
    cout << "Cola vacia \n";
    return;
    }
    int i=fr;
    while(i!=fi){
    if(fi==0 && i==0){
    break;
    }
    cout << "[" << cola[i++] << "]";
    if(i==max){
    i=0;
    }

    }
    cout << "[" << cola[fi] << "]";



    cout << "\n";
}
