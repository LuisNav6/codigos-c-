
//  main.cpp
//  busquedas
//
//  Created by Luis Navarrete on 16/11/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//prototypes
//search
void search_inorder(int v[],int n,int x);
void search_order(int v[],int n,int x);
void search_binary(int v[],int n,int x);
//order
void order_intercambio(int v[],int n);
void order_signal(int v[],int n);
void order_shaker(int v[],int n);
//show
void mostrar(int v[],int n);
//void order(int v[]);
int main(int argc, const char * argv[]) {
    srand(time_t(0));//hotbed
    int n=10;//size
    int v[n];//vector
    int x;//item to search
    int op;//use of switch and do-while
    for(int i=0;i<=n;i++){
        v[i]=rand()%(n-1+1)+1;
    }
    do{
        cout<<endl<<"Busqueda secuencial desordenada [1]"<<endl;
        cout<<endl<<"Busqueda secuencial ordenada [2]"<<endl;
        cout<<endl<<"Busqueda binaria [3]"<<endl;
        cout<<endl<<"-----ORDENAMIENTOS-----"<<endl;
        cout<<endl<<"Intercambio [4]"<<endl;
        cout<<endl<<"Intercambio con señal [5]"<<endl;
        cout<<endl<<"Shaker short [6]"<<endl;
        cout<<endl<<"Inseerción directa [7]"<<endl;
        cout<<endl<<"Selección directa [8]"<<endl;
        cout<<endl<<"Shell [9]"<<endl;
        cout<<endl<<"QuickShort [10]"<<endl;
        cout<<endl<<"Intecalación de archivos [11]"<<endl;
        cout<<endl<<"Mezcla directa [12]"<<endl;
        cout<<endl<<"Mezcla equilibrada [13]"<<endl;
        cout<<endl<<"Busqueda por transformación de claves (hash) [14]"<<endl;
        cout<<endl<<"Salir [15]"<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<endl<<"Dame el elemento a buscar:";
                cin>>x;
                search_inorder(v,n,x);
                break;
            case 2:cout<<endl<<"Dame el elemento a buscar:";
                cin>>x;
                search_order(v,n,x);
                break;
            case 3:cout<<endl<<"Dame el elemento a buscar:";
                cin>>x;
                search_binary(v,n,x);
                break;
            case 4:cout<<endl<<"METODO DE LA BURBUJA"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_intercambio(v,n);
                break;
            case 5:cout<<endl<<"METODO DE LA BURBUJA CON SEÑAL"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_signal(v,n);
                break;
            case 6:cout<<endl<<"METODO DE LA SACUDIDA"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_shaker(v,n);
                break;
        }
    }while(op!=15);
    return 0;
}
void order_shaker(int v[],int n){
    int i,izq,der,k,aux;
    izq=2;
    der=n;
    k=n;
    while(der>=izq){
        for(i=der;i>=izq;i--){
            if(v[i-1] > v[i]){
                aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;
                k=i;
            }
        }
        izq=k+1;
        for(i=izq;i<=der;i++){
            if(v[i-1] > v[i]){
                aux=v[i-1];
                v[i-1]=v[i];
                v[i]=aux;
                k=i;
            }
        }
        der=k-1;
    }
    mostrar(v,n);
}
void order_signal(int v[],int n){
    int i=0,j=0,aux=0;
    bool band=false;
    while((i <= n-1) && (band==false)){
        band=true;
        for(j=1;j<=n-1;j++){
            if(v[j] > v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                band=false;
            }
        }
        i+=1;
    }
    mostrar(v,n);
}
void mostrar(int v[],int n){
    for(int i=0;i<=n;i++){
        cout<<"["<<v[i]<<"]";
    }
    cout<<endl;
}
void order_intercambio(int v[],int n){
    int aux=0;
    for(int i=1;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(v[j-1]>v[j]){
                aux=v[j-1];
                v[j-1]=v[j];
                v[j]=aux;
            }
        }
    }
    mostrar(v,n);
}
void search_binary(int v[],int n,int x){
    int izq=0,der=n,cen=0;
    bool band=false;
    cen=(izq+der)/2;
    mostrar(v,n);
    while(izq<=der && band==false){
        if(x == v[cen]){
            band=true;
        }else{//se redefine el intervalo de busqueda
            if(x > v[cen]){
                izq=cen+1;
            }else{
                der=cen-1;
            }
        }
    }
    if(band==true){
        cout<<endl<<"La info esta en posicion: "<<cen<<endl;
    }else{
        cout<<endl<<"La info no se encuentra en el arreglo!! :("<<endl;
    }
}
void search_order(int v[],int n,int x){
    //vector ordering
    cout<<endl<<"sin ordenar"<<endl;
    mostrar(v,n);
    cout<<endl<<"ordenado"<<endl;;
    order_intercambio(v,n);
    int i=0;
    while(i<=n && x>v[i]){
        i+=1;
    }
    if(i>n || x<v[i]){
        cout<<endl<<"La info no esta en el arreglo! :("<<endl;
    }else{
        cout<<endl<<"La info se encuentra en la posicion:"<<i<<endl;
    }
}
void search_inorder(int v[],int n,int x){
    int i=0;
    for(int s=0;s<=n;s++){
        cout<<" ["<<v[s]<<"] ";
    }
    while(i<=n && v[i]!=x){
        i+=1;
    }
    if(i>n){
        cout<<endl<<"La info no esta en el arreglo! :("<<endl;
    }else{
        cout<<endl<<"La info se encuentra en la posicion:"<<i<<endl;
    }
}
