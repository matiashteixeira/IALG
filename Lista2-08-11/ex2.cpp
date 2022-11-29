#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    string nomeArquivo, palavra;
    cin >> nomeArquivo;
    ofstream saida(nomeArquivo);
    cin >> palavra;
    saida << palavra;
    return 0;
}