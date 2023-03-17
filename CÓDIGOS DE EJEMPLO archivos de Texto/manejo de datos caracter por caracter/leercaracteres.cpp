//Autor: GSP
/*   LEER EN UN ARCHIVO DE TEXTO CARACTER POR CARACTER*/

#include <iostream>
#include <fstream>//necesaria para el manejo de archivos
#include <windows.h>
using namespace std;


int main ()
{   fstream file;  //<-----I M P O R T A N T E
    char c;
	file.open("datos.txt",ios::in); //Abrimos el archivo de lectura
	//Las siguientes  dos lineas son necesarias para comenzar la lectura del archivo desde el principio
	file.clear();   //<-----I M P O R T A N T E
	file.seekg( 0 );  //<-----I M P O R T A N T E
	if ( !file )  // verifica que el archivo se abrio con exito
  	  cout << " No se pudo leer el archivo " << endl;
	else{//el archivo se abrio con exito
   	  
		 
		  //<-----I M P O R T A N T E lee caracter x caracter la informacion del archivo
		 while (file.get(c)){  // obtiene un caracter del archivo lo asigna a la c, el ciclo da vueltas
                              //mientras existan caracteres que leer
        cout<<c;//imprime el caracter leido en pantalla.
        Sleep(250);
      }//fin while
     }//fin else
file.close(); //<-----I M P O R T A N T E

cout<<endl;
system("pause");
return 0;
}//fin del main()



