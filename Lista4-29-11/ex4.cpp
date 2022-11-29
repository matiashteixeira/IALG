#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream entrada("entrada.txt");
    ofstream saida("saida.txt");
    int cont = 1, numero, fatorial, numero_inicial, termo;

    entrada >> numero;
    numero_inicial = numero;

    while((numero_inicial-cont) != 0){
        termo = numero_inicial-cont;
        numero = numero*termo;
        cont++;
    }
    saida << numero;

     return 0;
}