#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int saque, nota10, nota100, nota50;
    ofstream arquivo("saque.txt");

    cin >> saque;

    nota100 = saque/100;
    nota50 = (saque - nota100*100)/50;
    nota10 = (saque -nota100*100 - nota50*50)/10;
    
    arquivo << nota100 << endl;
    arquivo << nota50 << endl;
    arquivo << nota10 << endl;
    return 0;
}