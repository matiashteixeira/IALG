#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() 
{
    float base, gratificacao, imposto;
    cin >> base >> gratificacao >> imposto;
    ofstream arquivo ("holerite.txt");
    arquivo << base + gratificacao << fixed << setprecision(2) << endl;
    arquivo << imposto/100*(base+gratificacao) << fixed << setprecision(2) << endl;
    arquivo << (base - imposto/100*(base+gratificacao))+gratificacao << fixed << setprecision(2) << endl;
    
    return 0;
}