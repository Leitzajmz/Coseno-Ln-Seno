/*Programa que lee archivo de excel con los datos recopilados 
de una encuesta de un estudio de mercado acerca de la venta
de fuentes de poder.. */

#include <iostream>
#include <cstdlib>
#include <fstream>
	using namespace std ;
	
	int menu();
	void frecuencia(char mat[][70], int pregunta, int frec[]);
	int noPregunta(int pregunta);
	void inicializarVec(int moda[]);
	int modaF(int vec[], int tam);
	void grafica(int frec[], int pregunta);
	
int main(){
	
	char mat1[125][70] , letra, c;
	int op , numPregunta , frec[9] = {0} ;
	
	ifstream arch("c:\\datos\\pi.txt",ios::in); 
	
	for (int r = 0 ; r < 125 ; r++ )    //Guardar los datos del archivo en una matriz
		for (int c = 0 ; c < 70 ; c++)
		arch >> mat1[r][c] ;
		//cout << mat1[0][8] ;
		
	do{
		op = menu();
			
		switch (op){
			case 1:
				cout << "De que pregunta desea sacar la frecuencia? " ;
				cin >> numPregunta ;
				frecuencia(mat1, numPregunta , frec);
				for (int i = 0 ; i < 9; i++){
					if (i >= 0 && i <8)
						letra = i+97;
					else
						letra = 122 ;
							
					if(frec[i] > 0){
						cout << letra << ") " << frec[i] << endl ;
					}
				}
				cout << "Desea saber la moda? S/N " ;
				cin >> c ;
				if (c == 's' || c == 'S'){
					letra = modaF(frec,9);
					cout << "La moda es la letra... " << letra << endl ;	
				}
				else
					cout << "OK... " << endl ;	
				
				cout << "Quieres graficar tus resultados.. S/N " ;
				cin >> c ;
				if (c == 's' || c == 'S')
					grafica(frec, numPregunta);
				else
					cout << "Ok..." << endl ;	 
					
			break;
				
			case 0 :
				break ;
					
			}//cierre del switch 
		} while (op != 0 );
	arch.close();
	cin.get();
	return 0 ;
}

/*FUNCIONES*/

int menu(){
	int op ;
	
	do {
		cout << "MENU" << endl
		<< "1.- Sacar Frecuencia " << endl
		<< "0.- Salir" << endl 
		<< "Opcion... " ;
		cin >> op ;	
	} while (op < 0 || op > 1 );
	return op ;
}
void frecuencia(char mat[][70], int pregunta, int frec[] ){ //Segun la estructura del archvio se validan las preguntas
	int preguntaNew = noPregunta(pregunta) ; //Para trabajar las columnas en la matriz
	int tamFinal;
	
	if (pregunta == 1 || pregunta == 11){
		tamFinal = preguntaNew + 8 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 96 && mat[r][c] < 105)
					frec[(mat[r][c])-97]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if
	
	else
		if (pregunta == 3 ){
		tamFinal = preguntaNew + 3 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 96 && mat[r][c] < 105)
					frec[(mat[r][c])-97]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if	
	
	else
		if (pregunta == 4 || pregunta == 12 ){
		tamFinal = preguntaNew + 4 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 96 && mat[r][c] < 105)
					frec[(mat[r][c])-97]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if	
	
	else
		if (pregunta == 6 || pregunta == 14 ){
		tamFinal = preguntaNew + 6 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 96 && mat[r][c] < 105)
					frec[(mat[r][c])-97]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if	
	
	else
		if (pregunta == 15 ){
		tamFinal = preguntaNew + 2 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 96 && mat[r][c] < 105)
					frec[(mat[r][c])-97]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if	
	
	else
		if (pregunta == 7 || pregunta == 17 ){
		tamFinal = preguntaNew + 9 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 48 && mat[r][c] < 57)
					frec[(mat[r][c])-49]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if	
	
	else
		if (pregunta == 13){
		tamFinal = preguntaNew + 3 ;
		inicializarVec(frec);
		for (int r = 0 ; r < 125 ; r++ )
			for(int c = preguntaNew ; c < tamFinal ; c++){
				if (mat[r][c] > 48 && mat[r][c] < 57)
					frec[(mat[r][c])-49]++;
				else
					frec[8]++;
			} //cierre del 	for de columnas	
	} //Cierre del if
	
	else
		for(int r = 0 ; r < 125 ; r++){
			if (mat[r][preguntaNew] > 96 && mat[r][preguntaNew] < 105)
				frec[(mat[r][preguntaNew])-97]++;
			else
				frec[8]++;		
		}		
} //Fin de la funcion de frecuencia

int modaF(int moda[], int tam){
	int moda2 = 0 , letra ;
	for (int i = 0 ; i < tam-1 ; i++){
		if (moda2 < moda[i] )
			moda2 = moda[i] ;
	} 
	for (int i = 0 ; i < 8 ; i++)
			if (moda2 == moda[i])
				letra = i+97 ;
	
	return letra ;	
}

void grafica(int frec[], int pregunta){
	ofstream arch("c:\\datos\\graficas.csv",ios::out); 
	
	arch << "Pregunta No. " << pregunta << endl ;
	
	for (int i = 0 ; i < 9 ; i++)
		arch << frec[i] << endl ;		
}


int noPregunta(int pregunta){ //Posicion de la columna a la que corresponde su inicio en la matriz
	if (pregunta == 1)
		pregunta -= 1 ; 
	else
	if (pregunta == 2 || pregunta == 3)
		pregunta += 6 ;
	else
	if (pregunta == 4)
		pregunta += 8 ;
	else
	if (pregunta == 5 || pregunta == 6)
		pregunta += 11 ;
	else
	if (pregunta == 7)
		pregunta += 17 ;
	else
	if (pregunta == 8 || pregunta == 9 || pregunta == 10 || pregunta == 11)
		pregunta += 24 ;
	else
	if (pregunta == 12)
		pregunta += 31 ;
	else
	if (pregunta == 13)
		pregunta += 34 ;
	else
	if (pregunta == 14)
		pregunta += 36 ;
	else
	if (pregunta == 15)
		pregunta += 41 ;
	else
	if (pregunta == 16 || pregunta == 17)
		pregunta += 42 ;
	else
	if (pregunta == 18 || pregunta == 19)
		pregunta += 50 ;

	return pregunta ;
}

void inicializarVec(int vec[]){
	for (int i = 0 ; i < 9; i++)
		vec[i] = 0 ;
}

/*  Leitza Jocelyn Jimenez Aguilar
	Isis Garza Hernandez
	ALberto Aguayo Vargas
	Jorge Alberto Martinez Verduzco 
	3G								*/

