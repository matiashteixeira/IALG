#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int dia, mes, ano, tempo;
    ifstream arquivo ("entrada.txt");
    arquivo >> dia >> mes >> ano;
    tempo = (2022-ano)*360 + (11 - mes)*30 + 7 - dia;
    cout << tempo;
    return 0;
}