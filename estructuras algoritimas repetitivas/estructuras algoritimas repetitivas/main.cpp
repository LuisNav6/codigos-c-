//
//  main.cpp
//  estructuras algoritimas repetitivas
//
//  Created by Luis Navarrete on 16/08/21.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <math.h>
using namespace std;
void impares();
void serie();
void seriefracc();
void aumento();
void positivos();
void maymen();
void vendedor();
void ulam();
void sumacuadrados();
void fibonacci();
void elecciones();
void maysueldo();
void lluvias();
void estadio();
void tel();
void bodega();
void primos();
void secretaria();
void perfectos();
int main(int argc, const char * argv[]) {
    srand(time_t(0));
    int resp;
    do{
        cout<<endl<<"--------------------------------------------------------"<<endl;
        cout<<"M           E                N             U"<<endl;
        cout<<"Numeros impares y pares...1"<<endl;
        cout<<"Suma de Numeros en serie..2"<<endl;
        cout<<"Suma de Numeros fracionarios en serie...3"<<endl;
        cout<<"Aumento de sueldo...4"<<endl;
        cout<<"Números positivos...5"<<endl;
        cout<<"Mayor y Menor...6"<<endl;
        cout<<"Ventas...7"<<endl;
        cout<<"ULAM...8"<<endl;
        cout<<"serie suma de cuadrados...9"<<endl;
        cout<<"Serie Fibonacci...10"<<endl;
        cout<<"Elecciones...11"<<endl;
        cout<<"Mayor sueldo...12"<<endl;
        cout<<"Lluvias...13"<<endl;
        cout<<"Estadio...14"<<endl;
        cout<<"Telefono...15"<<endl;
        cout<<"Bodega...16"<<endl;
        cout<<"Primos...17"<<endl;
        cout<<"Secretaria de industria...18"<<endl;
        cout<<"Numeros perfectos...19"<<endl;
        cout<<"Salir...20"<<endl;
        cout<<"Selecciona la opcion deseada: "<<endl;
        cin>>resp;
        switch(resp){
            case 1: impares();
                break;
            case 2: serie();
                break;
            case 3: seriefracc();
                break;
            case 4: aumento();
                break;
            case 5: positivos();
                break;
            case 6: maymen();
                break;
            case 7: vendedor();
                break;
            case 8: ulam();
                break;
            case 9: sumacuadrados();
                break;
            case 10: fibonacci();
                break;
            case 11: elecciones();
                break;
            case 12: maysueldo();
                    break;
            case 13: lluvias();
                break;
            case 14: estadio();
                break;
            case 15: tel();
                break;
            case 16: bodega();
                break;
            case 17: primos();
                break;
            case 18: secretaria();
                break;
            case 19: perfectos();
                break;
                
        }
        if(resp==20)
            cout<<endl<<"HASTA LUEGO :)"<<endl;
    }while(resp!=20);
    return 0;
}
void perfectos(){
    int i,n,sum,j;
    cout<<endl<<"Dame el limite:";
    cin>>n;
    for(i=1;i<=n;i++){
        sum=0;
        for(j=1;j<=i/2;j++){
            if((i%j)==0){
                sum+=j;
            }
        }
        if(sum==i){
            cout<<i<<" Es un numero perfecto \t";
        }
    }
}
void secretaria(){
    int i,clave,j,n,fabrica;
    float maypro=0.0,totanu,mes;
    cout<<endl<<"Dame el total de fabricas registradas:";
    cin>>n;
    if(n<=1000){
        for(i=1;i<=n;i++){
            cout<<endl<<"Dame la clave que identifica a la empresa "<<i<<" :";
            cin>>fabrica;
            totanu=0.0;
            for(j=1;j<=12;j++){
                cout<<endl<<"Dame la producción del mes "<<j<<" de la empresa "<<i<<" :";
                cin>>mes;
                totanu+=mes;
                if(j==7&&mes>3000000.0){
                    cout<<fabrica<<endl;
                }
            }
            if(totanu>maypro){
                maypro=totanu;
                clave=fabrica;
            }
            cout<<"Producción anual fabrica:"<<fabrica<<" $:"<<totanu<<endl;
        }
    }else{
        cout<<"Error en números de fabricas!"<<endl;
    }
}
void primos(){
    int i=3,sp=0,j;
    float m;
    bool band;
    cout<<endl<<"Dame el limite:";
    cin>>m;
    if(m>=1){
        sp+=1;
        cout<<"Numero primo:"<<1<<"\t";
    }
    if(m>=2){
        sp+=1;
        cout<<"Numero primo:"<<2<<"\t";
    }
    while(i<=m){
        band=true;
        j=3;
    while(j<(i/2)&&band==true){
        if((i%j)==0){
            band=false;
        }
        j+=2;
    }
    if(band==true){
        cout<<"Numero primo:"<<i<<"\t";
        sp+=1;
    }
    i+=2;
}
    cout<<endl<<"Entre 1 y "<<m<<"hay "<<sp<<" numeros primos"<<endl;
}
void bodega(){
    int i,year,j,n;
    float t1=0.0,t2=0.0,t3=0.0,t4=0.0,t5=0.0,mct2=0.0,totvin,v;
    cout<<endl<<"Dame el número de años:";
    cin>>n;
    for(i=1;i<=n;i++){
        totvin=0.0;
        for(j=1;j<=5;j++){
            cout<<endl<<"Dame el total de litros:";
            cin>>v;
            totvin+=v;
            if(j==1)
                t1+=v;
            if(j==2)
                t2+=v;
            if(v>mct2){
                mct2=v;
                year=i;
            }
            if(j==3)
                t3+=v;
            if(v==0)
                cout<<endl<<"En el año:"<<i<<" no se podrujo vino tipo3!";
            if(j==4)
                t4+=v;
            if(j==5)
                t5+=v;
        }
        cout<<endl<<"Total de litros producidos en año:"<<i<<" son:"<<totvin;
    }
    cout<<endl<<"Total tipo 1:"<<t1;
    cout<<endl<<"Total tipo 2:"<<t2;
    cout<<endl<<"Total tipo 3:"<<t3;
    cout<<endl<<"Total tipo 4:"<<t4;
    cout<<endl<<"Total tipo 5:"<<t5;
    cout<<endl<<"Año en que se produjo mayor cantidad vino tipo 2:"<<year<<" litros:"<<mct2<<endl;
}
void tel(){
    int cl=0,dur=0;
    float cuenta,costo;
    char tipo;
    cout<<endl<<"Dame el tipo de llamada(i para Internacional, n para nacional y l para local y x para salir):";
    cin>>tipo;
    cout<<endl<<"Dame la duración de tu llamada:";
    cin>>dur;
    while(tipo!='x'&&dur!=-1){
        if(tipo=='i'){
            if(dur>3)
                costo=7.59+((dur-3)*3.03);
            else
                costo=7.59;
        }
        if(tipo=='l'){
            cl+=1;
            if(cl>50)
                costo=0.6;
            else
                costo=0;
    }
        if(tipo=='n'){
            if(dur>3)
                costo=1.2+((dur-3)*0.48);
            else
                costo=1.2;
            
        }
        cuenta+=costo;
        cout<<endl<<"Dame el tipo de llamada(i para Internacional, n para nacional y l para local y x para salir):";
        cin>>tipo;
        cout<<endl<<"Dame la duración de tu llamada:";
        cin>>dur;
}
    cout<<endl<<"El total a pagar es:$"<<cuenta<<endl;
}
void estadio(){
    int ap1=0,ap2=0,ap3=0,ap4=0,ap5=0,clave,cant;
    float recau=0.0,p1,p2,p3,p4,p5,pre;
    cout<<endl<<"Dame el precio de la localidad 1:";
    cin>>p1;
    cout<<endl<<"Dame el precio de la localidad 2:";
    cin>>p2;
    cout<<endl<<"Dame el precio de la localidad 3:";
    cin>>p3;
    cout<<endl<<"Dame el precio de la localidad 4:";
    cin>>p4;
    cout<<endl<<"Dame el precio de la localidad 5:";
    cin>>p5;
    cout<<endl<<"Dame el tipo de localidad que quieres(1,2,3,4,5):";
    cin>>clave;
    cout<<endl<<"Dame la cantidad de boletos que quieres:";
    cin>>cant;
    while(clave!=-1&&cant!=-1){
        if(clave==1){
            pre=p1*cant;
            ap1+=cant;
        }
        if(clave==2){
            pre=p2*cant;
            ap2+=cant;
        }
        if(clave==3){
            pre=p3*cant;
            ap3+=cant;
        }
        if(clave==4){
            pre=p4*cant;
            ap4+=cant;
        }
        if(clave==5){
            pre=p5*cant;
            ap5+=cant;
        }
        cout<<endl<<clave<<"\t"<<cant<<"\t"<<pre;
        recau+=pre;
        cout<<endl<<"Dame el tipo de localidad que quieres(1,2,3,4,5):";
        cin>>clave;
        cout<<endl<<"Dame la cantidad de boletos que quieres:";
        cin>>cant;
    }
    cout<<endl<<"cantidad boletos localidad 1:"<<ap1;
    cout<<endl<<"cantidad boletos localidad 2:"<<ap2;
    cout<<endl<<"cantidad boletos localidad 3:"<<ap3;
    cout<<endl<<"cantidad boletos localidad 4:"<<ap4;
    cout<<endl<<"cantidad boletos localidad 5:"<<ap5;
    cout<<endl<<"Recaudación del estadio fue:$"<<recau;
}
void lluvias(){
    int i,mes;
    float arno=0.0,arce=0.0,arsu=0.0,mersu=500000.0,rno,rce,rsu,prorce;
    for(i=1;i<=12;i++){
        cout<<endl<<"Dame las lluvias caidas en el mes "<<i<<" en la Región norte:";
        cin>>rno;
        cout<<endl<<"Dame las lluvias caidas en el mes "<<i<<" en la Región centro:";
        cin>>rce;
        cout<<endl<<"Dame las lluvias caidas en el mes "<<i<<" en la Región sur:";
        cin>>rsu;
        arno+=rno;
        arce+=rce;
        arsu+=rsu;
        if(rsu<mersu){
            mersu=rsu;
            mes=i;
        }
    }
    prorce=arce/12;
    cout<<"Promedio region:"<<prorce<<endl;
    cout<<"mes con menor lluvia en la region sur:"<<mes<<endl;
    cout<<"Registro del mes:"<<mersu<<endl;
    if(arno>arce){
        if(arno>arsu){
            cout<<"La región con más lluvia es la norte"<<endl;
        }else{
            cout<<"La región con más lluvia es la sur"<<endl;
        }
    }else{
        if(arce>arsu){
            cout<<"La región con más lluvia es la centro"<<endl;
        }else{
            cout<<"La región con más lluvia es la sur"<<endl;
        }
    }
}
void maysueldo(){
    int i,n,numep,manum;
    float sue,masue=0.0;
    cout<<endl<<"Dame el numero total de empleados:";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<endl<<"Dame tu ID de empleado:";
        cin>>numep;
        cout<<endl<<"Dame tu sueldo:";
        cin>>sue;
        if(sue>masue){
            masue=sue;
            manum=numep;
        }
    }
    cout<<endl<<"El empleado con el sueldo más alto es:"<<manum<<" con un sueldo de:$"<<masue<<endl;
}
void elecciones(){
    int voto;
    float por1,por2,por3,por4,can1=0.0,can2=0.0,can3=0.0,can4=0.0,sumv;
    cout<<endl<<"Dame tu voto(1,2,3,4): ";
    cin>>voto;
    while(voto!=0){
        if(voto==1)
            can1+=1;
        if(voto==2)
            can2+=1;
        if(voto==3)
            can3+=1;
        if(voto==4)
            can4+=1;
        cout<<endl<<"Dame tu voto(1,2,3,4): ";
        cin>>voto;
    }
        sumv=can1+can2+can3+can4;
        por1=(can1/sumv)*100;
        por2=(can2/sumv)*100;
        por3=(can3/sumv)*100;
        por4=(can4/sumv)*100;
        cout<<endl<<"Votos candidato 1:"<<can1<<" porcentaje:"<<por1<<endl;
        cout<<endl<<"Votos candidato 2:"<<can2<<" porcentaje:"<<por2<<endl;
        cout<<endl<<"Votos candidato 3:"<<can3<<" porcentaje:"<<por3<<endl;
        cout<<endl<<"Votos candidato 4:"<<can4<<" porcentaje:"<<por4<<endl;
        cout<<endl<<"Cantidad de votantes:"<<sumv;
    
}
void fibonacci(){
    float pri=0.0,seg=1.0,sig=0.0;
    cout<<pri<<"\t"<<seg<<"\t";
    for(int i=3;i<=180;i++){
       // cout<<i<<" ";
        sig=pri+seg;
        pri=seg;
        seg=sig;
        cout<<sig<<"\t";
    }

    cout<<endl;
}
void sumacuadrados(){
    int i,n;
    float serie=0.0;
    cout<<endl<<"Dame el numero de la serie: ";
    cin>>n;
    for(i=1;i<=n;i++){
        serie=serie+pow(i,i);
    }
    cout<<endl<<"La suma de la serie es: "<<serie<<endl;
}
void ulam(){
    int num;
    cout<<endl<<"Dame el numero: ";
    cin>>num;
    if(num>0){
        while(num!=1){
            cout<<num<<" ";
            if((pow(-1,num))>0){
                num=num/2;
            }else{
                num=(num*3)+1;
            }
    }
        cout<<num<<" ";
    }else{
        cout<<endl<<"El numero tiene que ser un entero positivo"<<endl;
    }
  
}
void vendedor(){
    int i=1,n,c=0,m=0,g=0;
    float v;
    cout<<endl<<"Dame el total de ventas: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<endl<<"Dame el costo de la venta "<<i<<": ";
        cin>>v;
        if(v<=200){
            c+=1;
        }else{
            if(v<400&&v>200){
                m+=1;
            }else{
                g+=1;
            }
        }
    }
    cout<<endl<<"Las ventas menores o iguales a 200 fueron:"<<c<<" las mayores a 200 pero menores a 400 fueron:"<<m<<" y las mayores a 400 fueron:"<<g<<endl;
}
void maymen(){
    int i,n,num;
    float may=-100000.00,men=100000.00;
    cout<<endl<<"Dame el limite: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<endl<<"Dame el numero: ";
        cin>>num;
        if(num>may){
            may=num;
        }
        if(num<men){
            men=num;
        }
    }
    cout<<endl<<"El mayor fue:"<<may<<" Y el menor fue:"<<men<<endl;
}

void positivos(){
    float sumpositivos=0.0,sumnegativos=0.0,prom,prompositivos;
    int cont=0,num,n,i;
    cout<<endl<<"Dame el limite: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<endl<<"Dame el numero: ";
        cin>>num;
        if(num>0){
            sumpositivos+=num;
            cont+=1;
        }else{
            sumnegativos+=num;
        }
    }
    prom=(sumpositivos+sumnegativos)/n;
    prompositivos=sumpositivos/cont;
    cout<<endl<<"El total de numeros positivos son:"<<cont<<" El promedio de numeros positivos fue:"<<prompositivos<<"% Y el promedio de todos los numeros ingresados fue:"<<prom<<"%"<<endl;
}
void aumento(){
    float nom=0.0,sueldo,nuevosueldo;
    cout<<endl<<"Dame tu sueldo: ";
    cin>>sueldo;
    while(sueldo!=-1){
        if(sueldo<1000){
            nuevosueldo=sueldo*1.15;
        }else{
            nuevosueldo=sueldo*1.12;
        }
        nom+=nuevosueldo;
        cout<<endl<<"el sueldo del trabajador es:$"<<nuevosueldo<<endl;
        cout<<endl<<"Dame tu sueldo(para salir pulsa -1): ";
        cin>>sueldo;
    }
    cout<<endl<<"La nòmina total quedo en:$"<<nom<<endl;
}

void seriefracc(){
    int i,n;
    float serie=0.0;
    bool band;
    band=true;
    i=1;
    cout<<endl<<"Dame el límite de la serie: ";
    cin>>n;
    while(i<=n){
        cout<<i<<"-";
        if(band==true){
            serie+=1.0/i;
            band=false;
        }else{
            serie-=1.0/i;
            band=true;
        }
        i+=1;
    }
    cout<<endl<<serie<<endl;
}
void serie(){
    int i,suma=0,num=2;
    bool band=true;
    for(i=2;num<=1800;i++){
        cout<<num<<"-";
        suma+=num;
        if(band==true){
            num+=3;
            band=false;
        }else{
            num+=2;
        }
      
    }
    cout<<"La suma de la serie es: "<<suma<<endl;
}
void impares(){
    float i,sumim=0,sumpar=0,totpar=0;
    int num;
    for(i=0;i<5;i++){
        num=(rand()%10)+1;
        cout<<num<<"-";
        if(num%2==0){
            sumpar+=num;
            totpar++;
        }else{
            sumim+=num;
        }
    }
    cout<<endl<<"El promedio de los pares es: "<<sumpar/totpar<<endl;
    cout<<"la suma de los impares es: "<<sumim<<endl;
}
