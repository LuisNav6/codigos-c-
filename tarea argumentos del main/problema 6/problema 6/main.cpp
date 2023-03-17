//
//  main.cpp
//  problema 6
//
//  Created by Luis Navarrete on 18/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void notacion(int num);//caso 2
int cuentadigitos(int num);//caso 4

int main(int argc,char **argv){
    int num=0;
    int notacion;
    printf("\nTotal de argumentos que mandaron:%d",argc-1);
    for(int i=1;i<argc;i++)
    {
    num=atoi(argv[i]);
      notacion=num;
    }
    //notacion(12345);
}
void notacion(int num){
    char cadena[20];
    int totaldigitos;
    float potencia;
    totaldigitos=cuentadigitos(num);
    printf("\ntotal de digitos: %d\n",totaldigitos);
//cambiar el numero a cadena
    itoa(num,cadena,10);
    printf("\n");
    printf("\n%d=>",num);
    potencia=totaldigitos-1;
    for(int i=0;i<totaldigitos;i++){
        printf("%.0f x %c--\t",pow(10,potencia),cadena[i]);
        potencia--;
    }
}
int cuentadigitos(int num){
    int contador=1;
    int cociente;
    cociente=num/10;
    while(cociente!=0){
        cociente/=10;
        contador++;
        
    }
    return contador;
}

