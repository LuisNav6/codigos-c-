//Autor: GSP
/* ESCRIBIR EN UN ARCHIVO DE TEXTO CAMPO X CAMPO*/

#include <iostream> 
#include <string>
#include <fstream> //necesaria para el manejo de archivos
using namespace std;

int main ()

{
//GUARDANDO numero de cuenta, nombre del cliente y monto de la cuenta   EN EL ARCHIVO DE TEXTO
fstream file; //<-----I M P O R T A N T E
char nomarch[30]="clientes.txt";
int cuenta;
string nombre;
float monto;
char resp='s';

//ABRE EL ARCHIVO DE TEXTO DE ESCRITURA CON CAPACIDAD DE AGREGAR INFORMACION A LA YA EXISTENTE
file.open(nomarch,ios::out|ios::app);  //<-----I M P O R T A N T E
if ( !file )  // verifica que el archivo se abrio con exito
    cout << " No se pudo abrir el archivo " << endl ;
else
{ //el archivo se abrio con exito
// datos del cliente
	while(resp=='s' ){ // mientras resp == 's'
  	  cout << "\nDame un numero de cuenta :";
  	  cin >> cuenta;
  	  cout << "\nDame un nombre ( solo una palabra ): ";
   	  fflush(stdin);
   	  getline(cin,nombre);
   	  cout << "\nDame el monto :";
      cin >> monto;
      
      //Escribe o guarda la informacion en el archivo de texto 
      file << cuenta << " " << nombre << " "<< monto << endl; //<-----I M P O R T A N T E
      
	  cout << "\nDeseas seguir ingresando datos s/n: ";
      fflush(stdin);
      cin.get(resp);  //captura la respuesta puede ser cin>>resp;
     }
    // cierra el archivo
	file.close(); //<-----I M P O R T A N T E
}//fin del else
cout<<endl<<"Informacion almacenada en el archivo "<<nomarch<<endl;
system("pause");
return 0;
}//fin del main()



