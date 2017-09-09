#include <iostream>
#include <math.h>
	using namespace std ;
	
	int menu () ;
	float coseno ( float x , int n) ;
	float factorial ( float x ) ;
	float ln ( float x , int n ) ;
	float seno ( float x , int n ) ;
	
int main () {
	
	int op , n ;
	float xcos , xln , xsen ;
	
	do {
		op = menu () ;
		switch ( op ) {
			case 1 :
				cout << " Opcion coseno " << endl ;
				cout << " Ingresa el numero del coseno deseado: " ;
				cin >> xcos ;
				cout << " Ingrese n " ;
				cin >> n ;
				cout << " El coseno de " << xcos << " es: " << coseno(xcos,n) << endl ; //*******Crear funcion coseno******
			break ; 
			
			case 2 :
				cout << " Opcion ln " << endl ;
				cout << " Ingrese el numero del ln deseado: " ;
				cin >> xln ;
				cout << " Ingrese n : " ;
				cin >> n ;
				cout << " ln de " << xln << " es: " << ln(xln,n) << endl ; //*******Crear funcion ln *******
			break ;
			
			case 3 :
				cout << " Opcion seno " << endl ;
				cout << " Ingrese el numero del seno deseado: " ;
				cin >> xsen ;
				cout << " Ingrese n: " ;
				cin >> n ;
				cout << " El seno de " << xsen << " es: " << seno(xsen,n) << endl ; //***** Crear funcion seno ****
			break ; 
			
			case 0 :
				break ;
		}
		
	} while ( op != 0) ; //El ciclo se repite hasta que el usuario introduzca un 0 como opcion de salida
	return 0 ;
}

/*** FUNCIONES ***/

	int menu () {
		int op ;
		do {
			cout << "                M E N U                 "
			<< endl << " 1. COSENO " 
			<< endl << " 2. ln "
			<< endl << " 3. SENO "
			<< endl << " 0. SALIR "
			<< endl << " Ingresa opcion... " ;
			cin >> op ;
			cout << " _______________________________________ " << endl << endl ;
		} while ( op > 3 || op < 0 ) ; // El ciclo se repetira hasta que el usuario introduzca opcion valida
		
		return op ;
	}
	
	
	
	float coseno ( float x , int n ) {
	
		float cosx = 0 , deno = 2 , positivo = 0 , negativo = 0 ;
	
			for ( int i = 1 ; i <= n ; i++ ) { 
				if ( i%2 == 0 ) {
					positivo += ( ( pow(x,deno) ) / factorial (deno) ) ;  	
				}
				else
					negativo += ( ( pow(x,deno) ) / factorial (deno) ) ;  
				deno += 2 ;
		}
		cosx = ( 1 + positivo ) - negativo ;
	return cosx ;
	}
	
	float factorial ( float x ) {
		float factorial = 1 ;
		for (int i = 1 ; i<=x ; i++ ) {
			factorial *= i ;
		}
	return factorial ;
	} 
	
	float ln ( float x , int n ) {
		float loga = 0 , y = 0 ;
			y =  ( ( x-1 ) / x  ) ;
		for ( int i = 1 ; i<= n ; i++ ) {
			loga +=  (1/i) * pow(y,i) ;
		}
	return loga ;
	}
	
	float seno ( float x , int n ) {
	
		float senx = 0 , deno = 3 , positivo = 0 , negativo = 0 ;
	
			for ( int i = 1 ; i <= n ; i++ ) { 
				if ( i%2 == 0 ) {
					positivo += ( ( pow(x,deno) ) / factorial (deno) ) ;  	
				}
				else
					negativo += ( ( pow(x,deno) ) / factorial (deno) ) ;  
				deno += 2 ;
		}
		senx = ( x + positivo ) - negativo ;
	return senx ;
	}
	
	
