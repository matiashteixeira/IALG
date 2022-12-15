#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
    float preco, avista, x4, x10;
    ifstream entrada("valor.txt");
    ofstream saida("opcoes.txt");
    entrada >> preco;
    avista = 0.92*preco;
    x4 = preco/4;
    x10 = 0.11*preco;

    saida << fixed << setprecision(2);
    saida << avista << endl;
    saida << x4 << endl;
    saida << x10;


    return 0;
}