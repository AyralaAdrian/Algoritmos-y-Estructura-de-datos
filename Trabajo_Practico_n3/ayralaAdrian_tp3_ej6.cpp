/*Ejercicio 6:
a) Realizar una rutina que reciba dos arreglos de N y M números enteros
respectivamente y devuelva un arreglo resultante con la unión de ambos
arreglos sin repetir valores.
b) Analizar el ejercicio a) pero considerando ambos arreglos ordenados
previamente. ¿Modificaría la estrategia de solución? ¿Si es asi, se obtiene un
algoritmo más eficiente*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEN 10
#define TOPEM 5
#define TOPE3 TOPEN + TOPEM

int buscarValor(int vector[],int &tope, int val){
	
	int k = 0;
	
	while(k < tope && vector[k] != val){
		k++;
	} 
	if(k == tope){
		k = -1;
	}

	return k;

}

void mostrarVec(int vector[], int tope){
	
	for(int i = 0; i < tope; i++){
		cout << vector[i] << " - ";
	}
		
}

int main(){

	int vec[TOPEN] = {12, 5, 4, 5, 9, 11, 5, 4, 13, 7};
	int vec2[TOPEM] = {0, 9, 3, 7, 10};
	int vec3[TOPE3];  
	int topeAuxiliar = 0;

	
	for(int i = 0; i < TOPEN; i++){
		if(buscarValor(vec3, topeAuxiliar, vec[i])	== -1){
			vec3[topeAuxiliar] = vec[i];
			topeAuxiliar++;
		}
	}
	for(int i = 0; i < TOPEM; i++){
		if(buscarValor(vec3, topeAuxiliar, vec2[i])== -1){
			vec3[topeAuxiliar] = vec2[i];
			topeAuxiliar++;
		}
	}
	mostrarVec(vec3, topeAuxiliar);

}

