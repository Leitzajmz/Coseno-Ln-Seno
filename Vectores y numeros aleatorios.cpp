/*Lanzar el dado 1 o 2 veces*/
#include <iostream>
#include <cstdlib>
#include <ctime>
	using namespace std ;

int menu();
int dado();
void histograma(int tam) ;
	
int main() {
	srand(time(NULL)) ;
	int op , d1 , tam , d[6] , suma [11] ;
	
	do{
		for (int i = 0 ; i < 6 ; i++ ) d[i] = 0 ; //Inicializar el vector
		for (int i = 0 ; i < 11 ; i++ ) suma[i] = 0 ;
		
		op = menu();	
		switch (op){
			case 1 :
				for (int i = 0 ; i < 100 ; i++ ){
					d1 = dado() ; //Funcion que simula lanzamiento del dado	
					d[d1-1] ++ ;
				} //Termino del ciclo for 
				
				cout << "Histograma de veces que cayo cada cara del dado... " << endl ;
				for (int i = 0 ; i < 6 ; i++ ){
					tam = d[i] ;
					cout << i+1 << " " ; 
					histograma(tam) ; //Funcion que crea el histograma
				}  
			break ; // Termino del case 1
			
			case 2:
				for (int i = 0 ; i < 100 ; i++ ) {
					d1 = dado() + dado() ;
					suma[d1-2]++ ;
				}//Termino del ciclo for
				
				cout << "Histograma de las posibles sumas con 2 dados... " << endl ;
				for (int i = 0 ; i < 11 ; i++ ){
					tam = suma[i] ;
					cout << i+2 << " " ; 
					histograma(tam) ; //Funcion que crea el histograma
				}  
			break ; // Termino del case 2
			
			case 0 :
				break;
				
		} // Termino del switch
	}while (op != 0) ;
		
	return 0 ;
} //Leitza Jocelyn Jimenez Aguilar 



/*FUNCIONES*/

int menu() {
	int op ;
	do{
		cout << "1.- Lanzar el dado una vez. " << endl
		<< "2.- Lanzar el dado dos veces. " << endl
		<< "0.- Salir " << endl 
		<< " Opcion... " ;
		cin >> op ;	
	}while (op<0 || op > 2 ) ;
	return op ;
}

int dado(){ //Simulacion del lanzamiento de un dado 
	int dado;
	dado = 1+ rand()%6 ;
	return dado ;
}

void histograma(int tam ) { // Creacion del histograma
	for (int i = 1; i <= tam ; i++ ) cout << '*' ;
	cout << "( " <<tam << " ) " << endl ; 
}
