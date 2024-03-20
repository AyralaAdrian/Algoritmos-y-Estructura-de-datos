#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPECAD 41

void copiarCadena(char cad1[], char cad2[]){
	
	for(int i = 0; i <= strlen(cad2); i++){
		cad1[i] = cad2[i];
	}
	
}

void mostrarCadena(char cad1[], char cad2[]){
	
	cout << " el contenido de cad2 es: " << cad2 << endl;
	cout << " la longitud de la cadena es: " << strlen(cad2) << endl;
	cout << " el contenido de cad1 es: " << cad1 << endl;
	cout << " la longitud de la cadena es: " << strlen(cad1) << endl;
	 
}

void ingresandoEnCad2(char cad[]){

	cout << endl;
	cout << "el contenido original de la cad2 es : " << cad << endl;
	cout << " la longitud de la cadena es: " << strlen(cad) << endl;
	cout << "ingrese un nuevo contenido para cad2: "<< endl;
	cin.getline(cad, TOPECAD);
	cout << "el nuevo contenido de cad2 es: " << cad << endl;
	cout << " la longitud de la cadena es: " << strlen(cad) << endl;
	cout << endl;
	 
}

int main(){

	char cad1[TOPECAD];
	char cad2[TOPECAD] = "univesidad nacional de avellaneda";
	
	copiarCadena(cad1, cad2);
	mostrarCadena(cad1, cad2);
	ingresandoEnCad2(cad2);
	cout << " muchas gracias  ";
	
}


