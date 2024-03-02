#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPEPROM 31
#define QPROMOTORES 10
#define TOPETEL 21
#define QTELEFONOS 10
#define QDIAS 31

struct tyVenta{
	
	char nPromotor[TOPEPROM];
	char descTelefono[TOPETEL];
	int qVendida;
	int dia;
	
};

struct tyProm{
	
	char nombre[TOPEPROM];
	float comision;
	
};

struct tyTel{
	
	char descTel[TOPETEL];
	int precio;
	
};

void cargarPromotores(tyProm vProm[], int tope, char arch[]){
	
	tyProm promotor;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(promotor);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &promotor, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			vProm[i] = promotor;
			i++;
			leerArch(fichero, &promotor, largo, finArch, pude);
		} 
		cerrarArch(fichero);	
	}
		
}

void mostrarPromotores(tyProm vProm[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "Promotor: " << vProm[i].nombre << endl;
		cout << "Comision: " << vProm[i].comision << endl;
	}
	
}

void cargarTelefonos(tyTel vTel[], int tope, char arch[]){
	
	tyTel telefono;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(telefono);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &telefono, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			vTel[i] = telefono;
			i++;
			leerArch(fichero, &telefono, largo, finArch, pude);
		}
		cerrarArch(fichero);
	}
	
}

void mostrarTelefonos(tyTel vTel[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "Telefono: " << vTel[i].descTel << endl;
		cout << "precio: " << vTel[i].precio << endl; 
	}
	
}

int buscarProm(tyProm vProm[], int tope, char prom[TOPEPROM]){
	
	int i = 0;
	
	while(i < tope && strcmp(vProm[i].nombre, prom) != 0){
		i++;
	}
	if (i == tope){
		i = -1;
	}
	else {
		i;		
	}
	
	return i;
				
}

int buscarTel(tyTel vTel[], int tope, char tel[TOPETEL]){
	int i = 0;
	
	while(i < tope && strcmp(vTel[i].descTel, tel) != 0){
		i++;
	}
	if (i == tope){
		i = -1;
	}
	else {
		i;		
	}
	
	return i;
				
}



void mostrarVenta(tyVenta &venta){
	
	cout << "Nombre del promotor     : " << venta.nPromotor << endl;
    cout << "Descripcion del telefono: " << venta.descTelefono << endl;
    cout << "Cantidad Vendida        : " << venta.qVendida << endl;
    cout << "Dia del mes             : " << venta.dia << endl << endl;
    cout << endl;
	
}

void factura(tyVenta &venta, tyProm v[], int &iP, tyTel vt[], int &iT, float &impVta, float &impComi){
	
	impVta = venta.qVendida * vt[iT].precio;
	impComi = impVta * v[iP].comision / 100;
	cout << "importe de factura : " << impVta << endl;
	cout << "importe de comision : "<< impComi << " de promotor/a : " << v[iP].nombre << endl;
	cout << endl;
	
}

void iniVec(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		v[i] = 0;
	}
	
}

void vtasPorDia(int v[], int &dia){
	
	v[dia-1]++;
	
}

void qFcPorDia(int v[], int &dia) {
	
	cout << "----------------------------" << endl;
	cout << " cantidad de facturas por dia: "  << endl;
	cout << "----------------------------" << endl;
	for(int i = 0; i < QDIAS; i++){
		cout << "dia: " << i + 1 << " - cantidad de ventas: " << v[i] << endl;
	}
	
}

int main(){

	tyVenta venta;
	tyProm promotor;
	tyTel telefono;
	tyProm vecProm[QPROMOTORES];
	tyTel vecTel[QTELEFONOS];
	char archivo[] = "promotores.dat";
	char archivoTel[] = "telefonos.dat";
	char archValida[] = "ventasValidas.dat";
	int sumaVtasDiarias[QDIAS];
	iniVec(sumaVtasDiarias, QDIAS);
	int iTel, iProm;
	float impVta, impComi;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(venta);
	
	cargarPromotores(vecProm, QPROMOTORES, archivo);
	mostrarPromotores(vecProm, QPROMOTORES);
	cout << " **************************** " << endl;
	cargarTelefonos(vecTel, QTELEFONOS, archivoTel);
	mostrarTelefonos(vecTel, QTELEFONOS);
	abrirArch(archValida,"rb", fichero, pude);
	while(pude && !finArch){
		leerArch(fichero,&venta, largo, finArch, pude);
		iProm = buscarProm(vecProm, QPROMOTORES, venta.nPromotor);
		iTel = buscarTel(vecTel, QTELEFONOS, venta.descTelefono);
		mostrarVenta(venta);
		factura(venta, vecProm, iProm, vecTel, iTel, impVta, impComi);
		vtasPorDia(sumaVtasDiarias, venta.dia);		
		leerArch(fichero,&venta, largo, finArch, pude);
	}
	cerrarArch(fichero);
	qFcPorDia(sumaVtasDiarias, venta.dia);
	
}

