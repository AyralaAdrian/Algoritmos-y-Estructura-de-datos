/*Ejercicio 1: Dado un arreglo de 20 elementos enteros:
c) Realizar una rutina que obtenga las posiciones donde están ubicados
el máximo y el mínimo valor.
d) Realizar una rutina que y muestre por pantalla el valor máximo del
arreglo y en qué posiciones se encuentra.
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPE 20

void buscarMaximoyMinimo(int vec[], int tope){
	
	int pos1;
	int valMin = 999;
	int pos;
	int valMax = -10;
	
	for(int i = 0; i <tope; i++){
		if(vec[i] > valMax ){
			valMax = vec[i];
			pos = i;
		}
		if(vec[i] < valMin){
			valMin = vec[i];
			pos1 = i;
		}
	}
	
	cout << "en la posicion: " << pos << " del vector se encuentra el maximo valor" << endl;
	cout << "en la posicion: " << pos1 << " del vector se encuentra el minimo valor" << endl;
	
}

void valorMaximo(int vec[], int tope){
	
	int pos;
	int valMax = -10;

	for(int i = 0; i <tope; i++){
		if(vec[i] > valMax){
			valMax = vec[i];
			pos = i ;
		}
	}
	
	cout << "en la posicion: " << pos << " se encuentra el maximo valor que es:"<< valMax << endl;
	cout << "Saludos ";
	
} 

int main(){

	int vecEle[TOPE] = 	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	
	buscarMaximoyMinimo(vecEle, TOPE);
	valorMaximo(vecEle, TOPE);

}

