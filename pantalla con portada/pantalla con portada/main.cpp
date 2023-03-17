//
//  main.cpp
//  pantalla con portada
//
//  Created by Luis Navarrete on 13/05/21.
//

#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y);
void textcolor(int n);
void portada();
int main(){
    portada();
    return 0;
}
void portada(){
    //la pantalla del monitor utiliza aprox 80 columnas y 25 renglones
    //cuando se usa gotoxy, lo primero es saber cual columna y renglon se quiere
    //gotoxy(CUAL_COLUMNA,CUAL_RENGLON);
    textcolor(10);
    for(int i=20;i<=50;i++){
        gotoxy(i,4);cout<<"=";
    }
    gotoxy(20,5);cout<<"UNIVERSIDAD AUTONOMA DE AGUASCALIENTES";
    textcolor(18);
    gotoxy(45,8);cout<<"ISC";
    textcolor(5);
    gotoxy(20,10);cout<<"PROGRAMACION 1";
     textcolor(20);
    gotoxy(20,15);cout<<"BINGO";
    //sleep(150);
     textcolor(8);
    gotoxy(20,20);cout<<"Georgina Salazar Partida";
   textcolor(2);
    gotoxy(20,25);cout<<"José Antonio Jimenez Romo";
       textcolor(3);
    gotoxy(20,30);cout<<"Andrea Candelario De La Cruz";
       textcolor(4);
    gotoxy(20,35);cout<<"Angel Armando Ramírez Almaraz";
       textcolor(5);
    gotoxy(20,40);cout<<"Luis Humberto Navarrete Balandrán";
       textcolor(7);
    gotoxy(40,50);cout<<"14/05/2021";
}
