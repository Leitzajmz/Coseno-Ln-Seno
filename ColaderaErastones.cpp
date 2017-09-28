#include <iostream>
	using namespace std ;
	
	void coladera (int primo[], int tam) ;
	
int main() {
	
	int primo[1000];
	
	cout << "Coladera de Erastotenes" << endl ;
	coladera(primo, 1000);
}






/*FUNCION*/

void coladera (int primo[], int tam){
	for (int i = 0 ; i < tam ; i++ ){
		primo[i] = 1 ;
	}
	
	for (int i = 2 ; i < tam ; i++ ){
		for (int j = 2 ; i*j < tam ; j ++  ){
			primo [i*j] = 0 ;
		}
	} // Ciclo i
	
	for (int i = 1 ; i < tam ; i++ ){
		if (primo[i] == 1 ) 
			cout << i << "	" ;
	}
}
