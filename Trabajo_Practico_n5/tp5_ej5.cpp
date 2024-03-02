#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEN 3
#define TOPEM 5 
#define TOPES 6

void mostrarMat(int m[][TOPEM], int tf, int tc){
	
	cout << "matriz: " << endl;
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c] << " - ";
		}
		cout << endl;
	}
	
}

void iniVec(int v[], int tope){
	
	for(int i = 0; i < tope; i++){
		v[i] = 0;
	}
	
}

void mostrarVec(int v[], int tope){
	
	cout << " vector: " << endl;
	for(int i = 0; i < tope; i++){
		cout << v[i] << " - " ;
	}
	cout << endl;
	
}

bool buscar(int m[][TOPEM], int tf, int tc, int valor, int &iF, int &iC){
	
	iF = 0;
	iC = 0;
	
	while(iF < tf && m[iF][iC] != valor){
		while(iC < tc && m[iF][iC] != valor){
			iC++;
		}
		if(iC == tc){
			iF++;
			iC = 0;
		}
	}
	if (iF == tf){
		iF = -1;
		iC = -1;
	}
				
}

void cargarVec(int v[], int &tope, int &valor){
	
	v[tope] = valor;
	tope++;
	
}

int main(){

	int mat[TOPEN][TOPEM] = {{8, 3, 6, 2, 5}, {1, 22, 0, 4, 3}, {7, 15, 8, 1, 4}};
	int vec[TOPES] = {25, 4, 7, 9, 15, 6};
	int topeVR = 0;
	int iF, iC;
	int vecResu[topeVR];
	iniVec(vecResu,topeVR);
	bool resu;
	
	mostrarMat(mat, TOPEN, TOPEM);
	mostrarVec(vec, TOPES);
	for(int i = 0; i <TOPES; i++){
		buscar(mat, TOPEN, TOPEM,vec[i], iF, iC);
		if(iF == -1 || iC == -1){
			cargarVec(vecResu, topeVR, vec[i]);	
		}	
	}
	cout << "vector de no encontrados: " << endl;
	mostrarVec(vecResu, topeVR);	
	
}

