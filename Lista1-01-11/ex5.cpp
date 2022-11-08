#include <iostream>
using namespace std;

int main() 
{
    int hulk, tanque, carro, soldado, rifle;
    cin >> hulk;
    tanque = hulk/60000;
    carro = (hulk-tanque*60000)/900;
    soldado = (hulk-tanque*60000-carro*900)/85;
    rifle = (hulk-tanque*60000-carro*900-soldado*85)/4;
    cout << tanque << endl;
    cout << carro << endl;
    cout << soldado << endl;
    cout << rifle << endl;
    return 0;
}

