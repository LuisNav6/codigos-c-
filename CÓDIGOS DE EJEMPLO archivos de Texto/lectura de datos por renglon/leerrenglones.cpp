//Autor: GSP
/* LEER EN UN ARCHIVO DE TEXTO RENGLON X RENGLON*/

#include <iostream> 
#include <fstream> //necesaria para el manejo de archivos
#include <windows.h>
using namespace std;


/*****************************************************************************************************/
int main ()
{
    fstream leerArch; //declaracion local
    char linea[100]; //variable para guardar ahi lo que sacamos del archivo
    leerArch.open("datos.txt",ios::in); //ABRE EL ARCHIVO DE TEXTO DE ESCRITURA
    if ( !leerArch )  // verifica que el archivo se abrio con exito
       cout << " No se pudo abrir el archivo " << endl ;
    else{
        while ( leerArch.getline(linea,100) ){ //recupera una linea de codigo y la almacena en la cadena linea
            cout<<linea<<endl; //imprime la linea a pantalla.
            Sleep(1000);
		}//fin de while
     }//fin del else    

cout<<endl;
system("pause");
return 0;
}//fin del main()

