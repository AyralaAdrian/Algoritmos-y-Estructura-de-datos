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
			cout << "Nombre del promotor     : " << venta.nPromotor<< endl;
    		cout << "Descripcion del telefono: " << venta.descTelefono << endl;
    		cout << "Cantidad Vendida        : " << venta.qVendida << endl;
    		cout << "Dia del mes             : " << venta.dia << endl << endl;
    		cout << endl;
			leerArch(fichero, &venta, largo , finArch, pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
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
	char archVta[] = "ingresoVentas.dat";
	char archValida[] = "ventasValidas.dat";
	char archErroneas[] = "ventasErroneas.dat";
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	bool pudeVal = false, finArchVal=false;
	FILE *ficheroV = NULL; 
	bool pudeErr = false, finArchErr=false;
	FILE *ficheroE=NULL;

	int largo = sizeof(venta);
	int iProm, iTel;
	
	cargarPromotores(vecProm, QPROMOTORES, archivo);
	//mostrarPromotores(vecProm, QPROMOTORES);
	cout << " **************************** " << endl;
	cargarTelefonos(vecTel, QTELEFONOS, archivoTel);
	//mostrarTelefonos(vecTel, QTELEFONOS);
	
	abrirArch(archVta, "rb", fichero, pude);
	abrirArch(archValida, "wb", ficheroV, pudeVal);
	abrirArch(archErroneas, "wb", ficheroE, pudeErr);
	if(pude && pudeVal && pudeErr){
		leerArch(fichero, &venta, largo, finArch, pude);
		while(pude && !finArch){
			iProm = buscarProm(vecProm, QPROMOTORES, venta.nPromotor);
			iTel = buscarTel(vecTel, QTELEFONOS, venta.descTelefono);
			if(iProm != -1 && iTel != -1 && venta.dia > 0 && venta.dia < 31 && venta.qVendida > 0){
				escribirArch(&venta, largo, ficheroV);
			}
			else{
				escribirArch(&venta, largo, ficheroE);
			}
			leerArch(fichero, &venta, largo, finArch, pude);
		}
		cerrarArch(fichero);
		cerrarArch(ficheroV);
		cerrarArch(ficheroE);	
		mostrarArch(archValida);
	}	
	
}

