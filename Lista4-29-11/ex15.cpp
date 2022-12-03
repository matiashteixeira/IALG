#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    int numero, Fibonnaci = 0, Fibonnaci_anterior = 1, Fibonnaci_anterior_anterior = 0, cont = 1;
    ofstream saida("resultado.txt");

    cin >> numero;

    while(numero>cont){

        if(cont == 1){
            saida << "0" << endl;
        }
        Fibonnaci_anterior_anterior = Fibonnaci_anterior;
        Fibonnaci_anterior = Fibonnaci;

        Fibonnaci = Fibonnaci_anterior + Fibonnaci_anterior_anterior;
        saida << Fibonnaci << endl;

        cont++;

    }   
    if(cont == 1){
            saida << "0" << endl;
        }
    return 0;
}