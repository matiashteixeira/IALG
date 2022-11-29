#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() 
{
    int criptar, primo1, primo2, primo3, resto1, resto2, resto3;
    ifstream chaves("chaves.txt");
    ofstream codigo("codigo.txt");

    cin >> criptar;
    chaves >> primo1 >> primo2 >> primo3;

    resto1 = criptar%primo1;
    resto2 = criptar%primo2;
    resto3 = criptar%primo3;

    codigo << resto1 << endl;
    codigo << resto2 << endl;
    codigo << resto3 << endl;
    
    
    return 0;
}