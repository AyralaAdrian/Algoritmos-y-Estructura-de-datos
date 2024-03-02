#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEF 3
#define TOPEC 2

void mostrarMat(int m[][TOPEC], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c] << " - ";
		}
		cout << endl;
	}
	
}

void buscar(int m[][TOPEC], int tf, int tc, int valor, int &iF, int &iC){

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

int main(){

	int mat[TOPEF][TOPEC] = {{0, 2}, {4, 8}, {10, 12}};
	mostrarMat(mat, TOPEF, TOPEC);
	int  num;
	int iFila, iCol;
	
	cout << "ingrese el valor que desea buscar: " << endl;
	cin >> num;
	buscar(mat, TOPEF, TOPEC, num, iFila, iCol);
	if(iFila != -1 ){
		cout << "el valor a buscar esta en la fila ["<< iFila <<"] clumna [" << iCol <<"]" << endl;	
	}
	else{
		cout << "el valor no esta en la matriz" << endl;
	}
		
}

