#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPEPROM 31

struct tyProm{
	
	char nombre[TOPEPROM];
	float comision;
	
};

void ingreso(tyProm &prom){
	
	cout << "ingrese nombre: " << endl;
	fflush(stdin);
	cin.getline(prom.nombre, TOPEPROM);
	//strcmp() => devuelve 0 si las cadenas son iguales, en caso de que la primera sea menor devuelve un negativo,
	if(strcmp(prom.nombre, "fin") != 0){
		cout << "ingrese comision: " << endl;
		cin >> prom.comision;
	}
	
}

void mostrarArch(char arch[]) {
	
	tyProm prom;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(prom);
	abrirArch(arch,"rb",fichero,pude);
	//cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArch(fichero, &prom,largo,finArch,pude);
		while(pude&&!finArch) {
			cout << "Nombre: "<<prom.nombre << endl;
			cout << "comision: " << prom.comision << endl;
			cout << "------------------" << endl;
			leerArch(fichero, &prom,largo,finArch,pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
	
}

int main(){

	tyProm prom;
	char archivo[] = "promotores.dat";
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(prom);
	
	abrirArch(archivo,"rb", fichero, pude);
	ingreso(prom);
	while(pude && strcmp(prom.nombre, "fin") != 0){
		escribirArch(&prom, largo, fichero);
		ingreso(prom);	
	}
	cerrarArch(fichero);
	mostrarArch(archivo);
	 
}

