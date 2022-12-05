#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    int qtd;
    float numero, numero_anterior = 0, maior, menor = 1000;
    string nome;
    cin >> nome;

    ifstream arquivo(nome);
    arquivo >> qtd;

    while(qtd>0){
        qtd--;
        numero_anterior = numero;
        arquivo >> numero;
        

        if(numero>numero_anterior){
            maior = numero;
        } else if(numero < menor){
        menor = numero;
        }
    }
    cout << maior << endl;
    cout << menor << endl;


    return 0;
}