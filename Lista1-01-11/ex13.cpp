#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    float depositado, taxa, montante;
    int meses;
    cin >> depositado >> taxa >> meses;
    montante = depositado * pow(1+taxa,meses);
    cout << montante;
    return 0;
}

