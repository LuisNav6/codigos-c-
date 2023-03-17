//
//  main.cpp
//  RECURSIVIDAD EXAMEN 1
//
//  Created by Luis Navarrete on 14/09/21.
//

#include <iostream>
using namespace std;
int invN(long int, long int );
float sumprim(float n);
void esp(int n);
int main(int argc, const char * argv[]){
    long int inv,res;
    int op;
    float  n,r;
    int num;
    do{
        cout<<endl<<"-----------R E C U R S I V I D A D----------"<<endl;
        cout<<endl<<"Invertir número [1]"<<endl;
        cout<<endl<<"Suma de los primeros numeros de una serie[2]"<<endl;
        cout<<endl<<"Escribe el numero que me das separado por espacios[3]"<<endl;
        cout<<endl<<"salir [4]"<<endl;
        cout<<endl<<"Dame la opción deseada:";
        cin>>op;
        switch(op){
            case 1:cout<<"Ingrese un numero:";
                cin>>inv;
                cout<<"El numero invertido es:";
                res=invN(inv,0);
                cout<<endl;
                break;
            case 2:cout<<endl<<"Dame el limite: ";
                cin>>n;
                r=sumprim(n);
                cout<<endl<<"La suma total de los valores hasta: 1/"<<n<<" es: "<<r-1<<endl;
                break;
            case 3:cout<<"Ingrese un numero:";
                cin>>num;
                esp(num);
                break;
        }
    }while(op!=4);
    return 0;
}
void esp(int n){
    if(n>0){
        esp(n/10);
        cout<<n%10<<" ";
    }
}
float sumprim(float n){
    if(n<=0)
        return 1;
    else
    return 1/n+sumprim(n-1);
}
int invN(long int a, long int b){
    if(a==0){
        return 0;
    }else{
        b=a%10;
        a=a/10;
        cout<<b;
        return invN(a,b);
    }
}
