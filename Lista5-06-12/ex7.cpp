#include <iostream>
#include <fstream>

using namespace std;

int calcula(int numero){

	if(numero%3 == 0){
		return numero;
	} else{
		return -1;
	}
}
	
int main()
{
	string nome;
	int numero;
	cin >> nome;
	
    ifstream entrada(nome);
    ofstream saida("saida.txt");
    
    while(entrada >> numero){
		if(calcula(numero) == -1){
			saida << numero << " ";
		}
	}
    
    
    return 0;
}
