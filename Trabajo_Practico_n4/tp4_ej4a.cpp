#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPEPROM 31
#define TOPETEL 21
#define QDIAS 31

struct tyVenta{
	
	char nPromotor[TOPEPROM];
	char descTelefono[TOPETEL];
	int qVendida;
	int dia;
	
};

void ingreseVenta(tyVenta &venta){
	
	fflush(stdin);
	cout << "ingrese el nombre del promotor:(fin para sair) " << endl;
	cin.getline(venta.nPromotor, TOPEPROM);
	if(strcmp(venta.nPromotor, "fin")){
			cout << "ingrese el telefono que desea: " << endl;
			cin.getline(venta.descTelefono, TOPETEL);
			fflush(stdin);
			cout << "ingrese la cantidad: " << endl;
			fflush(stdin);
			cin >> venta.qVendida;
			cout << "dia del mes que se vendio: " << endl;
			cin >> venta.dia;
	}
		
}

void mostrarArch (char arch[]) {
	tyVenta venta;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(venta);
	abrirArch(arch,"rb",fichero,pude);
	//cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArch(fichero, &venta,largo,finArch,pude);
		while(pude&&!finArch) {
			cout << "------------------" << endl;
			cout << "Nombre: "<<venta.nPromotor << endl;
			cout << "descripcion telefono: "<<venta.descTelefono << endl;
			cout << "cantidad vendida: "<<venta.qVendida << endl;
			cout << "dia: "<<venta.dia << endl;
			cout << "------------------" << endl;
			leerArch(fichero, &venta, largo, finArch, pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
}

int main(){
	
	tyVenta venta;
	char archVta[] = "ingresoVentas.dat";
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(venta);
	
	abrirArch(archVta, "rb", fichero, pude);
	ingreseVenta(venta);
	while( pude && strcmp(venta.nPromotor, "fin") != 0){
		escribirArch(&venta, largo, fichero);
		ingreseVenta(venta);
	}	
	cerrarArch(fichero);
	mostrarArch(archVta);

}

