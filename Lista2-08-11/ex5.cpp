#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int  peso1, nota2, peso2, nota3, peso3;
    float nota1, media;
    ifstream notas("notas.txt");
    ofstream ponderada("final.txt");
    notas >> nota1 >> peso1 >> nota2 >> peso2 >> nota3 >> peso3;
    media = (nota1*peso1 + nota2*peso2 + nota3*peso3)/ (peso1+peso2+peso3);
    ponderada.precision(4);
    ponderada << media;
    return 0;
}