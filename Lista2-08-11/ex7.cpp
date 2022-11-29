#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    string nome1, nome2, nome3, arq1, arq2, arq3;
    
    cin >> nome1;
    cin >> nome2;
    cin >> nome3;

    fstream arquivo1(nome1);
    fstream arquivo2(nome2);
    ofstream arquivo3(nome3);
    
    arquivo1 >> arq1;
    arquivo2 >> arq2;
    arq3 = arq1 + " " + arq2;
    arquivo3 << arq3;
    return 0;
}