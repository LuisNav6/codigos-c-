//
//  main.cpp
//  leerjugadores
//
//  Created by Luis Navarrete on 04/05/21.
//

//
//  main.cpp
//  leerjugadores
//
//  Created by Luis Navarrete on 03/05/21.
//

#include <iostream>
#include <string>
#include <fstream> //necesaria para el manejo de archivos
using namespace std;

 //RECUPERANDO INFORMACION EN EL ARCHIVO DE TEXTO campo x campo
 
int main ()
{
    fstream file; //I M P O R T A N T E
    
    int edad;
    string nomjug,nomeq;
    int contador;
    float acum = 0.0;
    //Abrimos el archivo de lectura
    file.open("jugadores.txt",ios::in);  //I M P O R T A N T E
    //Las siguientes  dos lineas son necesarias para comenzar la lectura del archivo desde el primer registro
    file.clear();    //I M P O R T A N T E
    file.seekg( 0 ); //I M P O R T A N T E
    if ( !file )  // verifica que el archivo se abrio con exito
        cout << " No se pudo leer el archivo " << endl;
    else{
        cout<<endl<<endl<<"Lista de jugadores!";
        contador=0;
        //I M P O R T A N T E  aqui recorre el archivo para recuperar la informacion
        while( file >>nomjug>>nomeq>>edad) /* obtiene un registro del archivo,
                                                    el ciclo da vueltas mientras no se acabe el archivo*/
           
        {
            contador++;//incrementando el total de jugadores
            acum=acum+edad;
              cout<<endl;
            cout << "\nNombre del jugador:";
            for(int i=0;i<nomjug.size();i++){
                if(nomjug[i]!='_')
                    cout<<nomjug[i];
                else
                    cout<<" ";
            }
              cout << "\nNombre del Equipo:" <<nomeq;
              cout << "\nEdad:" << edad;

        }//fin while
        cout<<endl<<"Total de jugadores: "<<contador;
        cout<<endl<<"Promedio de edades: "<<acum/contador;
        string equipo;
        cout<<endl<<"Equipo que deseas consultar: ";
        cin>>equipo;
        file.clear();    //I M P O R T A N T E
        file.seekg( 0 );
        bool existe=false;
        while( file >>nomjug>>nomeq>>edad){
            cout<<endl<<"Equipo que deseas consultar: ";
            cin>>equipo;
            //coloque el puntero al principio con lo de abajo
            if(equipo==nomeq)
                existe=true;
            cout<<endl<<"Nombre de jugador: ";
            for(int i=0;i<nomjug.size();i++){
                if(nomjug[i]!='_')
                    cout<<nomjug[i];
                else
                    cout<<" ";
            cout<<endl<<"Edad: "<<edad;
        }
          if(existe==false)
              cout<<endl<<"no tenemos ese equipo en la lista!";
        file.close(); //I M P O R T A N T E
    }//fin else
     
    cout<<endl;
    system("pause");
    return 0;
}//fin del main()
