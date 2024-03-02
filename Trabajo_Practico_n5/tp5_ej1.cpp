/*Ejercicio 1:
Dada una matriz entera de N x N, desarrollar una función que devuelva la suma
los elementos de su diagonal principal.
(mat [0][0]+ mat [1][1]+ mat [2][2]+ …+mat [N-1][N-1])
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEF 3
#define TOPEC 3

void mostrarMat(int m[][TOPEC], int tf, int tc){
	
	for(int f = 0; f < TOPEF; f++){
		for(int c = 0; c < TOPEC; c++){		
			cout << m[f][c] << " - ";
		}
		cout << endl;
	}
	
}

int sumarDiagonal(int m[][TOPEC], int tf){
	
	int total = 0;
	
	for(int i = 0; i < tf; i++){
		total += m[i][i];
	}
	
	return total;
	
}

int main(){

	int mat[TOPEF][TOPEC] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
	int total;
	
	mostrarMat(mat, TOPEF, TOPEC);
	total =sumarDiagonal(mat, TOPEF);
	cout << " la suma de la diagonal principal es : " << total;

}

