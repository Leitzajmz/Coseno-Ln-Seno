#include <iostream>
	using namespace std ;
	
	int menu();
	void instrucciones();
	void girarDerecha(int &horizonte);
	void girarIzquierda(int &horizonte);
	int bajarPluma();
	int subirPluma();
	void avanzar(int casillas, int horizonte, int pluma, int mat[][20], int tam , int &coord_x , int &coord_y );
	void imprimir(int mat[][20], int tam);
	
	
int main(){
	int op , horizonte = 0 , pluma , casillas , mat[20][20]={{0}}, tam = 20 ;
	int coord_x = 0 , coord_y = 0 ;
	
	instrucciones();
	
	do{
		op=menu();
		
		switch(op){
			case 1:
				cout << "Tortuga girada a la derecha " << endl ;
				girarDerecha(horizonte);
			break;
			
			case 2:
				cout << "Tortuga girada a la izquierda " << endl ;
				girarIzquierda(horizonte);	
			break ;
			
			case 3:
				cout << "Pluma abajo " << endl ;
				pluma = bajarPluma();		
			break ;
			
			case 4:
				cout << "Pluma arriba " << endl ;
				pluma = subirPluma() ;	
			break;
			
			case 5:
				cout << "Casillas que deseas avanzar... " ;
				cin >> casillas ;
				avanzar(casillas, horizonte, pluma, mat, tam , coord_x , coord_y);
			break;
				
		}	
	} while(op != 0) ;
	
	imprimir(mat, tam);
	return 0 ;
} //Cierre del main


void girarDerecha(int &horizonte){
	if (horizonte == 3)
		horizonte = 0 ;
	else
		horizonte++ ;
}

void girarIzquierda(int &horizonte){
	if (horizonte == 0)
		horizonte = 3 ;
	else
		horizonte-- ;
}

int bajarPluma(){
	int pluma = 1;
	return pluma ;
}

int subirPluma(){
	int pluma ;
	pluma = 0;
	return pluma ;
}

void avanzar(int casillas, int horizonte, int pluma, int mat[][20], int tam , int &coord_x , int &coord_y ){
	switch(horizonte){
		case 0 : //Se mueve hacia abajo
			if (pluma == 1){
				for (int r = coord_y ; r < casillas ; r++){
					for (int c = coord_x ; c < coord_x + 1 ; c++ )
						mat[r][c] = 1 ;
				} //cierre del for (renglones)
			} //cierre del if (pluma == 1)
			else {
				for (int r = coord_y ; r < casillas; r++){
					for (int c = coord_x ; c < coord_x + 1 ; c++ )
						mat[r][c] = 0 ;
				}
			} //cierre del else
			coord_y += casillas ; 
			
		break; 
		
		case 1: //se mueve a la derecha
			if (pluma == 1 ){
				for(int r = coord_y ; r < coord_y + 1 ; r++ ){
					for (int c = coord_x ; c < casillas ; c++ )
						mat[r][c] = 1 ; 
				}
			}//Cierre del if (pluma == 1)
			else {
				for(int r = coord_y ; r < coord_y + 1 ; r++ ){
					for (int c = coord_x ; c < casillas ; c++ )
						mat[r][c] = 0 ; 
				}
			} //Cierre del else 	
			coord_x += casillas ;
		break ;
		
		case 2 : //Se mueve hacia arriba
			if (pluma == 1){
				for (int r = coord_y ; r > casillas; r--){
					for (int c = coord_x ; c < coord_x + 1 ; c++ )
						mat[r][c] = 1 ;
				} //cierre del for (renglones)
			} //cierre del if (pluma == 1)
			else {
				for (int r = coord_y ; r < casillas ; r++){
					for (int c = coord_x ; c < coord_x + 1 ; c++ )
						mat[r][c] = 0 ;
				}
			} //cierre del else
			coord_y -= casillas ; 
			
		break; 
		
		case 3: //se mueve a la izquierda
			if (pluma == 1 ){
				for(int r = coord_y ; r > coord_y - 1 ; r-- ){
					for (int c = coord_x ; c < casillas ; c++ )
						mat[r][c] = 1 ; 
				}
			}//Cierre del if (pluma == 1)
			else {
				for(int r = coord_y ; r < coord_y + 1 ; r++ ){
					for (int c = coord_x ; c < casillas ; c++ )
						mat[r][c] = 0 ; 
				}
			} //Cierre del else 	
			coord_x -= casillas ;
		break ;
	} //Cierre del switch
}

void imprimir(int mat[][20], int tam){
	for (int r = 0 ; r < tam ; r++){
		for (int c = 0 ; c < tam ; c++){
			if (mat[r][c] == 1) 
				cout << '*' ;
			else
				if (mat[c][r] == 0) 
					cout << '°' ;
		}
		cout << endl ;
	}
}


int menu(){
	int op ;
	do{
		cout << "1.- Girar derecha. " << endl
		<< "2.- Girar izquierda. " << endl
		<< "3.- Bajar pluma. " << endl
		<< "4.- Subir pluma. " << endl
		<< "5.- Avanzar. " << endl
		<< "0.- Salir. " << endl
		<< "Opcion.. " ;
		cin >> op ;
	}while (op < 0 || op > 5 );
	
	return op ;
}

void instrucciones(){
	cout << "*********************************************************************" 
	<< "**********************************"<< endl
	<< "*  La tortuga se encuentra en un tablero de 20 X 20"
	<< "en la posicion 1,1 con la pluma arriba. " 
	<< "            *"<< endl 
	<< "*  Al momento de querer pintar algo sobre el tablero "
	<< "es necesario que la pluma se encuentre abajo.    *" << endl
	<< "*  La figura que quieras pintar se mostrara al momento que presiones 0." 
	<< "                               *"<< endl
	<< "*  Recuerda: " 
	<< " 							       " 
	<< "                               *" << endl
	<< "*  .-) El tablero es un cuadrado de 20 x 20. " 
	<< " 							      *" << endl
	<< "*  .-) Solo puedes pintar cuando la pluma se encuentra abajo. " 
	<< " 					      *" << endl
	<< "*  .-) La tortuga solo puede girar derecha o izquierda. " 
	<< " 					      *" << endl
	<< "*  .-) Lleva el control hacia donde esta viendo tu tortuga. " 
	<< " 					      *"<< endl
	<< "*  .-) Presiona 0 cuando creas que tu figura esta lista." 
	<< " 					      *"<< endl
	<< "*  .-) ¡¡ Suerte y diviertete!! " 
	<< " 					      			      *" << endl 
	<< "*********************************************************************"
	<< "**********************************" << endl ;
}

//Leitza Jocelyn Jimenez Aguilar
