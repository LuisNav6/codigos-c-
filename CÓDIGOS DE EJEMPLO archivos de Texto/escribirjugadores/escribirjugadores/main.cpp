//
//  main.cpp
//  escribirjugadores
//
//  Created by Luis Navarrete on 03/05/21.
//
#include <iostream>
#include <string>
#include <fstream> //necesaria para el manejo de archivos
using namespace std;

int main ()

{
//GUARDANDO numero de cuenta, nombre del cliente y monto de la cuenta   EN EL ARCHIVO DE TEXTO
fstream file; // M P O R T A N T E
char nomarch[30]="jugadores.txt";
    string nomjug,nomeq;
    int edad = 0,n;
    cout<<endl<<"Cuantos jugadores son: ";
    cin>>n;
    
//ABRE EL ARCHIVO DE TEXTO DE ESCRITURA CON CAPACIDAD DE AGREGAR INFORMACION A LA YA EXISTENTE
file.open(nomarch,ios::out|ios::app);  //I M P O R T A N T E
if ( !file )  // verifica que el archivo se abrio con exito
    cout << " No se pudo abrir el archivo " << endl ;
else
{ //el archivo se abrio con exito
// datos del jugador
    for(int i=1;i<=n;i++){
        cout << "\nDame el nombre del jugador#"<<i<<": ";
        cin >> nomjug;
        cout << "\nA que equipo pertenece: ";
        fflush(stdin);
        cin>>nomeq;
         cout << "\nDame la edad:";
      cin >>edad;
    }
      //Escribe o guarda la informacion en el archivo de texto
      file << nomjug << " " << nomeq << " "<< edad<< endl; //I M P O R T A N T E
    file.close(); //I M P O R T A N T E
}//fin del else
cout<<endl<<"Informacion almacenada en el archivo "<<nomarch<<endl;
system("pause");
return 0;
}//fin del main()

