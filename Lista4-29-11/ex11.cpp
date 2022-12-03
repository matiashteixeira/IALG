#include <iostream>
#include <fstream>


using namespace std;

int main() {
    
    int numero, bolinhas;
    ifstream entrada("entrada.txt");
    ofstream saida("saida.txt");

    entrada >> numero;
    bolinhas = (numero*(numero+1))/2;
    saida << bolinhas;
    return 0;
}