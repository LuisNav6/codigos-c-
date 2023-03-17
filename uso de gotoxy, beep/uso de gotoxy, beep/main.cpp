//
//  main.cpp
//  uso de gotoxy, beep
//
//  Created by Luis Navarrete on 11/05/21.
//
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define REN 3
# define COL 3
#define negro 0
#define azul 1
#define verde 2
#define cyan 3
#define rojo 4
#define magenta 5
#define marron 6
#define grisclaro 7
#define grisoscuro 8
#define azulclaro 9
#define verdeclaro 10
#define cyanclaro 11
#define rojoclaro 12
#define magentaclaro 13
#define amarillo 14
#define blanco 15
#include <iostream>

using namespace std;

//prototipos

void gotoxy(int x,int y);
void textcolor(int n);
 
void ejemplo1();
void ejemplo2();
void ejemplo3();
void colores();
void imprimeMatriz();
 

int main( )
{
    int opc;
    do{
        
        system("cls");
        system("color 07"); //Esta combinacion es fondo negro texto blanco
        printf("\n\nMenu");
        printf("\n***********************************");
        printf("\n1. Estrellas aleatorias con color y sonido");
        printf("\n2. Combinaciones de fondo y tipo de letra");
        printf("\n3. Melodia ");
        printf("\n4. Imprime una matriz usando gotoxy ");
    
        printf("\n5. salir ");
        printf("\n***********************************");
        printf("\n Que opcion deseas: \a ");
        scanf("%d", &opc);
        
        switch(opc){
            case 1: ejemplo1(); break;
            case 2: ejemplo2(); break;
            case 3: ejemplo3(); break;
            case 4: imprimeMatriz(); break;
        
            case 5: puts("fin de programa");break;
            default:
                puts("\n\nError  ..... ");
                fflush(stdin);
                getchar();
        }


    }while (opc!=5);
     
   
}

void imprimeMatriz(){
    fflush(stdin);
    int renglon,columna;
    int m[REN][COL]={{100,20,45},{89,345,12},{3,78,345}};
    renglon=6;//<---------------------
    system("cls");//limpia pantalla
    for (int r=0; r<REN; r++){
        columna=20; //<-------------------------
        for (int c=0; c<COL; c++){
             gotoxy(2,2);printf("posicion en pantalla utilizadas por el gotoxy col= %d ren= %d  ",columna,renglon);
             gotoxy(2,3);printf("indices de la matriz a imprimir ren= %d col= %d  ",r,c);
             
             gotoxy(columna,renglon); cout<<m[r][c];
             columna=columna+5;//<-----------------
             getchar();
        }//fin for de j
        renglon=renglon+3;
    }//fin for i
    system("pause");
}


void ejemplo3(){
    int tiempo[]={500,500,500,500,500,500,500,500,500,500,500,500,500,500,375,125,250,250,500,500,375,125,250,250,500,500,500,500,500};
     
    char nota[]="fgaffgafabDabDDRDbafDRDbaffcf";
     
    int i;
    for (i=0; i<strlen(nota);i++){
       printf ("\nNota %c tiempo %d",nota[i], tiempo[i]);
       Sleep(tiempo[i]-tiempo[i]/2);
       switch(nota[i]){
          case 'f': Beep(349,250); break;
          case 'g': Beep(392,250); break;
          case 'a': Beep(440,250); break;
          case 'b': Beep(493,250); break;
          case 'D': Beep(587,250); break;
          case 'e': Beep(329,250); break;
          case 'c': Beep(261,250);  break;
       }
          
    }
    getchar();
    
}



void ejemplo1(){
       int num;
       int columna, renglon, i,color, tiempo=200;
       srand(time_t(0));
       printf ("\n--Cuantas estrellas quieres: ");
       scanf("%d", &num);
       system("cls"); //borra pantalla completa
       for (i=1; i<=num; i++){
               textcolor(15);
               gotoxy(1,1);
                printf("contador %d/%d", i,num);
               //Sleep(tiempo);//retardo
               columna = 1+rand()%(80-1+1); //aleatorio para la columna entre 1 y 80
              renglon = 2+rand()%(24-2 +1); //aleatorio para el renglon entre 1 y 24
              color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
               textcolor(color); //Cambia el color a la letra
               Beep(200+rand()%(300-200+1),250);
               gotoxy(columna, renglon); printf("*");
       }
            
        
       fflush(stdin);
       getchar(); //Espera oprimir cualquier tecla
       system("cls"); //borra pantalla completa

}


void colores(){
    printf("\n Menu de Colores");
    printf("\n 0 = Black");
    printf("\n 1 = Blue ");
    printf("\n 2 = Green");
    printf("\n 3 = Aqua");
    printf("\n 4 = Red");
    printf("\n 5 = Purple");
    printf("\n 6 = Yellow");
    printf("\n 7 = White");
    printf("\n 8 = Gray");
    printf("\n 9 = Light Blue");
    printf("\n A = Light Green");
    printf("\n B = Light Aqua");
    printf("\n C = Light Red");
    printf("\n D = Light Purple");
    printf("\n E = Light Yellow");
    printf("\n F = Bright White");

    
}

void ejemplo2(){
      
       //COMBINACIONES DE FONDO Y TIPO DE LETRA
        
       char combinacion[10];
       char fondo[2]; //se  captura en cadena para facilitar la concatenacion o suma de cadenas
       char texto[2]; ////se captura en cadena para facilitar la concatenacion o suma de cadenas
       char resp;
 do{
       system("cls"); //borrar pantalla
       system("color 07"); //Esta combinacion es fondo negro texto blanco
       strcpy(combinacion,"");//limpiando cadena combinacion.
       colores();
       printf ("\n Selecciona un color para el fondo: ");
       fflush(stdin);
       gets(fondo);
       colores();
       printf( "\n Selecciona un color para el texto: ");
       gets(texto);
       
       //concatenacion de cadenas para ser usada como UNA SOLA CADENA dentro de system
       //la funcion strcat concatena cadenas, concatenar en unir a la cadena otro texto.
       strcat(combinacion,"color ");
       strcat(combinacion,fondo);
       strcat(combinacion,texto);
       
       
       system (combinacion); //<---- Esta es la instruccion que aplica la combinacion. Ejemplo system(color 5E);
       
       system("cls"); //borrar pantalla
       printf("\nEsta es la combinacion que elegiste fondo %s texto %s",fondo, texto);
       printf ("\n\nQuieres probar otra combinacion s/n: ");
       fflush(stdin);
       resp=getchar();
       
 }while (resp!='n');
       
 
}


/**********************************************/
void gotoxy(int x,int y){ //-----------------------------------------------------------------------------------------------------------------
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
/**********************************************/
void textcolor(int n){ //--------------------------------------------------------------------------------------------------------------------
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
