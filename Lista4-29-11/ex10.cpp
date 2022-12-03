#include <iostream>
#include <fstream>


using namespace std;

int main() {
    
    string arq1, arq2, arq3, portugues, ingles;
    cin >> arq1 >> arq2 >> arq3;
    ifstream entradaport(arq1);
    ifstream entradaingl(arq2);
    ofstream saida(arq3);

    while (entradaport >> portugues){
        entradaingl >> ingles;
        saida << portugues << ": " << ingles << endl;
    }

    return 0;
}