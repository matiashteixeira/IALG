#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    float profundidade, altura, largura, densidade, volume;
    ifstream entrada("entrada.txt");
    entrada >> profundidade >> altura >> largura >> densidade;
    volume = profundidade*altura*largura;
    cout << volume*densidade;   

    return 0;
}