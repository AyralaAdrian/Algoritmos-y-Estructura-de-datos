#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPEF 2
#define TOPEC 3

void mostrarMat(int m[][TOPEC], int tf, int tc){
	
	for(int f = 0; f < tf; f++){
		for(int c = 0; c < tc; c++){		
			cout << m[f][c] << " - ";
		}
		cout << endl;
	}
	
}

void transpuesta(int m[][TOPEC], int tf, int tc){
	
	for(int f = 0; f < tc; f++){
		for(int c = 0; c < tf; c++){		
			cout << m[c][f] << " - ";
		}
		cout << endl;
	}	

}

int main(){
	
	int mat[TOPEF][TOPEC] = {{1, 2, 3}, {4, 5, 6}};
	
	cout << "matriz original: " << endl;
	mostrarMat(mat,TOPEF, TOPEC);
	cout << "matriz transpuesta: " << endl;
	transpuesta(mat,TOPEF, TOPEC);

}

