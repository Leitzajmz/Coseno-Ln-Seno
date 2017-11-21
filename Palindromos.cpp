#include <iostream>
#include <string>
	using namespace std ;
	
	int palabraIgual(char frase[]);
	int longitud(char c[]);
	
int main (){
	
	char palindromo[35] ;
	int res ;
	
	cout << "Ingresa una frase: " << endl ;
	cin.getline(palindromo , 35 , '\n');

	res = palabraIgual(palindromo) ;
	if (res == -1)
		cout << "Tu palabra no es palindroma" << endl ;
	else 
		cout << "Tu palabra es palindroma" << endl ; 
	
	return 0 ;
}

int longitud(char c[]){
	int cont = 0 ;
	for ( ; c[cont]; cont++);
	return cont ;
}

int palabraIgual(char frase[]){
	int cont = 0 , p1 = 0 , p2 = longitud(frase)-1;
	
	while(p2 >= p1){
		if (frase[p1] == 32)
			p1 += 1 ;
		if (frase[p2] == 32 )
			p2 -= 1 ;
			
		if (frase[p1] == frase[p2])
			cont++ ;
		else
			cont = 0 ;
		p1++;
		p2--;
	}
	
	if (cont == 0)
		return -1 ;
	else
		return cont ;
} 
