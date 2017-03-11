#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main (){
	
	// reading from a file  -------------------
	ifstream file("example.txt");
	string STRING;
	
	if(file.is_open()){
		getline(file,STRING);
		cout<<STRING;
		file.close();
	}else
		cout<<"File doesn't exist";
	//-----------------------------------------
	
	
	//writing on a file------------------------
	ofstream file2("another_file.txt");
	
		if(file2.is_open()){
			file2<<"writing on the file again";
		}else
			cout<<"Unable to open file";
		file2.close();
	//-----------------------------------------
	
	//another way
	
	fstream file3;
	file3.open("example in class.txt",ios::out);
	if(file3.fail()){
		cout<<"falla al crear";
		system("pause");
		exit(0);
	}
	
	int n=10;
	int id[n]={1,2,5,6,5,8,7,4,5,8};
	string names[n]={"maria","jose","andres","ana","pedro","laura","marco","juan","daisy","chucho"};
	int i=0;
	for(i=0;i<n;i++){
		file3<<id[i]<<"	"<<names[i]<<endl;
	}
			
	file3.close();
	
	i=0;
	int otro[n];
	string anotherNAMES[n];
	file3.open("example in class.txt",ios::in);
	while(true)	{
		if(file3.eof())
			break;
		file3>>otro[i]>>anotherNAMES[n];//el delimitador con el flujo de la consola es el espacio en blanco por eso no se usa el strtok
		cout<<otro[i]<<"	"<<anotherNAMES[i]<<endl;
		i++;
			
	}
		
	return 0;
}


//realizar un programa abriendo tres archivos existentes
//cliente.txt. contiene el numero de cedula el nombre y telefono
//producto.txt contiene codigo entero, descripcion del producto y precio
//ventas.txt contiene cedula del cliente y codigo del producto
//considere que una persona adquiere o compra varios productos 
//utilice un elemento separador en todos los archivos
//muestre en pantalla un listado de todas las ventas realizadas se;alando 
