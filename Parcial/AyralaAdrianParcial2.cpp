#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <c:\users\burro\desktop\algoritmos\archivosg.h>

using namespace std;

#define TOPEV 8
#define TOPENYM 26
#define TOPEDOMICILIO 21
#define TOPEPRENDAS 15
#define TOPEM 5
#define TOPETALLES 21

struct ty_prenda{
	
	string codigo;
	float precio;
	int modelo;
	
};

struct ty_Modelo{
	
	string descripcion;
	float descuento;	/// Porcentaje a aplicar en concepto de descuento para el modelo

};

struct tyVenta{
	
	string codDePrenda;
	int codigoVendedor;
	int talle;
	int qComprada;
	
};

struct tyVendedores{
	
	char nombreApellido[TOPENYM];
	char dimicilio[TOPEDOMICILIO];
	float porcentajeComision;
	
};

struct tyAcumuladores{
	
	float importes;
	int unidadesVendidas;
	
};

/// cargar el archivo

void cargarVendedores(char arch[], tyVendedores v[], int tope){
	
	tyVendedores vendedor;
	int i = 0;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(vendedor);
	
	abrirArch(arch, "rb", fichero, pude);
	if(pude){
		leerArch(fichero, &vendedor, largo, finArch, pude);
		while(pude && !finArch && i < tope){
			cout << vendedor.nombreApellido  <<endl;
			v[i] = vendedor;
			i++;
			leerArch(fichero, &vendedor, largo, finArch, pude);
		} 
		cerrarArch(fichero);	
	}
	else{
		system("PAUSE");
	}
	
}

/// mostrar el vector con los archivos cargados con su strcut
 
void mostrarVendedor(tyVendedores v[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << "----------------" << endl;
		cout << "nombre y apellido: " << v[i].nombreApellido << endl;
		cout << "dimicilio: " << v[i].dimicilio << endl;
		cout << "porcentaje de Comision: " << v[i].porcentajeComision << endl;
	}
	
}

/// busqueda por string

int buscarPrenda(ty_prenda vP[], int tope, string valor){
	
	int i = 0;
	
	while(i < tope && vP[i].codigo != valor){
		i++;
	}
	if (i == tope){
		i = -1;
	}

	return i;
	
}

/// este es el ingreso y validacion de los datos

void ingreseVenta(tyVenta &venta, ty_prenda vecP[], int topeP, int &iP){
	
	fflush(stdin);
	cout << "ingrese el codigo de prenda:(fin para sair) " << endl;
	getline(cin, venta.codDePrenda);
	if(venta.codDePrenda  != "fin"){
		iP = buscarPrenda(vecP, topeP, venta.codDePrenda);
		while(venta.codDePrenda != "fin" && iP == -1){
			cout << "nombre incorecto: " << endl;
			cout << "ingrese el codigo de prenda:(fin para sair): " << endl;
			fflush(stdin);
			getline(cin, venta.codDePrenda);
			if(venta.codDePrenda !=  "fin"){
				iP = buscarPrenda(vecP, topeP, venta.codDePrenda);	
			}
		}
		if( venta.codDePrenda != "fin"){
			cout << "ingrese el codigo del vendedor: " << endl;
			cin >> venta.codigoVendedor;
			while( venta.codigoVendedor < 0 || venta.codigoVendedor > TOPEV-1 ){
				cout << " incorrecto: " << endl;
				cout << "ingrese el codigo del vendedor: " << endl;
				cin >> venta.codigoVendedor;
			} 
			fflush(stdin);
			cout << "ingrese el talle: " << endl;
			fflush(stdin);
			cin >> venta.talle;
			while(venta.talle  < 16 || venta.talle >36){
				cout << "numero incorrecto: " << endl;
				cout << "ingrese el talle:" << endl;
				cin >> venta.talle;
			}
			cout << "cantidad comprada: " << endl;
			cin >> venta.qComprada;
			while(venta.qComprada <= 0 ){
				cout << "cantidad incorrecta " << endl;
				cout << "cantidad comprada: " << endl;
				cin >> venta.qComprada;
			}
		}
	}
	
}

/// inicio y declaro la matriz

void iniMat(tyAcumuladores m[][TOPEV], int tf, int tc){
	
	for(int i = 0; i < tf; i++){
		for(int j = 0; j < tc; j++){
			m[i][j].importes = 0;
			m[i][j].unidadesVendidas = 0;
		}
	}
	
}

/// muestro la matriz

void mostrarMat(tyAcumuladores m[][TOPEV], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c].importes << " | ";
			cout << m[f][c].unidadesVendidas << " | ";
		}
		cout << endl;
	}
	
}

/// muestro los valores, asigno los indices y calculo los importes de la venta con sus descuentos

void mostrarVenta(ty_prenda v[], int iP, ty_Modelo vM[], tyVenta vta,tyVendedores vecVendedores[] , float &importe, int &iM, int &iV, int &qVendidas ){
	
	iM = v[iP].modelo -1;
	float precio;
	float descuento;
	iV = vta.codigoVendedor; 
	qVendidas = vta.qComprada;
	
	cout << "codigo de prenda: " << v[iP].codigo << endl;
	cout << "modelo: " << v[iP].modelo << endl ;
	descuento = (vM[iM].descuento * v[iP].precio / 100);// asi se calcula el porcentaje de descuento
	precio = v[iP].precio - descuento;
	cout << "precio" << precio << endl;
	importe = precio * vta.qComprada;// el importe sale del precio por la cantidad comprada/vendida
	cout << "el importe es: " << importe << endl;
	cout << " la fue hecha por : " << vecVendedores[iV].nombreApellido << endl;
	
}

/// acumular valores en la matriz

void acumularVenta(tyAcumuladores mat[][TOPEV], int iM, int iV, float precio, int qVendidas){
	
	mat[iM][iV].importes += precio;
	mat[iM][iV].unidadesVendidas += qVendidas ;
	
}

/// recorro la matriz por fila
 
void mostrarPorCadaModelo(tyAcumuladores m[][TOPEV],ty_Modelo  vM[], tyVendedores vV[], int topef, int topec){
	
	float impComi;
	
	for(int i = 0; i < topef; i++){
		cout << "descripcion por modelo:" << vM[i].descripcion << endl;
		for(int j = 0; j < topec; j++){
			impComi = m[i][j].importes * vV[j].porcentajeComision / 100;
			cout << " nombre y apellido" << vV[j].nombreApellido << "y la comision es : " << impComi << endl ;
		}
	}
	
}

/// recorrida por columnas
 
void porVendedorModeloConMayorQUnidadesVendidas(tyAcumuladores m[][TOPEV], ty_Modelo  vM[], tyVendedores vV[], int topef, int topec){

	int max = 0;
	int posModel = 0;

	cout << "---------------------------------------------" << endl;
	for(int c = 0; c < topec; c++){
		cout << "el vendedor: " << vV[c].nombreApellido << endl;
		for(int f = 0; f < topef; f++){
			if(max < m[f][c].unidadesVendidas){
				max = m[f][c].unidadesVendidas;
				posModel = f ;
			}
		}
		if( max == 0){
			cout << "no tuvo ventas " << endl;
		}
		else{
			cout << "el modelo mas vendido es: " << vM[posModel].descripcion <<endl;
		}
		max = 0;
	}

}

/// inicio un vector adicional
 
void iniVecTalles(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		v[i] = 0;
	}
	
}

/// asigno posiciones y valores al vector adicional

void ventasPorTalle(tyVenta venta, int vec[],int  &iT){
	
	iT = venta.talle - 16;
	vec[iT] += venta.qComprada;	
	
}

/// muestro vector adicinal

void mostrarVentasPorTalle(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		if(v[i] > 0){
			cout << "talle: " << i + 16 << "->  la cantidad de unidades vendidas fueron: " << v[i] << endl;
		}  
	}
	
}

int main(){
	
	ty_prenda vecPrendas[]={"cd01", 2399.99, 5, "f01", 1999.99, 2, "cm01", 1799.99, 1,
							"cd02", 1799.99, 5, "f02", 1899.99, 2, "cm02", 1599.99, 1,
							"p01", 5500, 3, "p02", 6499.88, 3, "b01", 26599.99, 4,
							"p03", 1199.99, 3, "b02", 999.99, 4, "cd03", 3500, 5,
							"cd04", 1099.99, 5, "f03", 2300, 2, "cd05", 12799, 5};							
	ty_Modelo vecModelosPrenda[]={"Campera", 7.2, "Falda", 11.8, "Pantalon", 10.5, "Blusa", 6.7, "Camisa", 5};
	tyVenta venta;
	ty_prenda prenda;
	ty_Modelo modelo;
	char archivo[] = "vendedores.dat";
	tyVendedores vendedores;
	/// con el registro de "vendedores" los cargo en un vector de vendedores con su estructura
	tyVendedores vecVendedores[TOPEV];
	/// declaro los indices 
	int iPrenda, iM, iV, iT;
	tyAcumuladores mat[TOPEM][TOPEV];
	float importe = 0;
	int qUnidades = 0;
	/// vector adicional
	int vecPorTalle[TOPETALLES];
	
	iniVecTalles(vecPorTalle, TOPETALLES);
	/// cargo el archivo en el vector
	cargarVendedores(archivo ,vecVendedores, TOPEV);
	/// los muestro para ver que todo este bien
	mostrarVendedor(vecVendedores, TOPEV);
	/// inicio la matriz
	iniMat(mat, TOPEM, TOPEV);
	/// muestro la matriz
	mostrarMat(mat, TOPEM, TOPEV);
	/// ingreso y validacion
	ingreseVenta(venta, vecPrendas, TOPEPRENDAS, iPrenda);
	while(venta.codDePrenda != "fin"){
		/// proceso la ventas, asigno indices y mustro los datos de la venta y facturacion 
		mostrarVenta(vecPrendas, iPrenda, vecModelosPrenda, venta,  vecVendedores, importe, iM, iV, qUnidades);
		/// acumulo los valores en la matriz
		acumularVenta(mat, iM, iV, importe, qUnidades);
		/// muestro la matriz para que controlar que todo este bien
		mostrarMat(mat, TOPEM, TOPEV);
		/// acumulo en el vector adicional 
		ventasPorTalle(venta, vecPorTalle, iT);
		ingreseVenta(venta, vecPrendas, TOPEPRENDAS, iPrenda);
	}
	/// recorro la matriz por fila
	mostrarPorCadaModelo(mat,vecModelosPrenda,vecVendedores,TOPEM, TOPEV);
	/// recorro la matriz por columnas
	porVendedorModeloConMayorQUnidadesVendidas(mat, vecModelosPrenda, vecVendedores, TOPEM,TOPEV);
	/// muestro el vetor adicional
	mostrarVentasPorTalle(vecPorTalle, TOPETALLES);
	
}

