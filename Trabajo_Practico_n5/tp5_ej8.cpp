#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPECODPRODVEND 6
#define TOPECODPROD 6
#define TOPEDESCPROD 31
#define PRODUCTOS 50
#define NOMBRETIPO 31
#define TIPOSPRODUCTOS 12
#define GRUPOS 10


struct tyVenta{
	
	char codigoProdVendido[TOPECODPRODVEND];
	char descuento;
	int edadComprador;
	
};

struct tyProd{
	
	char codigoProd[TOPECODPROD];
	char descProd[TOPEDESCPROD];
	float precio;
    int tipoProducto;	
	
};

struct tyTipo{
	
	char nombreTipo[NOMBRETIPO];
	float descuento;
	
};

struct tyGrupo {
	
	int	edadDesde; 
	int edadHasta; 

};

struct tyAcumuladores{
	
	int q;
	float importes;
	
};

void cargarProductos(char arch[],tyProd v[], int tope){
	
	tyProd producto;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(producto);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &producto, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			v[i] = producto;
			i++;
			leerArch(fichero, &producto, largo, finArch, pude);
		} 
		cerrarArch(fichero);	
	}
	
}
	
void mostrarProductos(tyProd v[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "Producto: " << v[i].codigoProd << endl;
		cout << "Descripcion de producto: " << v[i].descProd << endl;
		cout << "precio: " << v[i].precio << endl;
		cout << "codigo tipo producto: " << v[i].tipoProducto << endl;
	}
	
}

void cargarTipos(char arch[], tyTipo v[], int tope){
	
	tyTipo tipo;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(tipo);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &tipo, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			v[i] = tipo;
			i++;
			leerArch(fichero, &tipo, largo, finArch, pude);
		} 
		cerrarArch(fichero);	
	}
	
}

void mostrarTipo(tyTipo v[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "nombre tipo: " << v[i].nombreTipo << endl;
		cout << "Descuento: " << v[i].descuento << endl;
	}
	
}

void cargarGrupos(char arch[], tyGrupo v[], int tope){
	
	tyGrupo grupo;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(grupo);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &grupo, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			v[i] = grupo;
			i++;
			leerArch(fichero, &grupo, largo, finArch, pude);
		} 
		cerrarArch(fichero);	
	}
	
}

void mostrarGrupos(tyGrupo v[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "edad desde : " << v[i].edadDesde << endl;
		cout << "edad hasta : " << v[i].edadHasta << endl;
	}
	
}
//iniciar matrices 
void iniMat(tyAcumuladores m[][GRUPOS], int tf, int tc){
	
	for(int i = 0; i < tf; i++){
		for(int j = 0; j < tc; j++){
			m[i][j].q = 0;
			m[i][j].importes = 0;
		}
	}
	
}

void mostrarMat(tyAcumuladores m[][GRUPOS], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c].q << " | ";
			cout << m[f][c].importes << " | ";
		}
		cout << endl;
	}
	
}

void iniVec(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		v[i] = 0;
	}
	
}
// busqueda por char
int buscarProd(tyProd vP[], int tope, char codigo[]){

	int i = 0;
	
	while(i < tope && strcmp(vP[i].codigoProd, codigo) != 0){
		i++;
	}
	if (i == tope){
		i = -1;
	}
	
	return i;
				
}

bool valido(tyProd vProd[], int tope, tyVenta venta, int &iP){
	
	iP = buscarProd(vProd, tope, venta.codigoProdVendido);
	
	return (iP != -1 && (venta.edadComprador >= 6 && venta.edadComprador <= 100) && (venta.descuento == 'S' || venta.descuento =='N'));
	
}
//buscando entre rangos de numeros-----desde - hasta
int buscarGrupo(tyGrupo vG[], int tope, int edad){

	int i = 0;
	
	while(i < tope && edad < vG[i].edadDesde || edad > vG[i].edadHasta){
		i++;
	}
	if (i == tope){
		i = -1;
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
			cout << "codigoProdVendido : "<<venta.codigoProdVendido<< endl;
			cout << "descuento : "<<venta.descuento<< endl;
			cout << "edad  : "<<venta.edadComprador<< endl;
			cout << "------------------" << endl;
			leerArch(fichero, &venta,sizeof(venta),finArch,pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
	
}

float calcularPrecio(char descuento,tyProd vP[], tyTipo vT[], int iP, int iT){
	
	float precio;
	
	if(descuento == 'S'){
		precio = vP[iP].precio - (vP[iP].precio * vT[iT].descuento);
	}
	else{
		precio = vP[iP].precio;
	}
	
	return precio;
	
}

void contarVentas(int &qVentas){
	
	qVentas++;
	
}

void cargarVenta(tyAcumuladores mat[][GRUPOS], int iT, int iG, float precio){
	
	mat[iT][iG].q++;
	mat[iT][iG].importes += precio;
	
}

void acumularVentasPorTipo( int v[], int iT){
	
	v[iT]++;
	
}

void acumularVentasConDescuento(int  v[], int iG){
	
	v[iG]++;
	
}

void procesarVenta(char archVta[], char archErr[], tyProd vProd[], int topeP, tyTipo vTipo[], int topeT, tyGrupo vGrupo[], int topeG,tyAcumuladores mat[][GRUPOS], int &qVta, int acumVentasPorTipo[], int acumVentasConDescuento[]){
	
	tyVenta venta;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	bool pudeErr=false, finArchErr=false;
	FILE *ficheroErr=NULL;	
	int largo = sizeof(venta);
	int iProd, iTipo, iGrupo;
	float precio; 
	
	abrirArch(archVta, "rb", fichero, pude);
	abrirArch(archErr, "wb", ficheroErr, pudeErr);
	if(pude && pudeErr){
		leerArch(fichero, &venta, largo, finArch, pude);
		while(pude && !finArch){
			if(valido(vProd, topeP, venta, iProd)){
				iGrupo = buscarGrupo(vGrupo, topeG, venta.edadComprador);
				iTipo = vProd[iProd].tipoProducto - 1;
				precio = calcularPrecio(venta.descuento, vProd, vTipo, iProd, iTipo);
				cout << "precio " <<  precio << endl;
				contarVentas(qVta);
				cargarVenta(mat, iTipo, iGrupo, precio);
				acumularVentasPorTipo(acumVentasPorTipo, iTipo);
				if(venta.descuento == 'S'){
					acumularVentasConDescuento(acumVentasConDescuento, iGrupo);
				}
			}
			else{
				escribirArch(&venta, largo, ficheroErr);
			}
			leerArch(fichero, &venta, largo, finArch, pude);
		}
		cerrarArch(fichero);
		cerrarArch(ficheroErr);
	}
	mostrarArch(archErr);

}

void mostrarPorCadaTipoDeProducto(tyAcumuladores m[][GRUPOS], tyTipo vT[], tyGrupo vG[], int topef, int topec){
	
	for(int i = 0; i < topef; i++){
		cout << "nombre del tipo del producto:" << vT[i].nombreTipo << endl;
		for(int j = 0; j < topec; j++){
			cout << "recaudacion por grupo desde: " << vG[j].edadDesde << " hasta :" << vG[j].edadHasta << "  es de: " << m[i][j].importes << endl;
		}
	}
	
}

void mostrarPorCadaGrupoDeEdad(tyAcumuladores m[][GRUPOS], tyTipo vT[], tyGrupo vG[], int topef, int topec){
	
	cout << "****************************************************************" << endl;
	for(int i = 0; i < topec; i++){
		cout << "por grupo desde " << vG[i].edadDesde << " hasta " << vG[i].edadHasta << endl;
		for(int j = 0; j < topef; j++){
			cout << "El nombre del tipo del Producto: " << vT[j].nombreTipo << "  tiene una cantidad de : " << m[i][j].q << " compras " << endl;
		}
	}
	
}
// buscar el maximo
void mayorQProdConDescuento(int acum[], tyGrupo vecG[] , int tope){
	
	int posMax = 0;
	int valorMaximo = 0;
	
	for(int i = 0; i < tope; i++){
		if(acum[i] > valorMaximo){
			posMax = i;
			valorMaximo = acum[posMax];
		}
	}
	cout << "************************************************************************************* " << endl;
	cout <<"el grupo : "<< posMax <<   " [" << vecG[posMax].edadDesde << "-" << vecG[posMax].edadHasta << "] vendio " << valorMaximo << " productos con descuento" << endl;
	
}
// mostrar y calcular porcentaje
void mostrarPorcentajesDeVentasPorTipo(tyTipo vT[], int acumVentasPorTipo[], int tope, int totalVentas) {
    
	cout << "************************************************************************************* " << endl;	
	cout <<"Por cada Tipo de Producto: Nombre del Tipo y Porcentaje de productos vendidos: " << endl;
    float porcentaje;
    for (int i = 0; i < tope; i++) {
        porcentaje = acumVentasPorTipo[i] * 100 / (float)totalVentas; // Hago esto para mostrar decimales
        cout << "El tipo '" << vT[i].nombreTipo << "' represento el " <<  porcentaje << " % de las ventas" <<endl;
    }
    
}

int main(){

	tyVenta venta;
	tyProd producto;
	tyTipo tipo;
	tyGrupo grupo;
	tyProd vecProd[PRODUCTOS];
	tyTipo vecTipo[TIPOSPRODUCTOS];
	tyGrupo vecGrupo[GRUPOS];
	char archivoMovEj8[] = "movimientosEJ8.dat";
	char archivoErrores[] = "errores.dat";
	char archivoProd[] = "productos.dat";
	char archivoTipos[] = "tipos.dat";
	char archivoGrupos[] = "grupos.dat";
	tyAcumuladores matTiposGurpos[TIPOSPRODUCTOS][GRUPOS];
	int acumGrupoConDescuento[GRUPOS];
    int acumVentasPorTipo[TIPOSPRODUCTOS];
	int qVentas = 0;
	int qProductos = 0;

	iniMat(matTiposGurpos, TIPOSPRODUCTOS, GRUPOS);
	mostrarMat(matTiposGurpos, TIPOSPRODUCTOS, GRUPOS);
	iniVec(acumGrupoConDescuento, GRUPOS);
	iniVec(acumVentasPorTipo, TIPOSPRODUCTOS);
	cargarProductos(archivoProd, vecProd, PRODUCTOS);
	mostrarProductos(vecProd, PRODUCTOS);
	cout << "***********************************" << endl;
	cargarTipos(archivoTipos, vecTipo, TIPOSPRODUCTOS);
	mostrarTipo(vecTipo, TIPOSPRODUCTOS);
	cout << "***********************************" << endl;
	cargarGrupos(archivoGrupos, vecGrupo, GRUPOS);
	mostrarGrupos(vecGrupo, GRUPOS);
	//aca deberia ir el CICLO WHILE
	procesarVenta(archivoMovEj8, archivoErrores, vecProd, PRODUCTOS, vecTipo, TIPOSPRODUCTOS, vecGrupo, GRUPOS, matTiposGurpos, qVentas, acumVentasPorTipo,acumGrupoConDescuento);
	mostrarMat(matTiposGurpos, TIPOSPRODUCTOS, GRUPOS);
	mostrarPorCadaTipoDeProducto(matTiposGurpos, vecTipo, vecGrupo, TIPOSPRODUCTOS, GRUPOS);
	mostrarPorCadaGrupoDeEdad(matTiposGurpos, vecTipo, vecGrupo, TIPOSPRODUCTOS, GRUPOS);
	mayorQProdConDescuento(acumGrupoConDescuento, vecGrupo , GRUPOS);
	mostrarPorcentajesDeVentasPorTipo(vecTipo, acumVentasPorTipo, TIPOSPRODUCTOS, qVentas);
	
}

