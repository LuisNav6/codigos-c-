//Autor: GSP
/*  LEER EN UN ARCHIVO DE TEXTO CAMPO X CAMPO*/

#include <iostream>
#include <string> 
#include <fstream> //necesaria para el manejo de archivos
using namespace std;

 //RECUPERANDO INFORMACION EN EL ARCHIVO DE TEXTO campo x campo 
 
int main ()
{
    fstream file; //<----------- I M P O R T A N T E
    
	int cuenta;
	string nombre;
	float monto;

    //Abrimos el archivo de lectura 
	file.open("clientes.txt",ios::in);  //<----------- I M P O R T A N T E
	//Las siguientes  dos lineas son necesarias para comenzar la lectura del archivo desde el primer registro
	file.clear();    //<----------- I M P O R T A N T E
	file.seekg( 0 ); //<----------- I M P O R T A N T E
	if ( !file )  // verifica que el archivo se abrio con exito
    	cout << " No se pudo leer el archivo " << endl;
	else{
    	cout<<endl<<endl<<"Imprimiendo la informacion desde el archivo";
    	
    	//<----------- I M P O R T A N T E  aqui recorre el archivo para recuperar la informacion
		while( file >> cuenta >> nombre >> monto  ) /* obtiene un registro del archivo,
                                                    el ciclo da vueltas mientras no se acabe el archivo*/
    	{
      		cout<<endl;
      		cout << "\ncuenta  :" << cuenta;
      		cout << "\nNombre  :" << nombre;
      		cout << "\nMonto   :" << monto;

    	}//fin while
  		
		file.close(); //<----------- I M P O R T A N T E
	}//fin else
     
	cout<<endl;
	system("pause");
	return 0;
}//fin del main()
 
