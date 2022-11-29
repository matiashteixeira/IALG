#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    float aplicacao, taxa, acumulado;
    int meses;
    ifstream arquivo("poup.txt");

    arquivo >> aplicacao >> taxa >> meses;
    acumulado = (aplicacao*pow(1+taxa, meses))/taxa;
    cout << acumulado; 

    return 0;
}