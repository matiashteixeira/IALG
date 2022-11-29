#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    float largura, comprimento, area, potencia;
    const float pot = 18;
    ofstream arquivo1("potencia.txt");

    cin >> largura >> comprimento;

    area = largura*comprimento;
    potencia = area*pot;
    arquivo1 << fixed << setprecision(1);
    arquivo1 << area << "m2" << endl;
    arquivo1 << potencia << "W" << endl;
    return 0;
}