#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void ingreseJuegos(int &juegosN){
	
	cout << " ingrese njuegos: " << endl;
	cin >> juegosN;
	
}

void ingreseQValoresN1(int &n1){
	
	cout << " ingrese cantidad de n1valores: " << endl;
	cin >> n1;
	
}

void ingreseValores(int &valores){
	
	cout << "ingrese valores: " << endl;
	cin >> valores;
	
} 

void maxProm(float &prom, float &maxProm, int &juego, int &mayorNumJuego){
	
	if (prom > maxProm){
		maxProm = (float)prom;
		mayorNumJuego = juego;
	}
	
}

int main(){

	int n, n1, valores, sumaValDeJuego, sumaTotal = 0, juegoNum, numeroDeJuegoMayorProm = 0;
	float promedio, promMax = 0;
	
	ingreseJuegos(n);
	for(int i = 0; i < n; i++){
		sumaValDeJuego = 0;
		juegoNum = i + 1;
		cout << "juego numero: "<< juegoNum << endl;
		ingreseQValoresN1(n1);
		for (int j = 0; j < n1; j++){
			ingreseValores(valores);
			sumaValDeJuego += valores;
			sumaTotal += valores;
		}		
		cout << "la suma de valores es: " << sumaValDeJuego << endl;
		promedio = (float)sumaValDeJuego / n1;
		cout << "promedio: " << promedio << endl;
		maxProm(promedio, promMax, juegoNum, numeroDeJuegoMayorProm  );	
	}
	
	cout << "la suma total es: " << sumaTotal << endl;
	cout << "el promedio maximo es el del juego numero: " << numeroDeJuegoMayorProm << endl;
	
}

