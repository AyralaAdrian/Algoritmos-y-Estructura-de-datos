/*Ejercicio 2:
Modificar la rutina del ejercicio anterior, para que según un parámetro que se le
indique devuelva la suma de la diagonal principal o de la diagonal inversa*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEF 4
#define TOPEC 4

int sumarDiagonal(int m[][TOPEC], int tf){
	
	int total = 0;
	
	for(int i = 0; i < tf; i++){
		total += m[i][i];
	}
	
	return total;
	
}

int inversa(int m[][TOPEC], int tf){
	
	int total = 0;
	
	for(int i = tf; i > 0; i--){
		total += m[tf-i][i-1];
	}
	
	return total;
	
} 

int menu(char letra, int m[][TOPEC], int tf){
	
	int total = 0;
	
	cout << " bienvenidos " << endl;
	cout << "ingrese 'd' para suma diagonal,  'i' para inversa: " << endl;
	cin >> letra;
		if(letra == 'd'){
			total =  sumarDiagonal(m, tf);
			cout << "la suma de la diagonal prinicipal es: " << total << endl;
		}
		else if(letra == 'i'){
			total = inversa(m,tf);
			cout << "la suma de la diagonal inversa es: " << total << endl;
		}
		else{
			cout << "error" << endl;
		}			
	
	return total;
	
}

void mostrarMat(int m[][TOPEC], int tf, int tc){
	
	for(int f = 0; f < TOPEF; f++){
		for(int c = 0; c < TOPEC; c++){		
			cout << m[f][c] << " - ";
		}
		cout << endl;
	}
	
}

int main(){
	
	char letra;
	int mat[TOPEF][TOPEC] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {20, 13, 14, 15}};

	mostrarMat(mat, TOPEF, TOPEC);	
	menu(letra, mat, TOPEF);
	cout << "muchas gracias "; 
	
}

