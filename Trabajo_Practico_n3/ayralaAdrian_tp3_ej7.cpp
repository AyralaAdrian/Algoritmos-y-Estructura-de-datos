/*Ejercicio 7
a) Un estacionamiento de la zona céntrica trabaja de 7 a 21hs.y tiene
capacidad para 10 cocheras; al final del día no queda ningún vehículo
guardado. El dueño nos pide un programa que tenga un menú
con cuatro opciones: “Ingreso de vehículo”, “Salida de vehículo”, “Listado” y
“Fin”.
La primera opción nos pide el número de patente y la hora de entrada del
vehículo y lo registra como guardado (si no hay lugar en el estacionamiento se
debe informar un mensaje por pantalla).
La segunda opción nos pide el número de patente del vehículo que sale y
nosotros debemos informar la hora en que ingresó y liberar esa cochera.
En la tercera opción, debe mostrar por pantalla las patentes de los vehículos
que están guardados y la hora en que entraron.
En la cuarta opción, debe verificar que no quede ningún vehículo estacionado*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define TOPE 10

using namespace std;

struct tyVecEst{
	
	string patente;
	int hora;
	
};

// opcion 1
int ingresoOpcion() {
	
    int opcion;

    cout << endl << "1: Ingreso de vehiculo. 2: Salida de vehiculo. 3: Listado. 4: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> opcion;

    return opcion;
}

int buscarLibre(tyVecEst vector[]){
	
	int i = 0;
	
	while(i < TOPE && vector[i].patente != "LIBRE"){
		i++;
	} 
	if(i == TOPE){
		i = -1;
	}

	return i;

}

void buscarLugar(tyVecEst vector[], string patente, int hora){
	
	int indice = buscarLibre(vector);
	
	if(indice != -1){
		vector[indice].patente = patente;
		vector[indice].hora = hora;
 	}
 	else{
		cout << "no hay lugar" << endl; 
	}

}

void ingreso(tyVecEst &vehiculo, tyVecEst vector[], int &i){
	
	cout << "ingrese una hora: " << endl;
	cin >> vehiculo.hora;
	while(vehiculo.hora < 7 || vehiculo.hora > 21){
		cout << "hora incorrecta, ingrese entre las 7 y las 21" << endl;
		cout << "ingrese una hora: " << endl;
		cin >> vehiculo.hora;
	}
	cout << "ingrese la patente(3 - letrea / 3 - numeros):" << endl;
	fflush(stdin);
	getline(cin, vehiculo.patente);
	if (i < TOPE){
		buscarLugar(vector, vehiculo.patente, vehiculo.hora);	
	}
	
}

//opcion 2
int buscarPatente(tyVecEst vector[], string patente){
	
	int i = 0;
	
	while(i < TOPE && vector[i].patente != patente){
		i++;
	} 
	if(i == TOPE){
		i = -1;
	}

	return i;

}

void sacarVehiculo(tyVecEst vector[], string patente){

	int i = buscarPatente(vector, patente);
	
	if(i != -1){
		vector[i].patente = "LIBRE";
		vector[i].hora = 0;
	}

}

void salida(tyVecEst &vehiculo, tyVecEst vector[]){
	
	cout << "Ingrese la patente del vehivulo: " << endl;
	fflush(stdin);
	getline(cin, vehiculo.patente);
	sacarVehiculo(vector, vehiculo.patente);
	
}

//opcion 3
void mostrar(tyVecEst vector[]){
	
	for(int i = 0; i < TOPE; i++){
		cout << "patente: " << vector[i].patente << " hora: " << vector[i].hora << endl;
	}
}

//opcion 4
bool estVacio(tyVecEst vector[]){
	
	int i = 0;
	bool rta = false;

	while(i < TOPE && vector[i].patente == "LIBRE"){
		i++;
	} 
	if(i < TOPE){
		cout << "hay vehiculos estacionados" << endl;
	}
	else{
		rta = true;	
	}

	return rta;

}

void mostrarOpcionNoValida(){
	
	cout << "opcion no valida, ingrese un numero valido";

}

int main(){
	
    int opcion;
    tyVecEst vectorEstacionamiento[TOPE] = {"LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0 , "LIBRE",0};
	tyVecEst vehiculo;
 	int indice;
 	
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
				ingreso(vehiculo, vectorEstacionamiento, indice);
                break;
            case 2:
                salida(vehiculo, vectorEstacionamiento);
                break;
            case 3:
                mostrar(vectorEstacionamiento);
                break;
            case 4:
               	if(estVacio(vectorEstacionamiento)){
               		cout << "muchas gracias" << endl;
				   }
				else{
					opcion = 3;
					mostrar(vectorEstacionamiento);
				}
                break;
            default:
                mostrarOpcionNoValida();
        }
        
    } while (opcion != 4);

}
