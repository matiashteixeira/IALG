#include <iostream>
using namespace std;

int main() 
{
    int numero, produto, dig1, dig2, dig3;
    cin >> numero;
    dig1 = numero/100;
    dig2 = numero%100/10;
    dig3 = numero%100%10;
    produto = dig1*dig2*dig3;
    cout << produto;
    return 0;
}

