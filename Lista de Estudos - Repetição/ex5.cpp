#include <iostream>

using namespace std;

int main(){
    int numero, numero_triangular = 0, numero_triangular_anterior = 0, cont = 0;

    cin >> numero;

    while(numero>=cont){
        numero_triangular_anterior = numero_triangular;
        numero_triangular = cont + numero_triangular_anterior;
        cont++;
    }
    cout << numero_triangular;

    return 0;
}