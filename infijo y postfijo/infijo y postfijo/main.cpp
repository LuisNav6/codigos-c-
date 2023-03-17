//
//  main.cpp
//  infijo y postfijo
//
//  Created by Luis Navarrete on 21/08/21.
//

#include<iostream>
#include<conio.h>
#include<string.h>
#define tam 20

using namespace std;


//prototipos
int prioridad(char simbolo);


int main(){
    int op, tope=-1, pos=-1,tamexp;
    char expinf[tam],simbolo,pila[tam],epos[tam],epre[tam];

    
    do{
        cout<<endl<<"--------------------------------------------------"<<endl;
        cout<<"M         E           N            U   "<<endl;
        cout<<"Infija a Postfija...1"<<endl;
        cout<<"Infija a Prefija...2"<<endl;
        cout<<"Salir del Menu...3"<<endl;
        cout<<"\n Ingrese su opcion: "<<endl;
        cin>>op;
        
        switch(op){
        
        case 1:
              cout<<"Ingrese la expresion en notacion Infija (sin espacios): "<<endl;
              cin>>expinf;
              
              tope=-1;
              pos=-1;
              tamexp=strlen(expinf);
              for(int i=0; i<tamexp; i++){
                  simbolo=expinf[i];
                  if(simbolo=='('){
                      tope=tope+1;
                      pila[tope]=simbolo;
                  }
                  else if(simbolo==')'){
                      while(pila[tope]!='('){
                          pos=pos+1;
                          epos[pos]=pila[tope];
                          tope=tope-1;
                      }
                      tope=tope-1;
                  }
                  else if((simbolo>='a') && (simbolo<='z') || (simbolo>='A') && (simbolo<='Z')){
                      pos=pos+1;
                      epos[pos]=simbolo;
    
                  }
                  else{
                      while(tope>-1 && (prioridad(simbolo)<=prioridad(pila[tope]))){
                          pos=pos+1;
                          epos[pos]=pila[tope];
                          tope=tope-1;
                      }
                      tope=tope+1;
                      pila[tope]=simbolo;
                  }
              }
              
              while(tope>-1){
                  pos=pos+1;
                  epos[pos]=pila[tope];
                  tope=tope-1;
              }
            
            cout<<"La expresion en postfijo es: "<<endl;
            for(int i=0; i<=pos; i++){
            cout<<epos[i];
            }
        getch();
        break;
    
        case 2:
            cout<<"Ingrese la expresion en notacion Infija (sin espacios): "<<endl;
            cin>>expinf;
            
            tope=-1;
              pos=-1;
              tamexp=strlen(expinf);
              for(int i=tamexp-1; i>=0; i--){
                  simbolo=expinf[i];
                  if(simbolo==')'){
                      tope=tope+1;
                      pila[tope]=simbolo;
                  }
                  else if(simbolo=='('){
                      while(pila[tope]!=')'){
                          pos=pos+1;
                          epre[pos]=pila[tope];
                          tope=tope-1;
                      }
                      tope=tope-1;
                  }
                  else if((simbolo>='a') && (simbolo<='z') || (simbolo>='A') && (simbolo<='Z')){
                      pos=pos+1;
                      epre[pos]=simbolo;
                  }
                  else{
                      while((prioridad(simbolo)<prioridad(pila[tope]))){
                          pos=pos+1;
                          epre[pos]=pila[tope];
                          tope=tope-1;
                          
                      }
                      tope=tope+1;
                      pila[tope]=simbolo;
                  }
              }
              
              while(tope>-1){
                  pos=pos+1;
                  epre[pos]=pila[tope];
                  tope=tope-1;
              }
            
            cout<<"La expresion en prefijo es: "<<endl;
            for(int i=pos; i>=0; i--){
            cout<<epre[i];
            }
       getch();
                break;
        default: cout<<"\n Por favor seleccione una opcion valida ..."<<endl;
       getch();
        break;
    }
    
    }while(op!=3);
    getch();
}

int prioridad(char simbolo){
    int priori;
    switch(simbolo){
        case '^': priori = 3; break;
        case '*': priori = 2; break;
        case '/': priori = 2; break;
        case '+': priori = 1; break;
        case '-': priori = 1; break;
        case '(': priori = 0; break;
        case ')': priori = 0; break;
    }
    return priori;
}
