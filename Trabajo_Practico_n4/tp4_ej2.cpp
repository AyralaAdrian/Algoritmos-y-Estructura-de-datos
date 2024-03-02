#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPETEL 21

struct tyTel{
	
	char descTel[TOPETEL];
	int precio;
	
};

void ingresoTel(tyTel &tel){
	
	cout << "ingrese el telefono: " << endl;
	fflush(stdin);
	cin.getline(tel.descTel, TOPETEL);
	if(strcmp(tel.descTel, "fin") != 0){
		cout << "ingrese el percio: " << endl;
		cin >> tel.precio;
	}
	
}

void mostrarArch (char arch[]) {
	
	tyTel tel;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(tel);
	abrirArch(arch, "rb", fichero, pude);
	//cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArch(fichero, &tel, largo, finArch, pude);
		while(pude&&!finArch) {
			cout << "Nombre: "<<tel.descTel << endl;
			cout << "precio: " << tel.precio << endl;
			cout << "------------------" << endl;
			leerArch(fichero, &tel, largo, finArch, pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
	
}

int main(){
		
	tyTel telefono;
	char archivoTel[] = "telefonos.dat";
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(telefono);
	
	abrirArch(archivoTel, "ab", fichero, pude);
	ingresoTel(telefono);
	while(pude && strcmp(telefono.descTel, "fin") != 0){
		escribirArch(&telefono, largo, fichero);
		ingresoTel(telefono);
	}
	cerrarArch(fichero);
	mostrarArch(archivoTel);

}

