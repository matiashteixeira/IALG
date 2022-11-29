#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() 
{
    float salario, cheque1, cheque2;
    ifstream arquivo("entrada.txt");
    arquivo >> salario >> cheque1 >> cheque2;
    cout << salario-1.0038*(cheque1+cheque2);
    return 0;
}