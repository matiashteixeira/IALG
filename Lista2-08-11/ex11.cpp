#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int hora, min;
    cin >> hora >> min;
    ofstream saida("saida.txt");
    saida << hora*60 << endl << min + hora*60 << endl << (min + hora*60)*60;  
    return 0;
}