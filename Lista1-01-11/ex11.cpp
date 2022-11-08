#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    float altura, degrau;
    int qtd;
    cin >> degrau >> altura;
    qtd = ceil(altura*100/degrau);
    cout << qtd;
    return 0;
}
