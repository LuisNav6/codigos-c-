
//  main.cpp
//  busquedas
//
//  Created by Luis Navarrete on 16/11/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
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
void order_insertion(int v[],int n);
void order_selection(int v[],int n);
void order_shell(int v[],int n);
void order_quickshort(int v[],int ini, int fin);
int particion(int v[],int ini, int fin);
void intercambiar(int *a,int *b);
void intercalacion(int v[],int v2[],int n);
void imp(int x[],int ini,int n);
void mSort(int *A,int n);
void merge(int *izq,int nIzq,int *der,int nDer,int *A);
void search_hash(int v[],int n,int x);
//show
void mostrar(int v[],int n);
//void order(int v[]);
int main(int argc, const char * argv[]) {
    srand(time_t(0));//hotbed
    int n=10;//size
    int v[n];//vector
    int v2[n];//vector 2
    int x;//item to search
    int op;//use of switch and do-while
    for(int i=0;i<=n;i++){
        v[i]=rand()%(n-1+1)+1;
    }
    for(int i=0;i<=n;i++){
        v2[i]=rand()%(n-1+1)+1;
    }
    do{
        cout<<endl<<"-----BUSQUEDAS-----"<<endl;
        cout<<endl<<"Busqueda secuencial desordenada [1]"<<endl;
        cout<<endl<<"Busqueda secuencial ordenada [2]"<<endl;
        cout<<endl<<"Busqueda binaria [3]"<<endl;
        cout<<endl<<"-----ORDENAMIENTOS-----"<<endl;
        cout<<endl<<"Intercambio [4]"<<endl;
        cout<<endl<<"Intercambio con senal [5]"<<endl;
        cout<<endl<<"Shaker short [6]"<<endl;
        cout<<endl<<"Insercion directa [7]"<<endl;
        cout<<endl<<"Seleccion directa [8]"<<endl;
        cout<<endl<<"Shell [9]"<<endl;
        cout<<endl<<"QuickShort [10]"<<endl;
        cout<<endl<<"Intecalacion de archivos [11]"<<endl;
        cout<<endl<<"Mezcla directa [12]"<<endl;
        cout<<endl<<"Mezcla equilibrada [13]"<<endl;
        cout<<endl<<"Busqueda por transformacion de claves (hash) [14]"<<endl;
        cout<<endl<<"Salir [15]"<<endl;
        cout<<endl<<"Dame la opcion deseada:";
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
            case 7:cout<<endl<<"metodo de la insercion directa"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_insertion(v,n);
                break;
            case 8:cout<<endl<<"metodo de la seleccion directa"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_selection(v,n);
                break;
            case 9:cout<<endl<<"metodo SHELL"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_shell(v,n);
                break;
            case 10:cout<<endl<<"metodo QUICK SHORT"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                mostrar(v,n);
                cout<<"Vector ordenado: "<<endl;
                order_quickshort(v,0,n-1);
                mostrar(v,n);
                break;
			case 11:cout<<endl<<"metodo intercalacion de archivos"<<endl;
                cout<<endl<<"Vector 1:"<<endl;
                order_shaker(v,n);
                cout<<endl<<"Vector 2:"<<endl;
                order_intercambio(v2,n);
                cout<<"Vector 3: "<<endl;
                intercalacion(v,v2,n);
                break;
            case 12:cout<<endl<<"metodo mezcla directa"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                imp(v,0,n);
                mSort(v,n);
                cout<<"Vector ordenado: "<<endl;
                imp(v,0,n);
                break;
            case 13:cout<<endl<<"metodo mezcla equilibrada"<<endl;
                cout<<"Vector sin ordenar: "<<endl;
                imp(v,0,n);
                mSort(v,n);
                cout<<"Vector ordenado: "<<endl;
                imp(v,0,n);
                break;
			case 14: 
			 cout<<"Contenido del vector:"<<endl;
	         order_intercambio(v,n);
			 cout<<endl<<"Dame el elemento a buscar:";
                cin>>x;
                search_hash(v,n,x);
                break;
        }
    }while(op!=15);
    return 0;
}
void search_hash(int v[],int n,int x){
	int d,dx;
	d=(x%10)+1;
	if(v[dx] != v[0] && v[d] == x){
		cout<<endl<<"la info esta en la posicion: "<<d;
	}else{
		dx=d+1;
		while((dx <= n) && (v[dx] != v[0]) && (v[dx] != x) && (dx != d)){
			dx=dx+1;
			if(dx==n+1){
				dx=1;
			}
		}
		if((v[dx] == v[0]) || (dx == d)){
			cout<<endl<<"la info no se encuentra en el arreglo!!"<<endl;
		}else{
		 cout<<endl<<"la info esta en la posicion: "<<dx;	
		}
	}
}
void imp(int x[],int ini,int n)
{
for(int i=ini;i<n;i++)
  cout<<x[i]<<" ";
 cout<<endl;
}
void mSort(int *A,int n)
{
if(n==1){return;}
int mitad = n / 2;
int *izq = new int[mitad];
int *der = new int[n-mitad];
for(int i=0;i<mitad;i++)
  izq[i] = A[i];
for(int i=mitad;i<n;i++)
  der[i-mitad] = A[i];
mSort(izq, mitad);
mSort(der, n-mitad);
merge(izq, mitad, der, n-mitad, A);
}
void merge(int *izq,int nIzq,int *der,int nDer,int *A)
{
int i=0,j=0,k=0;
while( ( i < nIzq ) && ( j < nDer ) )
 {
if( izq[i] <= der[j])
  {
   A[k] = izq[i];
   i++;
  }
else
  {
   A[k] = der[j];
   j++;
  }
  k++;
 }
while(i < nIzq)
 {
  A[k] = izq[i];
  i++;k++;
 }
while(j < nDer)
 {
  A[k] = der[j];
  j++;k++;
 }
}
void intercalacion(int v[],int v2[],int n){
	int x=n+n;
	int v3[x];
	int i,j,k,p;
	i=0;j=0;k=0;
	while (i < n && j < n){
      if (v [ i ] <= v2 [ j]){
	   v3[ k ] = v[ i ];
	    i++;
	    }
      else{ 
	  v3[ k ] = v2[ j ];
	  j++;
	  }
      k++;
   }
   if (i == n)
      for (p = j ; p < n;p++){ 
	  v3[ k ] = v2[ p ]; 
	  k++;
	  }
   else
      for(p = i ; p < n;p++){
	   v3[ k ] = v[ p ];
	   k++;
	   }
	   mostrar(v3,x);
}
void order_quickshort(int v[],int ini,int fin){
if(ini < fin){
	int indice=particion(v,ini,fin);
	order_quickshort(v,ini,indice);
	order_quickshort(v,indice+1,fin);
}	
}
int particion(int v[],int ini, int fin){
	int pivote=v[ini];
	while(1){//ciclo infinito
		while(v[ini] < pivote){
			ini++;
		}
		while(v[fin] > pivote){
			fin--;
	   	}
	   	if(ini >= fin){
	   		return fin;
		   }else{
		   	intercambiar(&v[ini],&v[fin]);
		   	ini++;
		   	fin--;
		   }
		   //el while se repite hasta que ini >= fin
	}
}
void intercambiar(int *a,int *b){
	int temporal=*a;
	*a=*b;
	*b=temporal;
}
void order_shell(int v[],int n){
	int i,j,aux;
	bool band;
	i=n+1;
	while(i > 1){//2
		i=i/2;
		band=true;
		while(band == true){//2.1
			band=false;
			j=0;
			while((j+i) <= n){//2.1.1
				if(v[j] > v[j+i]){//2.1.1.1
					aux=v[j];
					v[j]=v[j+i];
					v[j+i]=aux;
					band=true;
				}//fin 2.1.1.1
					j+=1;
			}//fin 2.1.1
		}//fin 2.1
	}//fin 2
	mostrar(v,n);
}
void order_selection(int v[],int n){
	int i,menor,k,j;
	for(i=0;i<=n-1;i++){
		menor=v[i];
		k=i;
		for(j=i+1;j<=n;j++){
			if(v[j] < menor){
				menor=v[j];
				k=j;
			}
		}
		v[k]=v[i];
		v[i]=menor;
	}
	mostrar(v,n);
}
void order_insertion(int v[],int n){
	int i,aux,k=-1;
	for(i=0;i<=n;i++){
		aux=v[i];
		k=i-1;
		while(k >= 0 && aux < v[k]){
			v[k+1]=v[k];
			k-=1;
		}
		v[k+1]=aux;
	}
	mostrar(v,n);
}
void order_shaker(int v[],int n){
    int i,izq,der,k,aux;
    izq=1;
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
