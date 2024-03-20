#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEPROM 6
#define TOPETEL 4
#define TOPEDIAS 31 
	
struct tyVecProm{
	string nombreProm;
	float comision;
}; 

struct tyVecTel{
	string descTel;
	float precio;
};

struct tyVenta{
	string nProm;
	string descTel;
	int qVendida;
	int diaVenta;
};

int buscar(tyVecProm vector[], int tope, string &valor){

	int i = 0;
	
	while(i < tope && vector[i].nombreProm != valor){
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


int buscarTel(tyVecTel vector[], int tope, string &valor){

	int i = 0;
	
	while(i < tope && vector[i].descTel != valor){
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

void mostrarProm(tyVecProm vector[]){
	
	cout << "estos son nuestros promotores: " << endl;
	for(int i = 0; i < TOPEPROM; i++){
		cout << "nombre: " << vector[i].nombreProm << endl;
	}
	
}

void mostrarTel(tyVecTel vector[]){
	
	cout << "estos son nuestros telefonos: " << endl;
	for(int i = 0; i < TOPETEL; i++){
		cout << "telefono : " << vector[i].descTel << endl;
		cout << "precio : " << vector[i].precio << endl;
	} 
	
}

ingreso(tyVecProm promotores[], tyVecTel tel[], tyVenta &venta, int &iProm, int &iTel ){
	
	fflush(stdin);	
	mostrarProm(promotores);
	cout << "ingrese el nombre del promotor ('fin' para salir): " << endl;
	fflush(stdin);
	getline(cin, venta.nProm);
	if(venta.nProm != "fin"){
		iProm = buscar(promotores, TOPEPROM, venta.nProm);	
		while(venta.nProm != "fin" && iProm == -1){
			cout << "nombre incorecto: " << endl;
			cout << "ingrese el nombre del promotor ('fin' para salir): " << endl;
			fflush(stdin);
			getline(cin, venta.nProm);
			iProm = buscar(promotores, TOPEPROM, venta.nProm);
		}
	}  
	if(venta.nProm != "fin"){
		mostrarTel(tel);
		cout << "ingrese el telefono que desea: " << endl;
		getline(cin, venta.descTel);
		iTel = buscarTel(tel, TOPETEL, venta.descTel);
		while(iTel == -1){
			cout << "telefono incorrecto: " << endl;
			cout << "ingrese el telefono que desea: " << endl;
			getline(cin, venta.descTel);
			iTel = buscarTel(tel, TOPETEL, venta.descTel);
		} 
		fflush(stdin);
		cout << "ingrese la cantidad: " << endl;
		fflush(stdin);
		cin >> venta.qVendida;
		while(venta.qVendida  < 0){
			cout << "numero incorrecto: " << endl;
			cout << "ingrese la cantidad: " << endl;
			cin >> venta.qVendida;
		}
		cout << "dia del mes que se vendio: " << endl;
		cin >> venta.diaVenta;
		while(venta.diaVenta < 0 || venta.diaVenta > 31){
			cout << "dia incorrecto " << endl;
			cout << "dia del mes que se vendio: " << endl;
			cin >> venta.diaVenta;
		}
	}
	
}

void factura(tyVenta &venta, tyVecProm vectorProm[], int &iP, tyVecTel vectorTel[], int &iT, float &impVta, float &impComi){
	
	impVta = venta.qVendida * vectorTel[iT].precio;
	impComi = impVta * vectorProm[iP].comision / 100;
	cout << "importe de factura : " << impVta << endl;
	cout << "importe de comision : "<< impComi << " de promotor/a : " << vectorProm[iP].nombreProm << endl;
	
}

void iniVec(int vector[], int tope){
	
	for(int i = 0; i < tope; i++){
		vector[i] = 0;
	}
	
}

void vtasPorDia(int vector[], int &dia){
	
	vector[dia-1]++;
	
}

void qFcPorDia(int vector[], int &dia) {
	
	cout << "----------------------------" << endl;
	cout << " cantidad de facturas por dia: "  << endl;
	cout << "----------------------------" << endl;
	for(int i = 0; i < TOPEDIAS; i++){
		cout << "dia: " << i + 1 << " - cantidad de ventas: " << vector[i] << endl;
	}
	
}

void iniVecComi(float vector[], int tope){
	
	for(int i = 0; i < tope; i++){
		vector[i] = 0;
	}
	
}

void comisiones(float vector[], int &iP, float &comi){
	
	vector[iP] += comi;
	
}

void totalComisiones(tyVecProm vector[], float comiVec[] ){
	
	cout << "----------------------------" << endl;
	cout <<  "Total de comisiones: " << endl;
	cout << "----------------------------" << endl;
	for(int i = 0; i < TOPEPROM; i++){
		cout << vector[i].nombreProm << " comision total : " << comiVec[i] << endl;
	}
	
}

void iniVecAcumTel(int vector[], int tope){
	
	for(int i = 0; i < tope; i++){
		vector[i] = 0;
	}
	
}

void telVendidos(int vector[], int  &iT, int &q){
	
	vector[iT] += q;
	
}

void masVendido(string &telMax, int &qMasVendida, int v[], tyVecTel vtel[]){
	
	fflush(stdin);	
	for(int i = 0; i < TOPETEL; i++){
		if(v[i] > qMasVendida){
			qMasVendida = v[i];
			telMax = vtel[i].descTel;
		}
	}
	if( qMasVendida > 0){
		cout << "el telefono mas vendido es: " << telMax << " con: " << qMasVendida<< " ventas " << endl;	
	}
	else{
		cout << "no hubo ventas" << endl;
	}
	
}


int main(){
	
	tyVecProm vecProm[TOPEPROM] = {"Cacho", 3.50, "Susy", 3.75, "Milena", 2.90, "Juan", 4.10, "Javier", 2.90, "Lucia", 3.50};
	tyVecTel vecTel[TOPETEL] = {"Samsung1", 22000, "Moto1", 18500, "Huawei", 232002, "LG1", 9500};
	int sumaVtasDiarias[TOPEDIAS];
	iniVec(sumaVtasDiarias, TOPEDIAS);
	float vecComisiones[TOPEPROM];
	iniVecComi(vecComisiones, TOPEPROM);
	tyVenta venta;
	int iProm, iTel;
	float impVta, impComi;
	int vecQ[TOPETEL];
	iniVecAcumTel(vecQ,TOPETEL);
	string telMasVendido;
	int qMasVendida = 0;
	
	cout << " Bienvenidos " << endl;
	ingreso(vecProm, vecTel, venta,iProm, iTel);
	while(venta.nProm != "fin"){
		factura(venta,vecProm, iProm, vecTel, iTel, impVta, impComi);
		vtasPorDia(sumaVtasDiarias, venta.diaVenta);
		comisiones(vecComisiones, iProm,  impComi);
		telVendidos(vecQ, iTel, venta.qVendida);
		ingreso(vecProm, vecTel, venta,iProm, iTel);
	}
	qFcPorDia(sumaVtasDiarias, venta.diaVenta);
	totalComisiones(vecProm,vecComisiones);
	masVendido(telMasVendido, qMasVendida, vecQ, vecTel);
	cout << "muchas gracias" ; 
	
}

