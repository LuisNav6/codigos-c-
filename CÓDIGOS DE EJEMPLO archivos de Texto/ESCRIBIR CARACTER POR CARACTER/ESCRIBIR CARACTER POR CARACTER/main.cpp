//
//  main.cpp
//  ESCRIBIR CARACTER POR CARACTER
//
//  Created by Luis Navarrete on 05/05/21.
//
#include <iostream>
#include <fstream>//necesaria para el manejo de archivos
using namespace std;

int main ()
{
    fstream file;  //<-----I M P O R T A N T E
    char c;
    file.open("datos.txt",ios::out); //ABRE EL ARCHIVO DE TEXTO DE ESCRITURA
    if ( !file )  // verifica que el archivo se abrio con exito
           cout << " No se pudo abrir el archivo " << endl ;
    else
    {//El archivo se abrio con exito
        cout<<endl<<endl<<"Tecle las lineas que quieras termina con * y un ENTER"<<endl<<endl;
           
       
        //Aqui se graba caracter por caracter en el archivo
        //Ciclo infinito se rompera hasta que se teclee un * (asterisco)
        for (;;) //<-----I M P O R T A N T E
            {
            c=cin.get();  //permite la captura de un caracter
            if( c=='*')
              break;
            else
              file.put( c ); // escribe el car·cter en el archivo
            }
       
       file.close(); //<-----I M P O R T A N T E // cierra el archivo
    }//fin del else

cout<<endl;
system("pause");
return 0;
}//fin del main()
