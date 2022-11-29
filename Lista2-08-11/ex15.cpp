#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    int compra, dinheiro, nota20, nota10, nota5, nota2, nota1, troco;
    ifstream entrada("entrada.txt");
    ofstream saida("saida.txt");
    entrada >> dinheiro >> compra;
    troco = dinheiro - compra;
    nota20 = troco/20;
    nota10 = (troco - nota20*20)/10;
    nota5 = (troco - nota20*20 - nota10*10)/5;
    nota2 = (troco - nota20*20 - nota10*10 - nota5*5)/2;
    nota1 = (troco - nota20*20 - nota10*10 - nota5*5 - nota2*2);
    saida << nota20 << endl;
    saida << nota10 << endl;
    saida << nota5 << endl;
    saida << nota2 << endl;
    saida << nota1 << endl;
    
    return 0;
}