#include <iostream>

using namespace std;

int main(){
    char caracter = 'a', caracter_novo;
    int qtd, aux = 0, cont = 1, soma_caracter = 0;

    cin >> qtd;

    while(qtd > 0){
        qtd--;
        while(cont>aux){
            aux++;
            caracter_novo = caracter + soma_caracter;
            cout << caracter_novo << " ";
            soma_caracter++;
        }
        cout << endl;
        cont++;
        soma_caracter = 0;
        aux = 0;
    }

    return 0;
}