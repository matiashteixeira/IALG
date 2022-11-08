#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    float altura, angulo, escada;
    cin >> altura >> angulo;
    escada = altura/sin(angulo*M_PI/180);
    cout.precision(4);
    cout << escada; 
    return 0;
}
