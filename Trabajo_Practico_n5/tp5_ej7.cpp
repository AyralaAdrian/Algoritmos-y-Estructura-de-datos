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

//busqueda por char
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

void ingreseVenta(tyVenta &venta, tyProm vProm[], int topeProm, tyTel vTel[], int topeTel, int &iT, int &iP ){
	
	fflush(stdin);
	cout << "ingrese el nombre del promotor:(fin para sair) " << endl;
	cin.getline(venta.nPromotor, TOPEPROM);
	if(strcmp(venta.nPromotor, "fin") != 0){
		iP = buscarProm(vProm, topeProm, venta.nPromotor);
		while(iP == -1){
			cout << "nombre incorecto: " << endl;
			cout << "ingrese el nombre del promotor ('fin' para salir): " << endl;
			fflush(stdin);
			cin.getline(venta.nPromotor, TOPEPROM);
			if(strcmp(venta.nPromotor, "fin") != 0){
				iP = buscarProm(vProm, topeProm, venta.nPromotor);	
			}
		}
		if(strcmp(venta.nPromotor, "fin") != 0){
			cout << "ingrese el telefono que desea: " << endl;
			cin.getline(venta.descTelefono, TOPETEL);
			iT = buscarTel(vTel, topeTel, venta.descTelefono );
			while( iT == -1){
				cout << "telefono incorrecto: " << endl;
				cout << "ingrese el telefono que desea: " << endl;
				cin.getline(venta.descTelefono, TOPETEL);
				iT = buscarTel(vTel, topeTel, venta.descTelefono);
			} 
			fflush(stdin);
			cout << "ingrese la cantidad: " << endl;
			fflush(stdin);
			cin >> venta.qVendida;
			while(venta.qVendida  <= 0){
				cout << "numero incorrecto: " << endl;
				cout << "ingrese la cantidad: " << endl;
				cin >> venta.qVendida;
			}
			cout << "dia del mes que se vendio: " << endl;
			cin >> venta.dia;
			while(venta.dia < 0 || venta.dia >= 31){
				cout << "dia incorrecto " << endl;
				cout << "dia del mes que se vendio: " << endl;
				cin >> venta.dia;
			}
		}
	}
	
}

void mostrarVenta(tyVenta &venta){
	
	cout << "Nombre del promotor     : " << venta.nPromotor << endl;
    cout << "Descripcion del telefono: " << venta.descTelefono << endl;
    cout << "Cantidad Vendida        : " << venta.qVendida << endl;
    cout << "Dia del mes             : " << venta.dia << endl << endl;
    cout << endl;
	
}

void factura(tyVenta venta, tyProm v[], int iP, tyTel vt[], int iT, float &impVta, float &impComi){
	
	impVta = venta.qVendida * vt[iT].precio;
	impComi = impVta * v[iP].comision / 100;
	cout << "importe de factura : " << impVta << endl;
	cout << "importe de comision : "<< impComi << " de promotor/a : " << v[iP].nombre << endl;
	
}

void iniVec(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		v[i] = 0;
	}
	
}

void vtasPorDia(int v[], int dia){
	
	v[dia-1]++;
	
}

void qFcPorDia(int v[], int dia) {
	
	cout << "----------------------------" << endl;
	cout << " cantidad de facturas por dia: "  << endl;
	cout << "----------------------------" << endl;
	for(int i = 0; i < QDIAS; i++){
		cout << "dia: " << i + 1 << " - cantidad de ventas: " << v[i] << endl;
	}
	
}

void mostrarMat(int m[][QTELEFONOS], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c] << " | ";
		}
		cout << endl;
	}
	
}

void cargarMat(int m[][QTELEFONOS], int tf, int tc, int valor){
	
	for(int i = 0; i < tf; i++){
		for(int j = 0; j < tc; j++){
			m[i][j] = valor;
		}
	}
	
}
// poner los indices y acumular en esa posicion
void telefonosVendidosPorCadaPromotor(int m[][QTELEFONOS],int iP, int iT, int q){
	
	m[iP][iT] += q;
		
}
	
//b) Descripción del teléfono más vendido por cada promotor.
void telefonoMasVendidoPodCadaPromotor(int m[][QTELEFONOS], tyProm v[], tyTel vtel[], int tProm, int tTel){
//recorrida por filas	
	int pos = 0;
	int qMasVendido = 0;
	
	for(int i = 0; i <tProm; i++){
		cout << "promotor :" << v[i].nombre << endl;
		for(int j = 0; j <tTel; j++){
			if(m[i][j] > qMasVendido){
				qMasVendido = m[i][j];
				pos = j;	
			} 
		}
		if( qMasVendido > 0){
				cout << "el telefono mas vendido es: " << vtel[pos].descTel << " con: " << qMasVendido<< " ventas " << endl;	
			}
			else{
				cout << "no hubo ventas" << endl;
			}
		qMasVendido = 0;	
	}
	
}

//d) Para cada teléfono, el nombre de los promotores que no lo vendieronese mes.
void telefonosNoVendidos(int m[][QTELEFONOS], tyProm v[], tyTel vtel[], int tProm, int tTel){
//recorrida por columnas
	int pos = 0;
	int noVendido = 0;

	for(int c = 0; c < tTel; c++){
		cout << "----------------------------------------" << endl;
		cout << "telefono: " << vtel[c].descTel << endl;
		cout << " promotores que no vendio el telefono: " ;
		for(int f = 0; f < tProm; f++){
			if(m[f][c] == 0){
				noVendido = m[f][c];
				pos = f;
				cout << v[pos].nombre << " - "  ;  
			}
		}	
	}

}
//c) Descripción del teléfono más vendido entre todos los promotores.
void masVendidoEntreTodos(int m[][QTELEFONOS], tyProm v[], tyTel vtel[], int tProm, int tTel){
	
	int acum = 0;
	int max = 0;
	int posTel = 0;
	 
	cout << "------------------------------------------" << endl;
	for(int i = 0; i < tTel; i++){
		for(int j = 0; j< tProm; j++){
		acum += m[j][i];	
		}
		if(acum > max){
			max = acum;
			posTel = i;
		}		
		acum = 0;
	}
	if(max != 0){
		cout << "el telefono mas vendido entre todos los prom es: " << vtel[posTel].descTel << " con :" << max << endl;
		cout << "------------------------------------------" << endl;	
	}	
	else {
		cout << " no hubo ventas " << endl;
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
	int sumaVtasDiarias[QDIAS];
	iniVec(sumaVtasDiarias, QDIAS);
	int iTel, iProm;
	float impVta, impComi;
	int mat[QPROMOTORES][QTELEFONOS];
	
	cargarMat(mat,QPROMOTORES, QTELEFONOS, 0);
	mostrarMat(mat,QPROMOTORES, QTELEFONOS);	
	cargarPromotores(vecProm, QPROMOTORES, archivo);
	mostrarPromotores(vecProm, QPROMOTORES);
	cout << " **************************** " << endl;
	cargarTelefonos(vecTel, QTELEFONOS, archivoTel);
	mostrarTelefonos(vecTel, QTELEFONOS);
	ingreseVenta(venta, vecProm, QPROMOTORES, vecTel, QTELEFONOS, iTel, iProm);
	while(strcmp(venta.nPromotor, "fin") != 0){
		mostrarVenta(venta);
		factura(venta, vecProm, iProm, vecTel, iTel, impVta, impComi);
		telefonosVendidosPorCadaPromotor(mat,iProm, iTel, venta.qVendida);
		mostrarMat(mat,QPROMOTORES, QTELEFONOS);
		vtasPorDia(sumaVtasDiarias, venta.dia);		
		ingreseVenta(venta, vecProm, QPROMOTORES, vecTel, QTELEFONOS, iTel, iProm);
	}
	qFcPorDia(sumaVtasDiarias, venta.dia);
	telefonoMasVendidoPodCadaPromotor(mat,vecProm, vecTel, QPROMOTORES, QTELEFONOS);
	masVendidoEntreTodos(mat,vecProm, vecTel, QPROMOTORES, QTELEFONOS);
	telefonosNoVendidos(mat,vecProm, vecTel, QPROMOTORES, QTELEFONOS);
	
}


