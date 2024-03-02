/*Ejercicio 4: Ingresar una serie de números naturales que termina con -1 e
indicar cuántas veces se interrumpe el orden ascendente y cuántos números
hay en cada grupo ordenado.*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void ingreseNumero(int &numero){
	
	cout << "Ingrese un numero: " << endl;
	cin >> numero;
	
}

void mostrarSeries(int &series){
	
	cout << "el nuemero de series es: " << series << endl;

}

int main(){

	int numero, nvoNumero, qseries = 0, qvalores;
	
	ingreseNumero(nvoNumero);
	while(nvoNumero != -1){
		qvalores = 0;
		numero =nvoNumero - 1;  
		while(nvoNumero != -1 && nvoNumero > numero){
		qvalores++;
		cout << "cantidad de valores: " << qvalores << endl;
		numero = nvoNumero;
		ingreseNumero(nvoNumero);
		}
		qseries++;
		cout << "interrupcion " << qseries << endl;
	}
	mostrarSeries(qseries);
	cout << "muchas gracias";

}

