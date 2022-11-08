#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int dinheiro, barra, trufa, bala;
    cin >> dinheiro;
    barra = ceil(dinheiro/17);
    trufa = (dinheiro - barra*17)/5;
    bala = (dinheiro - barra*17 - trufa*5);
    cout << barra << endl;
    cout << trufa << endl;
    cout << bala << endl;
    return 0;
}

