#include <iostream>
using namespace std;

int main() 
{
    unsigned int produzidos, luxo, comum;
    cin >> produzidos;
    comum = produzidos/3*2 + produzidos%3;
    luxo = produzidos - comum;
    cout << comum << endl;
    cout << luxo << endl;
    return 0;
}
