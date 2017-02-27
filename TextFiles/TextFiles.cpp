#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main (){
	
	// reading from a file  ------------------
	ifstream file("example.txt");
	string STRING;
	
	if(file.is_open()){
		getline(file,STRING);
		cout<<STRING;
		file.close();
	}else
		cout<<"File doesn't exist";
	//----------------------------------------
	
	
	//writing on a file-----------------------
	ofstream file2("another_file.txt");
	
		if(file2.is_open()){
			file2<<"writing on the file";
		}else
			cout<<"Unable to open file";
		file2.close();
	//----------------------------------------
	return 0;
}
