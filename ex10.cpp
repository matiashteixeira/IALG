#include <iostream>
using namespace std;

int main() 
{
    int dinheiro, bala2, bala5, bala10, gastos;
    cin >> dinheiro;
    bala10 = dinheiro/20;
    bala5 = (dinheiro - bala10*20)/10;
    bala2 = (dinheiro - bala10*20 - bala5*10)/4;
    gastos = (bala10*20 + bala5*10 + bala2*4);
    cout << bala2 << endl;
    cout << bala5 << endl;
    cout << bala10 << endl;
    cout << gastos << endl;
    return 0;
}
