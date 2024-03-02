#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPE 200

void ingresoParrafo(char cadenaCh[],string &cadenaString,int tope){
	
	int i;
	int cadenaLongitud;
	int nuevotope = tope-1;
	
	cout << " ingrese un parrafo: " << endl;
	getline(cin,cadenaString);
	cadenaLongitud = cadenaString.size();
	while (cadenaLongitud > nuevotope){
		cout << "exeso, ingrese de nuevo :" << endl;
		getline(cin,cadenaString);
		cadenaLongitud = cadenaString.size();
	}
	cadenaLongitud = cadenaString.size();
	for(int i=0; i < cadenaLongitud ; i++){
		cadenaCh[i] = cadenaString[i];
	}
	cadenaCh[cadenaLongitud] = '\0';
	
}

void MostarPalabrasyCanLetras(char cadenaCh[],int &contp){
	
	char vecCaracteresEsp[10] = {'.', ',', ';', ':', '¡', '!' ,'¿', '?',' ','\0'};
	char palabra[20];
	int pos = 0;
	
	for (int i = 0; i <= strlen(cadenaCh) ; i++){
		for (int j = 0; j < strlen(vecCaracteresEsp); j++){
			if(cadenaCh[i] == vecCaracteresEsp[j]){
				palabra[pos] = '\0';
				if(strlen(palabra) != 0){
					contp++;
					cout << "La palabra es : " << palabra << endl;
					cout << "Y tiene una cantidad de " << strlen(palabra) << " letras" << endl;
				}
				pos = -1;
			}
			else{
				palabra[pos] = cadenaCh[i];	
			}
		}
		pos++;	
	}
	
	cout<<"Cantidad de palabras en el parrafo : "<<contp<<endl;
	cout<<" La longitud : " << strlen(cadenaCh)<<endl;
	
}

void ImprimirEnPantalla(char cadenaCh[], int &contp ) {
	
	MostarPalabrasyCanLetras(cadenaCh,contp);
	
}

int main(){
	
	string cadenaStr;
	char cadenaCh[TOPE];
	int contador = 0;

	ingresoParrafo(cadenaCh,cadenaStr,TOPE);
	ImprimirEnPantalla(cadenaCh, contador);
	
}

