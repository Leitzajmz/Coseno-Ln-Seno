#include <iostream>
#include <string.h>
#include <stdio.h>
	using namespace std ;
	
	int buscar (char texto[] , char palabra[]);
	int longitud(char c[]);
	
int main(){
	int pos ;
	char palabraBuscar[15] ;
	char texto[] = "Este es un texto cualquiera en el cual puedes buscar equis palabra. "; 
	
	cout << texto << endl ;
	cout << "Palabra a buscar: " ;
	cin >> palabraBuscar ;
	
	pos = buscar(texto, palabraBuscar) ;
	//cout << pos << endl ;
	if (pos == -1)
		cout << "Palabra no encontrada... " << endl ;
	else
		cout << "Tu palabra comienza en la posicion " << pos << endl ;
	
	return 0 ;
}

int longitud(char c[]){
	int cont = 0 ;
	for ( ; c[cont]; cont++);
	return cont ;
}


int buscar (char texto[] , char palabra[]){
	int cont = 0 ;	
	for (int i = 0; i < longitud(texto) ; i++){
		if (palabra[cont] == texto[i]){
			cont++;
			if (cont == longitud(palabra))
				return (2 + i - cont ); //(i = posicion en el texto donde termino )
		} //comparación de las letras	  (-cont que es el tamaño de la palabra ) 	
		else							//se suma el 2 por las dos posiciones en 0 de cada vector
			cont = 0 ; //Regresa el contador a su valor inicial
	}
	return -1 ;
} //Fin de la funcion
