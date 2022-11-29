#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int numero,soma, produto, dig1, dig2, dig3;
    ofstream arquivo("saida.txt");
    cin >> numero;
    dig1 = numero/100;
    dig2 = numero%100/10;
    dig3 = numero%100%10;
    produto = dig1*dig2*dig3;
    soma = dig1+dig2+dig3;
    arquivo << produto;
    cout << soma;
    return 0;
}