//
//  main.cpp
//  LEER CARACTER POR CARACTER
//
//  Created by Luis Navarrete on 05/05/21.
//

#include <iostream>
#include <fstream>//necesaria para el manejo de archivos
#include <windows.h>
using namespace std;


int main ()
{   fstream file,filecopia;  //I M P O R T A N T E
    char c;
    file.open("jugadores.txt",ios::in); //Abrimos el archivo de lectura
    //Las siguientes  dos lineas son necesarias para comenzar la lectura del archivo desde el principio
    file.open("copiajuagdores.txt",ios::in);
    file.clear();   //I M P O R T A N T E
    file.seekg( 0 );  //I M P O R T A N T E
    if ( !file || !filecopia )  // verifica que el archivo se abrio con exito
        cout << " No se pudo leer/escribir el archivo " << endl;
    else{//el archivo se abrio con exito
        int conA=0,conE=0,conI=0,conO=0,conU=0;
       
          //I M P O R T A N T E lee caracter x caracter la informacion del archivo
         while (file.get(c)){  // obtiene un caracter del archivo lo asigna a la c, el ciclo da vueltas
                              //mientras existan caracteres que leer
        cout<<c;//imprime el caracter leido en pantalla.
        //Sleep(250);
             filecopia.put(c);//escribe el caracter en otro archivo
             switch(c){
                 case 'a':case 'A': conA++; break;
                 case 'e':case 'E': conE++; break;
                 case 'i':case 'I': conI++; break;
                 case 'o':case 'O': conO++; break;
                 case 'u':case 'U': conU++; break;
             }
                 
      }//fin while
        cout<<endl<<"Total de a: "<<conA;
        cout<<endl<<"Total de e: "<<conE;
        cout<<endl<<"Total de i: "<<conI;
        cout<<endl<<"Total de o: "<<conO;
        cout<<endl<<"Total de u: "<<conU;
     }//fin else
file.close(); //I M P O R T A N T E
    filecopia.close();
cout<<endl;
system("pause");
return 0;
}//fin del main()
