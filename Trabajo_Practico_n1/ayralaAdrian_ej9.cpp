#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct tyFiesta{
	
	string fecha;
	char tipo;
	int qPersonas;
	int menu;
	
};

struct tyContador{
	
	int qC;
	int qS;
	int qO;
	
};

void ingreseFiesta(tyFiesta &fiesta){
	
	cout << "ingrese la fecha de la fiesta:(-1 para finalizar) " << endl;
	cin >> fiesta.fecha;
	if(fiesta.fecha != "-1"){
		cout << "ingrese el tipo de fiesta ('c', 's', 'o'):" << endl;
		cin >> fiesta.tipo;
		cout << "ingrese la cantida de personas: " << endl;
		cin >> fiesta.qPersonas;
		cout << "ingrse el tipo de menu (1 0 2): " << endl;
		cin >> fiesta.menu;	
	} 
		
}

void tipoDeFiesta(tyFiesta &fiesta, tyContador &contador ){
	
	if(fiesta.tipo == 'c' || fiesta.tipo == 'C'){
		contador.qC++;
	}
	else if(fiesta.tipo == 's'|| fiesta.tipo == 'S'){
		contador.qS++;
	}
	else if(fiesta.tipo == 'o' || fiesta.tipo == 'O'){
		contador.qO++;
	}
	else{
		cout << "ERROR - por favor ingrese solo caracteres validos " << endl;
	}
	
}

void fiestaMayorQPersonasXMenu(tyFiesta &fiesta, int &mayor, int &menu, string &fecha){
	
	if(fiesta.qPersonas > mayor){
		mayor = fiesta.qPersonas;
		menu = fiesta.menu;
		fecha = fiesta.fecha;	
	}
	
} 

void promedio(tyFiesta &fiesta, tyContador &contador, int &acumulador, int & contadorDeFiestas, float &prom){
	
	contadorDeFiestas = contador.qC + contador.qO + contador.qS;
	acumulador += fiesta.qPersonas;
	prom = (float)acumulador / contadorDeFiestas;
	
}

int main(){
	
	tyFiesta fiesta;
	tyContador contador;
	contador.qC = 0;
	contador.qO = 0;
	contador.qS = 0;
	int mayor = -10;
	int menu = 0;
	string fecha;
	int acumulador = 0;
	int contadorDeFiestas = 0;
	float prom;
	
	ingreseFiesta(fiesta);
	while(fiesta.fecha != "-1"){
		tipoDeFiesta(fiesta, contador);
		fiestaMayorQPersonasXMenu(fiesta, mayor, menu, fecha);
		promedio(fiesta, contador, acumulador, contadorDeFiestas, prom);	
		ingreseFiesta(fiesta);
	}
	
	cout << " Fiestas de tipo C: " << contador.qC << endl;
	cout << " Fiestas de tipo S: " << contador.qS << endl;
	cout << " Fiestas de tipo O: " << contador.qO << endl;
	cout << "el  menu: " << menu << " tendra la mayor q de personas: " << mayor << ", en la fecha: " << fecha << endl;
	cout << "el promedio de personas por fiesta es: " << prom << endl;	
	cout << "muchas gracias";

}

