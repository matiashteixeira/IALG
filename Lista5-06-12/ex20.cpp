#include <iostream>

using namespace std;



float sub_rotina(int parcelas){
	int cont = 1;
    float soma = 0, valor;
    
    while (cont<=parcelas){
        valor = (cont*(cont+1.0)/(cont+3)); 
        soma += valor;
        cont++;
    }
	return soma;
}
	
int main(){
    int parcelas;
    cin >> parcelas;

    cout << sub_rotina(parcelas);
}
