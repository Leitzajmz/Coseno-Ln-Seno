#include <iostream>
	using namespace std ;
	
	int longitud(char c[]);
	int numPalabras(char texto[]);
	void titulo(char texto[]) ;
	
int main(){
	char frase[] = "practica para contar palabras cuentalas " ;
	cout << frase << endl ;
	cout << "Tu frase tiene " << numPalabras(frase) << " palabras." << endl ;
	cout << "Frase tipo titulo... " << endl ;
	
	titulo(frase);
	cout << frase << endl ;
	
	return 0 ;
}

int longitud(char c[]){
	int cont = 0 ;
	for ( ; c[cont]; cont++);
	return cont ;
}

int numPalabras(char texto[]) {
	int cont = 0 ;
	
	for (int i= 0 ; i < longitud(texto) ; i++){
		if (texto[i] == 32) 
			if (texto[i+1] != 32)
				cont++ ; 
	}
	return cont ;
}

void titulo(char texto[]){
	
	int desp = 'a' - 'A' ;
	if (texto[0] >= 'a' && texto[0] <= 'z')
		texto[0] -= desp ;
		
	for (int i= 0 ; i < longitud(texto) ; i++){
		if (texto[i] == 32) 
			if (texto[i+1] != 32)
				if (texto[i+1] >= 'a' && texto[i+1] <= 'z')
					texto[i+1] -= desp ;
	}
}
