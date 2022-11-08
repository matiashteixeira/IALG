#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    float preco, avista, parc5x, parc10x;
    cin >> preco;
    avista = preco *0.9;
    parc5x = preco/5;
    parc10x = preco*1.2/10; 
    cout << setprecision(5) << avista << endl;
    cout << setprecision(5) << parc5x << endl;
    cout << setprecision(4) << parc10x << endl;
    return 0;
}
