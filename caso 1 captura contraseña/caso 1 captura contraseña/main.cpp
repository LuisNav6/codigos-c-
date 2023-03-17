//
//  main.cpp
//  caso 1 captura contraseña
//
//  Created by Luis Navarrete on 09/02/21.
//

#include <stdio.h>
void capturapassw();//funcion caso 1 No tiene parametros No retorna valor

int main(){
char resp;
do{
    capturapassw();
printf("\notra vez s/n: ");
fflush(stdin);
resp=getchar();
}while(resp=='s');
return 0;
}
void capturapassw(){
    int password,contador=1;
    do{
        printf("\nIngresa la contraseña:");
        scanf("%d",&password);
        if(password==12345){
            printf("\nBienvenido!!");
            break;
        }else{
            if(contador==1||contador==2){
            printf("\nError en la contraseña\n");
            }else{
                printf("\nOportunidades agotadas :(");
            }
        }
        contador++;
    }while(contador<=3);
}
