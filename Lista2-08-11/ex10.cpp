#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    float degraus, altura, altdegraus;
    ifstream entrada("entrada.txt");
    ofstream saida("degraus.txt");
    entrada >> altdegraus >> altura;
    degraus = ceil(altura*100/altdegraus);
    saida << degraus;
    return 0;
}