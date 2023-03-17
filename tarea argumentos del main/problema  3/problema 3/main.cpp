//
//  main.cpp
//  tarea
//
//  Created by Luis Navarrete on 16/02/21.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    float acum=0,prom;
    printf("\nNombre %s",argv[1]);
    printf("\nCalificaciones:\n");
    for(int i=2;i<argc;i++){
        printf("\n%s",argv[i]);
        acum+=atof(argv[i]);
    }
    prom=acum/(argc-2);
    printf("\nPromedio= %.2f",prom);
    if(prom>=7)
        printf("\nAprobado!!");
    else
        printf("\nReprobado!!");
    
    
    return 0;
}
