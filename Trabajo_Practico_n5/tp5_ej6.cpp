#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPEART 30
#define TOPESUC 4

struct tyRegMov{
	
	int codArt;
	int codSuc;
	char tipo;
	int q;
	
};

void mostrarMat(int m[][TOPESUC], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c] << " | ";
		}
		cout << endl;
	}
	
}

void cargarMat(int m[][TOPESUC], int tf, int tc, int valor){
	
	for(int i = 0; i < tf; i++){
		for(int j = 0; j < tc; j++){
			m[i][j] = valor;
		}
	}
	
}

void mostrarArch (char arch[]) {
	
	tyRegMov reg;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(reg);
	abrirArch(arch,"rb",fichero,pude);
	//cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArch(fichero, &reg,largo,finArch,pude);
		while(pude&&!finArch) {
			cout << "codigo Articulo: "<<reg.codArt << endl;
			cout << "codigo Sucursal: "<<reg.codSuc << endl;
			cout << "movimiento: "<<reg.tipo << endl;
			cout << "cantidad: "<<reg.q << endl;
			cout << "------------------" << endl;
			leerArch(fichero, &reg,sizeof(reg),finArch,pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
	
}

bool valido(tyRegMov registro){

	return (registro.codArt>=0 && registro.codArt <=29 && registro.codSuc>=0 && registro.codSuc<= 3 && registro.q > 0);
	
}

void fMovimiento(int m[][TOPESUC],tyRegMov registro, int iF,int iC){
	
	iF = registro.codArt;
	iC = registro.codSuc;
	
	if(registro.tipo == 'e'){
		m[iF][iC] +=  registro.q;
	}
	if(registro.tipo == 's'){
		m[iF][iC] -= registro.q;	
	}
	
}

void stockTotal(int m[][TOPESUC], int tf, int tc){

	int suma = 0;
	
	for(int i = 0; i < tf; i++){
		for(int j = 0; j < tc; j++){
			suma += m[i][j];
		}
		if(suma <= 0){
		cout << "el articulo: " << i << " -> tiene stock: " << suma << endl;
		}
		suma = 0;
	}
	
}

int main(){

	int mat[TOPEART][TOPESUC];
	int stockInicial = 20;
	tyRegMov rm;
	char archivo[] = "movimientosEJ6.dat";
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(rm);
	int iF, iC;
	
	cargarMat(mat, TOPEART, TOPESUC, stockInicial);
	mostrarMat(mat, TOPEART, TOPESUC);
	abrirArch(archivo, "rb", fichero, pude);	
	leerArch(fichero, &rm, largo, finArch, pude);
	while(pude && !finArch){
		if(valido(rm)){
			fMovimiento(mat,rm, iF, iC);
		}
		else{
			cout << "no es valido " << endl;
			cout << "codigo Articulo: "<<rm.codArt << endl;
			cout << "codigo Sucursal: "<<rm.codSuc << endl;
			cout << "movimiento: "<<rm.tipo << endl;
			cout << "cantidad: "<<rm.q << endl;
			cout << "------------------" << endl;
		}
		leerArch(fichero, &rm, largo, finArch, pude);
	}
	cerrarArch(fichero);
	mostrarArch(archivo);
	mostrarMat(mat, TOPEART, TOPESUC);
	stockTotal(mat, TOPEART, TOPESUC);

}

