//
//  main.cpp
//  condicionales 21 ejercicios
//
//  Created by Luis Navarrete on 12/08/21.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
void calif();
void aumnentosueldo();
void califex();
void aumentodos();
void ejercicioscorridos();
void aumcat();
void comABC();
void grillo();
void expresion();
void formulagral();
void promedio();
void positivo();
void par();
void orden();
void tienda();
void impuestos();
void mayor();
void llamadas();
void hrextras();
void facultad();
void hospital();
int main(int argc, const char * argv[]) {
    int resp;
    do{
        cout<<"califiaciones...1"<<endl;
        cout<<"aumento de sueldo...2"<<endl;
        cout<<"calificaciones examen...3"<<endl;
        cout<<"Aumento de sueldo versión dos...4"<<endl;
        cout<<"Ejercicio de corridas...5"<<endl;
        cout<<"Aumento de sueldo por categoria..6"<<endl;
        cout<<"Comparacion de valores A,B,C...7"<<endl;
        cout<<"GRILLO TEMPERATURA...8"<<endl;
        cout<<"FORMULA GENERAL...9"<<endl;
        cout<<"PROMEDIO ALUMNO...10"<<endl;
        cout<<"EVALUAR NUMERO...11"<<endl;
        cout<<"PAR-IMPAR-NULO...12"<<endl;
        cout<<"ORDEN CRECIENTE...13"<<endl;
        cout<<"TIENDA DE DESCUENTOS...14"<<endl;
        cout<<"IMPUESTOS...15"<<endl;
        cout<<"MAYOR O IGUALES EN NÚMEROS...16"<<endl;
        cout<<"COSTO DE LLAMADAS TELEFÓNICAS...17"<<endl;
        cout<<"HORAS EXTRAS...18"<<endl;
        cout<<"FACULTAD...19"<<endl;
        cout<<"HOSPITAL...20"<<endl;
        cout<<"salir...22"<<endl;
        cin>>resp;
        system("pause");
        switch(resp){
            case 1:calif();
                break;
            case 2:aumnentosueldo();
                break;
            case 3:califex();
                break;
            case 4:aumentodos();
                break;
            case 5:ejercicioscorridos();
                break;
            case 6:aumcat();
                break;
            case 7:comABC();
                break;
            case 8: expresion();
                break;
            case 9: formulagral();
                break;
            case 10: promedio();
                break;
            case 11: positivo();
                break;
            case 12: par();
                break;
            case 13: orden();
                break;
            case 14: tienda();
                break;
            case 15: impuestos();
                break;
            case 16: mayor();
                break;
            case 17: llamadas();
                break;
            case 18: hrextras();
                break;
            case 19: facultad();
                break;
            case 20: hospital();
                break;
        }
    }while(resp!=22);
}
void hospital(){
    int tipoenf,edad,dias;
    float costo = 0.0;
    cout<<"Dame la enfermedad que padeces: ";
    cin>>tipoenf;
    if(tipoenf<=4){
        cout<<"Que edad tienes: ";
        cin>>edad;
        cout<<"Cuantos dias tienes internado: ";
        cin>>dias;
        if(tipoenf==1)
            costo=dias*25;
        if(tipoenf==2)
            costo=dias*16;
        if(tipoenf==3)
            costo=dias*20;
        if(tipoenf==4)
            costo=dias*32;
        if(edad>=14&&edad<=22)
            costo*=1.10;
        cout<<"El costo total del internado es:$"<<costo<<endl;
    }else{
        cout<<"Tipo de enfermedad invalida!"<<endl;
    }
}
void facultad(){
    int mat,sem,carr;
    float prom;
    cout<<"Dame tu carrera(1)=economia,(2)=computacion,(3)=administracion,(4)=contabilidad: ";
    cin>>carr;
    cout<<"Dame tu matricula: ";
    cin>>mat;
    cout<<"Dame tu semestre perteneciente: ";
    cin>>sem;
    cout<<"Dame tu promedio: ";
    cin>>prom;
    switch(carr){
        case 1:
            if(sem>=6&&prom>=8.8){
                cout<<mat<<" "<<"Economía "<<"Aceptado"<<endl;
            }else{
                cout<<mat<<" "<<"Economía "<<"No aceptado"<<endl;
            }
            break;
        case 2:
            if(sem>6&&prom>8.5){
                cout<<mat<<" "<<"Computación "<<"Aceptado"<<endl;
        }else{
            cout<<mat<<" "<<"Computación "<<"No aceptado"<<endl;
        }
            break;
        case 3:
            if(sem>5&&prom>8.5){
                cout<<mat<<" "<<"Administración "<<"Aceptado"<<endl;
            }else{
                cout<<mat<<" "<<"Administración "<<"No aceptado"<<endl;
            }
            break;
        case 4:
            if(sem>5&&prom>8.5){
                cout<<mat<<" "<<"Contabilidad "<<"Aceptado"<<endl;
            }else{
                cout<<mat<<" "<<"Contabilidad "<<"No aceptado"<<endl;
            }
            break;
        default: cout<<"Tu carrera no se encuentra en esta facultad!"<<endl;
            break;
    }
    
}
void hrextras(){
    int cat,hrex;
    float sueldo,nsueldo,phe;
    cout<<"cual es tu categoria: ";
    cin>>cat;
    if(cat<=4){
    cout<<"cual es tu sueldo: ";
    cin>>sueldo;
    cout<<"cuantas horas extras trabajaste: ";
    cin>>hrex;
        if(cat==1)
            phe=30;
        if(cat==2)
            phe=38;
        if(cat==3)
            phe=50;
        if(cat==4)
            phe=70;
        else
            phe=0;
        if(hrex>30)
            nsueldo=sueldo+(30*phe);
        else
            nsueldo=sueldo+(hrex*phe);
        cout<<"Tu sueldo final es:$"<<nsueldo<<endl;
    }else{
        cout<<"categoria invalida"<<endl;
    }
}
void llamadas(){
    int clave=0,numin=0;
    float cost=0.0;
    cout<<"Dame la clave de la zona destino: ";
    cin>>clave;
    cout<<"Dame el número de minutos que duró la llamada: ";
    cin>>numin;
    if(clave==12){
        cost=numin*2;
    }
    if(clave==15){
        cost=numin*2.2;
    }
    if(clave==18){
        cost=numin*4.5;
    }
    if(clave==19){
        cost=numin*3.5;
    }
    if(clave==23||clave==25){
        cost=numin*6;
    }
    if(clave==29){
        cost=numin*5;
    }
    cout<<"El costo de llamada es:$"<<cost<<endl;
}
void mayor(){
    float a=0.0,b=0.0,c=0.0;
    cout<<endl<<"DAME EL VALOR DE A: ";
    cin>>a;
    cout<<endl<<"DAME EL VALOR DE B: ";
    cin>>b;
    cout<<endl<<"DAME EL VALOR DE C: ";
    cin>>c;
    if(a>b){
        if(a>c){
            cout<<endl<<"A es el mayor"<<endl;
        }else{
            if(a==c){
                cout<<endl<<"A y C son los mayores"<<endl;
            }else{
                cout<<endl<<"C es el mayor"<<endl;
            }
        }
    }else{
        if(a==b){
            if(a>c){
                cout<<endl<<"A y B son los mayores"<<endl;
            }else{
                if(a==c){
                    cout<<endl<<"A,B y C son iguales"<<endl;
                }else{
                    cout<<endl<<"C es el mayor"<<endl;
                }
            }
        }else{
            if(b>c){
                cout<<endl<<"B es el mayor"<<endl;
            }else{
                if(b==c){
                    cout<<endl<<"B y C son los mayores"<<endl;
                }else{
                    cout<<endl<<"C es el mayor"<<endl;
                }
        }
    }
}
}
void impuestos(){
    float prebase,imp,pretotal;
    cout<<endl<<"Dame el precio base: ";
    cin>>prebase;
    if(prebase>500){
        imp=20*0.30+(prebase-40)*0.5;
    }else{
        if(prebase>40){
            imp=20*0.3+(prebase-40)*0.4;
        }else{
            if(prebase>20){
                imp=(prebase-20)*0.3;
            }else{
                imp=0;
                
            }
        }
    }
    pretotal=prebase+imp;
    cout<<endl<<"EL PRECIO BASE ES:$"<<prebase<<" Y EL PRECIO DESPUES DE IMPUESTOS ES:$"<<pretotal;
    
}
void tienda(){
    float compra=0.0,pagar=0.0;
    cout<<endl<<"Dame el monto de la compra: ";
    cin>>compra;
    if(compra<500){
        pagar=compra;
    }else{
        if(compra>=1000){
            pagar=compra-(compra*0.05);
        }else{
            if(compra<=7000){
                pagar=compra-(compra*0.11);
            }else{
                if(compra<=15000){
                    pagar=compra-(compra*0.18);
                }else{
                    pagar=compra-(compra*0.25);
                }
            }
        }
    }
}
void orden(){
    int a,b,c;
    cout<<endl<<"DAME EL VALOR DE A: ";
    cin>>a;
    cout<<endl<<"DAME EL VALOR DE B: ";
    cin>>b;
    cout<<endl<<"DAME EL VALOR DE C: ";
    cin>>c;
    if(a<b){
        if(b<c){
            cout<<endl<<"LOS NUMEROS ESTAN EN ORDEN CRECIENTE!";
        }else{
            cout<<endl<<"LOS NUMEROS NO ESTAN EN ORDEN CRECIENTE!";
        }
    }
}
void par(){
    int a;
    cout<<"Dame el valor del numero: ";
    cin>>a;
    if(a==0){
        cout<<"NULO"<<endl;
    }else{
        if((pow(-1,a))>0){
            cout<<"PAR"<<endl;
        }else{
            cout<<"IMPAR"<<endl;
        }
    }
}
void positivo(){
    int num;
    cout<<endl<<"Dame el numero a evaluar: ";
    cin>>num;
    if(num>0){
        cout<<"POSITIVO"<<endl;
    }else{
        if(num==0){
            cout<<"NULO"<<endl;
        }else{
            cout<<"NEGATIVO"<<endl;
        }
    }
}
void promedio(){
    int mat=0;
    float cal1=0,cal2=0,cal3=0,cal4=0,cal5=0,prom=0;
    cout<<endl<<"dame tu matricula no excedente a 5 digitos: ";
    cin>>mat;
    cout<<endl<<"dame tu calificación 1: ";
    cin>>cal1;
    cout<<endl<<"dame tu calificación 2: ";
    cin>>cal2;
    cout<<endl<<"dame tu calificación 3: ";
    cin>>cal3;
    cout<<endl<<"dame tu calificación 4: ";
    cin>>cal4;
    cout<<endl<<"dame tu calificación 5: ";
    cin>>cal5;
    prom=(cal1+cal2+cal3+cal4+cal5)/5;
    if(prom>6){
        cout<<"APROBADO :)"<<endl;
    }else{
        cout<<"REPROBADO :("<<endl;
    }
}
void formulagral(){
    float a=0,b=0,c=0,dis=0,x1=0,x2=0;
    cout<<endl<<"DAME EL VALOR DE A: ";
    cin>>a;
    cout<<endl<<"DAME EL VALOR DE B: ";
    cin>>b;
    cout<<endl<<"DAME EL VALOR DE C: ";
    cin>>c;
    dis=(pow(b,2))-(4*(a*c));
    if(dis>0){
        x1=((-b)+pow(dis,0.5))/(2*a);
        x2=((-b)-pow(dis,0.5))/(2*a);
        cout<<endl<<"x1: "<<x1<<" y x2: "<<x2<<endl;
    }
}
void expresion(){
    int p,q;
    float exp;
    cout<<endl<<"Dame el valor de p: ";
    cin>>p;
    cout<<endl<<"Dame el valor de q: ";
    cin>>q;
    exp=(pow(p,3))+(pow(q,4))-(2*(pow(p,2)));
    if(exp<680)
        cout<<p<<" "<<q<<endl;
    else
        cout<<endl<<"NO SATISFACEN LA EXPRESION :("<<endl;
}
void grillo(){
    int n;
    float t;
    cout<<endl<<"Dame el número de sonidos emitidos por minuto: ";
    cin>>n;
    if(n>0){
        t=(n/4)+40;
        cout<<endl<<"LA TEMPERATURA EN GRADOS FAHRENHEIT ES: "<<t<<endl;
    }else{
        cout<<endl<<"LA TEMPERATURA ES NULA!"<<endl;
    }
    
}
void comABC(){
    int a=0;int b=0;int c=0;
    cout<<endl<<"Dame el valor de a: ";
    cin>>a;
    cout<<endl<<"Dame el valor de b: ";
    cin>>b;
    cout<<endl<<"Dame el valor de c: ";
    cin>>c;
    if(a>b){
        if(a>c){
            if(b>c){
                cout<<a<<b<<c<<endl;
            }else{
                cout<<a<<c<<b<<endl;
            }
        }else{
            cout<<c<<a<<b<<endl;
        }
    }else{
        if(b>c){
            if(a>c){
                cout<<b<<a<<c<<endl;
            }else{
                cout<<b<<c<<a<<endl;
            }
        }else{
            cout<<c<<b<<a<<endl;
        }
    }
    
}
void aumcat(){
    float sueldo=0,nsueldo = 0.0;
        int cat=0;
        cout<<endl<<"Dame tu categoria: ";
        cin>>cat;
        if(cat>4){
            cout<<endl<<"Categoria invalida, no eres acreedor a un aumento"<<endl;
        }else{
            cout<<endl<<"Dame tu sueldo actual: ";
            cin>>sueldo;
            if(cat==1){
                nsueldo=sueldo*1.15;
            }
            if(cat==2){
                nsueldo=sueldo*1.10;
            }
            if(cat==3){
                nsueldo=sueldo*1.08;
            }
            if(cat==4){
                nsueldo=sueldo*1.07;
            }
            cout<<endl<<"Tu categoria es: "<<cat<<" y tu nuevo sueldo es:$"<<nsueldo<<endl;
        }
}
void ejercicioscorridos(){
    int num,v;
        float val=0;
        cout<<endl<<"Dame el NUM: ";
        cin>>num;
        cout<<endl<<"Dame el valor de v: ";
        cin>>v;
        if(num==1){
            val=100*v;
        }
        if(num==2){
            val=pow(100,v);
        }
        if(num==3){
            val=100/v;
        }if(num>3){
            val=0;
        }
        cout<<endl<<"El valor de VAL es: "<<val<<endl;
}
void aumentodos(){
    float s,ns;
        cout<<endl<<"Dame tu sueldo: ";
        cin>>s;
        if(s<1000){
            ns=s*1.15;
        }else{
            ns=s*1.12;
        }
        cout<<"tu nuevo sueldo es:$"<<ns<<endl;
}
void califex(){
    float calex;
        cout<<endl<<"Dame la calificaciones de tu examen: ";
        cin>>calex;
        if(calex>=8){
            cout<<endl<<"APROBADO!!!"<<endl;
        }else{
            cout<<endl<<"REPROBADO :("<<endl;
        }
}
void aumnentosueldo(){
    float sue,aum,nsue;
        cout<<endl<<"DAME TU SUELDO: ";
        cin>>sue;
        if(sue<1000){
            aum=sue*0.15;
        nsue=sue+aum;
        cout<<endl<<"TU NUEVO SUELDO ES:$"<<nsue<<endl;
        }else{
            cout<<endl<<"NO ERES ACREEDOR DE AUMENTO :("<<endl;
        }
}
void calif(){
    float cal;
        cout<<endl<<"Dame tu califiación: "<<endl;
        cin>>cal;
        if(cal>8)
            cout<<endl<<"APROBADO!!!"<<endl;
        else
            cout<<endl<<"REPROBADO!!!"<<endl;
}

