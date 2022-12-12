#include <iostream>

using namespace std;

float calculo(int altura, int base){
    float inclinacao;
    inclinacao = altura*100/base;
    return inclinacao;
}
	
int main(){
	int qtd, altura, base, cont = 0;

    cin >> qtd;

    while (qtd>0){
        qtd--;
        cin >> altura >> base;

        cout << calculo(altura, base) << endl;

        if(calculo(altura, base)<=8){
            
            cont++;
        }
    }
    cout << cont;
	return 0;
}
