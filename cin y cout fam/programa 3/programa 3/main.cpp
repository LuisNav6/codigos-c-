//
//  main.cpp
//  programa 3
//
//  Created by Luis Navarrete on 17/03/21.
//
/*Este programa captura 3 calificaciones que envia a una funcion que se encarga de obtener el promedio ademas,si el alumno promedia calificaciones >=7,se despliga "aprobado", caso contrario se despliega "reprobado" */
#include <iostream>
using namespace std;
void promedio(float c1,float c2,float c3);
int main() {
    float c1,c2,c3;
    cout<<endl<<"calificacion 1:";
    cin>>c1;cout<<endl;
    cout<<endl<<"calificacion 2:";
    cin>>c2;cout<<endl;
    cout<<endl<<"calificacion 3:";
    cin>>c3;cout<<endl;
    promedio(c1,c2,c3);//llamamos a la funcion
    cout<<endl;
    return 0;
}
void promedio(float c1,float c2,float c3){
    float prom;
    prom=(c1+c2+c3)/3;
    if(prom>=7){
        cout<<endl;
        cout<<"APROBADO, tu calificacion es: "<<prom;
    }
    else{
        cout<<endl;
    cout<<"REPROBADO, tu calificacion es: "<<prom;
}
}
